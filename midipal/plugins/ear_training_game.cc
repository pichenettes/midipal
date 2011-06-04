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
// Ear Training Game plug-in.

#include "midipal/plugins/ear_training_game.h"

#include "avrlib/random.h"
#include "avrlib/string.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/resources.h"
#include "midipal/ui.h"

static const prog_uint8_t random_octave[8 * 5] PROGMEM = {
  48, 48, 48, 48, 48, 48, 48, 48,
  48, 48, 48, 48, 48, 48, 60, 60,
  48, 48, 48, 48, 60, 60, 60, 60,
  48, 48, 48, 60, 60, 60, 32, 32,
  36, 48, 60, 72, 36, 48, 60, 72
};

static const prog_uint8_t random_interval[16 * 5] PROGMEM = {
  0, 0, 0, 0, 5, 5, 5, 5, 7, 7, 7, 7, 12, 12, 12, 12,
  0, 0, 3, 3, 3, 4, 4, 4, 5, 5, 5, 7, 7, 7, 12, 12,
  0, 0, 3, 3, 4, 4, 5, 5, 7, 7, 9, 9, 10, 10, 12, 12,
  0, 2, 3, 4, 5, 7, 9, 10, 11, 12, 0, 3, 4, 5, 7, 11,
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 7, 5, 4,
};

static const prog_uint8_t random_sign[4 * 5] PROGMEM = {
  1, 1, 1, 1,
  1, 1, 1, -1,
  1, 1, -1, -1,
  1, 1, -1, -1,
  1, 1, -1, -1,
};

static const prog_uint8_t rank[16] PROGMEM = {
  0, 1, 1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, -6, -6, 195
};

namespace midipal { namespace plugins {

using namespace avrlib;

void EarTrainingGame::OnLoad() {
  level_ = LoadSetting(SETTING_EAR_TRAINING_LEVEL);
  num_notes_ = LoadSetting(SETTING_EAR_TRAINING_NUM_NOTES);
  ui.AddPage(STR_RES_LVL, 0, 1, 5);
  ui.AddPage(STR_RES_NUM, 0, 2, 4);
  ui.AddPage(STR_RES_RST, STR_RES_NO, 0, 1);
  GenerateChallenge();
  clock.Update(130, 0, 0);
  clock.Start();
  StartChallenge();
  seeded_ = 0;
  num_games_ = LoadSettingWord(SETTING_EAR_TRAINING_NUM_GAMES);
  num_attempts_ = LoadSettingWord(SETTING_EAR_TRAINING_NUM_ATTEMPTS);
  confirm_reset_ = 0;
}

void EarTrainingGame::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  Send(status, data, data_size);
  if (!seeded_) {
    Random::Seed(clock.value());
    seeded_ = 1;
  }
}



void EarTrainingGame::GenerateChallenge() {
  uint8_t root = Random::GetByte() & 0xf;
  root += ResourcesManager::Lookup<uint8_t, uint8_t>(
      random_octave, (Random::GetByte() & 0x07) + 8 * (level_ - 1));
  played_notes_[0] = root;
  for (uint8_t i = 1; i < 8; ++i) {
    int8_t interval = ResourcesManager::Lookup<int8_t, uint8_t>(
        random_interval, (Random::GetByte() & 0x0f) + 16 * (level_ - 1));
    int8_t sign = ResourcesManager::Lookup<int8_t, uint8_t>(
        random_sign, (Random::GetByte() & 0x03) + 4 * (level_ - 1));
    played_notes_[i] = root + interval * sign;
  }
  new_challenge_ = 1;
  if (attempts_) {
    ++num_games_;
    num_attempts_ += attempts_;
    SaveSettingWord(SETTING_EAR_TRAINING_NUM_GAMES, num_games_);
    SaveSettingWord(SETTING_EAR_TRAINING_NUM_ATTEMPTS, num_attempts_);
  }
}

void EarTrainingGame::StartChallenge() {
  play_ptr_ = 0;
  record_ptr_ = 0;
  step_counter_ = 0xff;
  if (new_challenge_) {
    attempts_ = 0;
  }
  new_challenge_ = 0;
}

void EarTrainingGame::OnInternalClockStep() {
  if (play_ptr_ < num_notes_) {
    step_counter_ = (step_counter_ + 1) & 0x3;
    if (step_counter_ == 0) {
      Send3(0x90, played_notes_[play_ptr_], 100);
    } else if (step_counter_ == 2) {
      Send3(0x80, played_notes_[play_ptr_], 0);
      ++play_ptr_;
    }
  } else {
    if (record_ptr_ == num_notes_) {
      --wait_;
      if (wait_ == 0) {
        StartChallenge();
      }
    }
  }
}

void EarTrainingGame::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (record_ptr_ < num_notes_) {
    recorded_notes_[record_ptr_] = note;
    ++record_ptr_;
    if (record_ptr_ == num_notes_) {
      uint8_t correct = 1;
      for (uint8_t i = 0; i < num_notes_; ++i) {
        if (recorded_notes_[i] != played_notes_[i]) {
          correct = 0;
          break;
        }
      }
      ++attempts_;
      show_score_ = 1;
      if (correct || attempts_ == 9) {
        GenerateChallenge();
      }
      wait_ = 8;
    }
  }
}

uint8_t EarTrainingGame::OnClick() {
  if (confirm_reset_ == 1) {
    confirm_reset_ = 0;
    show_score_ = 1;
    num_games_ = 0;
    num_attempts_ = 0;
    SaveSettingWord(SETTING_EAR_TRAINING_NUM_GAMES, 0);
    SaveSettingWord(SETTING_EAR_TRAINING_NUM_ATTEMPTS, 0);
  } else {
    show_score_ = 0;
  }
  return 0;
}

uint8_t EarTrainingGame::OnIncrement(int8_t value) {
  show_score_ = 0;
  return 0;
}

uint8_t EarTrainingGame::OnRedraw() {
  if (show_score_) {
    ui.Clear();
    
    if (wait_) {
      if (new_challenge_) {
        if (attempts_ == 1) {
          ui.PrintString(STR_RES_PERFECT_);
        } else if (attempts_ == 9) {
          ui.PrintString(STR_RES_SORRY___);
        } else {
          ui.PrintString(STR_RES_NOT_BAD_);
        }
      } else {
        line_buffer[0] = 't';
        line_buffer[1] = 'r';
        line_buffer[2] = 'y';
        line_buffer[5] = '1' + attempts_;
      }
    } else {
      uint32_t score = (num_attempts_ == 0)
          ? 100
          : num_games_ * 100 / num_attempts_;
      UnsafeItoa(score, 3, &line_buffer[0]);
      AlignRight(&line_buffer[0], 3);
      line_buffer[3] = '%';
      line_buffer[5] = '|';
      uint8_t log_num_attempts = 0;
      uint16_t n = num_attempts_;
      while (n) {
        ++log_num_attempts;
        n >>= 1;
      }
      line_buffer[7] = '0' + ResourcesManager::Lookup<uint8_t, uint8_t>(
          rank, log_num_attempts);
    }
    ui.RefreshScreen();
    return 1;
  } else {
    return 0;
  }
}


void EarTrainingGame::SetParameter(uint8_t key, uint8_t value) {
  static_cast<uint8_t*>(&level_)[key] = value;
  SaveSetting(SETTING_EAR_TRAINING_LEVEL + key, value);
}

uint8_t EarTrainingGame::GetParameter(uint8_t key) {
  return static_cast<uint8_t*>(&level_)[key];
}

} }  // namespace midipal::plugins
