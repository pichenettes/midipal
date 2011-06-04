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

#include "midipal/plugin.h"

namespace midipal { namespace plugins {

class Monitor : public PlugIn {
 public:
  Monitor() { }

  virtual void OnLoad();

  virtual void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  virtual void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  virtual void OnAftertouch(uint8_t channel, uint8_t note, uint8_t velocity);
  virtual void OnAftertouch(uint8_t channel, uint8_t velocity);
  virtual void OnControlChange(uint8_t channel, uint8_t controller,
    uint8_t value);
  virtual void OnProgramChange(uint8_t channel, uint8_t program);
  virtual void OnPitchBend(uint8_t channel, uint16_t pitch_bend);

  virtual void OnAllSoundOff(uint8_t channel);
  virtual void OnResetAllControllers(uint8_t channel);
  virtual void OnLocalControl(uint8_t channel, uint8_t state);
  virtual void OnAllNotesOff(uint8_t channel);
  virtual void OnOmniModeOff(uint8_t channel);
  virtual void OnOmniModeOn(uint8_t channel);
  virtual void OnMonoModeOn(uint8_t channel, uint8_t num_channels);
  virtual void OnPolyModeOn(uint8_t channel);
  virtual void OnSysExStart();
  virtual void OnSysExByte(uint8_t sysex_byte);
  virtual void OnSysExEnd();
  virtual void OnBozoByte(uint8_t bozo_byte);

  virtual void OnClock();
  virtual void OnStart();
  virtual void OnContinue();
  virtual void OnStop();
  virtual void OnActiveSensing();
  virtual void OnReset();

  virtual uint8_t CheckChannel(uint8_t channel);
     
  virtual void SetParameter(uint8_t key, uint8_t value);
  virtual uint8_t GetParameter(uint8_t key);
  
  virtual uint8_t OnRedraw();
  virtual uint8_t OnClick();
  
 private:
  void PrintString(uint8_t channel, uint8_t res_id);
  
  uint8_t monitored_channel_;
  
  DISALLOW_COPY_AND_ASSIGN(Monitor);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_MONITOR_H_
