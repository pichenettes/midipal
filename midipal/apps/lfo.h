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
// CC LFO app.

#ifndef MIDIPAL_APPS_LFO_H_
#define MIDIPAL_APPS_LFO_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

enum LfoSyncMode {
  LFO_SYNC_FREE_RUNNING,
  LFO_SYNC_NOTE_ON,
  LFO_SYNC_START
};

struct LfoData {
  uint8_t cc_number;
  uint8_t amount;
  uint8_t center_value;
  uint8_t waveform;
  uint8_t cycle_duration;
  uint8_t sync_mode;
};

const uint8_t kNumLfos = 4;

class Lfo : public App {
 public:
  Lfo() { }

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
  
  uint8_t settings_size() { return 7 + sizeof(LfoData) * kNumLfos; }
  uint16_t settings_offset() { return SETTINGS_LFO; }
  uint8_t* settings_data() { return &running_; }
  uint8_t app_name() { return STR_RES_CC_LFO; }

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
  
  LfoData lfo_data_[kNumLfos];

  uint16_t phase_[kNumLfos];
  uint16_t phase_increment_[kNumLfos];
  
  uint8_t tick_;
  uint8_t midi_clock_prescaler_;
  
  DISALLOW_COPY_AND_ASSIGN(Lfo);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_LFO_H_
