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

#include "midipal/plugins/euclidian_pattern_generator.h"
#include "midipal/note_stack.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/resources.h"
#include "midipal/ui.h"

namespace midipal { namespace plugins {

using namespace avrlib;

static const prog_uint8_t sizes[12] PROGMEM = {
  0, 1, 2, 3, 4, 5, 6, 8, 10, 12, 14, 16  
};

void EuclidianPatternGenerator::OnInitImpl() {
  for (uint8_t i = 0; i < kNumDrumParts; ++i) {
    num_notes_[i] = 0;
    num_steps_[i] = 11; // 16 steps
  }
}

void EuclidianPatternGenerator::OnNoteOnImpl() {
  // Select pattern depending on played notes.
  uint8_t previous_octave = 0xff;
  for (uint8_t i = 0; i < note_stack.size(); ++i) {
    Note n = FactorizeMidiNote(note_stack.sorted_note(i).note);
    uint8_t part = (n.octave >= 7) ? 3 : (n.octave <= 3 ? 0 : n.octave - 3);
    if (n.octave == previous_octave) {
      num_steps_[part] = n.note;
    } else {
      num_notes_[part] = n.note;
      step_count_[part] = 0;
      bitmask_[part] = 1;
    }
    previous_octave = n.octave;
  }
}

void EuclidianPatternGenerator::TickImpl() {
  if (tick_ == 6) {
    tick_ = 0;
    for (uint8_t part = 0; part < kNumDrumParts; ++part) {
      // Skip the muted parts.
      if (num_notes_[part]) {
        // Continue running the sequencer as long as something is playing.
        idle_ticks_ = 0;
        uint16_t pattern = ResourcesManager::Lookup<uint16_t, uint8_t>(
            lut_res_euclidian_patterns,
            num_notes_[part] + num_steps_[part] * 12);
        uint16_t mask = bitmask_[part];
        if (pattern & mask) {
          TriggerNote(part);
        }
      }
      ++step_count_[part];
      bitmask_[part] <<= 1;
      if (step_count_[part] == ResourcesManager::Lookup<uint16_t, uint8_t>(
                sizes, num_steps_[part])) {
        step_count_[part] = 0;
        bitmask_[part] = 1;
      }
    }
  } else if (tick_ == 3) {
    AllNotesOff();
  }
}

} }  // namespace midipal::plugins
