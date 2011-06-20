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
// CC LFO app.

#include "midipal/apps/lfo.h"

#include "avrlib/op.h"
#include "avrlib/string.h"

#include "midipal/clock.h"
#include "midipal/note_stack.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

/* extern */
const prog_uint8_t lfo_factory_data[31] PROGMEM = {
  0, 0, 120, 0, 0, 16, 0,
  
  7, 63, 63, 0, 2, 0,
  10, 0, 63, 0, 4, 0,
  74, 0, 63, 0, 2, 0,
  71, 0, 63, 0, 4, 0,
};

void Lfo::OnInit() {
  ui.AddPage(STR_RES_RUN, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_CLK, STR_RES_INT, 0, 1);
  ui.AddPage(STR_RES_BPM, UNIT_INTEGER, 40, 240);
  ui.AddPage(STR_RES_GRV, STR_RES_SWG, 0, 5);
  ui.AddPage(STR_RES_AMT, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_RES, STR_RES_2_1, 0, 16);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  
  for (uint8_t i = 0; i < kNumLfos; ++i) {
    ui.AddPage(STR_RES_CC1 + i, UNIT_INTEGER, 0, 127);
    ui.AddPage(STR_RES_AM1 + i, UNIT_SIGNED_INTEGER, -63, 63);
    ui.AddPage(STR_RES_CE1 + i, UNIT_INTEGER, 0, 127);
    ui.AddPage(STR_RES_WF1 + i, STR_RES_TRI, 0, 16);
    ui.AddPage(STR_RES_RT1 + i, STR_RES_4_1, 0, 18);
    ui.AddPage(STR_RES_SY1 + i, STR_RES_FRE, 0, 2);
  }

  clock.Update(bpm_, groove_template_, groove_amount_);
  SetParameter(2, bpm_);
  clock.Start();
  running_ = 0;
}

void Lfo::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  Send(status, data, data_size);
}

void Lfo::SetParameter(uint8_t key, uint8_t value) {
  if (key == 0) {
    if (value == 1) {
      Start();
    } else {
      Stop();
    }
  }
  static_cast<uint8_t*>(&running_)[key] = value;
  if (key < 5) {
    clock.Update(bpm_, groove_template_, groove_amount_);
  }
  midi_clock_prescaler_ = ResourcesManager::Lookup<uint8_t, uint8_t>(
      midi_clock_tick_per_step, clock_division_);
  uint16_t factor = midi_clock_prescaler_;
  for (uint8_t i = 0; i < kNumLfos; ++i) {
    phase_increment_[i] = ResourcesManager::Lookup<uint16_t, uint8_t>(
      lut_res_increments, lfo_data_[i].cycle_duration) * factor;
  }
}

void Lfo::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Start();
  }
}

void Lfo::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Stop();
  }
}

void Lfo::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

void Lfo::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    Tick();
  }
}

void Lfo::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL && running_) {
    SendNow(0xf8);
    Tick();
  }
}

void Lfo::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  for (uint8_t i = 0; i < kNumLfos; ++i) {
    if (lfo_data_[i].sync_mode == LFO_SYNC_NOTE_ON ||
        (lfo_data_[i].sync_mode == LFO_SYNC_START && note_stack.size() == 0)) {
      phase_[i] = 0;
    }
  }
  note_stack.NoteOn(note, velocity);
}

void Lfo::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  note_stack.NoteOff(note);
}


void Lfo::Stop() {
  if (!running_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    SendNow(0xfc);
  }
  running_ = 0;
}

void Lfo::Start() {
  if (running_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    SendNow(0xfa);
  }
  tick_ = midi_clock_prescaler_ - 1;
  running_ = 1;
  for (uint8_t i = 0; i < kNumLfos; ++i) {
    phase_[i] = 0;
  }
}

void Lfo::Tick() {
  ++tick_;
  if (tick_ >= midi_clock_prescaler_) {
    tick_ = 0;
    for (uint8_t i = 0; i < kNumLfos; ++i) {
      uint16_t offset = U8U8Mul(lfo_data_[i].waveform, 129);
      uint8_t value = InterpolateSample(
          wav_res_lfo_waveforms + offset,
          phase_[i] >> 1);
      phase_[i] += phase_increment_[i];
      if (lfo_data_[i].amount) {
        int16_t scaled_value = static_cast<int16_t>(lfo_data_[i].center_value) + 
            S8S8MulShift8(lfo_data_[i].amount << 1, value - 128);
        scaled_value = Clip(scaled_value, 0, 127);
        Send3(
            0xb0 | channel_,
            lfo_data_[i].cc_number & 0x7f,
            scaled_value & 0x7f);
      }
    }
  }
}

const prog_uint8_t* Lfo::factory_data() {
  return lfo_factory_data;
}

} }  // namespace midipal::apps
