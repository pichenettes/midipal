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
// Base class implemented by all the "Plug-ins" running on the Midipal.

#ifndef MIDIPAL_PLUGIN_MANAGER_H_
#define MIDIPAL_PLUGIN_MANAGER_H_

#include "midipal/plugin.h"

namespace midipal {

class PlugInManager {
 public:
  PlugInManager() { }
  
  static void set_active_plugin(uint8_t index);
  static PlugIn* active_plugin() { return active_plugin_; }
  
 private:
  static PlugIn* active_plugin_;
  static uint8_t active_plugin_index_;
  
  DISALLOW_COPY_AND_ASSIGN(PlugInManager);
};

extern PlugInManager plugin_manager;

}  // namespace midipal

#endif // MIDIPAL_PLUGIN_MANAGER_H_
