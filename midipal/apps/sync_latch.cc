// Copyright 2012 Olivier Gillet.
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
// Clock divider app.

#include "midipal/apps/sync_latch.h"

#include "avrlib/op.h"
#include "avrlib/string.h"

#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t sync_latch_factory_data[2] PROGMEM = {
  4, 8
};


/* static */
uint8_t SyncLatch::num_beats_;

/* static */
uint8_t SyncLatch::beat_division_;

/* static */
uint8_t SyncLatch::step_counter_;

/* static */
uint8_t SyncLatch::beat_counter_;

/* static */
uint8_t SyncLatch::state_;

/* static */
const prog_AppInfo SyncLatch::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  NULL, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnAftertouch)(uint8_t, uint8_t);
  NULL, // void (*OnControlChange)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnProgramChange)(uint8_t, uint8_t);
  NULL, // void (*OnPitchBend)(uint8_t, uint16_t);
  NULL, // void (*OnSysExByte)(uint8_t);
  &OnClock, // void (*OnClock)();
  &OnStart, // void (*OnStart)();
  NULL, // void (*OnContinue)();
  &OnStop, // void (*OnStop)();
  NULL, // uint8_t (*CheckChannel)(uint8_t);
  &OnRawByte, // void (*OnRawByte)(uint8_t);
  NULL, // void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t);
  NULL, // void (*OnInternalClockTick)();
  NULL, // void (*OnInternalClockStep)();
  NULL, // uint8_t (*OnIncrement)(int8_t);
  &OnClick, // uint8_t (*OnClick)();
#ifdef MIDIBUD_FIRMWARE
  NULL, // uint8_t (*OnSwitch)(uint8_t);
#else
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  &OnRedraw, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  NULL, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  2, // settings_size
  SETTINGS_SYNC_LATCH, // settings_offset
  &num_beats_, // settings_data
  sync_latch_factory_data, // factory_data
  STR_RES_SYNCLTCH, // app_name
  true
};  
  
/* static */
void SyncLatch::OnInit() {
  ui.AddPage(STR_RES_NUM, UNIT_INTEGER, 1, 32);
  ui.AddPage(STR_RES_DEN, STR_RES_2_1, 8, 16);
  // Add two dummy pages. They won't be shown on screen since Redraw is
  // overridden, but this allows the default navigation handling to be used.
  ui.AddPage(0, UNIT_INTEGER, 1, 1);
  ui.AddPage(0, UNIT_INTEGER, 1, 1);
  state_ = 0;
}

/* static */
void SyncLatch::OnRawByte(uint8_t byte) {
  app.SendNow(byte);
}

/* static */
void SyncLatch::OnStart() {
  beat_counter_ = 0;
  step_counter_ = 0;
  state_ = STATE_RUNNING;
}

/* static */
void SyncLatch::OnStop() {
  state_ = 0;
}

/* static */
void SyncLatch::OnClock() {
  ++step_counter_;
  uint8_t num_ticks_per_beat = ResourcesManager::Lookup<uint8_t, uint8_t>(
      midi_clock_tick_per_step, beat_division_);
  if (step_counter_ >= num_ticks_per_beat) {
    step_counter_ = 0;
    ++beat_counter_;
  }
  if (beat_counter_ >= num_beats_) {
    beat_counter_ = 0;
  }
  if ((state_ & STATE_ARMED) && step_counter_ == 0 && beat_counter_ == 0) {
    if (state_ & STATE_RUNNING) {
      app.SendNow(0xfc);
      state_ = 0;
    } else {
      app.SendNow(0xfa);
      state_ = STATE_RUNNING;
    }
  }
}

/* static */
uint8_t SyncLatch::OnClick() {
  if (ui.page() == 3) {
    beat_counter_ = 0;
    step_counter_ = 0;
  } else if (ui.page() == 2) {
    state_ |= STATE_ARMED;
  } else {
    return 0;
  }
  return 1;
}

/* static */
uint8_t SyncLatch::OnRedraw() {
  if (ui.page() == 2) {
    memset(line_buffer, ' ', kLcdWidth);
    UnsafeItoa(beat_counter_ + 1, 2, &line_buffer[1]);
    PadRight(&line_buffer[1], 2, '0');
    UnsafeItoa(step_counter_, 2, &line_buffer[4]);
    PadRight(&line_buffer[4], 2, '0');
    line_buffer[3] = ':';
    if (state_ & STATE_ARMED) {
      line_buffer[0] = '[';
      line_buffer[6] = ']';
    }
    line_buffer[7] = (state_ & STATE_RUNNING) ? '>' : 0xa5;
    display.Print(0, line_buffer);
  } else if (ui.page() == 3) {
    ui.PrintString(STR_RES_RESET);
  } else {
    return 0;
  }
  return 1;
}

} }  // namespace midipal::apps
