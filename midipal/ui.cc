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
// Multi data structure.

#include "midipal/ui.h"

#include "avrlib/op.h"
#include "avrlib/string.h"

#include "midipal/display.h"
#include "midipal/plugin_manager.h"
#include "midipal/resources.h"

namespace midipal {

/* <static> */
RotaryEncoder<EncoderALine, EncoderBLine, EncoderClickLine> Ui::encoder_;
EventQueue<32> Ui::queue_;
/* </static> */

/* extern */
Ui ui;

/* static */
void Ui::Init() {
  encoder_.Init();
}

/* static */
void Ui::Poll() {
  int8_t increment = encoder_.Read();
  if (increment != 0) {
    queue_.AddEvent(CONTROL_ENCODER, 0, increment);
  }
  if (encoder_.clicked()) {
    queue_.AddEvent(CONTROL_ENCODER_CLICK, 0, 1);
  }
}

/* static */
void Ui::DoEvents() {
  while (queue_.available()) {
    Event e = queue_.PullEvent();
    if (e.control_type == CONTROL_ENCODER) {
      plugin_manager.active_plugin()->OnIncrement(e.value);
    } else if (e.control_type == CONTROL_ENCODER_CLICK) {
      plugin_manager.active_plugin()->OnClick();
    }
  }
}

static const prog_char note_names[] PROGMEM = " CC# DD# E FF# GG# AA# B";
static const prog_char octaves[] PROGMEM = "-012345678";

/* static */
void Ui::PrintKeyValuePair(
    uint8_t key_res_id,
    uint8_t value_res_id,
    uint8_t value,
    uint8_t selected) {
  memset(line_buffer, ' ', kLcdWidth);
  ResourcesManager::LoadStringResource(key_res_id, &line_buffer[0], 3);
  AlignRight(&line_buffer[0], 3);
  ResourcesManager::LoadStringResource(
      value_res_id + value, &line_buffer[4], 3);
  AlignRight(&line_buffer[4], 3);
  if (selected) {
    line_buffer[3] = '>';
    line_buffer[7] = '<';
  }
  display.Print(0, line_buffer);
}

/* static */
void Ui::Clear() {
  memset(line_buffer, ' ', kLcdWidth);
}

/* static */
void Ui::PrintChannel(char* buffer, uint8_t channel) {
  *buffer = (channel == 0xff)
      ? ' '
      : ((channel < 9) ? '1' + channel : (channel - 8));
}

/* static */
void Ui::PrintHex(char* buffer, uint8_t value) {
  *buffer++ = NibbleToAscii(U8ShiftRight4(value));
  *buffer = NibbleToAscii(value & 0xf);
}

/* static */
void Ui::PrintNote(char* buffer, uint8_t note) {
  uint8_t octave = 0;
  while (note >= 12) {
    ++octave;
    note -= 12;
  }
  *buffer++ = ResourcesManager::Lookup<char, uint8_t>(
      note_names, note << 1);
  *buffer++ = ResourcesManager::Lookup<char, uint8_t>(
      note_names, 1 + (note << 1));
  *buffer = ResourcesManager::Lookup<char, uint8_t>(
      octaves, octave);
}

/* static */
void Ui::Refresh() {
  display.Print(0, line_buffer);
}

}  // namespace midipal
