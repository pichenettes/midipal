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
// Main definitions.

#ifndef MIDIPAL_MIDI_HANDLER_H_
#define MIDIPAL_MIDI_HANDLER_H_

#include "midi/midi.h"
#include "midipal/plugin_manager.h"

namespace midipal {

struct MidiHandler : public midi::MidiDevice {
  static void NoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
    plugin_manager.active_plugin()->OnNoteOn(channel, note, velocity);
  }
  
  static void NoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
    plugin_manager.active_plugin()->OnNoteOff(channel, note, velocity);
  }
  
  static void Aftertouch(uint8_t channel, uint8_t note, uint8_t velocity) {
    plugin_manager.active_plugin()->OnAftertouch(channel, note, velocity);
  }
  
  static void Aftertouch(uint8_t channel, uint8_t velocity) {
    plugin_manager.active_plugin()->OnAftertouch(channel, velocity);
  }
  
  static void ControlChange(uint8_t channel, uint8_t controller,
                             uint8_t value) {
    plugin_manager.active_plugin()->OnControlChange(channel, controller, value);
  }
  
  static void ProgramChange(uint8_t channel, uint8_t program) {
    plugin_manager.active_plugin()->OnProgramChange(channel, program);
  }
  
  static void PitchBend(uint8_t channel, uint16_t pitch_bend) {
    plugin_manager.active_plugin()->OnPitchBend(channel, pitch_bend);
  }

  static void AllSoundOff(uint8_t channel) {
    plugin_manager.active_plugin()->OnAllSoundOff(channel);
  }
  
  static void ResetAllControllers(uint8_t channel) {
    plugin_manager.active_plugin()->OnResetAllControllers(channel);
  }
  
  static void LocalControl(uint8_t channel, uint8_t state) {
    plugin_manager.active_plugin()->OnLocalControl(channel, state);
  }
  
  static void AllNotesOff(uint8_t channel) {
    plugin_manager.active_plugin()->OnAllNotesOff(channel);
  }
  
  static void OmniModeOff(uint8_t channel) {
    plugin_manager.active_plugin()->OnOmniModeOff(channel);
  }
  
  static void OmniModeOn(uint8_t channel) {
    plugin_manager.active_plugin()->OnOmniModeOn(channel);
  }
  
  static void MonoModeOn(uint8_t channel, uint8_t num_channels) {
    plugin_manager.active_plugin()->OnMonoModeOn(channel, num_channels);
  }
  
  static void PolyModeOn(uint8_t channel) {
    plugin_manager.active_plugin()->OnPolyModeOn(channel);
  }
  
  static void SysExStart() {
    plugin_manager.active_plugin()->OnSysExStart();
  }
  
  static void SysExByte(uint8_t sysex_byte) {
    plugin_manager.active_plugin()->OnSysExByte(sysex_byte);
  }
  
  static void SysExEnd() {
    plugin_manager.active_plugin()->OnSysExEnd();
  }
  
  static void BozoByte(uint8_t bozo_byte) {
    plugin_manager.active_plugin()->OnBozoByte(bozo_byte);
  }

  static void Clock() {
    plugin_manager.active_plugin()->OnClock();
  }
  
  static void Start() {
    plugin_manager.active_plugin()->OnStart();
  }
  
  static void Continue() {
    plugin_manager.active_plugin()->OnContinue();
  }
  
  static void Stop() {
    plugin_manager.active_plugin()->OnStop();
  }
  
  static void ActiveSensing() {
    plugin_manager.active_plugin()->OnActiveSensing();
  }
  
  static void Reset() {
    plugin_manager.active_plugin()->OnReset();
  }

  static uint8_t CheckChannel(uint8_t channel) {
    return plugin_manager.active_plugin()->CheckChannel(channel);
  }
  
  static void RawByte(uint8_t byte) {
    plugin_manager.active_plugin()->OnRawByte(byte);
  }
  
  static void RawMidiData(
      uint8_t status,
      uint8_t* data,
      uint8_t data_size,
      uint8_t accepted_channel) {
    plugin_manager.active_plugin()->OnRawMidiData(
        status,
        data,
        data_size,
        accepted_channel);
  }
};

}  // namespace midipal

#endif // MIDIPAL_MIDI_HANDLER_H_
