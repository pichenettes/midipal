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
// Chord memory plug-in.

#include "midipal/plugins/chord_memory.h"

#include "avrlib/random.h"

#include "midi/midi.h"

#include "midipal/resources.h"
#include "midipal/ui.h"

namespace midipal { namespace plugins {

using namespace avrlib;

void ChordMemory::OnInit() {
  ui.AddPage(STR_RES_CHN, UNIT_INTEGER_ALL, 0, 16);
}

void ChordMemory::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  uint8_t type = status & 0xf0;
  if (type != 0x80 && type != 0x90 && type != 0xa0) {
    Send(status, data, data_size);
  }
}

uint8_t ChordMemory::OnClick() {
  if (!ui.editing()) {
    num_notes_ = 0;
  }
  return 0;
}

void ChordMemory::PlayChord(
    uint8_t type,
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (num_notes_ == 0) {
    Send3(type | channel, note, velocity);
  } else {
    for (uint8_t i = 0; i < num_notes_; ++i) {
      int16_t n = note;
      n += chord_[i] - chord_[0];
      while (n < 0) {
        n += 12;
      }
      while (n > 127) {
        n -= 12;
      }
      Send3(type | channel, static_cast<uint8_t>(n), velocity);
    }
  }
}

void ChordMemory::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel_ && channel_ != (channel + 1)) {
    Send3(0x90 | channel, note, velocity);
  } else {
    // Record mode.
    if (ui.editing()) {
      chord_[num_notes_++] = note;
      // Rotate buffer of recorded notes to avoid overflow ; but do not
      // touch the first note.
      if (num_notes_ == 15) {
        for (uint8_t i = 1; i < 14; ++i) {
          chord_[i] = chord_[i + 1];
        }
        num_notes_ = 14;
      }
      Send3(0x90 | channel, note, velocity);
    } else {
      PlayChord(0x90, channel, note, velocity);
    }
  }
}

void ChordMemory::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  if ((channel_ && channel_ != (channel + 1)) || ui.editing()) {
    Send3(0x80 | channel, note, velocity);
  } else {
    PlayChord(0x80, channel, note, velocity);
  }
}

void ChordMemory::OnAftertouch(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if ((channel_ && channel_ != (channel + 1)) || ui.editing()) {
    Send3(0xa0 | channel, note, velocity);
  } else {
    PlayChord(0xa0, channel, note, velocity);
  }
}

} }  // namespace midipal::plugins
