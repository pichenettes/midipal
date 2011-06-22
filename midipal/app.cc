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
// Base class implemented by all the "Apps" running on the Midipal.

#include "midipal/app.h"

#include <avr/eeprom.h>

#include "avrlib/serial.h"

#include "midipal/display.h"
#include "midipal/hardware_config.h"
#include "midipal/event_scheduler.h"
#include "midipal/midi_handler.h"

namespace midipal {

/* extern */
const prog_uint8_t midi_clock_tick_per_step[17] PROGMEM = {
  192, 144, 96, 72, 64, 48, 36, 32, 24, 16, 12, 8, 6, 4, 3, 2, 1
};
  
using namespace avrlib;

Serial<MidiPort, 31250, DISABLED, POLLED> midi_out;

void App::Init() {
  // Load settings.
  eeprom_read_block(
      settings_data(),
      (void*)(settings_offset()),
      settings_size());
  OnIncrement(0);
  OnInit();
}

void App::SaveSettings() {
  eeprom_write_block(
      settings_data(),
      (void*)(settings_offset()),
      settings_size());
}

void App::SaveSetting(uint8_t index) {
  eeprom_write_byte(
      (uint8_t*)(settings_offset()) + index,
      settings_data()[index]);
}

void App::ResetToFactorySettings() {
  memcpy_P(
      settings_data(),
      factory_data(),
      settings_size());
  SaveSettings();
}

void App::SaveSettingWord(uint16_t setting_id, uint16_t value) {
  eeprom_write_word((uint16_t*)(setting_id), value);
}

void App::SendNow(uint8_t byte) {
  midi_out.Write(byte);
}

void App::Send3(uint8_t a, uint8_t b, uint8_t c) {
  FlushOutputBuffer(3);
  MidiHandler::OutputBuffer::Write(a);
  MidiHandler::OutputBuffer::Write(b);
  MidiHandler::OutputBuffer::Write(c);
}

void App::Send(uint8_t status, uint8_t* data, uint8_t size) {
  FlushOutputBuffer(size);
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

void App::FlushOutputBuffer(uint8_t requested_size) {
  while (MidiHandler::OutputBuffer::writable() < requested_size) {
    display.set_status('!');
    midi_out.Write(MidiHandler::OutputBuffer::Read());
  }
}

void App::SendLater(uint8_t note, uint8_t velocity, uint8_t when, uint8_t tag) {
  event_scheduler.Schedule(note, velocity, when, tag);
}

void App::SendScheduledNotes(uint8_t channel) {
  uint8_t current = event_scheduler.root();
  while (current) {
    const SchedulerEntry& entry = event_scheduler.entry(current);
    if (entry.when) {
      break;
    }
    if (entry.note != kZombieSlot) {
      if (entry.velocity == 0) {
        Send3(0x80 | channel, entry.note, 0);
      } else {
        Send3(0x90 | channel, entry.note, entry.velocity);
      }
    }
    current = entry.next;
  }
  event_scheduler.Tick();
}

void App::FlushQueue(uint8_t channel) {
  while (event_scheduler.size()) {
    SendScheduledNotes(channel);
  }
}

}  // namespace midipal
