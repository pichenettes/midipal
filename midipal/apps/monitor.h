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
// MIDI monitor app.

#ifndef MIDIPAL_APPS_MONITOR_H_
#define MIDIPAL_APPS_MONITOR_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class Monitor {
 public:
  Monitor() { }

  static void OnInit();

  static void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  static void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  static void OnNoteAftertouch(uint8_t channel, uint8_t note, uint8_t velocity);
  static void OnAftertouch(uint8_t channel, uint8_t velocity);
  static void OnControlChange(uint8_t channel, uint8_t controller,
    uint8_t value);
  static void OnProgramChange(uint8_t channel, uint8_t program);
  static void OnPitchBend(uint8_t channel, uint16_t pitch_bend);

  static void OnAllSoundOff(uint8_t channel);
  static void OnResetAllControllers(uint8_t channel);
  static void OnLocalControl(uint8_t channel, uint8_t state);
  static void OnAllNotesOff(uint8_t channel);
  static void OnOmniModeOff(uint8_t channel);
  static void OnOmniModeOn(uint8_t channel);
  static void OnMonoModeOn(uint8_t channel, uint8_t num_channels);
  static void OnPolyModeOn(uint8_t channel);
  static void OnSysExByte(uint8_t sysex_byte);

  static void OnClock();
  static void OnStart();
  static void OnContinue();
  static void OnStop();
  static void OnRawByte(uint8_t byte);

  static uint8_t CheckChannel(uint8_t channel);
     
  static uint8_t OnRedraw();
  static uint8_t OnClick();
  
  static void OnIdle();
  
  static const prog_AppInfo app_info_;
  
 private:
  static void PrintString(uint8_t channel, uint8_t res_id);
  
  static uint8_t monitored_channel_;
  static uint8_t idle_counter_;
  
  DISALLOW_COPY_AND_ASSIGN(Monitor);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_MONITOR_H_
