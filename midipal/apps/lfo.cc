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
#include "avrlib/random.h"

#include "midipal/clock.h"
#include "midipal/note_stack.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t lfo_factory_data[31] PROGMEM = {
  0, 0, 120, 0, 0, 16, 0,
  
  7, 63, 63, 0, 2, 0,
  10, 0, 63, 0, 4, 0,
  74, 0, 63, 0, 2, 0,
  71, 0, 63, 0, 4, 0,
};

/* <static> */
uint8_t Lfo::running_;
uint8_t Lfo::clk_mode_;
uint8_t Lfo::bpm_;
uint8_t Lfo::groove_template_;
uint8_t Lfo::groove_amount_;
uint8_t Lfo::clock_division_;  
uint8_t Lfo::channel_;

LfoData Lfo::lfo_data_[kNumLfos];

uint16_t Lfo::phase_[kNumLfos];
uint16_t Lfo::phase_increment_[kNumLfos];

uint8_t Lfo::tick_;
uint8_t Lfo::midi_clock_prescaler_;
/* </static> */

/* static */
const prog_AppInfo Lfo::app_info_ PROGMEM = {
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
  7 + sizeof(LfoData) * kNumLfos, // settings_size
  SETTINGS_LFO, // settings_offset
  &running_, // settings_data
  lfo_factory_data, // factory_data
  STR_RES_CC_LFO, // app_name
  true
};

/* static */
void Lfo::OnInit() {
  ui.AddPage(STR_RES_RUN, STR_RES_OFF, 0, 1);
  ui.AddClockPages();
  ui.AddPage(STR_RES_RES, STR_RES_2_1, 0, 16);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  
  for (uint8_t i = 0; i < kNumLfos; ++i) {
    ui.AddPage(STR_RES_CC1 + i, UNIT_INTEGER, 0, 127);
    ui.AddPage(STR_RES_AM1 + i, UNIT_SIGNED_INTEGER, -63, 63);
    ui.AddPage(STR_RES_CE1 + i, UNIT_INTEGER, 0, 127);
    ui.AddPage(STR_RES_WF1 + i, STR_RES_TRI, 0, 17);
    ui.AddPage(STR_RES_RT1 + i, STR_RES_4_1, 0, 18);
    ui.AddPage(STR_RES_SY1 + i, STR_RES_FRE, 0, 2);
  }

  clock.Update(bpm_, groove_template_, groove_amount_);
  SetParameter(2, bpm_);
  clock.Start();
  running_ = 0;
}

/* static */
void Lfo::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  app.Send(status, data, data_size);
}

/* static */
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

/* static */
void Lfo::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Start();
  }
}

/* static */
void Lfo::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Stop();
  }
}

/* static */
void Lfo::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

/* static */
void Lfo::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    Tick();
  }
}

/* static */
void Lfo::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL && running_) {
    app.SendNow(0xf8);
    Tick();
  }
}

/* static */
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

/* static */
void Lfo::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  note_stack.NoteOff(note);
}

/* static */
void Lfo::Stop() {
  if (!running_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    app.SendNow(0xfc);
  }
  running_ = 0;
}

/* static */
void Lfo::Start() {
  if (running_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    clock.Start();
    app.SendNow(0xfa);
  }
  tick_ = midi_clock_prescaler_ - 1;
  running_ = 1;
  for (uint8_t i = 0; i < kNumLfos; ++i) {
    phase_[i] = 0;
  }
}

/* static */
void Lfo::Tick() {
  ++tick_;
  if (tick_ >= midi_clock_prescaler_) {
    tick_ = 0;
    for (uint8_t i = 0; i < kNumLfos; ++i) {
      uint8_t value;
      uint8_t skip = 0;
      if (lfo_data_[i].waveform == 17) {
        if (phase_[i] < phase_increment_[i]) {
          value = Random::GetByte();
        } else {
          skip = 1;
        }
      } else {
        uint16_t offset = U8U8Mul(lfo_data_[i].waveform, 129);
        value = InterpolateSample(
            wav_res_lfo_waveforms + offset,
            phase_[i] >> 1);
      }
      phase_[i] += phase_increment_[i];
      if (lfo_data_[i].amount && !skip) {
        int16_t scaled_value = static_cast<int16_t>(lfo_data_[i].center_value) + 
            S8S8MulShift8(lfo_data_[i].amount << 1, value - 128);
        scaled_value = Clip(scaled_value, 0, 127);
        app.Send3(
            0xb0 | channel_,
            lfo_data_[i].cc_number & 0x7f,
            scaled_value & 0x7f);
      }
    }
  }
}

} }  // namespace midipal::apps
