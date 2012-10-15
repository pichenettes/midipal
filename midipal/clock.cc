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

#include "midipal/clock.h"

#include "midipal/resources.h"

namespace midipal {

Clock clock;

/* <static> */
bool Clock::running_;
uint32_t Clock::clock_;
uint16_t Clock::intervals_[kNumStepsInGroovePattern];
uint16_t Clock::interval_;
uint8_t Clock::tick_count_;
uint8_t Clock::step_count_;
/* </static> */

/* static */
void Clock::Update(
    uint16_t bpm,
    uint8_t bpm_tenth,
    uint8_t groove_template,
    uint8_t groove_amount) {
  int32_t base_tick_duration = 7812500 / \
      (static_cast<uint32_t>(bpm) * 10 + bpm_tenth) - 1;
  for (uint8_t i = 0; i < kNumStepsInGroovePattern; ++i) {
    int32_t swing_direction = ResourcesManager::Lookup<int16_t, uint8_t>(
          LUT_RES_GROOVE_SWING + groove_template, i);
    swing_direction *= base_tick_duration;
    swing_direction *= groove_amount;
    intervals_[i] = base_tick_duration + (swing_direction >> 16);
  }
}

/* static */
void Clock::UpdateFractional(
    uint16_t bpm,
    uint8_t multiplier,
    uint8_t divider,
    uint8_t groove_template,
    uint8_t groove_amount) {
  int32_t base_tick_duration = (781250L * divider) / \
      (static_cast<uint32_t>(bpm) * multiplier) - 1;
  for (uint8_t i = 0; i < kNumStepsInGroovePattern; ++i) {
    int32_t swing_direction = ResourcesManager::Lookup<int16_t, uint8_t>(
          LUT_RES_GROOVE_SWING + groove_template, i);
    swing_direction *= base_tick_duration;
    swing_direction *= groove_amount;
    intervals_[i] = base_tick_duration + (swing_direction >> 16);
  }
}

}  // namespace midipal
