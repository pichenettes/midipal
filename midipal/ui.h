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
// Main definitions.

#ifndef MIDIPAL_UI_H_
#define MIDIPAL_UI_H_

#include "avrlib/base.h"

#include "avrlib/devices/rotary_encoder.h"
#include "avrlib/devices/switch.h"
#include "avrlib/ui/event_queue.h"

#include "midipal/hardware_config.h"

namespace midipal {

using namespace avrlib;

struct PageDefinition {
  uint8_t key_res_id;
  uint8_t value_res_id;
  uint8_t min;
  uint8_t max;
};

class Ui {
 public:
  static void Init();
  static void Poll();
  static void DoEvents();
  
  static void PrintKeyValuePair(
      uint8_t key_res_id,
      uint8_t value_res_id,
      uint8_t value,
      uint8_t selected);

  static void Clear();
  static void PrintChannel(char* buffer, uint8_t channel);
  static void PrintHex(char* buffer, uint8_t value);
  static void PrintNote(char* buffer, uint8_t note);
  static void PrintString(uint8_t res_id);
  static void RefreshScreen();
  
  static void AddPage(
      uint8_t key_res_id,
      uint8_t value_res_id,
      uint8_t min,
      uint8_t max);
    
  static uint8_t editing() {
    return editing_;
  }

 private:
  static RotaryEncoder<EncoderALine, EncoderBLine, EncoderClickLine> encoder_;
  static EventQueue<32> queue_;
  static uint8_t num_pages_;
  static uint8_t page_;
  static uint8_t editing_;
  static PageDefinition pages_[32];
};

extern Ui ui;

}  // namespace midipal

#endif // MIDIPAL_UI_H_
