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
// Base class implemented by all the "Plug-ins" running on the Midipal.

#include "midipal/plugin.h"

#include <avr/eeprom.h>

#include "avrlib/serial.h"

#include "midipal/hardware_config.h"

namespace midipal {
  
using namespace avrlib;
  
Serial<MidiPort, 31250, DISABLED, POLLED> midi_out;

uint8_t PlugIn::LoadSetting(uint8_t setting_id) {
  return eeprom_read_byte((uint8_t*)(setting_id));
}

void PlugIn::SaveSetting(uint8_t setting_id, uint8_t value) {
  eeprom_write_byte((uint8_t*)(setting_id), value);
}

void PlugIn::SendNow(uint8_t byte) {
  midi_out.Overwrite(byte);
}

}  // namespace midipal
