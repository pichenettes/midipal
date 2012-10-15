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

class ClockSource {
 public:
  ClockSource() { }

  static void OnInit();
  static void OnStart();
  static void OnStop();
  static void OnContinue();
  static void OnRawByte(uint8_t byte);
  
  static void SetParameter(uint8_t key, uint8_t value);
  static uint8_t GetParameter(uint8_t key);
  static uint8_t OnClick();
  static uint8_t OnIncrement(int8_t increment);
  
  static void OnInternalClockTick();
  
  static const prog_AppInfo app_info_;
  
 private:
  static void Stop();
  static void Start();
  
  static uint8_t running_;
  static uint8_t bpm_;
  static uint8_t groove_template_;
  static uint8_t groove_amount_;
  
  static uint8_t num_taps_;
  static uint32_t elapsed_time_;
  
  DISALLOW_COPY_AND_ASSIGN(ClockSource);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_CLOCK_SOURCE_H_
