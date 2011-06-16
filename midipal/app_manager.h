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
// Class responsible for switching between the various apps.

#ifndef MIDIPAL_PLUGIN_MANAGER_H_
#define MIDIPAL_PLUGIN_MANAGER_H_

#include "midipal/app.h"

namespace midipal {

class AppManager {
 public:
  AppManager() { }
  
  static void set_active_app(uint8_t index);
  static App* active_app() { return active_app_; }
  
 private:
  static App* active_app_;
  static uint8_t active_app_index_;
  
  DISALLOW_COPY_AND_ASSIGN(AppManager);
};

extern AppManager plugin_manager;

}  // namespace midipal

#endif // MIDIPAL_PLUGIN_MANAGER_H_
