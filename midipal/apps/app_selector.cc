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
// Setup app.

#include "midipal/apps/app_selector.h"

#include "avrlib/string.h"
#include "avrlib/watchdog_timer.h"

#include "midi/midi.h"

#include "midipal/display.h"
#include "midipal/sysex_handler.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

/* static */
uint8_t AppSelector::active_app_;

/* static */
uint8_t AppSelector::selected_item_;

/* static */
const prog_AppInfo AppSelector::app_info_ PROGMEM = {
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
  NULL, // void (*OnInternalClockStep)();
  &OnIncrement, // uint8_t (*OnIncrement)(int8_t);
  &OnClick, // uint8_t (*OnClick)();
#ifdef MIDIBUD_FIRMWARE
  NULL, // uint8_t (*OnSwitch)(uint8_t);
#else
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  &OnRedraw, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  NULL, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  1, // settings_size
  SETTINGS_APP_SELECTOR, // settings_offset
  &active_app_, // settings_data
  0, // factory_data
  0, // app_name
  true
};

/* static */
void AppSelector::OnInit() {
  selected_item_ = active_app_;
  if (selected_item_ == 0) {
    selected_item_ = 1;
  }
}

/* static */
void AppSelector::OnRawByte(uint8_t byte) {
  app.SendNow(byte);
}

/* static */
uint8_t AppSelector::OnClick() {
  if (selected_item_ == app.num_apps()) {
    // Note nuke.
    for (uint8_t i = 0; i < 16; ++i) {
      for (uint8_t j = 0; j < 128; ++j) {
        app.Send3(0x80 | i, j, 0);
      }
    }
    return 1;
  } else if (selected_item_ == app.num_apps() + 1) {
    // Backup
    sysex_handler.SendBlock(0, 0);
  } else if (selected_item_ == app.num_apps() + 2) {
    // Factory reset.
    for (uint8_t i = 1; i < app.num_apps(); ++i) {
      app.Launch(i);
      app.ResetToFactorySettings();
    }
    app.Launch(0);
    active_app_ = 0;
  } else {
    active_app_ = selected_item_;    
  }
  app.SaveSettings();
  SystemReset(100);
  return 1;
}

/* static */
uint8_t AppSelector::OnIncrement(int8_t increment) {
  selected_item_ += increment;
  if (selected_item_ < 1) {
    selected_item_ = 1;
  } else if (selected_item_ > app.num_apps() + 3) {
    selected_item_ = app.num_apps() + 3;
  }
  return 1;
}

/* static */
uint8_t AppSelector::OnRedraw() {
  ui.Clear();
  if (selected_item_ >= app.num_apps()) {
    ResourcesManager::LoadStringResource(
        STR_RES_NOTENUKE + selected_item_ - app.num_apps(),
        &line_buffer[0], 8);
  } else {
    app.Launch(selected_item_);
    ResourcesManager::LoadStringResource(
        app.app_name(),
        &line_buffer[0], 8);
  }
  app.Launch(0);
  AlignLeft(&line_buffer[0], 8);
  ui.RefreshScreen();
  return 1;
}

} }  // namespace midipal::apps
