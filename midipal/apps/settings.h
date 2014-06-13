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

#ifndef MIDIPAL_APPS_SETTINGS_H_
#define MIDIPAL_APPS_SETTINGS_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class Settings {
 public:
  Settings() { }

  static void OnInit();
  static void OnRawByte(uint8_t byte);
 
  static const prog_AppInfo app_info_;
 
  static uint8_t filter_active_sensing() { return filter_active_sensing_; }
  static uint8_t remote_control_channel() { return remote_control_channel_; }
  static uint8_t note_clock_channel() { return note_clock_channel_; }
  static uint8_t note_clock_note() { return note_clock_note_; }
  static uint8_t note_clock_ticks() { return note_clock_ticks_; }

 private:
  static uint8_t filter_active_sensing_;
  static uint8_t remote_control_channel_;
  static uint8_t note_clock_channel_;
  static uint8_t note_clock_note_;
  static uint8_t note_clock_ticks_;
  
  DISALLOW_COPY_AND_ASSIGN(Settings);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_SETTINGS_H_