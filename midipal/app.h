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

#ifndef MIDIPAL_APP_H_
#define MIDIPAL_APP_H_

#include "avrlib/base.h"

#include "midipal/resources.h"

namespace midipal {

enum EepromSetting {
  // Settings must be defined here. Please leave some space between them
  // to allow for future improvements of apps.
  SETTINGS_POLY_SEQUENCER = 24,
  SETTINGS_MONITOR = 0,
  SETTINGS_0XFE_FILTER = 8,
  SETTINGS_SYNC_LATCH = 10,
  SETTINGS_CLOCK_SOURCE = 16,
  SETTINGS_CC_KNOB = 24,
  SETTINGS_EAR_TRAINING = 32,
  SETTINGS_EAR_TRAINING_NUM_GAMES = 35,
  SETTINGS_EAR_TRAINING_NUM_ATTEMPTS = 37,
  SETTINGS_TANPURA = 48,
  SETTINGS_DRUM_PATTERN_GENERATOR = 64,
  SETTINGS_CONTROLLER = 80,
  SETTINGS_SPLITTER = 128,
  SETTINGS_RANDOMIZER = 136,
  SETTINGS_CHORD_MEMORY = 144,
  SETTINGS_DISPATCHER = 176,
  SETTINGS_COMBINER = 192,
  SETTINGS_ARPEGGIATOR = 208,
  SETTINGS_DELAY = 256,
  SETTINGS_SCALE_PROCESSOR = 272,
  SETTINGS_SEQUENCER = 288,
  SETTINGS_LFO = 512,
  SETTINGS_FILTER = 544,
  SETTINGS_CLOCK_DIVIDER = 576,
  SETTINGS_GENERIC_FILTER_PROGRAM = 580,
  SETTINGS_GENERIC_FILTER_SETTINGS = 640,
  SETTINGS_GENERIC_FILTER_SETTINGS_DUMP_AREA = 896,
  SETTINGS_APP_SELECTOR = 1008,
  SETTINGS_SYSTEM_SETTINGS = 1012
};

enum ClockMode {
  CLOCK_MODE_INTERNAL,
  CLOCK_MODE_EXTERNAL
};

struct AppInfo {
  void (*OnInit)();
  void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
  void (*OnAftertouch)(uint8_t, uint8_t);
  void (*OnControlChange)(uint8_t, uint8_t, uint8_t);
  void (*OnProgramChange)(uint8_t, uint8_t);
  void (*OnPitchBend)(uint8_t, uint16_t);
  void (*OnSysExByte)(uint8_t);
  void (*OnClock)();
  void (*OnStart)();
  void (*OnContinue)();
  void (*OnStop)();
  uint8_t (*CheckChannel)(uint8_t);
  void (*OnRawByte)(uint8_t);
  void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t);
  void (*OnInternalClockTick)();
  void (*OnInternalClockStep)();
  uint8_t (*OnIncrement)(int8_t);
  uint8_t (*OnClick)();
#ifdef MIDIBUD_FIRMWARE
  uint8_t (*OnSwitch)(uint8_t);
#else
  uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  uint8_t (*OnRedraw)();
  void (*OnIdle)();
  void (*SetParameter)(uint8_t, uint8_t);
  uint8_t (*GetParameter)(uint8_t);
  uint8_t (*CheckPageStatus)(uint8_t);

  uint16_t settings_size;
  uint16_t settings_offset;
  uint8_t* settings_data;
  const prog_uint8_t* factory_data;
  uint8_t app_name;
  
  // Whether the app can respond to a clock message within 50µs. Set this to
  // false if your app can generate a big bunch of MIDI messages upon the
  // reception of a single clock tick (eg: anything that may generate
  // overlapping notes, polyphony...). Set to true if your app generates only
  // a couple of MIDI messages or does nothing on clock ticks.
  bool realtime_clock_handling;
};

typedef AppInfo PROGMEM prog_AppInfo;

class App {
 public:
  App() { }
  
  static void Init();
  
  // Can be used to save/load settings in EEPROM.
  static void SaveSetting(uint16_t index);
  static void SaveSettingWord(uint16_t setting_id, uint16_t value);
  static void SaveSettings();
  static void LoadSettings();
  static void ResetToFactorySettings();
  static void Launch(uint8_t app_index);
  
  static void OnInit() {
    if (app_info_.OnInit) {
      (*app_info_.OnInit)();
    }
  }
  static void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
    if (app_info_.OnNoteOn) {
      (*app_info_.OnNoteOn)(channel, note, velocity);
    }
  }
  static void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
    if (app_info_.OnNoteOff) {
      (*app_info_.OnNoteOff)(channel, note, velocity);
    }
  }
  static void OnAftertouch(uint8_t channel, uint8_t note, uint8_t velocity) {
    if (app_info_.OnNoteAftertouch) {
      (*app_info_.OnNoteAftertouch)(channel, note, velocity);
    }
  }
  static void OnAftertouch(uint8_t channel, uint8_t velocity) {
    if (app_info_.OnAftertouch) {
      (*app_info_.OnAftertouch)(channel, velocity);
    }
  }
  static void OnControlChange(uint8_t channel, uint8_t controller,
                               uint8_t value) {
    if (app_info_.OnControlChange) {
      (*app_info_.OnControlChange)(channel, controller, value);
    }
  }
  static void OnProgramChange(uint8_t channel, uint8_t program) {
    if (app_info_.OnProgramChange) {
      (*app_info_.OnProgramChange)(channel, program);
    }
  }
  static void OnPitchBend(uint8_t channel, uint16_t pitch_bend) {
    if (app_info_.OnPitchBend) {
      (*app_info_.OnPitchBend)(channel, pitch_bend);
    }
  }
  static void OnSysExByte(uint8_t sysex_byte) {
    if (app_info_.OnSysExByte) {
      (*app_info_.OnSysExByte)(sysex_byte);
    }
    if (app_info_.OnRawByte == NULL) {
      // Forwarding will not be handled by OnRawByte, nor by OnRawMidiData,
      // so we do it explicitly here.
      SendNow(sysex_byte);
    }
  }

  static void OnClock() {
    if (app_info_.OnClock) {
      (*app_info_.OnClock)();
    }
  }
  static void OnStart() {
    if (app_info_.OnStart) {
      (*app_info_.OnStart)();
    }
  }
  static void OnContinue() {
    if (app_info_.OnContinue) {
      (*app_info_.OnContinue)();
    }
  }
  static void OnStop() {
    if (app_info_.OnStop) {
      (*app_info_.OnStop)();
    }
  }

  static uint8_t CheckChannel(uint8_t channel) { 
    if (app_info_.CheckChannel) {
      return (*app_info_.CheckChannel)(channel);
    } else {
      return 1;
    }
  }
  
  static void OnRawByte(uint8_t byte) {
   if (app_info_.OnRawByte) {
      (*app_info_.OnRawByte)(byte);
    }
  }
  static void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel) {
    if (app_info_.OnRawMidiData) {
      (*app_info_.OnRawMidiData)(status, data, data_size, accepted_channel);
    }
  }
  
  // Event handlers for internal clock.
  static void OnInternalClockTick() {
    if (app_info_.OnInternalClockTick) {
      (*app_info_.OnInternalClockTick)();
    }
  }
  static void OnInternalClockStep() {
    if (app_info_.OnInternalClockStep) {
      (*app_info_.OnInternalClockStep)();
    }
  }
  
  // Event handlers for UI.
  static uint8_t OnIncrement(int8_t increment) { 
    return app_info_.OnIncrement ? (*app_info_.OnIncrement)(increment) : 0;
  }
  static uint8_t OnClick() {
    return app_info_.OnClick ? (*app_info_.OnClick)() : 0;
  }
#ifdef MIDIBUD_FIRMWARE
  static uint8_t OnSwitch(uint8_t sw) {
    return app_info_.OnSwitch ? (*app_info_.OnSwitch)(sw) : 0;
  }
#else
  static uint8_t OnPot(uint8_t pot, uint8_t value) {
    return app_info_.OnPot ? (*app_info_.OnPot)(pot, value) : 0;
  }
#endif
  static uint8_t OnRedraw() {
    return app_info_.OnRedraw ? (*app_info_.OnRedraw)() : 0;
  }
  static void OnIdle() {
    if (app_info_.OnIdle) {
      return (*app_info_.OnIdle)();
    }
  }
  
  // Parameter and page checking.
  static void SetParameter(uint8_t key, uint8_t value) {
    if (app_info_.SetParameter) {
      (*app_info_.SetParameter)(key, value);
    } else {
      settings_data()[key] = value;
    }
  }
  static uint8_t GetParameter(uint8_t key) {
    if (app_info_.GetParameter) {
      return (*app_info_.GetParameter)(key);
    } else {
      return settings_data()[key];
    }
  }
  static uint8_t CheckPageStatus(uint8_t index) { 
    return app_info_.CheckPageStatus ? (*app_info_.CheckPageStatus)(index) : 1;
  }
  
  // Access to settings data structure
  static uint16_t settings_size() { return app_info_.settings_size; }
  static uint16_t settings_offset() { return app_info_.settings_offset; }
  static uint8_t* settings_data() { return app_info_.settings_data; }
  static const prog_uint8_t* factory_data() { return app_info_.factory_data; }
  static uint8_t app_name() { return app_info_.app_name; }
  static bool realtime_clock_handling() {
    return app_info_.realtime_clock_handling;
  }
  
  static void FlushOutputBuffer(uint8_t size);
  static void SendNow(uint8_t byte);
  static void Send(uint8_t status, uint8_t* data, uint8_t size);
  static void Send3(uint8_t a, uint8_t b, uint8_t c);
  static void SendLater(uint8_t note, uint8_t velocity, uint8_t when) {
    SendLater(note, velocity, when, 0);
  }
  static void SendLater(uint8_t note, uint8_t velocity, uint8_t when, uint8_t tag);
  static void SendScheduledNotes(uint8_t channel);
  static void FlushQueue(uint8_t channel);
  
  static uint8_t num_apps();
  
 private:
  static AppInfo app_info_;
  
  DISALLOW_COPY_AND_ASSIGN(App);
};

extern const prog_uint8_t midi_clock_tick_per_step[];

extern App app;

}  // namespace midipal

#endif // MIDIPAL_APP_H_
