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
  SETTING_MONITOR_CHANNEL = 0,
  
  SETTING_0XFE_FILTER_ENABLED = 8,
  
  SETTING_CLOCK_SOURCE_BPM = 16,
  SETTING_CLOCK_SOURCE_GROOVE_TEMPLATE,
  SETTING_CLOCK_SOURCE_GROOVE_AMOUNT,
  
  SETTING_CC_KNOB_VALUE = 24,
  SETTING_CC_KNOB_CHANNEL,
  SETTING_CC_KNOB_CC,
  SETTING_CC_KNOB_MIN,
  SETTING_CC_KNOB_MAX,
  
  SETTING_EAR_TRAINING_LEVEL = 32,
  SETTING_EAR_TRAINING_NUM_NOTES,
  SETTING_EAR_TRAINING_NUM_GAMES = 34,
  SETTING_EAR_TRAINING_NUM_ATTEMPTS = 36,
  
  SETTING_EUCLIDIAN_PATTERN_GENERATOR = 48,
};

class PlugIn {
 public:
  PlugIn() { }
  
  virtual void OnLoad() { }
  
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
  virtual uint8_t OnRedraw() { return 0; }
  virtual void OnIdle() { }
  
  virtual void SetParameter(uint8_t key, uint8_t value) { }
  virtual uint8_t GetParameter(uint8_t key) { }
  
  // Event handlers for clock.
  virtual void OnInternalClockTick() { }
  virtual void OnInternalClockStep() { }

 protected:
  // Can be used to save/load settings in EEPROM.
  uint8_t LoadSetting(uint8_t setting_id);
  void SaveSetting(uint8_t setting_id, uint8_t value);
  uint16_t LoadSettingWord(uint8_t setting_id);
  void SaveSettingWord(uint8_t setting_id, uint16_t value);
  
  void SendNow(uint8_t byte);
  void Send(uint8_t status, uint8_t* data, uint8_t size);
  void Send3(uint8_t a, uint8_t b, uint8_t c);
  
 private:  
  DISALLOW_COPY_AND_ASSIGN(PlugIn);
};

}  // namespace midipal

#endif // MIDIPAL_PLUGIN_H_
