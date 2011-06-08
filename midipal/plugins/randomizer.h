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
// Randomizer plug-in.

#ifndef MIDIPAL_PLUGINS_RANDOMIZER_H_
#define MIDIPAL_PLUGINS_RANDOMIZER_H_

#include "midipal/plugin.h"

namespace midipal { namespace plugins {

struct NoteMapping {
  uint8_t original;
  uint8_t modified;
};

static const uint8_t kNumNoteMappings = 32;

class Randomizer : public PlugIn {
 public:
  Randomizer() { }

  void OnInit();
  void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  
  uint8_t settings_size() { return 7; }
  uint8_t settings_offset() { return SETTINGS_RANDOMIZER; }
  uint8_t* settings_data() { return &channel_; }
  
 private:
  uint8_t ScaleModulationAmount(uint8_t amount);
  uint8_t channel_;
  uint8_t global_amount_;
  uint8_t note_amount_;
  uint8_t velocity_amount_;
  uint8_t cc_amount_[2];
  uint8_t cc_[2];
  
  NoteMapping note_mappings_[kNumNoteMappings];
  
  DISALLOW_COPY_AND_ASSIGN(Randomizer);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_RANDOMIZER_H_
