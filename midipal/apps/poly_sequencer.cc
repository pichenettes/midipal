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

#include "midipal/apps/poly_sequencer.h"

#include "avrlib/op.h"
#include "avrlib/string.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t sequencer_factory_data[1] PROGMEM = {
  1
};

/* <static> */
uint8_t PolySequencer::running_;
uint8_t PolySequencer::recording_;
uint8_t PolySequencer::overdubbing_;
uint8_t PolySequencer::clk_mode_;
uint8_t PolySequencer::bpm_;
uint8_t PolySequencer::groove_template_;
uint8_t PolySequencer::groove_amount_;
uint8_t PolySequencer::clock_division_;  
uint8_t PolySequencer::channel_;
uint8_t PolySequencer::tie_note_;
uint8_t PolySequencer::rest_note_;
uint8_t PolySequencer::sequence_data_[kPSNumTracks * kPSNumSteps];
uint8_t PolySequencer::num_steps_;

uint8_t PolySequencer::midi_clock_prescaler_;
uint8_t PolySequencer::tick_;
uint8_t PolySequencer::step_;
uint8_t PolySequencer::edit_step_;
uint8_t PolySequencer::current_track_;
uint8_t PolySequencer::root_note_;
uint8_t PolySequencer::last_note_;
uint8_t PolySequencer::pending_notes_[kPSNumTracks];
/* </static> */

/* static */
const prog_AppInfo PolySequencer::app_info_ PROGMEM = {
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
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  &SetParameter, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  1, // settings_size
  SETTINGS_POLY_SEQUENCER, // settings_offset
  &running_, // settings_data
  sequencer_factory_data, // factory_data
  STR_RES_POLYSEQ, // app_name
};

/* static */
void PolySequencer::OnInit() {
  ui.AddPage(STR_RES_RUN, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_REC, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_DUB, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_CLK, STR_RES_INT, 0, 1);
  ui.AddPage(STR_RES_BPM, UNIT_INTEGER, 40, 240);
  ui.AddPage(STR_RES_GRV, STR_RES_SWG, 0, 5);
  ui.AddPage(STR_RES_AMT, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_DIV, STR_RES_2_1, 0, 16);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_TIE, UNIT_NOTE, 0, 127);
  ui.AddPage(STR_RES_RST, UNIT_NOTE, 0, 1);
  clock.Update(bpm_, groove_template_, groove_amount_);
  SetParameter(4, bpm_);
  clock.Start();
  running_ = 0;
}

/* static */
void PolySequencer::OnRawMidiData(
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
void PolySequencer::SetParameter(uint8_t key, uint8_t value) {
  if (key == 0) {
    if (value == 1) {
      Start();
    } else {
      Stop();
    }
  }
  if (key == 1) {
    if (value == 1) {
      overdubbing_ = 0;
      recording_ = 1;
      edit_step_ = 0;
      num_steps_ = 0;
      memset(sequence_data_, 0x00, sizeof(sequence_data_));
      current_track_ = 0;
    } else {
      recording_ = 0;
    }
  }
  if (key == 2) {
    if (value == 1) {
      edit_step_ = 0;
      recording_ = 0;
      overdubbing_ = 1;
      ++current_track_;
      if (current_track_ >= kPSNumTracks) {
        current_track_ = 0;
      }
    } else {
      overdubbing_ = 0;
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
void PolySequencer::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Start();
  }
}

/* static */
void PolySequencer::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Stop();
  }
}

/* static */
void PolySequencer::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    recording_ = 0;
    overdubbing_ = 0;
    running_ = 1;
  }
}

/* static */
void PolySequencer::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    Tick();
  }
}

/* static */
void PolySequencer::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL && running_) {
    app.SendNow(0xf8);
    Tick();
  }
}

/* static */
void PolySequencer::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  
  if (recording_ || overdubbing_) {
    if (note == tie_note_) {
      note = 0xfe;
    } else if (note == rest_note_) {
      note = 0xff;
    }
    sequence_data_[current_track_ * kPSNumSteps + edit_step_] = note;

    // Auto-overdub if max number of steps is reached.
    edit_step_ = edit_step_ + 1;
    if (edit_step_ >= kPSNumSteps) {
      edit_step_ = 0;
    }
    if (recording_) {
      num_steps_ = edit_step_;
    }
  } else if (running_) {
    if (clk_mode_ == CLOCK_MODE_INTERNAL && note == last_note_) {
      Stop();
    }
  } else {
    if (clk_mode_ == CLOCK_MODE_INTERNAL) {
      Start();
      root_note_ = note;
    }
  }
  
  if (!running_) {
    app.Send3(0x90 | channel, note, velocity);
  }
  last_note_ = note;
}

/* static */
void PolySequencer::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  
  if (!running_) {
    app.Send3(0x80 | channel, note, velocity);
  }
}

/* static */
void PolySequencer::Stop() {
  if (!running_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    app.SendNow(0xfc);
  }
  running_ = 0;
  root_note_ = 0;
  last_note_ = 0;
  // Stop pending notes.
  for (uint8_t i = 0; i < kPSNumTracks; ++i) {
    if (pending_notes_[i] != 0xff) {
      app.Send3(0x80 | channel_, pending_notes_[i], 0);
    }
  }
}

/* static */
void PolySequencer::Start() {
  if (running_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    app.SendNow(0xfa);
  }
  if (root_note_ == 0 || last_note_ == 0) {
    root_note_ = 60;
    last_note_ = 60;
  } 
  tick_ = midi_clock_prescaler_ - 1;
  running_ = 1;
  step_ = 0;
  memset(pending_notes_, 0xff, kPSNumTracks);
}

/* static */
void PolySequencer::Tick() {
  ++tick_;
  if (tick_ >= midi_clock_prescaler_) {
    tick_ = 0;
    
    // Send note off.
    for (uint8_t i = 0; i < kPSNumTracks; ++i) {
      if (pending_notes_[i] != 0xff &&
          sequence_data_[i * kPSNumSteps + step_] != 0xfe) {
        app.Send3(0x80 | channel_, pending_notes_[i], 0);
        pending_notes_[i] = 0xff;
      }
    }
    
    // Send note on.
    for (uint8_t i = 0; i < kPSNumTracks; ++i) {
      uint8_t note = sequence_data_[i * kPSNumSteps + step_];
      if (note < 0x80) {
        note = note + last_note_ - root_note_;
        app.Send3(0x90 | channel_, note, 100);
      }
      pending_notes_[i] = note;
    }
    ++step_;
    if (step_ >= num_steps_) {
      step_ = 0;
    }
  }
}

} }  // namespace midipal::apps
