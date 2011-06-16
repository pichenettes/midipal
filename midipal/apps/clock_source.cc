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
// MIDI clock generator app.

#include "midipal/apps/clock_source.h"

#include "avrlib/string.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

void ClockSource::OnInit() {
  ui.AddPage(STR_RES_RUN, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_BPM, UNIT_INTEGER, 40, 240);
  ui.AddPage(STR_RES_GRV, STR_RES_SWG, 0, 5);
  ui.AddPage(STR_RES_AMT, UNIT_INTEGER, 0, 127);
  clock.Update(bpm_, groove_template_, groove_amount_);
  running_ = 0;
}

void ClockSource::OnRawByte(uint8_t byte) {
  uint8_t is_realtime = (byte & 0xf0) == 0xf0;
  uint8_t is_sysex = (byte == 0xf7) || (byte == 0xf0);
  if (!is_realtime || is_sysex) {
    SendNow(byte);
  }
}

void ClockSource::SetParameter(uint8_t key, uint8_t value) {
  if (key == 0) {
    if (value == 1) {
      Start();
    } else {
      Stop();
    }
  }
  static_cast<uint8_t*>(&running_)[key] = value;
  clock.Update(bpm_, groove_template_, groove_amount_);
}

void ClockSource::OnStart() {
  Start();
}

void ClockSource::OnStop() {
  Stop();
}

void ClockSource::OnContinue() {
  Start();
}

void ClockSource::OnInternalClockTick() {
  SendNow(0xf8);
}

void ClockSource::Stop() {
  if (running_) {
    clock.Stop();
    SendNow(0xfc);
    running_ = 0;
  }
}

void ClockSource::Start() {
  if (!running_) {
    clock.Start();
    SendNow(0xfa);
    running_ = 1;
  }
}

} }  // namespace midipal::plugins
