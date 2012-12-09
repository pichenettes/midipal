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

#ifndef MIDIPAL_UI_H_
#define MIDIPAL_UI_H_

#include "avrlib/base.h"

#ifndef MIDIBUD_FIRMWARE
#include "avrlib/devices/pot_scanner.h"
#endif

#include "avrlib/devices/rotary_encoder.h"
#include "avrlib/devices/switch.h"
#include "avrlib/ui/event_queue.h"

#include "midipal/hardware_config.h"

namespace midipal {

struct PageDefinition {
  uint8_t key_res_id;
  uint8_t value_res_id;
  uint8_t min;
  uint8_t max;
};

enum Unit {
  UNIT_INTEGER,
  UNIT_INDEX,
  UNIT_NOTE,
  UNIT_INTEGER_ALL,
  UNIT_SIGNED_INTEGER,
  UNIT_CHANNEL
};

enum PageScrollingStatus {
  PAGE_BAD = 0,
  PAGE_GOOD = 1,
  PAGE_LAST = 2
};

#ifdef MIDIBUD_FIRMWARE
enum SwitchNumber {
  SWITCH_1,
  SWITCH_2,
  SWITCH_3,
  SWITCH_4,
  SWITCH_5,
  SWITCH_COUNT
};
#endif

class Ui {
 public:
  static void Init();
  static void Poll();
  static void DoEvents();
  
  static void Clear();

  static void PrintKeyValuePair(
      uint8_t key_res_id,
      uint8_t index,
      uint8_t value_res_id,
      uint8_t value,
      uint8_t selected);
  static void PrintChannel(char* buffer, uint8_t channel);
  static void PrintHex(char* buffer, uint8_t value);
  static void PrintNote(char* buffer, uint8_t note);
  static void PrintString(uint8_t res_id);

  static void RefreshScreen();
  
#ifndef MIDIBUD_FIRMWARE
  static inline void set_read_pots(uint8_t value) {
    read_pots_ = value;
  }
#endif
  static void AddPage(
      uint8_t key_res_id,
      uint8_t value_res_id,
      uint8_t min,
      uint8_t max);
  static void AddRepeatedPage(
      uint8_t key_res_id,
      uint8_t value_res_id,
      uint8_t min,
      uint8_t max,
      uint8_t num_repetitions);
  static void AddClockPages();

#ifdef MIDIBUD_FIRMWARE
  static void SetPage(uint8_t page);
#endif;

  static uint8_t page_index();
  static inline uint8_t editing() { return editing_; }
  static inline uint8_t page() { return page_; }
  static inline void set_page(uint8_t page) { page_ = page; }

 private:
  static avrlib::RotaryEncoder<
      EncoderALine, EncoderBLine, EncoderClickLine> encoder_;
#ifdef MIDIBUD_FIRMWARE
  static avrlib::DebouncedSwitch<Switch1Line> switch1_;
  static avrlib::DebouncedSwitch<Switch2Line> switch2_;
  static avrlib::DebouncedSwitch<Switch3Line> switch3_;
  static avrlib::DebouncedSwitch<Switch4Line> switch4_;
  static avrlib::DebouncedSwitch<Switch5Line> switch5_;
#else
  static avrlib::PotScanner<8, 0, 8, 7> pots_;
#endif
  static avrlib::EventQueue<32> queue_;
  static uint16_t encoder_hold_time_;
  static uint8_t num_declared_pages_;
  static uint8_t num_pages_;
  static uint8_t stride_;
  static uint8_t page_;
  static uint8_t editing_;
#ifdef MIDIBUD_FIRMWARE
  static uint8_t read_switch_;
#else
  static uint8_t read_pots_;
  static uint8_t pot_value_[8];
#endif
  static PageDefinition pages_[48];
};

extern Ui ui;

}  // namespace midipal

#endif // MIDIPAL_UI_H_
