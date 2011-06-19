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

#ifndef MIDIPAL_NOTES_H_
#define MIDIPAL_NOTES_H_

#include "avrlib/base.h"

#include "midipal/note_map.h"

namespace midipal {
  
struct Note {
  uint8_t octave;
  uint8_t note;
};

Note FactorizeMidiNote(uint8_t note);

uint8_t Transpose(uint8_t note, int8_t by);

uint8_t Constraint(uint8_t note, uint8_t root, uint8_t scale);

extern NoteMap<40> note_map;

}  // namespace midipal

#endif // MIDIPAL_NOTES_H_
