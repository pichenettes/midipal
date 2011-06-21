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
// Scale processor app.

#ifndef MIDIPAL_APPS_SCALE_PROCESSOR_H_
#define MIDIPAL_APPS_SCALE_PROCESSOR_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class ScaleProcessor : public App {
 public:
  ScaleProcessor() { }

  void OnInit();
  void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  void OnAftertouch(uint8_t channel, uint8_t note, uint8_t velocity);

  uint8_t settings_size() { return 6; }
  uint16_t settings_offset() { return SETTINGS_SCALE_PROCESSOR; }
  uint8_t* settings_data() { return &channel_; }
  const prog_uint8_t* factory_data();
  uint8_t app_name() { return STR_RES_SCALE; }

 protected:
  void ProcessNoteMessage(uint8_t message, uint8_t note, uint8_t velocity);
   
  uint8_t channel_;
  uint8_t root_;
  uint8_t scale_;
  uint8_t original_;
  uint8_t voice_1_;
  uint8_t voice_2_;
  
  uint8_t lowest_note_;
  uint8_t previous_note_;
  uint8_t voice_2_note_;
  uint8_t flip_;

  DISALLOW_COPY_AND_ASSIGN(ScaleProcessor);
};

} }  // namespace midipal::apps

#endif  // MIDIPAL_APPS_SCALE_PROCESSOR_H_
