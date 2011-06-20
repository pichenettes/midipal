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

#ifndef MIDIPAL_APPS_CC_KNOB_H_
#define MIDIPAL_APPS_CC_KNOB_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class CcKnob : public App {
 public:
  CcKnob() { }

  void OnInit();
  void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  
  void SetParameter(uint8_t key, uint8_t value);
  uint8_t GetParameter(uint8_t key);
  
  uint8_t settings_size() { return 6; }
  uint16_t settings_offset() { return SETTINGS_CC_KNOB; }
  uint8_t* settings_data() { return &value_; }
  const prog_uint8_t* factory_data();
  uint8_t app_name() { return STR_RES_CC_KNOB; }
  
 private:
  uint8_t value_;
  uint8_t channel_;
  uint8_t type_;
  uint8_t number_;
  uint8_t min_;
  uint8_t max_;
  
  DISALLOW_COPY_AND_ASSIGN(CcKnob);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_CC_KNOB_H_
