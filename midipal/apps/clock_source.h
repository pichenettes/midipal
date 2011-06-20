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

#ifndef MIDIPAL_APPS_CLOCK_SOURCE_H_
#define MIDIPAL_APPS_CLOCK_SOURCE_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class ClockSource : public App {
 public:
  ClockSource() { }

  void OnInit();
  void OnStart();
  void OnStop();
  void OnContinue();
  void OnRawByte(uint8_t byte);
  
  void SetParameter(uint8_t key, uint8_t value);
  
  void OnInternalClockTick();
  
  uint8_t settings_size() { return 4; }
  uint16_t settings_offset() { return SETTINGS_CLOCK_SOURCE; }
  uint8_t* settings_data() { return &running_; }
  const prog_uint8_t* factory_data();
  uint8_t app_name() { return STR_RES_CLOCK; }

 private:
  void UpdateCursor();
  void Stop();
  void Start();
  
  uint8_t running_;
  uint8_t bpm_;
  uint8_t groove_template_;
  uint8_t groove_amount_;
  
  DISALLOW_COPY_AND_ASSIGN(ClockSource);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_CLOCK_SOURCE_H_
