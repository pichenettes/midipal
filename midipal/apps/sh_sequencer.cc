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
// A sequencer app inspired by the SH-101 sequencer.

#include "midipal/apps/sh_sequencer.h"

#include "avrlib/op.h"
#include "avrlib/string.h"

#include "midi/midi.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t sequencer_factory_data[18] PROGMEM = {
  0, 0,
  0, 120, 0, 0, 12, 0, 8,
  48, 0xff, 48, 0xff, 60, 0xff, 60, 0xff,
};

/* <static> */
uint8_t ShSequencer::running_;
uint8_t ShSequencer::recording_;
uint8_t ShSequencer::clk_mode_;
uint8_t ShSequencer::bpm_;
uint8_t ShSequencer::groove_template_;
uint8_t ShSequencer::groove_amount_;
uint8_t ShSequencer::clock_division_;  
uint8_t ShSequencer::channel_;
uint8_t ShSequencer::num_steps_;
uint8_t ShSequencer::sequence_data_[kShSequencerNumSteps];
uint8_t ShSequencer::slide_data_[kShSequencerNumSteps / 8 + 1];
uint8_t ShSequencer::accent_data_[kShSequencerNumSteps / 8 + 1];

uint8_t ShSequencer::midi_clock_prescaler_;
uint8_t ShSequencer::tick_;
uint8_t ShSequencer::step_;
uint8_t ShSequencer::root_note_;
uint8_t ShSequencer::last_note_;
uint8_t ShSequencer::rec_mode_menu_option_;
uint8_t ShSequencer::pending_note_;
/* </static> */

/* static */
const prog_AppInfo ShSequencer::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  &OnNoteOn, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  &OnNoteOff, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnAftertouch)(uint8_t, uint8_t);
  OnControlChange, // void (*OnControlChange)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnProgramChange)(uint8_t, uint8_t);
  OnPitchBend, // void (*OnPitchBend)(uint8_t, uint16_t);
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
  &OnSwitch, // uint8_t (*OnSwitch)(uint8_t);
#else
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  &OnRedraw, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  &SetParameter, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  9 + kShSequencerNumSteps + 2 * (kShSequencerNumSteps / 8 + 1), // settings_size
  SETTINGS_SEQUENCER, // settings_offset
  &running_, // settings_data
  sequencer_factory_data, // factory_data
  STR_RES_SEQUENCR, // app_name
  true
};

/* static */
void ShSequencer::OnInit() {
  ui.AddPage(STR_RES_RUN, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_REC, STR_RES_OFF, 0, 1);
  ui.AddClockPages();
  ui.AddPage(STR_RES_DIV, STR_RES_2_1, 0, 16);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  clock.Update(bpm_, groove_template_, groove_amount_);
  SetParameter(3, bpm_);
  clock.Start();
  running_ = 0;
  recording_ = 0;
}

/* static */
void ShSequencer::OnRawMidiData(
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
void ShSequencer::SetParameter(uint8_t key, uint8_t value) {
  if (key == 0) {
    if (value == 1) {
      Start();
    } else {
      Stop();
    }
  }
  if (key == 1) {
    Stop();
    memset(sequence_data_, 60, sizeof(sequence_data_));
    memset(slide_data_, 0, sizeof(slide_data_));
    memset(accent_data_, 0, sizeof(accent_data_));
    recording_ = 1;
    rec_mode_menu_option_ = 0;
    num_steps_ = 0;
  }
  static_cast<uint8_t*>(&running_)[key] = value;
  if (key < 6) {
    clock.Update(bpm_, groove_template_, groove_amount_);
  }
  midi_clock_prescaler_ = ResourcesManager::Lookup<uint8_t, uint8_t>(
      midi_clock_tick_per_step, clock_division_);
}

/* static */
uint8_t ShSequencer::OnRedraw() {
  if (recording_) {
    memset(line_buffer, 0, kLcdWidth);
    line_buffer[0] = 0xa5;
    UnsafeItoa(num_steps_, 2, &line_buffer[1]);
    PadRight(&line_buffer[1], 2, ' ');
    line_buffer[3] = '|';
    
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
uint8_t ShSequencer::OnIncrement(int8_t increment) {
  if (recording_) {
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
uint8_t ShSequencer::OnClick() {
  if (recording_) {
    switch (rec_mode_menu_option_) {
      case 0:
      case 1:
        sequence_data_[num_steps_] = 0xff - rec_mode_menu_option_;
        app.SaveSetting(num_steps_ + 9);
        ++num_steps_;
        if (num_steps_ == kShSequencerNumSteps) {
          recording_ = 0;
        }
        break;
      case 2:
        recording_ = 0;
        ui.set_page(0);  // Go back to "run" page.
        break;
    }
  } else {
    return 0;
  }
  ui.RefreshScreen();
  return 1;
}

/* static */
void ShSequencer::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Start();
  }
}

/* static */
void ShSequencer::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Stop();
  }
}

/* static */
void ShSequencer::OnContinue() {
  if (!running_) {
    Start();
  }
}

/* static */
void ShSequencer::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    Tick();
  }
}

/* static */
void ShSequencer::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL && running_) {
    app.SendNow(0xf8);
    Tick();
  }
}

/* static */
void ShSequencer::OnPitchBend(uint8_t channel, uint16_t value) {
  if (channel != channel_ || !recording_) {
    return;
  }
  if ((value > 8192 + 2048 || value < 8192 - 2048)) {
    uint8_t accent_slide_index = num_steps_ >> 3;
    uint8_t accent_slide_mask = 1 << (num_steps_ & 0x7);
    slide_data_[accent_slide_index] |= accent_slide_mask;
    app.SaveSetting(9 + kShSequencerNumSteps + accent_slide_index);
  }
}

/* static */
void ShSequencer::OnControlChange(
    uint8_t channel,
    uint8_t controller,
    uint8_t value) {
  if (channel != channel_ || !recording_) {
    return;
  }
  if (controller == midi::kModulationWheelMsb && value > 0x40)  {
    uint8_t accent_slide_index = num_steps_ >> 3;
    uint8_t accent_slide_mask = 1 << (num_steps_ & 0x7);
    accent_data_[accent_slide_index] |= accent_slide_mask;
    app.SaveSetting(
        9 + kShSequencerNumSteps + (kShSequencerNumSteps / 8 + 1) + \
        accent_slide_index);
  }
}

/* static */
void ShSequencer::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  uint8_t was_running = running_;
  uint8_t just_started = 0;
  if (recording_) {
    sequence_data_[num_steps_] = note;
    app.SaveSetting(num_steps_ + 9);
    ++num_steps_;
    if (num_steps_ == kShSequencerNumSteps) {
      recording_ = 0;
    }
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
  if (running_ && !recording_) {
    last_note_ = note;
  }
}

/* static */
void ShSequencer::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  
  if (!running_) {
    app.Send3(0x80 | channel, note, velocity);
  }
}

/* static */
void ShSequencer::Stop() {
  if (!running_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    app.SendNow(0xfc);
  }
  running_ = 0;
  if (pending_note_ != 0xff) {
    app.Send3(0x80 | channel_, pending_note_, 0);
  }
  pending_note_ = 0xff;
}

/* static */
void ShSequencer::Start() {
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
  pending_note_ = 0xff;
}

/* static */
void ShSequencer::Tick() {
  ++tick_;
  if (tick_ >= midi_clock_prescaler_) {
    tick_ = 0;
    uint8_t note = sequence_data_[step_];
    if (note == 0xff) {
      // It's a rest
      app.Send3(0x80 | channel_, pending_note_, 0);
      pending_note_ = 0xff;
    } else if (note == 0xfe) {
      // It's a tie, do nothing.
    } else {
      uint8_t accent_slide_index = step_ >> 3;
      uint8_t accent_slide_mask = 1 << (step_ & 0x7);
      bool accented = accent_data_[accent_slide_index] & accent_slide_mask;
      bool slid = slide_data_[accent_slide_index] & accent_slide_mask;
      note &= 0x7f;
      note = Clip(static_cast<int16_t>(note) + last_note_ - root_note_, 0, 127);
      
      if (pending_note_ != 0xff && !slid) {
        app.Send3(0x80 | channel_, pending_note_, 0);
      }
      app.Send3(0x90 | channel_, note, accented ? 127 : 64);
      if (pending_note_ != 0xff && slid) {
        app.Send3(0x80 | channel_, pending_note_, 0);
      }
      pending_note_ = note;
    }
    ++step_;
    if (step_ >= num_steps_) {
      step_ = 0;
    }
  }
}

#ifdef MIDIBUD_FIRMWARE
/* static */
uint8_t ShSequencer::OnSwitch(uint8_t sw) {
  
  if (!recording_)
    return 0;

  switch (sw) {
  case SWITCH_1: rec_mode_menu_option_ = 0; break;
  case SWITCH_2: rec_mode_menu_option_ = 1; break;
  case SWITCH_3: 
  case SWITCH_4: 
  case SWITCH_5: rec_mode_menu_option_ = 2; break;
  }

  OnClick();

  if (sw == SWITCH_4 || sw == SWITCH_5) {
    Start();
  }

  return 1;
}
#endif

} }  // namespace midipal::apps
