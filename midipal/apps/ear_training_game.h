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
// Ear Training Game app.

#ifndef MIDIPAL_EAR_TRAINING_GAME_H_
#define MIDIPAL_EAR_TRAINING_GAME_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

const uint8_t kMaxNotes = 4;

class EarTrainingGame {
 public:
  EarTrainingGame() { }

  static void OnInit();
  static void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  static void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  
  static void OnInternalClockStep();
  static uint8_t OnRedraw();
  static uint8_t OnClick();
  static uint8_t OnIncrement(int8_t value);
  
  static const prog_AppInfo app_info_;
  
 private:
  static void GenerateChallenge();
  static void StartChallenge();
  
  static uint8_t level_;
  static uint8_t num_notes_;
  static uint8_t confirm_reset_;
  static uint16_t num_games_;
  static uint16_t num_attempts_;
  
  static uint8_t step_counter_;
  static uint8_t played_notes_[kMaxNotes];
  static uint8_t recorded_notes_[kMaxNotes];
  static uint8_t record_ptr_;
  static uint8_t play_ptr_;
  static uint8_t wait_;
  static uint8_t attempts_;
  static uint8_t new_challenge_;
  static uint8_t show_score_;

  static uint8_t seeded_;
  
  DISALLOW_COPY_AND_ASSIGN(EarTrainingGame);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_EAR_TRAINING_GAME_H_
