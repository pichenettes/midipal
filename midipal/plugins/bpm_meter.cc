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
// MIDI clock monitor plug-in.

#include "midipal/plugins/bpm_meter.h"

#include "avrlib/string.h"

#include "midipal/clock.h"
#include "midipal/resources.h"
#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace plugins {

using namespace avrlib;

void BpmMeter::OnLoad() {
  active_page_ = 0;
  refresh_bpm_ = 1;
  OnIdle();
  ui.Refresh();
}

void BpmMeter::Reset() {
  num_ticks_ = 0;
  clock_ = 0;
  clock.Reset();
}

void BpmMeter::OnClock() {
  if (num_ticks_ == 0) {
    clock.Reset();
  }
  clock_ = clock.value();
  ++num_ticks_;
}

void BpmMeter::OnStart() {
  Reset();
}

void BpmMeter::OnStop() {
  Reset();
}

void BpmMeter::OnContinue() {
  Reset();
}

void BpmMeter::OnClick() {
  Reset();
}

void BpmMeter::OnReset() {
  Reset();
}

void BpmMeter::PrintBpm() {
  line_buffer[0] = active_page_ == 1 ? 'B' : 'b';
  
  uint32_t num_ticks = num_ticks_;
  if (num_ticks) {
    --num_ticks;
  }
  uint32_t num = (78125 * 2 * 60 * 2 / 24 / 5) * num_ticks;
  uint32_t den = (2 * clock_ / 25);
  if (den == 0) {
    den = 1;
  }
  UnsafeItoa(num / den, 6, &line_buffer[2]);
  AlignRight(&line_buffer[2], 6);
  // A dirty hack to get the decimal display.
  if (line_buffer[6] == ' ') {
    line_buffer[6] = '0';
  }
  for (uint8_t i = 0; i < 5; ++i) {
    line_buffer[i + 1] = line_buffer[i + 2];
  }
  line_buffer[6] = '.';
}

void BpmMeter::OnIdle() {
  if (active_page_ < 2) {
    if (refresh_bpm_ || active_page_ == 1) {
      PrintBpm();
      ui.Refresh();
      if (active_page_ == 0) {
        Reset();
      }
    }
    refresh_bpm_ = \
        (active_page_ == 0 && clock.value() > 30000 && num_ticks_ > 48);
  } else {
    line_buffer[0] = 't';
    UnsafeItoa(num_ticks_, 7, &line_buffer[1]);
    AlignRight(&line_buffer[1], 7);
    ui.Refresh();
  }
}

void BpmMeter::OnIncrement(int8_t increment) {
  if (increment) {
    active_page_ = active_page_ + increment;
    if (active_page_ == -1) {
      active_page_ = 0;
    } else if (active_page_ > 2) {
      active_page_ = 2;
    }
  }
  refresh_bpm_ = 1;
  OnIdle();
  ui.Refresh();
}

} }  // namespace midipal::plugins
