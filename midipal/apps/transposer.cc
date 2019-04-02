// Copyright 2012 Emilie Gillet.
//
// Author: Emilie Gillet (emilie.o.gillet@gmail.com)
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
// Transposer app.

#include "midipal/apps/transposer.h"

#include "midipal/display.h"

#include "midipal/notes.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t transposer_factory_data[2] PROGMEM = {
  0, 0
};

/* <static> */
uint8_t Transposer::channel_;
int8_t Transposer::transposition_;
/* </static> */

/* static */
const prog_AppInfo Transposer::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  &OnNoteOn, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  &OnNoteOff, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  &OnNoteAftertouch, // void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
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
  NULL, // uint8_t (*OnIncrement)(int8_t);
  NULL, // uint8_t (*OnClick)();
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  2, // settings_size
  SETTINGS_SCALE_PROCESSOR, // settings_offset
  &channel_, // settings_data
  transposer_factory_data, // factory_data
  STR_RES_SCALE, // app_name
  true
};

/* static */
void Transposer::OnInit() {
  ui.AddPage(STR_RES_CHN, UNIT_INTEGER_ALL, 0, 16);
  ui.AddPage(STR_RES_TRS, UNIT_SIGNED_INTEGER, -24, 24);
}

/* static */
void Transposer::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  // Forward everything except note on for the selected channel.
  uint8_t kind = status & 0xf0;
  bool is_note = (kind == 0x80) || (kind == 0x90) || (kind == 0xa0);
  bool selected_channel = (channel_ == 0) || (((status & 0x0f) + 1) == channel_);
  if (!is_note || !selected_channel) {
    app.Send(status, data, data_size);
  }
}

/* static */
void Transposer::OnNoteOn(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  bool selected_channel = (channel_ == 0) || ((channel + 1) == channel_);
  if (!selected_channel) {
    return;
  }
  app.Send3(0x90 | channel, Transpose(note, transposition_), velocity);
}

/* static */
void Transposer::OnNoteOff(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  bool selected_channel = (channel_ == 0) || ((channel + 1) == channel_);
  if (!selected_channel) {
    return;
  }
  app.Send3(0x80 | channel, Transpose(note, transposition_), velocity);
}

/* static */
void Transposer::OnNoteAftertouch(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  bool selected_channel = (channel_ == 0) || ((channel + 1) == channel_);
  if (!selected_channel) {
    return;
  }
  app.Send3(0xa0 | channel, Transpose(note, transposition_), velocity);
}

} }  // namespace midipal::apps
