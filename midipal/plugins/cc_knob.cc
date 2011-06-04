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
// MIDI clock generator plug-in.

#include "midipal/plugins/cc_knob.h"

#include "midipal/resources.h"
#include "midipal/ui.h"

namespace midipal { namespace plugins {

using namespace avrlib;

void CcKnob::OnLoad() {
  value_ = LoadSetting(SETTING_CC_KNOB_VALUE);
  channel_ = LoadSetting(SETTING_CC_KNOB_CHANNEL);
  cc_ = LoadSetting(SETTING_CC_KNOB_CC);
  min_ = LoadSetting(SETTING_CC_KNOB_MIN);
  max_ = LoadSetting(SETTING_CC_KNOB_MAX);
  ui.AddPage(STR_RES_VAL, 0, 0, 127);
  ui.AddPage(STR_RES_CHN, 0, 1, 16);
  ui.AddPage(STR_RES_CC_, 0, 0, 127);
  ui.AddPage(STR_RES_MIN, 0, 0, 127);
  ui.AddPage(STR_RES_MAX, 0, 0, 127);
}

void CcKnob::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  Send(status, data, data_size);
}

void CcKnob::SetParameter(uint8_t key, uint8_t value) {
  uint8_t previous_value = value_;
  static_cast<uint8_t*>(&value_)[key] = value;
  value_ = Clip(value_, min_, max_);
  if (value_ != previous_value) {
    Send3(0xb0 | (channel_ - 1), cc_, value_);
  }
  SaveSetting(SETTING_CC_KNOB_VALUE + key, value);
}

uint8_t CcKnob::GetParameter(uint8_t key) {
  if (key == 0) {
    return Clip(value_, min_, max_);
  } else {
    return static_cast<uint8_t*>(&value_)[key];
  }
}

} }  // namespace midipal::plugins
