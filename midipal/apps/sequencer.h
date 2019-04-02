// Copyright 2011 Emilie Gillet.
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
// Sequencer app.

#ifndef MIDIPAL_APPS_SEQUENCER_H_
#define MIDIPAL_APPS_SEQUENCER_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

static const uint8_t kNumBytesPerStep = 4;

class Sequencer {
 public:
  Sequencer() { }

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
  static void OnClock(uint8_t clock_mode);
  
  static void SetParameter(uint8_t key, uint8_t value);
  static uint8_t CheckPageStatus(uint8_t index);
  
  static const prog_AppInfo app_info_;
  
 private:
  static void Stop();
  static void Start();
  static void Tick();
  
  static uint8_t running_;
  static uint8_t clk_mode_;
  static uint8_t bpm_;
  static uint8_t groove_template_;
  static uint8_t groove_amount_;
  static uint8_t clock_division_;  
  static uint8_t channel_;
  static uint8_t cc_number_;
  static uint8_t note_track_;
  static uint8_t duration_track_;
  static uint8_t velocity_track_;
  static uint8_t cc_track_;
  static uint8_t num_steps_;
  static uint8_t sequence_data_[32 * kNumBytesPerStep];
  
  static uint8_t midi_clock_prescaler_;
  static uint8_t tick_;
  static uint8_t step_;
  static uint8_t root_note_;
  static uint8_t last_note_;
  
  DISALLOW_COPY_AND_ASSIGN(Sequencer);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_SEQUENCER_H_
