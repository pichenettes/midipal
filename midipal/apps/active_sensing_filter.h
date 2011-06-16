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

#ifndef MIDIPAL_PLUGINS_ACTIVE_SENSING_FILTER_H_
#define MIDIPAL_PLUGINS_ACTIVE_SENSING_FILTER_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class ActiveSensingFilter : public App {
 public:
  ActiveSensingFilter() { }

  void OnInit();
  void OnRawByte(uint8_t byte);
  
  uint8_t settings_size() { return 1; }
  uint8_t settings_offset() { return SETTINGS_0XFE_FILTER; }
  uint8_t* settings_data() { return &enabled_; }
  
 private:
  uint8_t enabled_;
  DISALLOW_COPY_AND_ASSIGN(ActiveSensingFilter);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_ACTIVE_SENSING_FILTER_H_
