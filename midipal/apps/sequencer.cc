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
// Sequencer app.

#include "midipal/apps/sequencer.h"

#include "avrlib/op.h"
#include "avrlib/string.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t sequencer_factory_data[141] PROGMEM = {
  0, 0, 120, 0, 0,
  12, 0, 74, 1, 1, 1, 1, 8,
  48, 12, 15, 127,
  48, 12,  0, 127,
  60, 12, 15, 112,
  60, 12,  0, 112,
  48, 12, 15, 96,
  48, 12,  0, 96,
  60, 12, 15, 80,
  60, 12,  0, 80,
  48, 12, 15, 64,
  48, 12,  0, 64,
  60, 12, 15, 48,
  60, 12,  0, 48,
  48, 12, 15, 32,
  48, 12,  0, 32,
  60, 12, 15, 16,
  60, 12,  0, 16,
  48, 12, 15, 0,
  48, 12,  0, 0,
  60, 12, 15, 16,
  60, 12,  0, 16,
  48, 12, 15, 32,
  48, 12,  0, 32,
  60, 12, 15, 48,
  60, 12,  0, 48,
  48, 12, 15, 64,
  48, 12,  0, 64,
  60, 12, 15, 80,
  60, 12,  0, 80,
  48, 12, 15, 96,
  48, 12,  0, 96,
  60, 12, 15, 112,
  60, 12,  0, 112,
};

/* <static> */
uint8_t Sequencer::running_;
uint8_t Sequencer::clk_mode_;
uint8_t Sequencer::bpm_;
uint8_t Sequencer::groove_template_;
uint8_t Sequencer::groove_amount_;
uint8_t Sequencer::clock_division_;  
uint8_t Sequencer::channel_;
uint8_t Sequencer::cc_number_;
uint8_t Sequencer::note_track_;
uint8_t Sequencer::duration_track_;
uint8_t Sequencer::velocity_track_;
uint8_t Sequencer::cc_track_;
uint8_t Sequencer::num_steps_;
uint8_t Sequencer::sequence_data_[32 * kNumBytesPerStep];

uint8_t Sequencer::midi_clock_prescaler_;
uint8_t Sequencer::tick_;
uint8_t Sequencer::step_;
uint8_t Sequencer::root_note_;
uint8_t Sequencer::last_note_;
/* </static> */

/* static */
const prog_AppInfo Sequencer::app_info_ PROGMEM = {
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
  &CheckPageStatus, // uint8_t (*CheckPageStatus)(uint8_t);
  13 + 32 * kNumBytesPerStep, // settings_size
  SETTINGS_SEQUENCER, // settings_offset
  &running_, // settings_data
  sequencer_factory_data, // factory_data
  STR_RES_SEQUENCR, // app_name
  false
};

/* static */
void Sequencer::OnInit() {
  lcd.SetCustomCharMapRes(chr_res_sequencer_icons, 4, 1);
  ui.AddPage(STR_RES_RUN, STR_RES_OFF, 0, 1);
  ui.AddClockPages();
  ui.AddPage(STR_RES_DIV, STR_RES_2_1, 0, 16);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_CC_, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_NOT, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_DUR, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_VEL, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_CC_LFO, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_STP, UNIT_INTEGER, 1, 32);
  ui.AddRepeatedPage(STR_RES_1, UNIT_NOTE, 0, 127, 32);
  ui.AddRepeatedPage(STR_RES_2, STR_RES_2_1, 0, 16, 32);
  ui.AddRepeatedPage(STR_RES_3, UNIT_INTEGER, 0, 15, 32);
  ui.AddRepeatedPage(STR_RES_4, UNIT_INTEGER, 0, 127, 32);
  clock.Update(bpm_, groove_template_, groove_amount_);
  SetParameter(2, bpm_);
  clock.Start();
  running_ = 0;
}

/* static */
void Sequencer::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  // Forward everything except note on for the selected channel.
  if (status != (0x80 | channel_) && 
      status != (0x90 | channel_)) {
    app.Send(status, data, data_size);
  }
}

/* static */
void Sequencer::SetParameter(uint8_t key, uint8_t value) {
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
}

/* static */
void Sequencer::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Start();
  }
}

/* static */
void Sequencer::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Stop();
  }
}

/* static */
void Sequencer::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

/* static */
void Sequencer::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    Tick();
  }
}

/* static */
void Sequencer::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL && running_) {
    app.SendNow(0xf8);
    Tick();
  }
}

/* static */
void Sequencer::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  
  if (!note_track_) {
    app.Send3(0x90 | channel, note, velocity);
  }

  // Step recording.
  if (ui.editing() && ui.page() >= 13) {
    if (!running_) {
      app.Send3(0x90 | channel, note, velocity);
    }
    uint8_t offset = U8U8Mul(ui.page_index(), kNumBytesPerStep);
    sequence_data_[offset] = note;
    if (velocity_track_) {
      sequence_data_[offset + 2] = velocity >> 3;
    }
    uint8_t next_page = ui.page() + kNumBytesPerStep;
    if (CheckPageStatus(next_page) == PAGE_GOOD) {
      ui.set_page(next_page);
    }
    return;
  }
  if (running_ &&
      clk_mode_ == CLOCK_MODE_INTERNAL &&
      note == last_note_ &&
      note_track_) {
    Stop();
  } else if (!running_ && clk_mode_ == CLOCK_MODE_INTERNAL) {
    Start();
    root_note_ = note;
  }
  last_note_ = note;
}

/* static */
void Sequencer::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  
  if (!note_track_ || !running_) {
    app.Send3(0x80 | channel, note, velocity);
  }
}

/* static */
void Sequencer::Stop() {
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
  root_note_ = 0;
  last_note_ = 0;
}

/* static */
void Sequencer::Start() {
  if (running_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    clock.Start();
    app.SendNow(0xfa);
  }
  if (root_note_ == 0 || last_note_ == 0) {
    root_note_ = 60;
    last_note_ = 60;
  } 
  tick_ = midi_clock_prescaler_ - 1;
  running_ = 1;
  step_ = 0;
}

/* static */
void Sequencer::Tick() {
  ++tick_;
  
  app.SendScheduledNotes(channel_);
  
  if (tick_ >= midi_clock_prescaler_) {
    tick_ = 0;
    uint8_t offset = U8U8Mul(step_, 4);
    uint8_t note = sequence_data_[offset];
    uint8_t duration = ResourcesManager::Lookup<uint8_t, uint8_t>(
        midi_clock_tick_per_step, sequence_data_[offset + 1]);
    uint8_t velocity = U8U8Mul(sequence_data_[offset + 2], 8);
    uint8_t cc = sequence_data_[offset + 3];

    // If a CC sequence is programmed, send a CC.
    if (cc_track_) {
      app.Send3(0xb0 | channel_, cc_number_ & 0x7f, cc & 0x7f);
    }
    // If no velocity track is programmed, use the default velocity.
    if (!velocity_track_) {
      velocity = 0x64;
    }
    if (!duration_track_) {
      duration = midi_clock_prescaler_;
    }
    // If a note is programmed, send it.
    if (note_track_ && velocity) {
      note = Clip(static_cast<int16_t>(note) + last_note_ - root_note_, 0, 127);
      app.Send3(0x90 | channel_, note, velocity);
      app.SendLater(note, 0, duration - 1);
    }
    ++step_;
    if (step_ >= num_steps_) {
      step_ = 0;
    }
  }
}

/* static */
uint8_t Sequencer::CheckPageStatus(uint8_t index) {
  if (index < 13) {
    return 1;
  }
  index -= 13;
  
  uint8_t step_index;
  while (index >= kNumBytesPerStep) {
    ++step_index;
    index -= kNumBytesPerStep;
  }
  
  // We cannot go beyond the number of steps defined.
  if (step_index >= num_steps_) {
    return PAGE_LAST;
  }
  
  if (index == 0 && !note_track_) {
    return PAGE_BAD;
  }
  
  if (index == 1 && !duration_track_) {
    return PAGE_BAD;
  }
  
  if (index == 2 && !velocity_track_) {
    return PAGE_BAD;
  }
  
  if (index == 3 && !cc_track_) {
    return PAGE_BAD;
  }
  
  return PAGE_GOOD;
}

} }  // namespace midipal::apps
