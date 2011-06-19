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
// Sequencer app.

#ifndef MIDIPAL_APPS_SEQUENCER_H_
#define MIDIPAL_APPS_SEQUENCER_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

static const uint8_t kNumBytesPerStep = 4;

class Sequencer : public App {
 public:
  Sequencer() { }

  void OnInit();
  void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  
  void OnInternalClockTick();
  void OnContinue();
  void OnStart();
  void OnStop();
  void OnClock();
  
  void SetParameter(uint8_t key, uint8_t value);
  uint8_t CheckPageStatus(uint8_t index);
  
  uint8_t settings_size() { return 13 + 32 * kNumBytesPerStep; }
  uint16_t settings_offset() { return SETTINGS_SEQUENCER; }
  uint8_t* settings_data() { return &running_; }
  uint8_t app_name() { return STR_RES_SEQUENCR; }

 private:
  void Stop();
  void Start();
  void Tick();
  
  uint8_t running_;
  uint8_t clk_mode_;
  uint8_t bpm_;
  uint8_t groove_template_;
  uint8_t groove_amount_;
  uint8_t clock_division_;  
  uint8_t channel_;
  uint8_t cc_number_;
  uint8_t note_track_;
  uint8_t duration_track_;
  uint8_t velocity_track_;
  uint8_t cc_track_;
  uint8_t num_steps_;
  uint8_t sequence_data_[32 * kNumBytesPerStep];
  
  uint8_t midi_clock_prescaler_;
  uint8_t tick_;
  uint8_t step_;
  uint8_t root_note_;
  uint8_t last_note_;
  
  DISALLOW_COPY_AND_ASSIGN(Sequencer);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_SEQUENCER_H_
