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

#ifndef MIDIPAL_PLUGINS_EUCLIDIAN_PATTERN_GENERATOR_H_
#define MIDIPAL_PLUGINS_EUCLIDIAN_PATTERN_GENERATOR_H_

#include "midipal/plugin.h"
#include "midipal/plugins/drum_sequencer.h"

namespace midipal { namespace plugins {

class EuclidianPatternGenerator : public DrumSequencer {
 public:
  EuclidianPatternGenerator() { }
 protected:
  virtual void OnInitImpl();
  virtual void ParseNotes();
  virtual void TickImpl();
  virtual uint8_t settings_base() {
    return SETTING_EUCLIDIAN_PATTERN_GENERATOR;
  }
  
 private:
  uint8_t num_notes_[4];
  uint8_t num_steps_[4];
  uint8_t step_count_[4];
  uint16_t bitmask_[4];
  
  DISALLOW_COPY_AND_ASSIGN(EuclidianPatternGenerator);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_EUCLIDIAN_PATTERN_GENERATOR_H_
