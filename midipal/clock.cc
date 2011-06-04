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
// Instance of the display class, configured for the Shruti-1 project.

#include "midipal/clock.h"

#include "midipal/resources.h"

namespace midipal {

Clock clock;

/* <static> */
uint32_t Clock::clock_;
uint16_t Clock::tick_duration_table_[kNumStepsInGroovePattern];
uint8_t Clock::running_;
uint8_t Clock::tick_count_;
uint8_t Clock::step_count_;
uint16_t Clock::tick_duration_ = 0;
/* </static> */

/* static */
void Clock::Update(
    uint8_t bpm,
    uint8_t groove_template,
    uint8_t groove_amount) {
  const int32_t kTempoFactor = (2 * 78125 * 60L / 24);
  int16_t base_tick_duration = kTempoFactor / (2 * static_cast<int32_t>(bpm));
  for (uint8_t i = 0; i < kNumStepsInGroovePattern; ++i) {
    int32_t swing_direction = ResourcesManager::Lookup<int16_t, uint8_t>(
        LUT_RES_GROOVE_SWING + groove_template, i);
    swing_direction *= base_tick_duration;
    swing_direction *= groove_amount;
    int16_t swing = swing_direction >> 16;
    tick_duration_table_[i] = base_tick_duration + swing;
  }
}

}  // namespace midipal
