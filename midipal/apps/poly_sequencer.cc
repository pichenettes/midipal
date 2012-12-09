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

const prog_uint8_t sequencer_factory_data[12] PROGMEM = {
  0, 0,
  0, 
  0,
  120,
  0,
  0,
  12,
  0,
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
uint8_t PolySequencer::num_steps_;
uint8_t PolySequencer::sequence_data_[kPSNumTracks * kPSNumSteps];

uint8_t PolySequencer::midi_clock_prescaler_;
uint8_t PolySequencer::tick_;
uint8_t PolySequencer::step_;
uint8_t PolySequencer::edit_step_;
uint8_t PolySequencer::root_note_;
uint8_t PolySequencer::last_note_;
uint8_t PolySequencer::previous_rec_note_;
uint8_t PolySequencer::rec_mode_menu_option_;
uint8_t PolySequencer::pending_notes_[kPSNumTracks];
uint8_t PolySequencer::pending_notes_transposed_[kPSNumTracks];
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
  &OnIncrement, // uint8_t (*OnIncrement)(int8_t);
  &OnClick, // uint8_t (*OnClick)();
#ifdef MIDIBUD_FIRMWARE
  NULL, // uint8_t (*OnSwitch)(uint8_t);
#else
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  &OnRedraw, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  &SetParameter, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  10 + kPSNumTracks * kPSNumSteps, // settings_size
  SETTINGS_POLY_SEQUENCER, // settings_offset
  &running_, // settings_data
  sequencer_factory_data, // factory_data
  STR_RES_POLYSEQ, // app_name
  false
};

/* static */
void PolySequencer::OnInit() {
  ui.AddPage(STR_RES_RUN, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_REC, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_DUB, STR_RES_OFF, 0, 1);
  ui.AddClockPages();
  ui.AddPage(STR_RES_DIV, STR_RES_2_1, 0, 16);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  clock.Update(bpm_, groove_template_, groove_amount_);
  SetParameter(4, bpm_);
  clock.Start();
  running_ = 0;
  recording_ = 0;
  overdubbing_ = 0;
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
  else if (key == 1) {
    edit_step_ = 0;
    recording_ = 1;
    rec_mode_menu_option_ = 0;
    overdubbing_ = 0;
    num_steps_ = 0;
    previous_rec_note_ = 0xff;
  } else if (key == 2) {
    edit_step_ = 0;
    recording_ = 0;
    overdubbing_ = 1;
    rec_mode_menu_option_ = 0;
    previous_rec_note_ = 0xff;
  }
  static_cast<uint8_t*>(&running_)[key] = value;
  if (key < 7) {
    clock.Update(bpm_, groove_template_, groove_amount_);
  }
  midi_clock_prescaler_ = ResourcesManager::Lookup<uint8_t, uint8_t>(
      midi_clock_tick_per_step, clock_division_);
}

/* static */
uint8_t PolySequencer::OnRedraw() {
  if (recording_ || overdubbing_) {
    memset(line_buffer, 0, kLcdWidth);
    UnsafeItoa(edit_step_, 3, &line_buffer[0]);
    PadRight(&line_buffer[0], 3, ' ');
    line_buffer[3] = 0xa5;
    ResourcesManager::LoadStringResource(
        STR_RES_REST + rec_mode_menu_option_,
        &line_buffer[4], 4);
    AlignRight(&line_buffer[4], 4);
    display.Print(0, line_buffer);
  } else {
    return 0;
  }
  return 1;
}

/* static */
uint8_t PolySequencer::OnIncrement(int8_t increment) {
  if (recording_ || overdubbing_) {
    rec_mode_menu_option_ += increment;
    if (rec_mode_menu_option_ == 0xff) {
      rec_mode_menu_option_ = 0;
    }
    if (rec_mode_menu_option_ >= 2) {
      rec_mode_menu_option_ = 2;
    }
  } else {
    return 0;
  }
  ui.RefreshScreen();
  return 1;
}

/* static */
uint8_t PolySequencer::OnClick() {
  if (recording_ || overdubbing_) {
    switch (rec_mode_menu_option_) {
      case 0:
      case 1:
        Record(0xff - rec_mode_menu_option_);
        break;
      case 2:
        recording_ = 0;
        overdubbing_ = 0;
        break;
    }
  } else {
    return 0;
  }
  ui.RefreshScreen();
  return 1;
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
  if (!running_) {
    Start();
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
void PolySequencer::Record(uint8_t note) {
  uint8_t step_data = note;
  if (note == 0xfe && previous_rec_note_ != 0xff) {
    step_data = 0x80 | previous_rec_note_;
  } else if (note == 0xff) {
    step_data = 0xff;
  } else {
    previous_rec_note_ = note;
  }
  if (recording_) {
    for (uint8_t i = 0; i < kPSNumTracks; ++i) {
      sequence_data_[i * kPSNumSteps + edit_step_] = 0xff;
      app.SaveSetting(i * kPSNumSteps + edit_step_ + 10);
    }
  }
  if (step_data != 0xff) {
    // Find a free slot to record the note.
    uint8_t slot_found = 0;
    for (uint8_t i = 0; i < kPSNumTracks; ++i) {
      if (sequence_data_[i * kPSNumSteps + edit_step_] == 0xff) {
        sequence_data_[i * kPSNumSteps + edit_step_] = step_data;
        app.SaveSetting(i * kPSNumSteps + edit_step_ + 10);
        slot_found = 1;
        break;
      }
    }
    if (!slot_found) {
      sequence_data_[edit_step_] = step_data;
      app.SaveSetting(edit_step_ + 10);
    }
  }
  
  edit_step_ = edit_step_ + 1;
  if (edit_step_ >= kPSNumSteps) {
    // Auto-overdub if max number of steps is reached.
    edit_step_ = 0;
  }
  if (overdubbing_ && edit_step_ >= num_steps_) {
    edit_step_ = 0;
  }
  if (recording_) {
    num_steps_ = edit_step_;
    app.SaveSetting(9);
  }
}

/* static */
void PolySequencer::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  uint8_t was_running = running_;
  uint8_t just_started = 0;
  if (recording_ || overdubbing_) {
    Record(note);
  } else if (running_) {
    if (clk_mode_ == CLOCK_MODE_INTERNAL && note == last_note_) {
      Stop();
    }
  } else {
    if (clk_mode_ == CLOCK_MODE_INTERNAL) {
      Start();
      root_note_ = note;
      just_started = 1;
    }
  }
  
  if (!was_running && !just_started) {
    app.Send3(0x90 | channel, note, velocity);
  }
  if (running_ && !recording_ && !overdubbing_) {
    last_note_ = note;
  }
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
  // Stop pending notes.
  for (uint8_t i = 0; i < kPSNumTracks; ++i) {
    if (pending_notes_[i] != 0xff) {
      app.Send3(0x80 | channel_, pending_notes_transposed_[i], 0);
    }
  }
}

/* static */
void PolySequencer::Start() {
  if (running_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    clock.Start();
    app.SendNow(0xfa);
  }
  tick_ = midi_clock_prescaler_ - 1;
  root_note_ = 60;
  last_note_ = 60;
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
      if (pending_notes_[i] != 0xff) {
        uint8_t is_tied = 0;
        for (uint8_t j = 0; j < kPSNumTracks; ++j) {
          if (sequence_data_[j * kPSNumSteps + step_] == \
              (pending_notes_[i] | 0x80)) {
            is_tied = 1;
            break;
          }
        }
        if (!is_tied) {
          app.Send3(0x80 | channel_, pending_notes_transposed_[i], 0);
          pending_notes_[i] = 0xff;
        }
      }
    }
    
    // Send note on.
    for (uint8_t i = 0; i < kPSNumTracks; ++i) {
      uint8_t note = sequence_data_[i * kPSNumSteps + step_];
      if (note < 0x80) {
        pending_notes_[i] = note;
        note += last_note_ - root_note_;
        pending_notes_transposed_[i] = note;
        app.Send3(0x90 | channel_, note, 100);
      }
    }
    ++step_;
    if (step_ >= num_steps_) {
      step_ = 0;
    }
  }
}

} }  // namespace midipal::apps
