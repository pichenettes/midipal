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

using namespace avrlib;

/* <static> */
RotaryEncoder<EncoderALine, EncoderBLine, EncoderClickLine> Ui::encoder_;
PotScanner<8, 0, 8, 7> Ui::pots_;
EventQueue<32> Ui::queue_;
PageDefinition Ui::pages_[32];
uint8_t Ui::num_pages_;
uint8_t Ui::page_;
uint8_t Ui::pot_value_[8];
uint8_t Ui::editing_;
uint8_t Ui::read_pots_;

/* </static> */

/* extern */
Ui ui;

/* static */
void Ui::Init() {
  encoder_.Init();
  pots_.Init();
  read_pots_ = 0;
  num_pages_ = 0;
  page_ = 0;
  editing_ = 0;
}

/* static */
void Ui::AddPage(
    uint8_t key_res_id,
    uint8_t value_res_id,
    uint8_t min,
    uint8_t max) {
  pages_[num_pages_].key_res_id = key_res_id;
  pages_[num_pages_].value_res_id = value_res_id;
  pages_[num_pages_].min = min;
  pages_[num_pages_].max = max;
  ++num_pages_;
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
  if (read_pots_) {
    pots_.Read();
    uint8_t index = pots_.last_read();
    uint8_t value = pots_.value(index);
    if (value != pot_value_[index]) {
      pot_value_[index] = value;
      queue_.AddEvent(CONTROL_POT, index, value);
    }
  }
}

/* static */
void Ui::DoEvents() {
  uint8_t redraw = 0;
  PlugIn* plugin = plugin_manager.active_plugin();
  while (queue_.available()) {
    redraw = 1;
    Event e = queue_.PullEvent();
    if (e.control_type == CONTROL_ENCODER) {
      // Internal handling of the encoder.
      if (!plugin->OnIncrement(e.value)) {
        if (editing_) {
          int16_t v = plugin->GetParameter(page_);
          v = Clip(
              v + static_cast<int8_t>(e.value),
              pages_[page_].min,
              pages_[page_].max);
          plugin->SetParameter(page_, v);
        } else {
          page_ += e.value;
          if (page_ == 0xff) {
            page_ = 0;
          } else if (page_ >= num_pages_) {
            page_ = num_pages_ - 1;
          }
        }
      }
    } else if (e.control_type == CONTROL_ENCODER_CLICK) {
      if (!plugin_manager.active_plugin()->OnClick()) {
        editing_ ^= 1;
      }
    } else if (e.control_type == CONTROL_POT) {
      plugin_manager.active_plugin()->OnPot(e.control_id, e.value);
    }
  }
  
  if (queue_.idle_time_ms() > 50) {
    redraw = 1;
    queue_.Touch();
    plugin_manager.active_plugin()->OnIdle();
  }
  
  if (redraw && !plugin->OnRedraw()) {
    PrintKeyValuePair(
        pages_[page_].key_res_id,
        pages_[page_].value_res_id,
        plugin->GetParameter(page_),
        editing_);
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
  if (value_res_id == 0) {
    UnsafeItoa(value, 3, &line_buffer[4]);
  } else if (value_res_id == 1) {
    PrintNote(&line_buffer[4], value);
  } else {
    ResourcesManager::LoadStringResource(
        value_res_id + value, &line_buffer[4], 3);
  }
  AlignRight(&line_buffer[4], 3);
  if (selected) {
    line_buffer[3] = '>';
    line_buffer[7] = '<';
  }
  display.Print(0, line_buffer);
}

/* static */
void Ui::PrintString(uint8_t res_id) {
  ResourcesManager::LoadStringResource(res_id, &line_buffer[0], 8);
  AlignRight(&line_buffer[0], 8);
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
void Ui::RefreshScreen() {
  display.Print(0, line_buffer);
}

}  // namespace midipal
