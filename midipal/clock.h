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
  static inline void Reset() {
    clock_ = 0;
  }
  
  static inline void Start() {
    Reset();
    running_ = 1;
    tick_count_ = 0;
    step_count_ = 0;
    tick_duration_ = tick_duration_table_[0];
  }
  
  static inline void Stop() {
    running_ = 0;
  }

  static inline uint8_t Tick() {
    ++clock_;
    uint8_t result = 0;
    if (running_ && static_cast<uint16_t>(clock_) == tick_duration_) {
      clock_ = 0;
      ++tick_count_;
      result |= 1;
      if (tick_count_ == kNumTicksPerStep) {
        tick_count_ = 0;
        result |= 2;
        ++step_count_;
        if (step_count_ == kNumStepsInGroovePattern) {
          result |= 4;
          step_count_ = 0;
        }
        tick_duration_ = tick_duration_table_[step_count_];
      }
    }
    return result;
  }

  static uint32_t value() {
    return clock_;
  }
  
  static uint8_t tick() {
    return tick_count_;
  }

  static uint8_t step() {
    return step_count_;
  }
  
  static void Update(
      uint8_t bpm,
      uint8_t groove_template,
      uint8_t groove_amount);

 private:
  static uint8_t running_;
  static uint32_t clock_;
  static uint16_t tick_duration_table_[kNumStepsInGroovePattern];
  static uint16_t tick_duration_;
  static uint8_t tick_count_;
  static uint8_t step_count_;
};

extern Clock clock;

}  // namespace midipal

#endif // MIDIPAL_CLOCK_H_
