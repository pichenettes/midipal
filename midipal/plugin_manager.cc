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

#include "midipal/plugin_manager.h"

#include "midipal/plugins/active_sensing_filter.h"
#include "midipal/plugins/monitor.h"

namespace midipal {

plugins::Monitor monitor;
plugins::ActiveSensingFilter active_sensing_filter;

PlugIn* registry[] = {
  &monitor,
  &active_sensing_filter
};

/* extern */
PlugInManager plugin_manager;

/* static */
PlugIn* PlugInManager::active_plugin_;

/* static */
void PlugInManager::set_active_plugin(uint8_t index) {
  active_plugin_ = registry[index];
}

}  // namespace midipal
