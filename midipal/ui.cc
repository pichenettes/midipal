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
// Multi data structure.

#include "midipal/ui.h"
#include "midipal/display.h"

namespace midipal {

/* <static> */
RotaryEncoder<EncoderALine, EncoderBLine, EncoderClickLine> Ui::encoder_;
EventQueue<32> Ui::queue_;
/* </static> */

/* extern */
Ui ui;

/* static */
void Ui::Init() {
  encoder_.Init();
}

/* static */
void Ui::Poll() {
  int8_t increment = encoder_.Read();
  if (increment != 0) {
    queue_.AddEvent(CONTROL_ENCODER, 0, increment);
  }
  if (encoder_.clicked()) {
    queue_.AddEvent(CONTROL_ENCODER_CLICK, 0, 1);
  }
}

/* static */
void Ui::DoEvents() {
  while (queue_.available()) {
    Event e = queue_.PullEvent();
    if (e.control_type == CONTROL_ENCODER) {
      if (e.value == 1) {
        display.Print(0, "encoder+");
      } else {
        display.Print(0, "encoder-");
      }
    } else if (e.control_type == CONTROL_ENCODER_CLICK) {
      display.Print(0, "switch   ");
    }
  }
}

}  // namespace midipal
