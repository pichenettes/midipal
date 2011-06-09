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
// Map from a note index to an 8-bit integer.

#ifndef MIDIPAL_NOTE_MAP_
#define MIDIPAL_NOTE_MAP_

#include <string.h>

#include "midipal/plugin.h"

namespace midipal {

struct NoteMapEntry {
  uint8_t note;
  uint8_t value;
};

template<uint8_t size>
class NoteMap {
 public:
  NoteMap() {
    memset(map_, 0xff, size * sizeof(NoteMapEntry));
  }
  
  void Put(uint8_t note, uint8_t value) {
    uint8_t index = 0xff;
    for (uint8_t i = 0; i < size; ++i) {
      if (map_[i].note == note) {
        index = i;
        break;
      }
    }
    if (index == 0xff) {
      for (uint8_t i = 0; i < size; ++i) {
        if (map_[i].note == 0xff) {
          index = i;
          break;
        }
      }
    }
    if (index == 0xff) {
      index = 0;
    }
    map_[index].note = note;
    map_[index].value = value;
  }
  
  NoteMapEntry* Find(uint8_t note) {
    for (uint8_t i = 0; i < size; ++i) {
      if (map_[i].note == note) {
        return &map_[i];
      }
    }
    return NULL;
  }

 private:
  NoteMapEntry map_[size];
  
  DISALLOW_COPY_AND_ASSIGN(NoteMap);
};

}  // namespace midipal:

#endif // MIDIPAL_NOTE_MAP_
