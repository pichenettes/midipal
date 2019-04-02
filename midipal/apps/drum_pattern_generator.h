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
// Drum pattern generator app.

#ifndef MIDIPAL_APPS_DRUM_PATTERN_GENERATOR_H_
#define MIDIPAL_APPS_DRUM_PATTERN_GENERATOR_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

const uint8_t kNumDrumParts = 4;

class DrumPatternGenerator {
 public:
  DrumPatternGenerator() { }

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
  
  static const prog_AppInfo app_info_;
  
 private:
  static void Reset();
  static void Tick();
  static void AllNotesOff();
  static void TriggerNote(uint8_t part);
  
  static uint8_t running_;
   
  static uint8_t mode_;
  static uint8_t clk_mode_;
  static uint8_t bpm_;
  static uint8_t groove_template_;
  static uint8_t groove_amount_;
  static uint8_t channel_;
  static uint8_t part_instrument_[kNumDrumParts];
  
  static uint8_t tick_;
  static uint8_t idle_ticks_;
  
  static uint8_t active_note_[kNumDrumParts];
  
  static uint8_t euclidian_num_notes_[kNumDrumParts];
  static uint8_t euclidian_num_steps_[kNumDrumParts];
  static uint8_t euclidian_step_count_[kNumDrumParts];
  static uint16_t euclidian_bitmask_[kNumDrumParts];
  
  static uint8_t active_pattern_[kNumDrumParts];
  static uint8_t step_count_;
  static uint16_t bitmask_;
  
  DISALLOW_COPY_AND_ASSIGN(DrumPatternGenerator);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_DRUM_PATTERN_GENERATOR_H_
