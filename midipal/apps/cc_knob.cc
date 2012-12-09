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
// MIDI clock generator app.

#include "midipal/apps/cc_knob.h"

#include "midi/midi.h"

#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t cc_knob_factory_data[6] PROGMEM = {
  63, 0, 0, 7, 0, 127
};

/* static */
uint8_t CcKnob::value_;

/* static */
uint8_t CcKnob::channel_;

/* static */
uint8_t CcKnob::type_;

/* static */
uint8_t CcKnob::number_;

/* static */
uint8_t CcKnob::min_;

/* static */
uint8_t CcKnob::max_;

/* static */
const prog_AppInfo CcKnob::app_info_ PROGMEM = {
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
  NULL, // uint8_t (*OnSwitch)(uint8_t);
#else
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  &SetParameter, // void (*SetParameter)(uint8_t, uint8_t);
  &GetParameter, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  6, // settings_size
  SETTINGS_CC_KNOB, // settings_offset
  &value_, // settings_data
  cc_knob_factory_data, // factory_data
  STR_RES_CC_KNOB, // app_name
  true
};

/* static */
void CcKnob::OnInit() {
  ui.AddPage(STR_RES_VAL, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_TYP, STR_RES_CC_, 0, 1);
  ui.AddPage(STR_RES_NUM, UNIT_INTEGER, 0, 255);
  ui.AddPage(STR_RES_MIN, UNIT_INTEGER, 0, 255);
  ui.AddPage(STR_RES_MAX, UNIT_INTEGER, 0, 255);
}

/* static */
void CcKnob::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  app.Send(status, data, data_size);
}

/* static */
void CcKnob::SetParameter(uint8_t key, uint8_t value) {
  uint8_t previous_value = value_;
  static_cast<uint8_t*>(&value_)[key] = value;
  if (type_ == 0) {
    // Extended range not supported by CC.
    if (min_ > 127) {
      min_ = 127;
    }
    if (max_ > 127) {
      max_ = 127;
    }
    if (number_ > 127) {
      number_ = 127;
    }
  }
  value_ = Clip(value_, min_, max_);
  if (value_ != previous_value) {
    if (type_ == 0) {
      app.Send3(0xb0 | channel_, number_ & 0x7f, value_ & 0x7f);
    } else {
      app.Send3(0xb0 | channel_, midi::kNrpnMsb, number_ > 127);
      app.Send3(0xb0 | channel_, midi::kNrpnLsb, number_ & 0x7f);
      app.Send3(0xb0 | channel_, midi::kDataEntryMsb, value_ > 127);
      app.Send3(0xb0 | channel_, midi::kDataEntryLsb, value_ & 0x7f);
    }
  }
}

/* static */
uint8_t CcKnob::GetParameter(uint8_t key) {
  if (key == 0) {
    return Clip(value_, min_, max_);
  } else {
    return static_cast<uint8_t*>(&value_)[key];
  }
}

} }  // namespace midipal::apps
