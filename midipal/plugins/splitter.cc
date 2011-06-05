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
// Splitter plug-in.

#include "midipal/plugins/splitter.h"

#include "midi/midi.h"

#include "midipal/resources.h"
#include "midipal/ui.h"

namespace midipal { namespace plugins {

using namespace avrlib;

void Splitter::OnLoad() {
  for (uint8_t i = 0; i < 4; ++i) {
    SetParameter(i, LoadSetting(SETTING_SPLITTER_INPUT_CHANNEL + i));
  }
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
  if (type != 0x80 && type != 0x90 && type != 0xa0) {
    Send(status, data, data_size);
  }
}

void Splitter::Split(
    uint8_t type,
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel == input_channel_) {
    channel = note < split_point_ ? lower_channel_ : upper_channel_;
  }
  Send3(type | channel, note, velocity);
}

void Splitter::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  Split(0x90, channel, note, velocity);
}

void Splitter::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  Split(0x80, channel, note, velocity);
}

void Splitter::OnAftertouch(uint8_t channel, uint8_t note, uint8_t velocity) {
  Split(0xa0, channel, note, velocity);
}

void Splitter::SetParameter(uint8_t key, uint8_t value) {
  static_cast<uint8_t*>(&input_channel_)[key] = value;
  SaveSetting(SETTING_SPLITTER_INPUT_CHANNEL + key, value);
}

uint8_t Splitter::GetParameter(uint8_t key) {
  return static_cast<uint8_t*>(&input_channel_)[key];
}

} }  // namespace midipal::plugins
