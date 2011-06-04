// Copyright 2009 Olivier Gillet.
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
// Active Sensing filter plug-in.

#include "midipal/plugins/active_sensing_filter.h"
#include "midipal/resources.h"
#include "midipal/ui.h"

namespace midipal { namespace plugins {

using namespace avrlib;

void ActiveSensingFilter::OnLoad() {
  enabled_ = LoadSetting(SETTING_0XFE_FILTER_ENABLED) != 0;
  OnIncrement(0);  // Forces a screen refresh
}

void ActiveSensingFilter::OnRawByte(uint8_t byte) {
  if (byte != 0xfe || !enabled_) {
    SendNow(byte);
  }
}

void ActiveSensingFilter::OnIncrement(int8_t increment) {
  if (increment && editing_) {
    enabled_ ^= 1;
    SaveSetting(SETTING_0XFE_FILTER_ENABLED, enabled_);
  }
  ui.PrintKeyValuePair(STR_RES_FLT, STR_RES_OFF, enabled_, editing_);
  ui.Refresh();
}

void ActiveSensingFilter::OnClick() {
  editing_ ^= 1;
  OnIncrement(0);
}

} }  // namespace midipal::plugins
