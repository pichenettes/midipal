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
// MIDI monitor plug-in.

#ifndef MIDIPAL_PLUGINS_MONITOR_H_
#define MIDIPAL_PLUGINS_MONITOR_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class Monitor : public App {
 public:
  Monitor() { }

  void OnInit();

  void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  void OnAftertouch(uint8_t channel, uint8_t note, uint8_t velocity);
  void OnAftertouch(uint8_t channel, uint8_t velocity);
  void OnControlChange(uint8_t channel, uint8_t controller,
    uint8_t value);
  void OnProgramChange(uint8_t channel, uint8_t program);
  void OnPitchBend(uint8_t channel, uint16_t pitch_bend);

  void OnAllSoundOff(uint8_t channel);
  void OnResetAllControllers(uint8_t channel);
  void OnLocalControl(uint8_t channel, uint8_t state);
  void OnAllNotesOff(uint8_t channel);
  void OnOmniModeOff(uint8_t channel);
  void OnOmniModeOn(uint8_t channel);
  void OnMonoModeOn(uint8_t channel, uint8_t num_channels);
  void OnPolyModeOn(uint8_t channel);
  void OnSysExStart();
  void OnSysExByte(uint8_t sysex_byte);
  void OnSysExEnd();
  void OnBozoByte(uint8_t bozo_byte);

  void OnClock();
  void OnStart();
  void OnContinue();
  void OnStop();
  void OnActiveSensing();
  void OnReset();
  void OnRawByte(uint8_t byte);

  uint8_t CheckChannel(uint8_t channel);
     
  uint8_t OnRedraw();
  uint8_t OnClick();
  
 private:
  void PrintString(uint8_t channel, uint8_t res_id);
  
  uint8_t settings_size() { return 1; }
  uint8_t settings_offset() { return SETTINGS_MONITOR; }
  uint8_t* settings_data() { return &monitored_channel_; }
  
  uint8_t monitored_channel_;
  
  DISALLOW_COPY_AND_ASSIGN(Monitor);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_MONITOR_H_
