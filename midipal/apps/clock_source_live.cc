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

#include "midipal/apps/clock_source_live.h"

#include "avrlib/op.h"
#include "avrlib/string.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

const prog_uint8_t clock_source_factory_data[6] PROGMEM = {
  0, 120, 1, 1, 0, 24
};

/* static */
uint8_t ClockSourceLive::running_;

/* static */
uint8_t ClockSourceLive::bpm_;

/* static */
uint8_t ClockSourceLive::multiplier_;

/* static */
uint8_t ClockSourceLive::divider_;

/* static */
uint8_t ClockSourceLive::send_start_;

/* static */
uint8_t ClockSourceLive::control_note_;

/* static */
uint8_t ClockSourceLive::num_taps_;

/* static */
uint8_t ClockSourceLive::num_ticks_;

/* static */
uint32_t ClockSourceLive::elapsed_time_;

/* static */
const prog_AppInfo ClockSourceLive::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  &OnNoteOn, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
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
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  &SetParameter, // void (*SetParameter)(uint8_t, uint8_t);
  &GetParameter, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  6, // settings_size
  SETTINGS_CLOCK_SOURCE, // settings_offset
  &running_, // settings_data
  clock_source_factory_data, // factory_data
  STR_RES_CLOCK, // app_name
  true
};

/* static */
void ClockSourceLive::OnInit() {
  ui.AddPage(STR_RES_RUN, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_BPM, UNIT_INTEGER, 40, 240);
  ui.AddPage(STR_RES_NUM, UNIT_INTEGER, 1, 16);
  ui.AddPage(STR_RES_DIV, UNIT_INTEGER, 1, 16);
  ui.AddPage(STR_RES_START, STR_RES_OFF, 0, 1);
  ui.AddPage(STR_RES_NOT, UNIT_NOTE, 0, 111);
  ui.AddPage(STR_RES_TAP, UNIT_INTEGER, 40, 240);
  SetParameter(1, bpm_);
  running_ = 0;
  num_taps_ = 0;
}

static const prog_uint8_t ratios[] PROGMEM = {
  0x13, 0x12, 0x23, 0x34, 0x11, 0x54, 0x43, 0x32, 0x53, 0x74, 0x21, 0x94,
  0x73, 0x52, 0x00, 0x00, 0x11
};

/* static */
void ClockSourceLive::OnNoteOn(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (note >= control_note_ && note < control_note_ + sizeof(ratios)) {
    uint8_t ratio = pgm_read_byte(ratios + note - control_note_);
    if (ratio) {
      multiplier_ = avrlib::U8ShiftRight4(ratio);
      SetParameter(3, ratio & 0x0f);
      if (send_start_) {
        app.SendNow(0xfa);
      }
    }
  }
}

/* static */
void ClockSourceLive::OnRawByte(uint8_t byte) {
  uint8_t is_realtime = (byte & 0xf0) == 0xf0;
  uint8_t is_sysex = (byte == 0xf7) || (byte == 0xf0);
  if (!is_realtime || is_sysex) {
    app.SendNow(byte);
  }
  if (byte == 0xfa) {
    num_ticks_ = 0;
  }
  if (byte == 0xf8) {
    ++num_ticks_;
    if (num_ticks_ == 192) {
      SetParameter(1, avrlib::Clip(18750000 * 8 / clock.value(), 10, 255));
      num_ticks_ = 0;
      clock.Reset();
    }
  }
}

/* static */
void ClockSourceLive::SetParameter(uint8_t key, uint8_t value) {
  if (key == 0) {
    if (value == 1) {
      Start();
    } else {
      Stop();
    }
  }
  if (key == 6) {
    key = 1;
  }
  static_cast<uint8_t*>(&running_)[key] = value;
  clock.UpdateFractional(bpm_, multiplier_, divider_, 0, 0);
}

/* static */
uint8_t ClockSourceLive::GetParameter(uint8_t key) {
  if (key == 6) {
    key = 1;
  }
  return static_cast<uint8_t*>(&running_)[key];
}

/* static */
uint8_t ClockSourceLive::OnClick() {
  if (ui.page() == 6) {
    TapTempo();
    return 1;
  } else {
    return 0;
  }
}

/* static */
void ClockSourceLive::TapTempo() {
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
}

/* static */
uint8_t ClockSourceLive::OnIncrement(int8_t increment) {
  num_taps_ = 0;
  return 0;
}

/* static */
void ClockSourceLive::OnStart() {
  Start();
}

/* static */
void ClockSourceLive::OnStop() {
  Stop();
}

/* static */
void ClockSourceLive::OnContinue() {
  Start();
}

/* static */
void ClockSourceLive::OnInternalClockTick() {
  app.SendNow(0xf8);
}

/* static */
void ClockSourceLive::Stop() {
  if (running_) {
    clock.Stop();
    app.SendNow(0xfc);
    running_ = 0;
  }
}

/* static */
void ClockSourceLive::Start() {
  if (!running_) {
    clock.Start();
    app.SendNow(0xfa);
    running_ = 1;
  }
}

} }  // namespace midipal::apps
