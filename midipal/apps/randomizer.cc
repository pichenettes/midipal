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
// Randomizer app.

#include "midipal/apps/randomizer.h"

#include "avrlib/random.h"

#include "midi/midi.h"

#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

void Randomizer::OnInit() {
  ui.AddPage(STR_RES_CHN, UNIT_INTEGER_ALL, 0, 16);
  ui.AddPage(STR_RES_AMT, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_NOT, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_VEL, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_CC1, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_CC2, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES__C1, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES__C2, UNIT_INTEGER, 0, 127);
}

void Randomizer::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  uint8_t type = status & 0xf0;
  if (type != 0x80 && type != 0x90 && type != 0xa0) {
    Send(status, data, data_size);
  }
}

uint8_t Randomizer::ScaleModulationAmount(uint8_t amount) {
  if (Random::GetByte() < (global_amount_ << 1)) {
    return amount << 1;
  } else {
    return 0;
  }
}


void Randomizer::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel_ && channel_ != (channel + 1)) {
    Send3(0x90 | channel, note, velocity);
  } else {
    // Send random CCs before the note
    for (uint8_t i = 0; i < 2; ++i) {
      if (cc_amount_[i] && global_amount_) {
        uint8_t value = U8Mix(
            63,
            Random::GetByte() & 0x7f,
            ScaleModulationAmount(cc_amount_[i]));
        Send3(0xb0 | channel, cc_[i], value);
      }
    }
    if (velocity_amount_) {
      velocity = U8Mix(
          velocity,
          Random::GetByte() & 0x7f,
          ScaleModulationAmount(velocity_amount_));
    }
    uint8_t new_note = note;
    if (note_amount_) {
      new_note = U8Mix(
          note,
          Random::GetByte() & 0x7f,
          ScaleModulationAmount(note_amount_));
    }

    map_.Put(note, new_note);

    Send3(0x90 | channel, new_note, velocity);
  }
}

void Randomizer::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  SendMessage(0x80, channel, note, velocity);
}

void Randomizer::OnAftertouch(uint8_t channel, uint8_t note, uint8_t velocity) {
  SendMessage(0xa0, channel, note, velocity);
}

void Randomizer::SendMessage(
    uint8_t message,
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel_ && channel_ != (channel + 1)) {
    Send3(message | channel, note, velocity);
  } else {
    NoteMapEntry* entry = map_.Find(note);
    if (entry) {
      Send3(message | channel, entry->value, velocity);
      if (message == 0x80) {
        entry->note = 0xff;
      }
    }
  }  
}

} }  // namespace midipal::plugins
