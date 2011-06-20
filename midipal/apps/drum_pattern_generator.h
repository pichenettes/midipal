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
// Drum pattern generator app.

#ifndef MIDIPAL_APPS_DRUM_PATTERN_GENERATOR_H_
#define MIDIPAL_APPS_DRUM_PATTERN_GENERATOR_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

const uint8_t kNumDrumParts = 4;

class DrumPatternGenerator : public App {
 public:
  DrumPatternGenerator() { }

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
  uint16_t settings_offset() { return SETTINGS_DRUM_PATTERN_GENERATOR; }
  uint8_t* settings_data() { return &mode_; }
  const prog_uint8_t* factory_data();
  uint8_t app_name() { return STR_RES_DRUMS; }

 private:
  void Reset();
  void Tick();
  void AllNotesOff();
  void TriggerNote(uint8_t part);
  
  uint8_t running_;
   
  uint8_t mode_;
  uint8_t clk_mode_;
  uint8_t bpm_;
  uint8_t groove_template_;
  uint8_t groove_amount_;
  uint8_t channel_;
  uint8_t part_instrument_[kNumDrumParts];
  
  uint8_t tick_;
  uint8_t idle_ticks_;
  
  uint8_t active_note_[kNumDrumParts];
  
  uint8_t euclidian_num_notes_[kNumDrumParts];
  uint8_t euclidian_num_steps_[kNumDrumParts];
  uint8_t euclidian_step_count_[kNumDrumParts];
  uint16_t euclidian_bitmask_[kNumDrumParts];
  
  uint8_t active_pattern_[kNumDrumParts];
  uint8_t step_count_;
  uint16_t bitmask_;
  
  DISALLOW_COPY_AND_ASSIGN(DrumPatternGenerator);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_DRUM_PATTERN_GENERATOR_H_
