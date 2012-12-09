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
// MIDI clock generator app.

#include "midipal/apps/clock_source.h"

#include "avrlib/op.h"
#include "avrlib/string.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

const prog_uint8_t clock_source_factory_data[4] PROGMEM = {
  0, 120, 0, 0
};

/* static */
uint8_t ClockSource::running_;

/* static */
uint8_t ClockSource::bpm_;

/* static */
uint8_t ClockSource::groove_template_;

/* static */
uint8_t ClockSource::groove_amount_;

/* static */
uint8_t ClockSource::num_taps_;

/* static */
uint32_t ClockSource::elapsed_time_;

/* static */
const prog_AppInfo ClockSource::app_info_ PROGMEM = {
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
  &OnStart, // void (*OnStart)();
  &OnContinue, // void (*OnContinue)();
  &OnStop, // void (*OnStop)();
  NULL, // uint8_t (*CheckChannel)(uint8_t);
  &OnRawByte, // void (*OnRawByte)(uint8_t);
  NULL, // void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t);
  &OnInternalClockTick, // void (*OnInternalClockTick)();
  NULL, // void (*OnInternalClockStep)();
  &OnIncrement, // uint8_t (*OnIncrement)(int8_t);
  &OnClick, // uint8_t (*OnClick)();
#ifdef MIDIBUD_FIRMWARE
  NULL, // uint8_t (*OnSwitch)(uint8_t);
#else
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  &SetParameter, // void (*SetParameter)(uint8_t, uint8_t);
  &GetParameter, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  4, // settings_size
  SETTINGS_CLOCK_SOURCE, // settings_offset
  &running_, // settings_data
  clock_source_factory_data, // factory_data
  STR_RES_CLOCK, // app_name
  true
};

/* static */
void ClockSource::OnInit() {
  ui.AddPage(STR_RES_RUN, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_BPM, UNIT_INTEGER, 40, 240);
  ui.AddPage(STR_RES_GRV, STR_RES_SWG, 0, 5);
  ui.AddPage(STR_RES_AMT, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_TAP, UNIT_INTEGER, 40, 240);
  clock.Update(bpm_, groove_template_, groove_amount_);
  running_ = 0;
  num_taps_ = 0;
}

/* static */
void ClockSource::OnRawByte(uint8_t byte) {
  uint8_t is_realtime = (byte & 0xf0) == 0xf0;
  uint8_t is_sysex = (byte == 0xf7) || (byte == 0xf0);
  if (!is_realtime || is_sysex) {
    app.SendNow(byte);
  }
}

/* static */
void ClockSource::SetParameter(uint8_t key, uint8_t value) {
  if (key == 0) {
    if (value == 1) {
      Start();
    } else {
      Stop();
    }
  }
  if (key == 4) {
    key = 1;
  }
  static_cast<uint8_t*>(&running_)[key] = value;
  clock.Update(bpm_, groove_template_, groove_amount_);
}

/* static */
uint8_t ClockSource::GetParameter(uint8_t key) {
  if (key == 4) {
    key = 1;
  }
  return static_cast<uint8_t*>(&running_)[key];
}

/* static */
uint8_t ClockSource::OnClick() {
  if (ui.page() == 4) {
    uint32_t t = clock.value();
    clock.Reset();
    if (num_taps_ > 0 && t < 400000L) {
      elapsed_time_ += t;
      SetParameter(
          1,
          avrlib::Clip(18750000 * num_taps_ / elapsed_time_, 40, 240));
    } else {
      num_taps_ = 0;
      elapsed_time_ = 0;
    }
    ++num_taps_;
    return 1;
  } else {
    return 0;
  }
}

/* static */
uint8_t ClockSource::OnIncrement(int8_t increment) {
  num_taps_ = 0;
  return 0;
}

/* static */
void ClockSource::OnStart() {
  Start();
}

/* static */
void ClockSource::OnStop() {
  Stop();
}

/* static */
void ClockSource::OnContinue() {
  Start();
}

/* static */
void ClockSource::OnInternalClockTick() {
  app.SendNow(0xf8);
}

/* static */
void ClockSource::Stop() {
  if (running_) {
    clock.Stop();
    app.SendNow(0xfc);
    running_ = 0;
  }
}

/* static */
void ClockSource::Start() {
  if (!running_) {
    clock.Start();
    app.SendNow(0xfa);
    running_ = 1;
  }
}

} }  // namespace midipal::apps
