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
#include "midipal/resources.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

void Monitor::OnInit() {
  lcd.SetCustomCharMapRes(chr_res_digits_10, 7, 1);
  ui.Clear();
  ui.AddPage(STR_RES_CHN, UNIT_INTEGER_ALL, 0, 16);
}

void Monitor::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  // 01234567
  // 1 C#7 7f
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  ui.PrintNote(&line_buffer[2], note);
  ui.PrintHex(&line_buffer[6], velocity);
  ui.RefreshScreen();
}

void Monitor::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  ui.PrintNote(&line_buffer[2], note);
  line_buffer[6] = '-';
  line_buffer[7] = '-';
  ui.RefreshScreen();
}

void Monitor::OnAftertouch(uint8_t channel, uint8_t note, uint8_t velocity) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  ui.PrintNote(&line_buffer[2], note);
  line_buffer[6] = 'a';
  ui.PrintHex(&line_buffer[7], velocity);
  ui.RefreshScreen();
}

void Monitor::OnAftertouch(uint8_t channel, uint8_t velocity) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  line_buffer[2] = 'a';
  line_buffer[3] = 'f';
  line_buffer[4] = 't';
  ui.PrintHex(&line_buffer[6], velocity);
  ui.RefreshScreen();
}

void Monitor::OnControlChange(
    uint8_t channel,
    uint8_t controller,
    uint8_t value) {
  // 01234567
  // 1 C45 67
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  line_buffer[2] = '#';
  ui.PrintHex(&line_buffer[3], controller);
  ui.PrintHex(&line_buffer[6], value);
  ui.RefreshScreen();
}

void Monitor::OnProgramChange(uint8_t channel, uint8_t program) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  line_buffer[2] = 'p';
  line_buffer[3] = 'g';
  line_buffer[4] = 'm';
  ui.PrintHex(&line_buffer[6], program);
  ui.RefreshScreen();
}

void Monitor::OnPitchBend(uint8_t channel, uint16_t pitch_bend) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  line_buffer[2] = 'b';
  ui.PrintHex(&line_buffer[4], pitch_bend >> 8);
  ui.PrintHex(&line_buffer[6], pitch_bend & 0xff);
  ui.RefreshScreen();
}

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

void Monitor::OnAllSoundOff(uint8_t channel) {
  PrintString(channel, STR_RES_SNDOFF);
}

void Monitor::OnResetAllControllers(uint8_t channel) {
  PrintString(channel, STR_RES_RSTCTR);
}

void Monitor::OnLocalControl(uint8_t channel, uint8_t state) {
  ui.Clear();
  ui.PrintChannel(&line_buffer[0], channel);
  line_buffer[2] = 'l';
  line_buffer[3] = 'o';
  line_buffer[4] = 'c';
  ui.PrintHex(&line_buffer[6], state);
  ui.RefreshScreen();
}

void Monitor::OnAllNotesOff(uint8_t channel) {
  PrintString(channel, STR_RES_NOTOFF);
}

void Monitor::OnOmniModeOff(uint8_t channel) {
  PrintString(channel, STR_RES_OMNOFF);
}

void Monitor::OnOmniModeOn(uint8_t channel) {
  PrintString(channel, STR_RES_OMNION);
}

void Monitor::OnMonoModeOn(uint8_t channel, uint8_t num_channels) {
  PrintString(channel, STR_RES_MONOON);
}

void Monitor::OnPolyModeOn(uint8_t channel) {
  PrintString(channel, STR_RES_POLYON);
}

void Monitor::OnSysExStart() {
  PrintString(0xff, STR_RES_SYSX__);
}

void Monitor::OnSysExByte(uint8_t sysex_byte) {
  PrintString(0xff, STR_RES__SYSX_);
}

void Monitor::OnSysExEnd() {
  PrintString(0xff, STR_RES___SYSX);
}

void Monitor::OnBozoByte(uint8_t bozo_byte) {

}

void Monitor::OnClock() {
  if (ui.editing()) {
    return;
  }
  
  line_buffer[1] = 0xa5;
  ui.RefreshScreen();
}

void Monitor::OnStart() {
  PrintString(0xff, STR_RES_START);
}

void Monitor::OnContinue() {
  PrintString(0xff, STR_RES_CONT_);
}

void Monitor::OnStop() {
  PrintString(0xff, STR_RES_STOP);
}

void Monitor::OnActiveSensing() {
  if (ui.editing()) {
    return;
  }
  
  line_buffer[1] = '*';
  ui.RefreshScreen();
}

void Monitor::OnReset() {
  PrintString(0xff, STR_RES_RESET);
}

uint8_t Monitor::CheckChannel(uint8_t channel) {
  return (ui.editing() == 0) && 
      ((monitored_channel_ == 0) || (channel + 1 == monitored_channel_));
}

void Monitor::OnRawByte(uint8_t byte) {
  SendNow(byte);
}

uint8_t Monitor::OnClick() {
  ui.Clear();
  ui.RefreshScreen();
  return 0;
}

uint8_t Monitor::OnRedraw() {
  if (!ui.editing()) {
    return 1;  // Prevent the default screen redraw handler to be called.
  } else {
    return 0;
  }
}

} }  // namespace midipal::plugins
