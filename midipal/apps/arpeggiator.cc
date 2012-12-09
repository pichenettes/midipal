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
// Arpeggiator app.

#include "midipal/apps/arpeggiator.h"

#include "avrlib/random.h"
#include "midi/midi.h"

#include "midipal/display.h"

#include "midipal/clock.h"
#include "midipal/event_scheduler.h"
#include "midipal/note_stack.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;
using namespace midi;

enum ArpeggiatorDirection {
  ARPEGGIO_DIRECTION_UP = 0,
  ARPEGGIO_DIRECTION_DOWN,
  ARPEGGIO_DIRECTION_UP_DOWN,
  ARPEGGIO_DIRECTION_RANDOM,
};

const prog_uint8_t arpeggiator_factory_data[11] PROGMEM = {
  0, 120, 0, 0, 0, 0, 1, 0, 12, 14, 0
};

/* <static> */
uint8_t Arpeggiator::running_;
 
uint8_t Arpeggiator::clk_mode_;
uint8_t Arpeggiator::bpm_;
uint8_t Arpeggiator::groove_template_;
uint8_t Arpeggiator::groove_amount_;
uint8_t Arpeggiator::channel_;
uint8_t Arpeggiator::direction_;
uint8_t Arpeggiator::num_octaves_;
uint8_t Arpeggiator::pattern_;
uint8_t Arpeggiator::clock_division_;
uint8_t Arpeggiator::duration_;
uint8_t Arpeggiator::latch_;

uint8_t Arpeggiator::midi_clock_prescaler_;

uint8_t Arpeggiator::tick_;
uint8_t Arpeggiator::idle_ticks_;
uint16_t Arpeggiator::bitmask_;
int8_t Arpeggiator::current_direction_;
int8_t Arpeggiator::current_octave_;
int8_t Arpeggiator::current_step_;
uint8_t Arpeggiator::ignore_note_off_messages_;
uint8_t Arpeggiator::recording_;
/* </static> */

/* static */
const prog_AppInfo Arpeggiator::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  &OnNoteOn, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  &OnNoteOff, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnAftertouch)(uint8_t, uint8_t);
  &OnControlChange, // void (*OnControlChange)(uint8_t, uint8_t, uint8_t);
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
  11, // settings_size
  SETTINGS_ARPEGGIATOR, // settings_offset
  &clk_mode_, // settings_data
  arpeggiator_factory_data, // factory_data
  STR_RES_ARPEGGIO, // app_name
  false
};

/* static */
void Arpeggiator::OnInit() {
  ui.AddClockPages();
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_DIR, STR_RES_UP, 0, 3);
  ui.AddPage(STR_RES_OCT, UNIT_INTEGER, 1, 4);
  ui.AddPage(STR_RES_PTN, UNIT_INDEX, 0, 21);
  ui.AddPage(STR_RES_DIV, STR_RES_2_1, 0, 16);
  ui.AddPage(STR_RES_DUR, STR_RES_2_1, 0, 16);
  ui.AddPage(STR_RES_LAT, STR_RES_OFF, 0, 1);
  
  clock.Update(bpm_, groove_template_, groove_amount_);
  SetParameter(8, clock_division_);  // Force an update of the prescaler.
  clock.Start();
  idle_ticks_ = 96;
  running_ = 0;
  ignore_note_off_messages_ = 0;
  recording_ = 0;
}

/* static */
void Arpeggiator::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  // Forward everything except note on for the selected channel.
  if (status != (0x80 | channel_) && 
      status != (0x90 | channel_) &&
      (status != (0xb0 | channel_) || data[0] != kHoldPedal)) {
    app.Send(status, data, data_size);
  }
}

/* static */
void Arpeggiator::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

/* static */
void Arpeggiator::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Start();
  }
}

/* static */
void Arpeggiator::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 0;
    app.FlushQueue(channel_);
  }
}

/* static */
void Arpeggiator::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    Tick();
  }
}

/* static */
void Arpeggiator::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL && running_) {
    app.SendNow(0xf8);
    Tick();
  }
}

/* static */
void Arpeggiator::OnNoteOn(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    if (idle_ticks_ >= 96) {
      clock.Start();
      Start();
      app.SendNow(0xfa);
    }
    idle_ticks_ = 0;
  }
  if (latch_ && !recording_) {
    note_stack.Clear();
    recording_ = 1;
  }
  note_stack.NoteOn(note, velocity);
}

/* static */
void Arpeggiator::OnNoteOff(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_ || ignore_note_off_messages_) {
    return;
  }
  if (!latch_) {
    note_stack.NoteOff(note);
  } else {
    if (note == note_stack.most_recent_note().note) {
      recording_ = 0;
    }
  }
}

/* static */
void Arpeggiator::Tick() {
  ++tick_;
  
  if (note_stack.size()) {
    idle_ticks_ = 0;
  }
  ++idle_ticks_;
  if (idle_ticks_ >= 96) {
    idle_ticks_ = 96;
    if (clk_mode_ == CLOCK_MODE_INTERNAL) {
      running_ = 0;
      app.SendNow(0xfc);
      app.FlushQueue(channel_);
    }
  }
  
  app.SendScheduledNotes(channel_);
  
  if (tick_ >= midi_clock_prescaler_) {
    tick_ = 0;
    uint16_t pattern = ResourcesManager::Lookup<uint16_t, uint8_t>(
        lut_res_arpeggiator_patterns,
        pattern_);
    uint8_t has_arpeggiator_note = (bitmask_ & pattern) ? 255 : 0;
    if (note_stack.size() && has_arpeggiator_note) {
      uint8_t note = note_stack.sorted_note(current_step_).note;
      uint8_t velocity = note_stack.sorted_note(current_step_).velocity;
      note += 12 * current_octave_;
      while (note > 127) {
        note -= 12;
      }
      // If there are some Note Off messages for the note about to be triggeered
      // remove them from the queue and process them now.
      if (event_scheduler.Remove(note, 0)) {
        app.Send3(0x80 | channel_, note, 0);
      }
      // Send a note on and schedule a note off later.
      app.Send3(0x90 | channel_, note, velocity);
      app.SendLater(note, 0, ResourcesManager::Lookup<uint8_t, uint8_t>(
          midi_clock_tick_per_step, duration_) - 1);
      StepArpeggio();
    }
    bitmask_ <<= 1;
    if (!bitmask_) {
      bitmask_ = 1;
    }
  }
}

/* static */
void Arpeggiator::Start() {
  running_ = 1;
  bitmask_ = 1;
  tick_ = midi_clock_prescaler_ - 1;
  current_direction_ = (direction_ == ARPEGGIO_DIRECTION_DOWN ? -1 : 1);
  recording_ = 0;
  StartArpeggio();
}

/* static */
void Arpeggiator::StartArpeggio() {
  if (current_direction_ == 1) {
    current_octave_ = 0;
    current_step_ = 0;
  } else {
    current_step_ = note_stack.size() - 1;
    current_octave_ = num_octaves_ - 1;
  }
}

/* static */
void Arpeggiator::OnControlChange(uint8_t channel, uint8_t cc, uint8_t value) {
  if (channel != channel_ || cc != kHoldPedal) {
    return;
  }
  if (ignore_note_off_messages_ && !value) {
    // Pedal was released, kill all pending arpeggios.
    note_stack.Clear();
  }
  ignore_note_off_messages_ = value;
}

/* static */
void Arpeggiator::StepArpeggio() {
  uint8_t num_notes = note_stack.size();
  if (direction_ == ARPEGGIO_DIRECTION_RANDOM) {
    uint8_t random_byte = Random::GetByte();
    current_octave_ = random_byte & 0xf;
    current_step_ = (random_byte & 0xf0) >> 4;
    while (current_octave_ >= num_octaves_) {
      current_octave_ -= num_octaves_;
    }
    while (current_step_ >= num_notes) {
      current_step_ -= num_notes;
    }
  } else {
    current_step_ += current_direction_;
    uint8_t change_octave = 0;
    if (current_step_ >= num_notes) {
      current_step_ = 0;
      change_octave = 1;
    } else if (current_step_ < 0) {
      current_step_ = num_notes - 1;
      change_octave = 1;
    }
    if (change_octave) {
      current_octave_ += current_direction_;
      if (current_octave_ >= num_octaves_ || current_octave_ < 0) {
        if (direction_ == ARPEGGIO_DIRECTION_UP_DOWN) {
          current_direction_ = -current_direction_;
          StartArpeggio();
          if (num_notes > 1 || num_octaves_ > 1) {
            StepArpeggio();
          }
        } else {
          StartArpeggio();
        }
      }
    }
  }
}

/* static */
void Arpeggiator::SetParameter(uint8_t key, uint8_t value) {
  static_cast<uint8_t*>(&clk_mode_)[key] = value;
  if (key < 4) {
    clock.Update(bpm_, groove_template_, groove_amount_);
  }
  midi_clock_prescaler_ = ResourcesManager::Lookup<uint8_t, uint8_t>(
      midi_clock_tick_per_step, clock_division_);
  if (key == 5) {
    // When changing the arpeggio direction, reset the pattern.
    current_direction_ = (direction_ == ARPEGGIO_DIRECTION_DOWN ? -1 : 1);
    StartArpeggio();
  }
  if (key == 10) {
    // When disabling latch mode, clear the note stack.
    if (value == 0) {
      note_stack.Clear();
      recording_ = 0;
    }
  }
}

} }  // namespace midipal::apps
