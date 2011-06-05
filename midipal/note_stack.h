// Copyright 2009 Olivier Gillet.
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
// Stack of currently pressed keys.
//
// Currently pressed keys are stored as a linked list. The linked list is used
// as a LIFO stack to allow monosynth-like behaviour. An example of such
// behaviour is:
// player presses and holds C4-> C4 is played.
// player presses and holds C5 (while holding C4) -> C5 is played.
// player presses and holds G4 (while holding C4&C5)-> G4 is played.
// player releases C5 -> G4 is played.
// player releases G4 -> C4 is played.
//
// The nodes used in the linked list are pre-allocated from a pool of 16
// nodes, so the "pointers" (to the root element for example) are not actual
// pointers, but indices of an element in the pool.
//
// Additionally, an array of pointers is stored to allow random access to the
// n-th note, sorted by ascending order of pitch (for arpeggiation).
//
// TODO(pichenettes): having this class implemented as a "static singleton"
// saves almost 300 bytes of code. w00t! But we'd rather move this back to a
// simple class when adding multitimbrality. When will we add multitimbrality?
// Probably never.

#ifndef MIDIPAL_NOTE_STACK_H_
#define MIDIPAL_NOTE_STACK_H_

#include "avrlib/base.h"

static const uint8_t kNoteStackSize = 16;

namespace midipal {

struct NoteEntry {
  uint8_t note;
  uint8_t velocity;
  uint8_t next_ptr;  // Base 1.
};

class NoteStack {
 public: 
  NoteStack() { }
  static void Init() { Clear(); }

  static void NoteOn(uint8_t note, uint8_t velocity);
  static void NoteOff(uint8_t note);
  static void Clear();

  static uint8_t size() { return size_; }
  static const NoteEntry& most_recent_note() { return pool_[root_ptr_]; }
  static const NoteEntry& least_recent_note() {
    uint8_t current = root_ptr_;
    while (current && pool_[current].next_ptr) {
      current = pool_[current].next_ptr;
    }
    return pool_[current];
  }
  static const NoteEntry& sorted_note(uint8_t index) {
    return pool_[sorted_ptr_[index]];
  }
  static const NoteEntry& note(uint8_t index) { return pool_[index]; }
  static const NoteEntry& dummy() { return pool_[0]; }

 private:
  static uint8_t size_;
  static NoteEntry pool_[kNoteStackSize + 1];  // First element is a dummy node!
  static uint8_t root_ptr_;  // Base 1.
  static uint8_t sorted_ptr_[kNoteStackSize + 1];  // Base 1.

  DISALLOW_COPY_AND_ASSIGN(NoteStack);
};

extern NoteStack note_stack;

}  // namespace midipal

#endif // MIDIPAL_NOTE_STACK_H_
