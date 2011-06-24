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
// Delay app.

#ifndef MIDIPAL_APPS_DELAY_H_
#define MIDIPAL_APPS_DELAY_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class Delay {
 public:
  Delay() { }

  static void OnInit();
  static void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  static void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  static void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);

  static void OnContinue();
  static void OnStart();
  static void OnStop();
  static void OnClock();
  static void OnInternalClockTick();

  static void SetParameter(uint8_t key, uint8_t value);
  
  static const prog_AppInfo app_info_;

 protected:
  static void ScheduleEchoes(uint8_t note, uint8_t velocity, uint8_t num_taps);
  static void SendEchoes();
  
  static uint8_t running_;
   
  static uint8_t clk_mode_;
  static uint8_t bpm_;
  static uint8_t groove_template_;
  static uint8_t groove_amount_;
  static uint8_t channel_;
  static uint8_t delay_;
  static uint8_t num_taps_;
  static uint8_t velocity_factor_;
  static int8_t transposition_;
  static int8_t doppler_;

  static uint8_t velocity_factor_reverse_log_;
  
  DISALLOW_COPY_AND_ASSIGN(Delay);
};

} }  // namespace midipal::apps

#endif  // MIDIPAL_APPS_DELAY_H_
