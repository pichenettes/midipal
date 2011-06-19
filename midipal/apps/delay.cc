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
  
static const prog_uint8_t velocity_factor[16] PROGMEM = {
  31, 60, 87, 112, 134, 155, 174, 191, 206, 219, 230, 239, 246, 251, 253, 255
};

using namespace avrlib;

void Delay::OnInit() {
  ui.AddPage(STR_RES_CLK, STR_RES_INT, 0, 1);
  ui.AddPage(STR_RES_BPM, UNIT_INTEGER, 40, 240);
  ui.AddPage(STR_RES_GRV, STR_RES_SWG, 0, 5);
  ui.AddPage(STR_RES_AMT, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_DELAY, STR_RES_1_1, 0, 10);
  ui.AddPage(STR_RES_REP, UNIT_INTEGER, 0, 32);
  ui.AddPage(STR_RES_VEL, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_TRS, UNIT_SIGNED_INTEGER, -24, 24);
  
  clock.Update(bpm_, groove_template_, groove_amount_);
  SetParameter(5, delay_);  // Force an update of the prescaler.
  clock.Start();
  running_ = 0;
}

void Delay::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  // Forward everything.
  Send(status, data, data_size);
}

void Delay::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

void Delay::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

void Delay::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 0;
  }
}

void Delay::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    SendEchoes();
  }
}

void Delay::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    SendNow(0xf8);
    SendEchoes();
  }
}

void Delay::OnNoteOn(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  ScheduleEchoes(note, velocity, num_taps_);
}

void Delay::OnNoteOff(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  ScheduleEchoes(note, 0, num_taps_);
}

void Delay::SendEchoes() {
  uint8_t current = event_scheduler.root();
  while (current) {
    const SchedulerEntry& entry = event_scheduler.entry(current);
    if (entry.when) {
      break;
    }
    if (entry.note != kZombieSlot) {
      if (entry.velocity == 0) {
        Send3(0x80 | channel_, entry.note, 0);
      } else {
        Send3(0x90 | channel_, entry.note, entry.velocity);
      }
      ScheduleEchoes(entry.note, entry.velocity, entry.tag);
    }
    current = entry.next;
  }
  event_scheduler.Tick();
}

void Delay::ScheduleEchoes(uint8_t note, uint8_t velocity, uint8_t num_taps) {
  if (num_taps == 0) {
    return;
  }
  uint8_t delay = ResourcesManager::Lookup<uint8_t, uint8_t>(
      midi_clock_tick_per_step, delay_);
  uint8_t min_velocity_value = velocity > 0 ? 1 : 0;
  velocity = U8U8MulShift8(velocity, velocity_factor_reverse_log_);
  if (velocity < min_velocity_value) {
    velocity = min_velocity_value;
  }
  note = Transpose(note, transposition_);
  SendLater(note, velocity, delay, num_taps - 1);
  if (event_scheduler.overflow()) {
    display.set_status('!');
  }
}

void Delay::SetParameter(uint8_t key, uint8_t value) {
  static_cast<uint8_t*>(&clk_mode_)[key] = value;
  if (key < 4) {
    clock.Update(bpm_, groove_template_, groove_amount_);
  }
  velocity_factor_reverse_log_ = ResourcesManager::Lookup<uint8_t, uint8_t>(
      velocity_factor, velocity_factor_);
}

} }  // namespace midipal::apps
