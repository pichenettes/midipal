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
// Channel merger app.

#include "midipal/apps/combiner.h"

#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t combiner_factory_data[3] PROGMEM = {
  0, 3, 0
};

/* static */
uint8_t Combiner::input_channel_;

/* static */
uint8_t Combiner::num_channels_;

/* static */
uint8_t Combiner::output_channel_;

/* static */
const prog_AppInfo Combiner::app_info_ PROGMEM = {
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
#ifdef MIDIBUD_FIRMWARE
  NULL, // uint8_t (*OnSwitch)(uint8_t);
#else
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  NULL, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  3, // settings_size
  SETTINGS_COMBINER, // settings_offset
  &input_channel_, // settings_data
  combiner_factory_data, // factory_data
  STR_RES_CHNMERGR, // app_name
  true
};

/* static */
void Combiner::OnInit() {
  ui.AddPage(STR_RES_INP, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_NUM, UNIT_INTEGER, 1, 16);
  ui.AddPage(STR_RES_OUT, UNIT_INDEX, 0, 15);
}

/* static */
void Combiner::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  uint8_t type = status & 0xf0;
  uint8_t channel = status & 0x0f;
  // Pass-through real time messages.
  if (type == 0xf0) {
    app.Send(status, data, data_size);
  } else {
    uint8_t in_range = channel >= input_channel_ && \
        channel < input_channel_ + num_channels_;
    in_range |= (channel + 0x10) >= input_channel_ && \
        (channel + 0x10) < input_channel_ + num_channels_;
    if (in_range) {
      channel = output_channel_;
    }
    app.Send(type | channel, data, data_size);
  }
}

} }  // namespace midipal::apps
