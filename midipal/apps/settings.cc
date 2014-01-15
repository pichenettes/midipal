// Copyright 2012 Peter Kvitek.
//
// Author: Peter Kvitek (pete@kvitek.com)
// Based on app code by Olivier Gillet (ol.gillet@gmail.com)
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
// Settings app.

#include "midipal/apps/settings.h"

#include "midi/midi.h"

#include "midipal/ui.h"

namespace midipal { namespace apps {

const prog_uint8_t settings_factory_data[5] PROGMEM = {
  0, 2, 0, 0, 12
};

/* static */
uint8_t Settings::filter_active_sensing_;

/* static */
uint8_t Settings::encoder_hold_threshold_;

/* static */
uint8_t Settings::remote_control_channel_;

/* static */
uint8_t Settings::note_clock_channel_;

/* static */
uint8_t Settings::note_clock_ticks_;

/* static */
const prog_AppInfo Settings::app_info_ PROGMEM = {
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
  &OnRawByte, // void (*OnRawByte)(uint8_t);
  NULL, // void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t);
  NULL, // void (*OnInternalClockTick)();
  NULL, // uint8_t (*OnIncrement)(int8_t);
  NULL, // uint8_t (*OnClick)();
#ifdef MIDIBUD_FIRMWARE
  NULL, // uint8_t (*OnSwitch)(uint8_t);
#else
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  5, // settings_size
  SETTINGS_SYSTEM_SETTINGS, // settings_offset
  &filter_active_sensing_, // settings_data
  settings_factory_data, // factory_data
  STR_RES_SETTINGS, // app_name
};  

/* static */
void Settings::OnInit() {
  ui.AddPage(STR_RES_XFE, STR_RES_LET, 0, 1);
  ui.AddPage(STR_RES_HLD, STR_RES__5S, 0, 2);
  ui.AddPage(STR_RES_CCC, UNIT_INTEGER, 0, 16);
  ui.AddPage(STR_RES_CLC, UNIT_INTEGER, 0, 16);
  ui.AddPage(STR_RES_DIV, STR_RES_2_1, 0, 16);
}

/* static */
void Settings::OnRawByte(uint8_t byte) {
  app.SendNow(byte);
}

/* static */
uint16_t Settings::encoder_hold_threshold() {
  // Return encoder hold threshold in 500us ticks for Ui::Poll() at 2Khz
  switch (encoder_hold_threshold_) {
    case 0: return  500 * 2;
    case 1: return 1000 * 2;
  }
  return 2000 * 2;
};

} }  // namespace midipal::apps