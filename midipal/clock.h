// Copyright 2009 Olivier Gillet.
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

#ifndef MIDIPAL_CLOCK_H_
#define MIDIPAL_CLOCK_H_

#include "avrlib/base.h"

namespace midipal {

class Clock {
 public:
  static inline void Reset() {
    clock_ = 0;    
  }

  static inline void Tick() {
    ++clock_;
  }

  static uint32_t value() {
    return clock_;
  }

 private:
  static uint32_t clock_;
};

extern Clock clock;

}  // namespace midipal

#endif // MIDIPAL_CLOCK_H_
