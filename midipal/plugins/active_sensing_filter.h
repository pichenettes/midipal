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

#ifndef MIDIPAL_PLUGINS_ACTIVE_SENSING_FILTER_H_
#define MIDIPAL_PLUGINS_ACTIVE_SENSING_FILTER_H_

#include "midipal/plugin.h"

namespace midipal { namespace plugins {

class ActiveSensingFilter : public PlugIn {
 public:
  ActiveSensingFilter() : enabled_(0), editing_(0) { }

  virtual void OnLoad();

  virtual void OnRawByte(uint8_t byte);
  virtual void OnIncrement(int8_t increment);
  virtual void OnClick();
  
 private:
  uint8_t enabled_;
  uint8_t editing_;
  DISALLOW_COPY_AND_ASSIGN(ActiveSensingFilter);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_ACTIVE_SENSING_FILTER_H_
