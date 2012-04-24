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

#include "midipal/ui.h"

#include "avrlib/op.h"
#include "avrlib/string.h"

#include "midipal/app.h"
#include "midipal/display.h"
#include "midipal/resources.h"

namespace midipal {

using namespace avrlib;

/* <static> */
RotaryEncoder<EncoderALine, EncoderBLine, EncoderClickLine> Ui::encoder_;
PotScanner<8, 0, 8, 7> Ui::pots_;
EventQueue<32> Ui::queue_;
PageDefinition Ui::pages_[48];
uint8_t Ui::num_declared_pages_;
uint8_t Ui::num_pages_;
uint8_t Ui::page_;
uint8_t Ui::stride_;
uint8_t Ui::pot_value_[8];
uint8_t Ui::editing_;
uint8_t Ui::read_pots_;
uint16_t Ui::encoder_hold_time_;

/* </static> */

/* extern */
Ui ui;

/* static */
void Ui::Init() {
  encoder_.Init();
  pots_.Init();
  lcd.Init();
  display.Init();
  read_pots_ = 0;
  num_declared_pages_ = 0;
  num_pages_ = 0;
  stride_ = 0;
  page_ = 0;
  editing_ = 0;
  encoder_hold_time_ = 0;
}

/* static */
void Ui::AddPage(
    uint8_t key_res_id,
    uint8_t value_res_id,
    uint8_t min,
    uint8_t max) {
  pages_[num_declared_pages_].key_res_id = key_res_id;
  pages_[num_declared_pages_].value_res_id = value_res_id;
  pages_[num_declared_pages_].min = min;
  pages_[num_declared_pages_].max = max;
  ++num_declared_pages_;
  ++num_pages_;
}

/* static */
void Ui::AddRepeatedPage(
    uint8_t key_res_id,
    uint8_t value_res_id,
    uint8_t min,
    uint8_t max,
    uint8_t num_repetitions) {
  AddPage(key_res_id, value_res_id, min, max);
  num_pages_ += (num_repetitions - 1);
  ++stride_;
}

/* static */
void Ui::Poll() {
  int8_t increment = encoder_.Read();
  if (increment != 0) {
    queue_.AddEvent(CONTROL_ENCODER, 0, increment);
  }
  if (encoder_.immediate_value() == 0x00) {
    ++encoder_hold_time_;
    if (encoder_hold_time_ > 4000) {
      queue_.AddEvent(CONTROL_ENCODER_CLICK, 0, 0xff);
    }
  }
  if (encoder_.clicked()) {
    // Do not enqueue a click event when the encoder is released after a long
    // press.
    if (encoder_hold_time_ <= 4000) {
      queue_.AddEvent(CONTROL_ENCODER_CLICK, 0, 1);
    }
    encoder_hold_time_ = 0;
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
  lcd.Tick();
}

/* static */
uint8_t Ui::page_index() {
  uint8_t p = page_;
  uint8_t index = 0;
  while (p >= num_declared_pages_) {
    p -= stride_;
    ++index;
  }
  return index;
}

/* static */
void Ui::DoEvents() {
  uint8_t redraw = 0;
  while (queue_.available()) {
    uint8_t p = page_;
    while (p >= num_declared_pages_ && num_declared_pages_ && stride_) {
      p -= stride_;
    }
    const PageDefinition& page_def = pages_[p];
    
    redraw = 1;
    Event e = queue_.PullEvent();
    if (e.control_type == CONTROL_ENCODER) {
      // Internal handling of the encoder.
      if (!app.OnIncrement(e.value)) {
        if (editing_) {
          int16_t v;
          if (page_def.value_res_id == UNIT_SIGNED_INTEGER) {
            int16_t v = static_cast<int8_t>(app.GetParameter(page_));
            v = Clip(
                v + static_cast<int8_t>(e.value),
                static_cast<int8_t>(page_def.min),
                static_cast<int8_t>(page_def.max));
            app.SetParameter(page_, static_cast<int8_t>(v));
          } else {
            int16_t v = app.GetParameter(page_);
            v = Clip(
                v + static_cast<int8_t>(e.value),
                page_def.min,
                page_def.max);
            app.SetParameter(page_, v);
          }
        } else {
          uint8_t current_page = page_;
          while (1) {
            page_ += e.value;
            if (page_ == 0xff) {
              page_ = 0;
            } else if (page_ >= num_pages_) {
              page_ = num_pages_ - 1;
            }
            uint8_t page_status = app.CheckPageStatus(page_);
            if (page_status == PAGE_GOOD) {
              break;
            } else if (page_status == PAGE_LAST) {
              page_ = current_page;
              break;
            }
          }
        }
      }
    } else if (e.control_type == CONTROL_ENCODER_CLICK) {
      if (e.value == 1) {
        if (!app.OnClick()) {
          if (page_def.value_res_id == STR_RES_OFF) {
            app.SetParameter(page_, app.GetParameter(page_) ? 0 : 1);
            app.SaveSetting(page_);
          } else {
            editing_ ^= 1;
            // Left the editing mode, save settings.
            if (!editing_) {
              app.SaveSetting(page_);
            }
          }
        }
      } else {
        app.Launch(0);
      }
    } else if (e.control_type == CONTROL_POT) {
      app.OnPot(e.control_id, e.value);
    }
  }
  
  if (queue_.idle_time_ms() > 50) {
    redraw = 1;
    queue_.Touch();
    app.OnIdle();
  }
  
  if (redraw && !app.OnRedraw()) {
    uint8_t p = page_;
    uint8_t index = 0;
    while (p >= num_declared_pages_ && num_declared_pages_ && stride_) {
      p -= stride_;
      ++index;
    }
    const PageDefinition& page_def = pages_[p];
    
    PrintKeyValuePair(
        page_def.key_res_id,
        index,
        page_def.value_res_id,
        app.GetParameter(page_),
        editing_);
  }
  display.Tick();
}

static const prog_char note_names[] PROGMEM = " CC# DD# E FF# GG# AA# B";
static const prog_char octaves[] PROGMEM = "-012345678";

/* static */
void Ui::PrintKeyValuePair(
    uint8_t key_res_id,
    uint8_t index,
    uint8_t value_res_id,
    uint8_t value,
    uint8_t selected) {
  memset(line_buffer, ' ', kLcdWidth);
  if (key_res_id == UNIT_CHANNEL) {
    line_buffer[0] = 'c';
    line_buffer[1] = 'h';
    PrintChannel(&line_buffer[2], index);
  } else {
    ResourcesManager::LoadStringResource(key_res_id, &line_buffer[0], 3);
  }
  AlignRight(&line_buffer[0], 3);
  
  // This is a hack to add the index id on the step sequencer pages.
  if (line_buffer[2] < 0x20 && line_buffer[1] == ' ') {
    UnsafeItoa(index + 1, 2, &line_buffer[0]);
    PadRight(&line_buffer[0], 2, '0');
  }
  
  switch (value_res_id) {
    case UNIT_INTEGER:
    case UNIT_INTEGER_ALL:
      UnsafeItoa(value, 3, &line_buffer[4]);
      if (value == 0 && value_res_id == UNIT_INTEGER_ALL) {
          ResourcesManager::LoadStringResource(
              STR_RES_ALL, &line_buffer[4], 3);
      }
      break;
    case UNIT_SIGNED_INTEGER:
      UnsafeItoa(static_cast<int8_t>(value), 3, &line_buffer[4]);
      break;
    case UNIT_INDEX:
      UnsafeItoa(value + 1, 3, &line_buffer[4]);
      break;
    case UNIT_NOTE:
      PrintNote(&line_buffer[4], value);
      break;
    default:
      ResourcesManager::LoadStringResource(
          value_res_id + value, &line_buffer[4], 3);
      break;
  }
  AlignRight(&line_buffer[4], 3);
  if (selected) {
    line_buffer[3] = '[';
    line_buffer[7] = ']';
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
