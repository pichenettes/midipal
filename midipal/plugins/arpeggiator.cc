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
// Arpeggiator plug-in.

#include "midipal/plugins/arpeggiator.h"

#include "avrlib/random.h"

#include "midipal/display.h"

#include "midipal/clock.h"
#include "midipal/note_stack.h"
#include "midipal/resources.h"
#include "midipal/ui.h"

namespace midipal { namespace plugins {

using namespace avrlib;

enum ArpeggiatorDirection {
  ARPEGGIO_DIRECTION_UP = 0,
  ARPEGGIO_DIRECTION_DOWN,
  ARPEGGIO_DIRECTION_UP_DOWN,
  ARPEGGIO_DIRECTION_RANDOM,
};

static const prog_uint8_t midi_clock_tick_per_step[15] PROGMEM = {
  96, 72, 64, 48, 36, 32, 24, 16, 12, 8, 6, 4, 3, 2, 1
};

void Arpeggiator::OnInit() {
  ui.AddPage(STR_RES_CLK, STR_RES_INT, 0, 1);
  ui.AddPage(STR_RES_BPM, UNIT_INTEGER, 40, 240);
  ui.AddPage(STR_RES_GRV, STR_RES_SWG, 0, 5);
  ui.AddPage(STR_RES_AMT, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_DIR, STR_RES_UP, 0, 3);
  ui.AddPage(STR_RES_OCT, UNIT_INTEGER, 1, 4);
  ui.AddPage(STR_RES_PTN, UNIT_INDEX, 0, 14);
  ui.AddPage(STR_RES_DIV, STR_RES_1_1, 0, 14);
  ui.AddPage(STR_RES_DUR, UNIT_INTEGER, 1, 24);
  
  clock.Update(bpm_, groove_template_, groove_amount_);
  SetParameter(8, clock_division_);  // Force an update of the prescaler.
  clock.Start();
  idle_ticks_ = 96;
  running_ = 0;
}

void Arpeggiator::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  // Forward everything except note on for the selected channel.
  if (status != (0x80 | channel_) && 
      status != (0x90 | channel_)) {
    Send(status, data, data_size);
  }
}

void Arpeggiator::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

void Arpeggiator::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Start();
  }
}

void Arpeggiator::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 0;
  }
  // AllNotesOff();
}

void Arpeggiator::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    Tick();
  }
}

void Arpeggiator::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL && running_) {
    SendNow(0xf8);
    Tick();
  }
}

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
      SendNow(0xfa);
    }
    idle_ticks_ = 0;
  }
  note_stack.NoteOn(note, velocity);
}

void Arpeggiator::OnNoteOff(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  note_stack.NoteOff(note);
}

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
      SendNow(0xfc);
    }
  }
  
  if (tick_ >= midi_clock_prescaler_) {
    tick_ = 0;
    bitmask_ <<= 1;
    if (!bitmask_) {
      bitmask_ = 1;
    }
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
      Send3(0x90 | channel_, note, velocity);
      StepArpeggio();
      // TODO: schedule note off.
    }
  }
}

void Arpeggiator::Start() {
  running_ = 1;
  bitmask_ = 0x8000;
  tick_ = midi_clock_prescaler_ - 1;
  current_direction_ = (direction_ == ARPEGGIO_DIRECTION_DOWN ? -1 : 1);
  StartArpeggio();
}

void Arpeggiator::StartArpeggio() {
  if (current_direction_ == 1) {
    current_octave_ = 0;
    current_step_ = 0;
  } else {
    current_step_ = note_stack.size() - 1;
    current_octave_ = num_octaves_ - 1;
  }
}

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
          if (num_notes > 1 || direction_ > 1) {
            StepArpeggio();
          }
        } else {
          StartArpeggio();
        }
      }
    }
  }
}

void Arpeggiator::SetParameter(uint8_t key, uint8_t value) {
  static_cast<uint8_t*>(&clk_mode_)[key] = value;
  if (key < 4) {
    clock.Update(bpm_, groove_template_, groove_amount_);
  }
  if (key == 8) {
    midi_clock_prescaler_ = ResourcesManager::Lookup<uint8_t, uint8_t>(
        midi_clock_tick_per_step, clock_division_);
  }
}

} }  // namespace midipal::plugins
