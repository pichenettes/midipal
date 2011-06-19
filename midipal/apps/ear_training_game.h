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

class EarTrainingGame : public App {
 public:
  EarTrainingGame() { }

  void OnInit();
  void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  
  void OnInternalClockStep();
  uint8_t OnRedraw();
  uint8_t OnClick();
  uint8_t OnIncrement(int8_t value);
  
  uint8_t settings_size() { return 7; }
  uint16_t settings_offset() { return SETTINGS_EAR_TRAINING; }
  uint8_t* settings_data() { return &level_; }
  uint8_t app_name() { return STR_RES_EAR_GAME; }
  
 private:
  void GenerateChallenge();
  void StartChallenge();
  
  uint8_t level_;
  uint8_t num_notes_;
  uint8_t confirm_reset_;
  uint16_t num_games_;
  uint16_t num_attempts_;
  
  uint8_t step_counter_;
  uint8_t played_notes_[kMaxNotes];
  uint8_t recorded_notes_[kMaxNotes];
  uint8_t record_ptr_;
  uint8_t play_ptr_;
  uint8_t wait_;
  uint8_t attempts_;
  uint8_t new_challenge_;
  uint8_t show_score_;

  uint8_t seeded_;
  
  DISALLOW_COPY_AND_ASSIGN(EarTrainingGame);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_EAR_TRAINING_GAME_H_
