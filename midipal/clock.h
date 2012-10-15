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
// Global clock.

#ifndef MIDIPAL_CLOCK_H_
#define MIDIPAL_CLOCK_H_

#include "avrlib/base.h"

namespace midipal {

static const uint8_t kNumStepsInGroovePattern = 16;
static const uint8_t kNumTicksPerStep = 6;

class Clock {
 public:
  static inline void Init() {
    Update(120, 0, 0);
    tick_count_ = 0;
    step_count_ = 0;
    running_ = false;
  }
  static inline void Reset() {
    clock_ = 0;
  }
  
  static inline void Start() {
    Reset();
    running_ = true;
    tick_count_ = 0;
    step_count_ = 0;
    interval_ = intervals_[0];
  }
  
  static inline void Stop() {
    running_ = false;
  }
  
  static inline bool stepped() {
    return tick_count_ == 0;
  }

  static inline bool running() {
    return running_;
  }

  static inline uint16_t Tick() {
    clock_ += interval_ + 1;
    ++tick_count_;
    if (tick_count_ == kNumTicksPerStep) {
      tick_count_ = 0;
      ++step_count_;
      if (step_count_ == kNumStepsInGroovePattern) {
        step_count_ = 0;
      }
      interval_ = intervals_[step_count_];
    }
    return interval_;
  }
  
  static uint32_t value() {
    return clock_;
  }
  
  static void Update(
      uint16_t bpm,
      uint8_t groove_template,
      uint8_t groove_amount) {
    Update(bpm, 0, groove_template, groove_amount);
  }
  
  static void UpdateFractional(
      uint16_t bpm,
      uint8_t multiplier,
      uint8_t divider,
      uint8_t groove_template,
      uint8_t groove_amount);

  static void Update(
      uint16_t bpm,
      uint8_t bpm_10th,
      uint8_t groove_template,
      uint8_t groove_amount);

 private:
  static bool running_;
  static uint32_t clock_;  // Counts forever
  static uint16_t intervals_[kNumStepsInGroovePattern];
  static uint16_t interval_;
  static uint8_t tick_count_;
  static uint8_t step_count_;
};

extern Clock clock;

}  // namespace midipal

#endif // MIDIPAL_CLOCK_H_
