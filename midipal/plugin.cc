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
#include "midipal/midi_handler.h"

namespace midipal {
  
using namespace avrlib;

Serial<MidiPort, 31250, DISABLED, POLLED> midi_out;

void PlugIn::Init() {
  // Load settings.
  eeprom_read_block(
      settings_data(),
      (void*)(settings_offset()),
      settings_size());
  OnIncrement(0);
  OnInit();
}

void PlugIn::SaveSettings() {
  eeprom_write_block(
      settings_data(),
      (void*)(settings_offset()),
      settings_size());
}

void PlugIn::SaveSetting(uint8_t setting_id, uint8_t value) {
  eeprom_write_byte((uint8_t*)(setting_id), value);
}

void PlugIn::SaveSettingWord(uint8_t setting_id, uint16_t value) {
  eeprom_write_word((uint16_t*)(setting_id), value);
}

void PlugIn::SendNow(uint8_t byte) {
  midi_out.Overwrite(byte);
}

void PlugIn::Send3(uint8_t a, uint8_t b, uint8_t c) {
  MidiHandler::OutputBuffer::Write(a);
  MidiHandler::OutputBuffer::Write(b);
  MidiHandler::OutputBuffer::Write(c);
}

void PlugIn::Send(uint8_t status, uint8_t* data, uint8_t size) {
  MidiHandler::OutputBuffer::Write(status);
  if (size) {
    MidiHandler::OutputBuffer::Write(*data++);
    --size;
  }
  if (size) {
    MidiHandler::OutputBuffer::Write(*data++);
    --size;
  }
}


}  // namespace midipal
