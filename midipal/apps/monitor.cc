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
// MIDI monitor app.

#include "midipal/apps/monitor.h"

#include "avrlib/string.h"

#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t monitor_factory_data[1] PROGMEM = { 0 };

/* static */
uint8_t Monitor::monitored_channel_;

/* static */
uint8_t Monitor::idle_counter_;

/* static */
const prog_AppInfo Monitor::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  &OnNoteOn, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  &OnNoteOff, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  &OnNoteAftertouch, // void (*OnNoteAftertouch)(uint8_t, uint8_t);
  &OnAftertouch, // void (*OnAftertouch)(uint8_t, uint8_t, uint8_t);
  &OnControlChange, // void (*OnControlChange)(uint8_t, uint8_t, uint8_t);
  &OnProgramChange, // void (*OnProgramChange)(uint8_t, uint8_t);
  &OnPitchBend, // void (*OnPitchBend)(uint8_t, uint16_t);
  &OnSysExByte, // void (*OnSysExByte)(uint8_t);
  &OnClock, // void (*OnClock)();
  &OnStart, // void (*OnStart)();
  &OnContinue, // void (*OnContinue)();
  &OnStop, // void (*OnStop)();
  &CheckChannel, // uint8_t (*CheckChannel)(uint8_t);
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
  &OnIdle, // void (*OnIdle)();
  NULL, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)();
  1, // settings_size
  SETTINGS_MONITOR, // settings_offset
  &monitored_channel_, // settings_data
  monitor_factory_data, // factory_data
  STR_RES_MONITOR, // app_name
  true
};

/* static */
void Monitor::OnInit() {
  lcd.SetCustomCharMapRes(chr_res_digits_10, 7, 1);
  ui.Clear();
  ui.AddPage(STR_RES_CHN, UNIT_INTEGER_ALL, 0, 16);
}

/* static */
void Monitor::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  // 01234567
  // 1 C#7 7f
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  ui.PrintNote(&line_buffer[2], note);
  ui.PrintHex(&line_buffer[6], velocity);
  ui.RefreshScreen();
}

/* static */
void Monitor::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  ui.PrintNote(&line_buffer[2], note);
  line_buffer[6] = '-';
  line_buffer[7] = '-';
  ui.RefreshScreen();
}

/* static */
void Monitor::OnNoteAftertouch(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  ui.PrintNote(&line_buffer[2], note);
  line_buffer[6] = 'a';
  ui.PrintHex(&line_buffer[7], velocity);
  ui.RefreshScreen();
}

/* static */
void Monitor::OnAftertouch(uint8_t channel, uint8_t velocity) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  line_buffer[2] = 'a';
  line_buffer[3] = 'f';
  line_buffer[4] = 't';
  ui.PrintHex(&line_buffer[6], velocity);
  ui.RefreshScreen();
}

/* static */
void Monitor::OnControlChange(
    uint8_t channel,
    uint8_t controller,
    uint8_t value) {
  // 01234567
  // 1 C45 67
  switch (controller) {
    case 0x78:
      OnAllSoundOff(channel);
      break;
    case 0x79:
      OnResetAllControllers(channel);
      break;
    case 0x7a:
      OnLocalControl(channel, value);
      break;
    case 0x7b:
      OnAllNotesOff(channel);
      break;
    case 0x7c:
      OnOmniModeOff(channel);
      break;
    case 0x7d:
      OnOmniModeOn(channel);
      break;
    case 0x7e:
      OnMonoModeOn(channel, value);
      break;
    case 0x7f:
      OnPolyModeOn(channel);
      break;
    default:
      ui.Clear();
      ui.PrintChannel(&line_buffer[0], channel);
      line_buffer[2] = '#';
      ui.PrintHex(&line_buffer[3], controller);
      ui.PrintHex(&line_buffer[6], value);
      ui.RefreshScreen();
      break;
  }
}

/* static */
void Monitor::OnProgramChange(uint8_t channel, uint8_t program) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  line_buffer[2] = 'p';
  line_buffer[3] = 'g';
  line_buffer[4] = 'm';
  ui.PrintHex(&line_buffer[6], program);
  ui.RefreshScreen();
}

/* static */
void Monitor::OnPitchBend(uint8_t channel, uint16_t pitch_bend) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  line_buffer[2] = 'b';
  ui.PrintHex(&line_buffer[4], pitch_bend >> 8);
  ui.PrintHex(&line_buffer[6], pitch_bend & 0xff);
  ui.RefreshScreen();
}

/* static */
void Monitor::PrintString(uint8_t channel, uint8_t res_id) {
  if (ui.editing()) {
    return;
  }
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  ResourcesManager::LoadStringResource(res_id, &line_buffer[2], 6);
  AlignRight(&line_buffer[2], 6);
  ui.RefreshScreen();
}

/* static */
void Monitor::OnAllSoundOff(uint8_t channel) {
  PrintString(channel, STR_RES_SNDOFF);
}

/* static */
void Monitor::OnResetAllControllers(uint8_t channel) {
  PrintString(channel, STR_RES_RSTCTR);
}

/* static */
void Monitor::OnLocalControl(uint8_t channel, uint8_t state) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  line_buffer[2] = 'l';
  line_buffer[3] = 'o';
  line_buffer[4] = 'c';
  ui.PrintHex(&line_buffer[6], state);
  ui.RefreshScreen();
}

/* static */
void Monitor::OnAllNotesOff(uint8_t channel) {
  PrintString(channel, STR_RES_NOTOFF);
}

/* static */
void Monitor::OnOmniModeOff(uint8_t channel) {
  PrintString(channel, STR_RES_OMNOFF);
}

/* static */
void Monitor::OnOmniModeOn(uint8_t channel) {
  PrintString(channel, STR_RES_OMNION);
}

/* static */
void Monitor::OnMonoModeOn(uint8_t channel, uint8_t num_channels) {
  PrintString(channel, STR_RES_MONOON);
}

/* static */
void Monitor::OnPolyModeOn(uint8_t channel) {
  PrintString(channel, STR_RES_POLYON);
}

/* static */
void Monitor::OnSysExByte(uint8_t sysex_byte) {
  if (sysex_byte == 0xf0) {
    PrintString(0xff, STR_RES_SYSX__);
  } else if (sysex_byte == 0xf7) {
    PrintString(0xff, STR_RES___SYSX);
  } else {
    PrintString(0xff, STR_RES__SYSX_);
  }
}

/* static */
void Monitor::OnClock() {
  if (ui.editing()) {
    return;
  }
  
  line_buffer[1] = 0xa5;
  ui.RefreshScreen();
}

/* static */
void Monitor::OnStart() {
  PrintString(0xff, STR_RES_START);
}

/* static */
void Monitor::OnContinue() {
  PrintString(0xff, STR_RES_CONT_);
}

/* static */
void Monitor::OnStop() {
  PrintString(0xff, STR_RES_STOP);
}

/* static */
uint8_t Monitor::CheckChannel(uint8_t channel) {
  return (ui.editing() == 0) && 
      ((monitored_channel_ == 0) || (channel + 1 == monitored_channel_));
}

/* static */
void Monitor::OnRawByte(uint8_t byte) {
  if (byte != 0xfe && byte != 0xf8) {
    idle_counter_ = 0;
  }
  if (byte == 0xff) {
    PrintString(0xff, STR_RES_RESET);
  }
  app.SendNow(byte);
}

/* static */
uint8_t Monitor::OnClick() {
  ui.Clear();
  ui.RefreshScreen();
  return 0;
}

/* static */
uint8_t Monitor::OnRedraw() {
  if (!ui.editing()) {
    return 1;  // Prevent the default screen redraw handler to be called.
  } else {
    return 0;
  }
}

/* static */
void Monitor::OnIdle() {
  if (idle_counter_ < 60) {
    ++idle_counter_;
    if (idle_counter_ == 60) {
      ui.Clear();
      ui.RefreshScreen();
    }
  }
}

} }  // namespace midipal::apps
