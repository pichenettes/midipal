// Copyright 2011 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// -----------------------------------------------------------------------------
//
// Delay app.

#include "midipal/apps/delay.h"

#include "midipal/display.h"

#include "midipal/clock.h"
#include "midipal/event_scheduler.h"
#include "midipal/note_stack.h"
#include "midipal/notes.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {
  
using namespace avrlib;

static const prog_uint8_t velocity_factor[16] PROGMEM = {
  31, 60, 87, 112, 134, 155, 174, 191, 206, 219, 230, 239, 246, 251, 253, 255
};

const prog_uint8_t delay_factory_data[10] PROGMEM = {
  0, 120, 0, 0, 0, 8, 4, 10, 0, 0
};

/* <static> */
uint8_t Delay::running_;
uint8_t Delay::clk_mode_;
uint8_t Delay::bpm_;
uint8_t Delay::groove_template_;
uint8_t Delay::groove_amount_;
uint8_t Delay::channel_;
uint8_t Delay::delay_;
uint8_t Delay::num_taps_;
uint8_t Delay::velocity_factor_;
int8_t Delay::transposition_;
int8_t Delay::doppler_;
uint8_t Delay::velocity_factor_reverse_log_;
/* </static> */

/* static */
const prog_AppInfo Delay::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  &OnNoteOn, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  &OnNoteOff, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnAftertouch)(uint8_t, uint8_t);
  NULL, // void (*OnControlChange)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnProgramChange)(uint8_t, uint8_t);
  NULL, // void (*OnPitchBend)(uint8_t, uint16_t);
  NULL, // void (*OnSysExByte)(uint8_t);
  &OnClock, // void (*OnClock)();
  &OnStart, // void (*OnStart)();
  &OnContinue, // void (*OnContinue)();
  &OnStop, // void (*OnStop)();
  NULL, // uint8_t (*CheckChannel)(uint8_t);
  NULL, // void (*OnRawByte)(uint8_t);
  &OnRawMidiData, // void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t);
  &OnInternalClockTick, // void (*OnInternalClockTick)();
  NULL, // void (*OnInternalClockStep)();
  NULL, // uint8_t (*OnIncrement)(int8_t);
  NULL, // uint8_t (*OnClick)();
#ifdef MIDIBUD_FIRMWARE
  NULL, // uint8_t (*OnSwitch)(uint8_t);
#else
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  &SetParameter, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  10, // settings_size
  SETTINGS_DELAY, // settings_offset
  &clk_mode_, // settings_data
  delay_factory_data, // factory_data
  STR_RES_DELAY, // app_name
  false
};

/* static */
void Delay::OnInit() {
  ui.AddClockPages();
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_DELAY, STR_RES_2_1, 0, 12);
  ui.AddPage(STR_RES_REP, UNIT_INTEGER, 0, 32);
  ui.AddPage(STR_RES_VEL, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_TRS, UNIT_SIGNED_INTEGER, -24, 24);
  ui.AddPage(STR_RES_DPL, UNIT_SIGNED_INTEGER, -63, 63);
  
  clock.Update(bpm_, groove_template_, groove_amount_);
  SetParameter(5, delay_);  // Force an update of the prescaler.
  clock.Start();
  running_ = 0;
}

/* static */
void Delay::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  // Forward everything.
  app.Send(status, data, data_size);
}

/* static */
void Delay::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

/* static */
void Delay::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

/* static */
void Delay::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 0;
  }
}

/* static */
void Delay::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    SendEchoes();
  }
}

/* static */
void Delay::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    app.SendNow(0xf8);
    SendEchoes();
  }
}

/* static */
void Delay::OnNoteOn(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  ScheduleEchoes(note, velocity, num_taps_);
}

/* static */
void Delay::OnNoteOff(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  ScheduleEchoes(note, 0, num_taps_);
}

/* static */
void Delay::SendEchoes() {
  uint8_t current = event_scheduler.root();
  while (current) {
    const SchedulerEntry& entry = event_scheduler.entry(current);
    if (entry.when) {
      break;
    }
    if (entry.note != kZombieSlot) {
      if (entry.velocity == 0) {
        app.Send3(0x80 | channel_, entry.note, 0);
      } else {
        app.Send3(0x90 | channel_, entry.note, entry.velocity);
      }
      ScheduleEchoes(entry.note, entry.velocity, entry.tag);
    }
    current = entry.next;
  }
  event_scheduler.Tick();
}

/* static */
void Delay::ScheduleEchoes(uint8_t note, uint8_t velocity, uint8_t num_taps) {
  if (num_taps == 0) {
    return;
  }
  int8_t doppler_iterations = num_taps_ - num_taps;
  if (doppler_iterations < 0) {
    doppler_iterations = 0;
  }
  int16_t delay = ResourcesManager::Lookup<uint8_t, uint8_t>(
      midi_clock_tick_per_step, delay_);
  for (uint8_t i = 0; i < doppler_iterations && doppler_; ++i) {
    delay += S16S8MulShift8(delay, doppler_ << 1);
  }

  uint8_t min_velocity_value = velocity > 0 ? 1 : 0;
  velocity = U8U8MulShift8(velocity, velocity_factor_reverse_log_);
  if (velocity < min_velocity_value) {
    velocity = min_velocity_value;
  }
  note = Transpose(note, transposition_);
  app.SendLater(note, velocity, Clip(delay, 1, 255), num_taps - 1);
  if (event_scheduler.overflow()) {
    display.set_status('!');
  }
}

/* static */
void Delay::SetParameter(uint8_t key, uint8_t value) {
  static_cast<uint8_t*>(&clk_mode_)[key] = value;
  if (key < 4) {
    clock.Update(bpm_, groove_template_, groove_amount_);
  }
  if (key == 0 && value == 0) {
    app.SendNow(0xfc);
  }
  velocity_factor_reverse_log_ = ResourcesManager::Lookup<uint8_t, uint8_t>(
      velocity_factor, velocity_factor_);
}

} }  // namespace midipal::apps
