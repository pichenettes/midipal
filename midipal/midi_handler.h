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
#include "midipal/app.h"

namespace midipal {

struct MidiHandler : public midi::MidiDevice {
  
  enum {
    buffer_size = 128,
    data_size = 8,
  };
  typedef avrlib::RingBuffer<MidiHandler> OutputBuffer;
  typedef avrlib::DataTypeForSize<data_size>::Type Value;
  
  static void NoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
    app.OnNoteOn(channel, note, velocity);
  }
  
  static void NoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
    app.OnNoteOff(channel, note, velocity);
  }
  
  static void Aftertouch(uint8_t channel, uint8_t note, uint8_t velocity) {
    app.OnAftertouch(channel, note, velocity);
  }
  
  static void Aftertouch(uint8_t channel, uint8_t velocity) {
    app.OnAftertouch(channel, velocity);
  }
  
  static void ControlChange(uint8_t channel, uint8_t controller,
                             uint8_t value) {
    app.OnControlChange(channel, controller, value);
  }
  
  static void ProgramChange(uint8_t channel, uint8_t program) {
    app.OnProgramChange(channel, program);
  }
  
  static void PitchBend(uint8_t channel, uint16_t pitch_bend) {
    app.OnPitchBend(channel, pitch_bend);
  }

  static void AllSoundOff(uint8_t channel) {
    app.OnAllSoundOff(channel);
  }
  
  static void ResetAllControllers(uint8_t channel) {
    app.OnResetAllControllers(channel);
  }
  
  static void LocalControl(uint8_t channel, uint8_t state) {
    app.OnLocalControl(channel, state);
  }
  
  static void AllNotesOff(uint8_t channel) {
    app.OnAllNotesOff(channel);
  }
  
  static void OmniModeOff(uint8_t channel) {
    app.OnOmniModeOff(channel);
  }
  
  static void OmniModeOn(uint8_t channel) {
    app.OnOmniModeOn(channel);
  }
  
  static void MonoModeOn(uint8_t channel, uint8_t num_channels) {
    app.OnMonoModeOn(channel, num_channels);
  }
  
  static void PolyModeOn(uint8_t channel) {
    app.OnPolyModeOn(channel);
  }
  
  static void SysExStart() {
    app.OnSysExStart();
  }
  
  static void SysExByte(uint8_t sysex_byte) {
    app.OnSysExByte(sysex_byte);
  }
  
  static void SysExEnd() {
    app.OnSysExEnd();
  }
  
  static void BozoByte(uint8_t bozo_byte) { }

  static void Clock() {
    app.OnClock();
  }
  
  static void Start() {
    app.OnStart();
  }
  
  static void Continue() {
    app.OnContinue();
  }
  
  static void Stop() {
    app.OnStop();
  }
  
  static void ActiveSensing() {
    app.OnActiveSensing();
  }
  
  static void Reset() {
    app.OnReset();
  }

  static uint8_t CheckChannel(uint8_t channel) {
    return app.CheckChannel(channel);
  }
  
  static void RawByte(uint8_t byte) {
    app.OnRawByte(byte);
  }
  
  static void RawMidiData(
      uint8_t status,
      uint8_t* data,
      uint8_t data_size,
      uint8_t accepted_channel) {
    app.OnRawMidiData(
        status,
        data,
        data_size,
        accepted_channel);
  }
};

}  // namespace midipal

#endif // MIDIPAL_MIDI_HANDLER_H_
