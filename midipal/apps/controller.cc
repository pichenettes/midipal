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
// Knob controller app.

#ifndef MIDIBUD_FIRMWARE

#include "midipal/apps/controller.h"

#include "midi/midi.h"

#include "midipal/ui.h"

namespace midipal { namespace apps {

const prog_uint8_t controller_factory_data[9] PROGMEM = {
  0, 7, 10, 74, 71, 73, 80, 72, 91
};

/* static */
uint8_t Controller::channel_;

/* static */
uint8_t Controller::cc_[8];

/* static */
const prog_AppInfo Controller::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  NULL, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnAftertouch)(uint8_t, uint8_t);
  NULL, // void (*OnControlChange)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnProgramChange)(uint8_t, uint8_t);
  NULL, // void (*OnPitchBend)(uint8_t, uint16_t);
  NULL, // void (*OnSysExByte)(uint8_t);
  NULL, // void (*OnClock)();
  NULL, // void (*OnStart)();
  NULL, // void (*OnContinue)();
  NULL, // void (*OnStop)();
  NULL, // uint8_t (*CheckChannel)(uint8_t);
  NULL, // void (*OnRawByte)(uint8_t);
  &OnRawMidiData, // void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t);
  NULL, // void (*OnInternalClockTick)();
  NULL, // void (*OnInternalClockStep)();
  NULL, // uint8_t (*OnIncrement)(int8_t);
  NULL, // uint8_t (*OnClick)();
  &OnPot, // uint8_t (*OnPot)(uint8_t, uint8_t);
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  NULL, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  9, // settings_size
  SETTINGS_CONTROLLER, // settings_offset
  &channel_, // settings_data
  controller_factory_data, // factory_data
  STR_RES_CONTRLLR, // app_name
  true
};

/* static */
void Controller::OnInit() {
  ui.set_read_pots(1);
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  for (uint8_t i = 0; i < 8; ++i) {
    ui.AddPage(STR_RES_CC1 + i, UNIT_INTEGER, 0, 127);
  }
}

/* static */
void Controller::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  app.Send(status, data, data_size);
}

/* static */
uint8_t Controller::OnPot(uint8_t pot, uint8_t value) {
  app.Send3(0xb0 | channel_, cc_[pot], value);
}

} }  // namespace midipal::apps

#endif // #ifndef MIDIBUD_FIRMWARE
