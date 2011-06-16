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
// Knob controller app.

#include "midipal/apps/controller.h"

#include "midi/midi.h"

#include "midipal/ui.h"

namespace midipal { namespace apps {

void Controller::OnInit() {
  ui.set_read_pots(1);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  for (uint8_t i = 0; i < 8; ++i) {
    ui.AddPage(STR_RES_CC1 + i, UNIT_INTEGER, 0, 127);
  }
}

void Controller::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  Send(status, data, data_size);
}

uint8_t Controller::OnPot(uint8_t pot, uint8_t value) {
  Send3(0xb0 | channel_, cc_[pot], value);
}

} }  // namespace midipal::plugins
