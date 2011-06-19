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
// Scale processor app.

#include "midipal/apps/scale_processor.h"

#include "avrlib/random.h"

#include "midipal/display.h"

#include "midipal/clock.h"
#include "midipal/event_scheduler.h"
#include "midipal/note_stack.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {
  
using namespace avrlib;

void ScaleProcessor::OnInit() {
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_ROO, STR_RES_C, 0, 23);
  ui.AddPage(STR_RES_SCL, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_TRS, UNIT_SIGNED_INTEGER, -24, 24);
  ui.AddPage(STR_RES_PT1, UNIT_SIGNED_INTEGER, -24, 24);
  ui.AddPage(STR_RES_PT2, STR_RES_OFF_, 0, 4);
}

void ScaleProcessor::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  // Forward everything except note on for the selected channel.
  if (status != (0x80 | channel_) && 
      status != (0x90 | channel_) &&
      status != (0xa0 | channel_)) {
    Send(status, data, data_size);
  }
}

void ScaleProcessor::OnNoteOn(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  ProcessNoteMessage(0x90, note, velocity);
}

void ScaleProcessor::OnNoteOff(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  ProcessNoteMessage(0x80, note, velocity);
}

void ScaleProcessor::OnAftertouch(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  ProcessNoteMessage(0xa0, note, velocity);
}


void ScaleProcessor::ProcessNoteMessage(
    uint8_t message,
    uint8_t note,
    uint8_t velocity) {
  Send3(message | channel_, note, velocity);
}

} }  // namespace midipal::apps
