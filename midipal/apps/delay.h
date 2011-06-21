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

class Delay : public App {
 public:
  Delay() { }

  void OnInit();
  void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);

  void OnContinue();
  void OnStart();
  void OnStop();
  void OnClock();
  void OnInternalClockTick();

  void SetParameter(uint8_t key, uint8_t value);
  
  uint8_t settings_size() { return 10; }
  uint16_t settings_offset() { return SETTINGS_DELAY; }
  uint8_t* settings_data() { return &clk_mode_; }
  const prog_uint8_t* factory_data();
  uint8_t app_name() { return STR_RES_DELAY; }

 protected:
  void ScheduleEchoes(uint8_t note, uint8_t velocity, uint8_t num_taps);
  void SendEchoes();
  
  uint8_t running_;
   
  uint8_t clk_mode_;
  uint8_t bpm_;
  uint8_t groove_template_;
  uint8_t groove_amount_;
  uint8_t channel_;
  uint8_t delay_;
  uint8_t num_taps_;
  uint8_t velocity_factor_;
  int8_t transposition_;
  int8_t doppler_;

  uint8_t velocity_factor_reverse_log_;
  
  DISALLOW_COPY_AND_ASSIGN(Delay);
};

} }  // namespace midipal::apps

#endif  // MIDIPAL_APPS_DELAY_H_
