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
// Active Sensing filter plug-in.

#include "midipal/plugins/active_sensing_filter.h"

#include "midipal/resources.h"
#include "midipal/ui.h"

namespace midipal { namespace plugins {

void ActiveSensingFilter::OnLoad() {
  enabled_ = LoadSetting(SETTING_0XFE_FILTER_ENABLED) != 0;
  ui.AddPage(STR_RES_FLT, STR_RES_OFF, 0, 1);
}

void ActiveSensingFilter::OnRawByte(uint8_t byte) {
  if (byte != 0xfe || !enabled_) {
    SendNow(byte);
  }
}

void ActiveSensingFilter::SetParameter(uint8_t key, uint8_t value) {
  enabled_ = value;
  SaveSetting(SETTING_0XFE_FILTER_ENABLED, enabled_);
}

uint8_t ActiveSensingFilter::GetParameter(uint8_t key) {
  return enabled_;
}

} }  // namespace midipal::plugins
