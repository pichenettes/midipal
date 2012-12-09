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

#include <avr/eeprom.h>

#include "midipal/apps/generic_filter.h"

#include "avrlib/random.h"
#include "avrlib/op.h"

#include "midi/midi.h"

#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t generic_filter_factory_data[1] PROGMEM = { 0 };

/* static */
Modifier GenericFilter::modifiers_[kNumModifiers];

/* static */
uint8_t GenericFilter::active_program_;

/* static */
const prog_AppInfo GenericFilter::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  NULL, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnAftertouch)(uint8_t, uint8_t);
  NULL, // void (*OnControlChange)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnProgramChange)(uint8_t, uint8_t);
  NULL, // void (*OnPitchBend)(uint8_t, uint16_t);
  NULL, // void (*OnSysExByte)(uint8_t);
  NULL, // void (*OnClock)();
  NULL, // void (*OnStart)();
  NULL, // void (*OnContinue)();
  NULL, // void (*OnStop)();
  NULL, // uint8_t (*CheckChannel)(uint8_t);
  NULL, // void (*OnRawByte)(uint8_t);
  &OnRawMidiData, // void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t);
  NULL, // void (*OnInternalClockTick)();
  NULL, // void (*OnInternalClockStep)();
  NULL, // uint8_t (*OnIncrement)(int8_t);
  NULL, // uint8_t (*OnClick)();
#ifdef MIDIBUD_FIRMWARE
  &OnSwitch, // uint8_t (*OnSwitch)(uint8_t);
#else
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  &SetParameter, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  1, // settings_size
  SETTINGS_GENERIC_FILTER_PROGRAM, // settings_offset
  &active_program_, // settings_data
  generic_filter_factory_data, // factory_data
  STR_RES_USER_PRG, // app_name
  true
};  

/* static */
void GenericFilter::OnInit() {
  ui.AddPage(STR_RES_PRG, UNIT_INDEX, 0, 3);
  SetParameter(0, active_program_);
}

/* static */
void GenericFilter::SetParameter(uint8_t key, uint8_t value) {
  active_program_ = value;
  uint16_t address = value * sizeof(modifiers_);
  address += SETTINGS_GENERIC_FILTER_SETTINGS;
  eeprom_read_block(
      &modifiers_[0],
      (void*)(address),
      sizeof(modifiers_));
}

/* static */
void GenericFilter::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  uint8_t destroyed = 0;
  uint8_t forwarded = 0;
  for (uint8_t i = 0; i < kNumModifiers; ++i) {
    const Modifier& modifier = modifiers_[i];
    if (modifier.accept(status, data[0], data[1])) {
      destroyed = destroyed || modifier.destroys();
      forwarded = forwarded || modifier.forwards();
    }
  }
  
  if (destroyed) {
    return;
  }
  
  if (forwarded) {
    app.Send(status, data, data_size);
  }
  
  // The rules are now applied one by one.
  for (uint8_t i = 0; i < kNumModifiers; ++i) {
    const Modifier& modifier = modifiers_[i];
    if (modifier.accept(status, data[0], data[1])) {
      // Apply a transformation on the channel.
      uint8_t channel = status;
      if (modifier.remaps_channel()) {
        channel = modifier.action;
      } else {
        channel += modifier.action;
      }
      if (modifier.promotes_to_cc()) {
        status = 0xb0 | (channel & 0x0f);
        data_size = 2;
      } else {
        status = (status & 0xf0) | (channel & 0x0f);
      }
      
      uint8_t new_data[2];
      // Apply a transformation on the values
      for (uint8_t j = 0; j < 2; ++j) {
        ValueTransformation t = modifier.value_transformation[j];
        uint8_t original_value = data[t.swap_source() ? (1 - j) : j];
        int16_t value = original_value;
        switch (t.operation & 0x0f) {
          case VALUE_OEPRATION_ADD:
            value += t.argument[0];
            break;

          case VALUE_OPERATION_SUBTRACT:
            value -= t.argument[0];
            break;

          case VALUE_OPERATION_INVERT:
            value = 127 - value;
            break;

          case VALUE_OPERATION_SET_TO:
            value = t.argument[0];
            break;
          
          case VALUE_OPERATION_SET_TO_RANDOM:
            value = Random::GetByte() & 0x7f;
            // Fall through

          case VALUE_OPERATION_MAP_TO_RANGE:
            if (t.argument[0] < t.argument[1]) {
              value = U8U8MulShift8(value << 1, t.argument[1] - t.argument[0]);
              value += t.argument[0];
            } else {
              value = U8U8MulShift8(value << 1, t.argument[0] - t.argument[1]);
              value = t.argument[1] - value;
            }
            break;

          case VALUE_OPERATION_ADD_RANDOM:
            value += U8U8MulShift8(
                Random::GetByte(),
                t.argument[1] - t.argument[0]);
            value += t.argument[0];
            break;
        }
        if (t.preserves_zero() && original_value == 0) {
          value = 0;
        }
        if (t.wrap()) {
          new_data[j] = value & 0x7f;
        } else {
          new_data[j] = Clip(value, 0x00, 0x7f);
        }
      }
      data[0] = new_data[0];
      data[1] = new_data[1];
    }
  }
  
  app.Send(status, data, data_size);
}

#ifdef MIDIBUD_FIRMWARE
/* static */
uint8_t GenericFilter::OnSwitch(uint8_t sw) {
  if (sw < 4) {
    SetParameter(0, sw);
  }
  return 1;
}
#endif

} }  // namespace midipal::apps
