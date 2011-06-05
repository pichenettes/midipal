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
// Euclidian pattern generator plug-in.

#include "midipal/plugins/drum_pattern_generator.h"
#include "midipal/note_stack.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/resources.h"
#include "midipal/ui.h"

namespace midipal { namespace plugins {

using namespace avrlib;

void DrumPatternGenerator::OnInitImpl() {
  memset(&active_pattern_[0], 0, kNumDrumParts);
}

void DrumPatternGenerator::ResetImpl() {
  step_count_ = 0;
  bitmask_ = 1;
}

void DrumPatternGenerator::OnNoteOnImpl() {
  // Select pattern depending on played notes.
  for (uint8_t i = 0; i < note_stack.size(); ++i) {
    uint8_t n = FactorizeMidiNote(note_stack.sorted_note(i).note);
    uint8_t octave = U8ShiftRight4(n);
    n &= 0x0f;
    uint8_t part = (octave >= 7) ? 3 : (octave <= 3 ? 0 : octave - 3);
    active_pattern_[part] = n;
  }
}

void DrumPatternGenerator::TickImpl() {
  if (tick_ == 6) {
    tick_ = 0;
    uint8_t offset = 0;
    for (uint8_t part = 0; part < 4; ++part) {
      if (active_pattern_[part]) {
        idle_ticks_ = 0;
      }
      uint16_t pattern = ResourcesManager::Lookup<uint16_t, uint8_t>(
            lut_res_drum_patterns, active_pattern_[part] + offset);
      offset += 12;
      if (pattern & bitmask_) {
        TriggerNote(part);
      }
    }
    ++step_count_;
    bitmask_ <<= 1;
    if (step_count_ == 16) {
      step_count_ = 0;
      bitmask_ = 1;
    }
  } else if (tick_ == 3) {
    AllNotesOff();
  }
}

} }  // namespace midipal::plugins
