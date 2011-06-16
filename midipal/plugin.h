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
// Base class implemented by all the "Plug-ins" running on the Midipal.

#ifndef MIDIPAL_PLUGIN_H_
#define MIDIPAL_PLUGIN_H_

#include "avrlib/base.h"

namespace midipal {

enum EepromSetting {
  // Settings must be defined here. Please leave some space between them
  // to allow for future improvements of plug-ins.
  SETTINGS_MONITOR = 0,
  SETTINGS_0XFE_FILTER = 8,
  SETTINGS_CLOCK_SOURCE = 16,
  SETTINGS_CC_KNOB = 24,
  SETTINGS_EAR_TRAINING = 32,
  SETTINGS_EAR_TRAINING_NUM_GAMES = 35,
  SETTINGS_EAR_TRAINING_NUM_ATTEMPTS = 37,
  SETTINGS_DRUM_PATTERN_GENERATOR = 64,
  SETTINGS_CONTROLLER = 80,
  SETTINGS_SPLITTER = 128,
  SETTINGS_RANDOMIZER = 136,
  SETTINGS_CHORD_MEMORY = 144,
  SETTINGS_DISPATCHER = 176,
  SETTINGS_COMBINER = 192,
  SETTINGS_ARPEGGIATOR = 208,
};

enum ClockMode {
  CLOCK_MODE_INTERNAL,
  CLOCK_MODE_EXTERNAL
};

class PlugIn {
 public:
  PlugIn() { }
  
  void Init();
  void SaveSettings();
  
  virtual void OnInit() { }
  
  // Event handlers for MIDI input.
  virtual void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) { }
  virtual void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) { }
  virtual void OnAftertouch(uint8_t channel, uint8_t note, uint8_t velocity) { }
  virtual void OnAftertouch(uint8_t channel, uint8_t velocity) { }
  virtual void OnControlChange(uint8_t channel, uint8_t controller,
                               uint8_t value) { }
  virtual void OnProgramChange(uint8_t channel, uint8_t program) { }
  virtual void OnPitchBend(uint8_t channel, uint16_t pitch_bend) { }

  virtual void OnAllSoundOff(uint8_t channel) { }
  virtual void OnResetAllControllers(uint8_t channel) { }
  virtual void OnLocalControl(uint8_t channel, uint8_t state) { }
  virtual void OnAllNotesOff(uint8_t channel) { }
  virtual void OnOmniModeOff(uint8_t channel) { }
  virtual void OnOmniModeOn(uint8_t channel) { }
  virtual void OnMonoModeOn(uint8_t channel, uint8_t num_channels) { }
  virtual void OnPolyModeOn(uint8_t channel) { }
  virtual void OnSysExStart() { }
  virtual void OnSysExByte(uint8_t sysex_byte) { }
  virtual void OnSysExEnd() { }
  virtual void OnBozoByte(uint8_t bozo_byte) { }

  virtual void OnClock() { }
  virtual void OnStart() { }
  virtual void OnContinue() { }
  virtual void OnStop() { }
  virtual void OnActiveSensing() { }
  virtual void OnReset() { }

  virtual uint8_t CheckChannel(uint8_t channel) { return 1; }
  virtual void OnRawByte(uint8_t byte) { }
  virtual void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel) { }
    
  // Event handlers for UI.
  virtual uint8_t OnIncrement(int8_t increment) { return 0; }
  virtual uint8_t OnClick() { return 0; }
  virtual uint8_t OnPot(uint8_t pot, uint8_t value) { return 0; }
  virtual uint8_t OnRedraw() { return 0; }
  virtual void OnIdle() { }
  
  // Access to settings data structure
  virtual uint8_t settings_size() { return 0; }
  virtual uint8_t settings_offset() { return 0; }
  virtual uint8_t* settings_data() { return NULL; }
  
  virtual void SetParameter(uint8_t key, uint8_t value) {
    settings_data()[key] = value;
  }
  virtual uint8_t GetParameter(uint8_t key) {
    return settings_data()[key];
  }
  
  // Event handlers for clock.
  virtual void OnInternalClockTick() { }
  virtual void OnInternalClockStep() { }

 protected:
  // Can be used to save/load settings in EEPROM.
  void SaveSetting(uint8_t setting_id, uint8_t value);
  void SaveSettingWord(uint8_t setting_id, uint16_t value);
  
  void SendNow(uint8_t byte);
  void Send(uint8_t status, uint8_t* data, uint8_t size);
  void Send3(uint8_t a, uint8_t b, uint8_t c);
  void SendLater(uint8_t note, uint8_t velocity, uint8_t when);
  void SendScheduledNotes(uint8_t channel);
  void FlushQueue(uint8_t channel);
  
 private:
  DISALLOW_COPY_AND_ASSIGN(PlugIn);
};

}  // namespace midipal

#endif // MIDIPAL_PLUGIN_H_
