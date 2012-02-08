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
// Functions for processing notes.

#include "midipal/notes.h"

#include "avrlib/op.h"

#include "midipal/resources.h"

namespace midipal {
  
using namespace avrlib;

Note FactorizeMidiNote(uint8_t note) {
  Note n;
  n.note = note;
  n.octave = 0;
  while (n.note >= 12) {
    n.note -= 12;
    ++n.octave;
  }
  return n;
}

uint8_t Transpose(uint8_t note, int8_t by) {
  if (by < 0) {
    if (note >= -by) {
      note += by;
    }
  } else {
    if (note < 127 - by) {
      note += by;
    }
  }
  return note;
}

uint8_t Constraint(uint8_t note, uint8_t root, uint8_t scale) {
  // Root notes 12-24 are just 0-12 with b instead of #.
  if (root >= 12) {
    root -= 12;
  }
  // Transpose back in C.
  note -= root;
  if (note > 127) {
    note += 12;
  }
  
  // Constraint to scale.
  Note n = FactorizeMidiNote(note);
  n.note = ResourcesManager::Lookup<uint16_t, uint8_t>(
      LUT_RES_SCALE_0 + scale, n.note);
  
  note = U8U8Mul(n.octave, 12) + n.note;
  note += root;
  if (note > 127) {
    note -= 12;
  }
  return note;
}

/* extern */
NoteMap<32> note_map;

}  // namespace midipal
