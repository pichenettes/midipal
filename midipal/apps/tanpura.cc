// Copyright 2012 Olivier Gillet.
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
// Tanpura app.

#include "midipal/apps/tanpura.h"

#include "avrlib/op.h"
#include "avrlib/string.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t tanpura_factory_data[8] PROGMEM = {
  0, 0, 120, 8, 0, 60, 0, 5
};

/* <static> */
uint8_t Tanpura::running_;
uint8_t Tanpura::clk_mode_;
uint8_t Tanpura::bpm_;
uint8_t Tanpura::clock_division_;  
uint8_t Tanpura::channel_;
uint8_t Tanpura::root_;
uint8_t Tanpura::pattern_;
uint8_t Tanpura::shift_;

uint8_t Tanpura::midi_clock_prescaler_;
uint8_t Tanpura::tick_;
uint8_t Tanpura::step_;
/* </static> */

/* static */
const prog_AppInfo Tanpura::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  &OnNoteOn, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
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
  8, // settings_size
  SETTINGS_TANPURA, // settings_offset
  &running_, // settings_data
  tanpura_factory_data, // factory_data
  STR_RES_TANPURA, // app_name
  true
};

/* static */
void Tanpura::OnInit() {
  ui.AddPage(STR_RES_RUN, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_CLK, STR_RES_INT, 0, 1);
  ui.AddPage(STR_RES_BPM, UNIT_INTEGER, 40, 240);
  ui.AddPage(STR_RES_DIV, STR_RES_2_1, 0, 16);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_SA, UNIT_NOTE, 36, 84);
  ui.AddPage(STR_RES_MOD, STR_RES_PA, 0, 3);
  ui.AddPage(STR_RES_CYC, UNIT_INTEGER, 0, 7);
  clock.Update(bpm_, 0, 0);
  SetParameter(2, bpm_);
  clock.Start();
  running_ = 0;
}

/* static */
void Tanpura::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  app.Send(status, data, data_size);
}

/* static */
void Tanpura::SetParameter(uint8_t key, uint8_t value) {
  if (key == 0) {
    if (value == 1) {
      Start();
    } else {
      Stop();
    }
  }
  static_cast<uint8_t*>(&running_)[key] = value;
  if (key == 2) {
    clock.Update(bpm_, 0, 0);
  }
  midi_clock_prescaler_ = ResourcesManager::Lookup<uint8_t, uint8_t>(
      midi_clock_tick_per_step, clock_division_);
}

/* static */
void Tanpura::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Start();
  }
}

/* static */
void Tanpura::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Stop();
  }
}

/* static */
void Tanpura::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

/* static */
void Tanpura::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    Tick();
  }
}

/* static */
void Tanpura::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL && running_) {
    app.SendNow(0xf8);
    Tick();
  }
}

/* static */
void Tanpura::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  if (ui.editing() && ui.page() == 5) {
    while (note < 36) {
      note += 12;
    }
    while (note > 84) {
      note -= 12;
    }
    root_ = note;
  }
}

/* static */
void Tanpura::Stop() {
  if (!running_) {
    return;
  }
  
  // Flush the note off messages in the queue.
  app.FlushQueue(channel_);
  // To be on the safe side, send an all notes off message.
  app.Send3(0xb0 | channel_, 123, 0);
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    app.SendNow(0xfc);
  }
  running_ = 0;
}

/* static */
void Tanpura::Start() {
  if (running_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    clock.Start();
    app.SendNow(0xfa);
  }
  tick_ = midi_clock_prescaler_ - 1;
  running_ = 1;
  step_ = 0;
}

const prog_int8_t shifts[] PROGMEM = { -5, -7, -1, 0 };
const prog_uint8_t durations[] PROGMEM = { 5, 0, 0, 0, 0, 1, 1, 2 };

/* static */
void Tanpura::Tick() {
  ++tick_;
  if (tick_ >= midi_clock_prescaler_) {
    app.SendScheduledNotes(channel_);
    tick_ = 0;
    uint8_t note = 0;
    uint8_t actual_step = (step_ + shift_) & 0x07;
    uint8_t duration = pgm_read_byte(durations + actual_step);
    if (actual_step == 0) {
      note = root_ - 12;
    } else if (actual_step == 5) {
      int8_t shift = pgm_read_byte(shifts + pattern_);
      if (shift != 0) {
        note = root_ + shift;
      }
    } else if (actual_step >= 6) {
      note = root_;
    }
    if (note) {
      app.Send3(0x90 | channel_, note, actual_step == 0 ? 127 : 80);
      app.SendLater(note, 0, duration - 1);
    }
    step_ = (step_ + 1) & 0x7;
  }
}

} }  // namespace midipal::apps
