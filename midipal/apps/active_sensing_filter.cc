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
// Active Sensing filter app.

#include "midipal/apps/active_sensing_filter.h"

#include "midipal/ui.h"

namespace midipal { namespace apps {

const prog_uint8_t active_sensing_filter_factory_data[1] PROGMEM = {
  1,
};

void ActiveSensingFilter::OnInit() {
  ui.AddPage(STR_RES_FLT, STR_RES_OFF, 0, 1);
}

void ActiveSensingFilter::OnRawByte(uint8_t byte) {
  if (byte != 0xfe || !enabled_) {
    SendNow(byte);
  }
}

const prog_uint8_t* ActiveSensingFilter::factory_data() {
  return active_sensing_filter_factory_data;
}

} }  // namespace midipal::apps
