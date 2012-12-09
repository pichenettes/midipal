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
// Channel filter app.

#include "midipal/apps/filter.h"

#include "midi/midi.h"

#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

const prog_uint8_t filter_factory_data[16] PROGMEM = {
  1, 0, 0, 0, 
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0
};

/* static */
uint8_t Filter::channel_enabled_[16];

/* static */
const prog_AppInfo Filter::app_info_ PROGMEM = {
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
  16, // settings_size
  SETTINGS_FILTER, // settings_offset
  channel_enabled_, // settings_data
  filter_factory_data, // factory_data
  STR_RES_CHNFILTR, // app_name
  true
};  

/* static */
void Filter::OnInit() {
  lcd.SetCustomCharMapRes(chr_res_digits_10, 7, 1);
  ui.AddRepeatedPage(UNIT_CHANNEL, STR_RES_OFF, 0, 1, 16);    
}

/* static */
void Filter::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  uint8_t type = status & 0xf0;
  if (type == 0xf0) {
    app.Send(status, data, data_size);
  } else {
    uint8_t channel = status & 0x0f;
    if (channel_enabled_[channel]) {
      app.Send(status, data, data_size);
    }
  }
}

} }  // namespace midipal::apps
