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
// Chord memory app.

#ifndef MIDIPAL_APPS_CHORD_MEMORY_H_
#define MIDIPAL_APPS_CHORD_MEMORY_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class ChordMemory {
 public:
  ChordMemory() { }

  static void OnInit();
  static void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  static void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  static void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  static void OnNoteAftertouch(uint8_t channel, uint8_t note, uint8_t velocity);
  static uint8_t OnClick();
  
  static const prog_AppInfo app_info_;
  
 private:
  static void PlayChord(
      uint8_t type,
      uint8_t channel,
      uint8_t note,
      uint8_t velocity);
  
  static uint8_t channel_;
  static uint8_t num_notes_;
  static uint8_t chord_[15];
  
  static uint8_t root_;
  
  DISALLOW_COPY_AND_ASSIGN(ChordMemory);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_CHORD_MEMORY_H_
