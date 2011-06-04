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

#ifndef MIDIPAL_PLUGINS_CC_KNOB_
#define MIDIPAL_PLUGINS_CC_KNOB_

#include "midipal/plugin.h"

namespace midipal { namespace plugins {

class CcKnob : public PlugIn {
 public:
  CcKnob() { }

  virtual void OnLoad();
  virtual void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  
  virtual void SetParameter(uint8_t key, uint8_t value);
  virtual uint8_t GetParameter(uint8_t key);
  
 private:
  uint8_t value_;
  uint8_t channel_;
  uint8_t cc_;
  uint8_t min_;
  uint8_t max_;
  
  DISALLOW_COPY_AND_ASSIGN(CcKnob);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_CC_KNOB_
