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
// Channel merger app.

#include "midipal/apps/combiner.h"

#include "midipal/resources.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

void Combiner::OnInit() {
  ui.AddPage(STR_RES_INP, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_NUM, UNIT_INTEGER, 1, 16);
  ui.AddPage(STR_RES_OUT, UNIT_INDEX, 0, 15);
}

void Combiner::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  uint8_t type = status & 0xf0;
  uint8_t channel = status & 0x0f;
  // Pass-through real time messages.
  if (type == 0xf0) {
    Send(status, data, data_size);
  } else {
    uint8_t in_range = channel >= input_channel_ && \
        channel < input_channel_ + num_channels_;
    in_range |= (channel + 0x10) >= input_channel_ && \
        (channel + 0x10) < input_channel_ + num_channels_;
    if (in_range) {
      channel = output_channel_;
    }
    Send(type | channel, data, data_size);
  }
}

} }  // namespace midipal::plugins
