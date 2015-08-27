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
// Clock divider app.

#include "midipal/apps/clock_divider.h"

#include "midipal/ui.h"

namespace midipal { namespace apps {

const prog_uint8_t clock_divider_factory_data[2] PROGMEM = {
  1, 0,
};

/* static */
uint8_t ClockDivider::divider_;

/* static */
uint8_t ClockDivider::start_delay_;

/* static */
uint8_t ClockDivider::counter_;

/* static */
uint8_t ClockDivider::start_delay_counter_;

/* static */
bool ClockDivider::running_;


/* static */
const prog_AppInfo ClockDivider::app_info_ PROGMEM = {
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
  2, // settings_size
  SETTINGS_CLOCK_DIVIDER, // settings_offset
  &divider_, // settings_data
  clock_divider_factory_data, // factory_data
  STR_RES_DIVIDER, // app_name
  true
};  
  
/* static */
void ClockDivider::OnInit() {
  ui.AddPage(STR_RES_DIV, UNIT_INTEGER, 1, 32);
  ui.AddPage(STR_RES_DELAY, UNIT_INTEGER, 0, 96);
  counter_ = 0;
  start_delay_counter_ = 0;
  running_ = false;
}

/* static */
void ClockDivider::OnRawByte(uint8_t byte) {
  if (byte == 0xf8) {
    // Send a delayed START if necessary.
    if (start_delay_counter_) {
      --start_delay_counter_;
      if (!start_delay_counter_) {
        app.SendNow(0xfa);
        running_ = true;
      }
    }
    // Process clock message and divide it.
    if (running_) {
      ++counter_;
      if (counter_ >= divider_) {
        app.SendNow(0xf8);
        counter_ = 0;
      }
    }
  } else if (byte == 0xfa) {
    counter_ = divider_ - 1;
    start_delay_counter_ = start_delay_;
    if (!start_delay_counter_) {
      app.SendNow(0xfa);
      running_ = true;
    }
  } else {
    if (byte == 0xfc) {
      running_ = false;
    }
    app.SendNow(byte);
  }
}

} }  // namespace midipal::apps
