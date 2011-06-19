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
// Splitter app.

#include "midipal/apps/splitter.h"

#include "midi/midi.h"

#include "midipal/ui.h"

namespace midipal { namespace apps {

void Splitter::OnInit() {
  ui.AddPage(STR_RES_INP, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_SPL, UNIT_NOTE, 20, 108);
  ui.AddPage(STR_RES_LOW, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_UPP, UNIT_INDEX, 0, 15);
}

void Splitter::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  uint8_t type = status & 0xf0;
  if (type == 0xf0) {
    Send(status, data, data_size);
  } else if (type == 0x80 || type == 0x90 || type == 0xa0) {
    // Split note on/off/aftertouch messages depending on the note value.
    uint8_t note = data[0];
    uint8_t channel = status & 0x0f;
    if (channel == input_channel_) {
      channel = note < split_point_ ? lower_channel_ : upper_channel_;
    }
    Send(type | channel, data, data_size);
  } else {
    // Pass through the other messages, just rewrite their channel.
    uint8_t channel = status & 0x0f;
    if (channel == input_channel_) {
      if (upper_channel_ != lower_channel_) {
        Send(type | upper_channel_, data, data_size);
      }
      status = type | lower_channel_;
    }
    Send(status, data, data_size);
  }
}

} }  // namespace midipal::apps
