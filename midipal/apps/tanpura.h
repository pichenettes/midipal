// Copyright 2012 Emilie Gillet.
//
// Author: Emilie Gillet (emilie.o.gillet@gmail.com)
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
// Tanpura app.

#ifndef MIDIPAL_APPS_TANPURA_H_
#define MIDIPAL_APPS_TANPURA_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class Tanpura {
 public:
  Tanpura() { }

  static void OnInit();
  static void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  static void OnNoteOn(uint8_t, uint8_t, uint8_t);
  static void OnContinue();
  static void OnStart();
  static void OnStop();
  static void OnClock(uint8_t clock_mode);
  
  static void SetParameter(uint8_t key, uint8_t value);
  
  static const prog_AppInfo app_info_;
  
 private:
  static void Stop();
  static void Start();
  static void Tick();
  
  static uint8_t running_;
  static uint8_t clk_mode_;
  static uint8_t bpm_;
  static uint8_t clock_division_;  
  static uint8_t channel_;
  static uint8_t root_;
  static uint8_t pattern_;
  static uint8_t shift_;
  
  static uint8_t midi_clock_prescaler_;
  static uint8_t tick_;
  static uint8_t step_;
  
  DISALLOW_COPY_AND_ASSIGN(Tanpura);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_TANPURA_H_
