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
// Generic filter app.

#ifndef MIDIPAL_APPS_GENERIC_FILTER_H_
#define MIDIPAL_APPS_GENERIC_FILTER_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

static const uint8_t kNumModifiers = 4;

enum ValueOperation {
  VALUE_OEPRATION_NOP,
  VALUE_OEPRATION_ADD,
  VALUE_OPERATION_SUBTRACT,
  VALUE_OPERATION_INVERT,
  VALUE_OPERATION_SET_TO,
  VALUE_OPERATION_MAP_TO_RANGE,
  VALUE_OPERATION_SET_TO_RANDOM,
  VALUE_OPERATION_ADD_RANDOM,
};

struct Range {
  int8_t min;
  int8_t max;
};

struct ValueTransformation {
  uint8_t operation;
  int8_t argument[2];
  
  inline uint8_t preserves_zero() const {
    return operation & 0x80;
  }
  
  inline uint8_t wrap() const {
    return operation & 0x40;
  }
  
  inline uint8_t swap_source() const {
    return operation & 0x20;
  }
};

struct Modifier {
  // Event filtering.
  uint16_t channel_bitmask;
  uint8_t message_type_bitmask;
  Range value[2];

  // Action / Transformation
  uint8_t action;
  uint16_t delay;
  ValueTransformation value_transformation[2];
  
  inline uint8_t accept_channel(uint8_t channel) const {
    uint16_t channel_bit = 1;
    channel_bit <<= channel;
    return channel_bit & channel_bitmask;
  }
  
  inline uint8_t accept_message(uint8_t message) const {
    uint8_t message_bit = 1 << ((message >> 4) - 8);
    return message_bit & message_type_bitmask;
  }
  
  inline uint8_t accept(uint8_t status, uint8_t data1, uint8_t data2) const {
    if ((status & 0xf0) == 0xf0) {
      // For realtime messages, only test the message type.
      return accept_message(status);
    } else {
      return accept_channel(status & 0x0f) && \
          accept_message(status) && \
          data1 >= value[0].min && \
          data1 <= value[0].max && \
          data2 >= value[1].min && \
          data2 <= value[1].max;
    }
  }
  
  inline uint8_t destroys() const {
    return action & 0x80;
  }
  
  inline uint8_t forwards() const {
    return action & 0x40;
  }
  
  inline uint8_t promotes_to_cc() const {
    return action & 0x20;
  }
  
  inline uint8_t remaps_channel() const {
    return action & 0x10;
  }
};

class GenericFilter {
 public:
  GenericFilter() { }

  static void OnInit();
  static void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
 
  static void SetParameter(uint8_t key, uint8_t value);

#ifdef MIDIBUD_FIRMWARE
  static uint8_t OnSwitch(uint8_t pot);
#endif  
  
  static const prog_AppInfo app_info_;
 
 private:
  static uint8_t active_program_;
  static Modifier modifiers_[kNumModifiers];
  
  DISALLOW_COPY_AND_ASSIGN(GenericFilter);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_GENERIC_FILTER_H_
