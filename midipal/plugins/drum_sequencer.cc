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
// Generic drum sequencer plugin.

#include "midipal/plugins/drum_sequencer.h"
#include "midipal/note_stack.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/resources.h"
#include "midipal/ui.h"

namespace midipal { namespace plugins {

using namespace avrlib;

void DrumSequencer::OnLoad() {
  for (uint8_t i = 0; i < 9; ++i) {
    SetParameter(i, LoadSetting(settings_base() + i));
  }
  
  ui.AddPage(STR_RES_CLK, STR_RES_INT, 0, 1);
  ui.AddPage(STR_RES_BPM, 0, 40, 240);
  ui.AddPage(STR_RES_GRV, STR_RES_SWG, 0, 5);
  ui.AddPage(STR_RES_AMT, 0, 0, 127);
  ui.AddPage(STR_RES_CHN, 0, 1, 16);
  ui.AddPage(STR_RES_PT1, 1, 20, 108);
  ui.AddPage(STR_RES_PT2, 1, 20, 108);
  ui.AddPage(STR_RES_PT3, 1, 20, 108);
  ui.AddPage(STR_RES_PT4, 1, 20, 108);
  clock.Start();
  idle_ticks_ = 96;
  OnInitImpl();
}

void DrumSequencer::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  // Forward everything except note on for the selected channel.
  if (status != (0x80 | (channel_ - 1)) && 
      status != (0x90 | (channel_ - 1))) {
    Send(status, data, data_size);
  }
}

void DrumSequencer::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

void DrumSequencer::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

void DrumSequencer::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 0;
  }
}

void DrumSequencer::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    Tick();
  }
}

void DrumSequencer::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL && running_) {
    Tick();
  }
}

void DrumSequencer::OnNoteOn(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_ - 1) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    // Reset the clock counter.
    if (idle_ticks_ >= 96) {
      clock.Start();
      running_ = 1;
    }
    idle_ticks_ = 0;
  }
  note_stack.NoteOn(note, velocity);
  ParseNotes();
}

void DrumSequencer::OnNoteOff(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_ - 1) {
    return;
  }
  note_stack.NoteOff(note);
}

void DrumSequencer::Tick() {
  ++tick_;
  
  // Stop the internal clock when no key has been pressed for the duration
  // of 1 bar.
  ++idle_ticks_;
  if (idle_ticks_ >= 96) {
    idle_ticks_ = 96;
    if (clk_mode_ == CLOCK_MODE_INTERNAL) {
      running_ = 0;
    }
  }
  TickImpl();
}

void DrumSequencer::SetParameter(uint8_t key, uint8_t value) {
  static_cast<uint8_t*>(&clk_mode_)[key] = value;
  SaveSetting(settings_base() + key, value);
  if (key < 4) {
    clock.Update(bpm_, groove_template_, groove_amount_);
  }
}

uint8_t DrumSequencer::GetParameter(uint8_t key) {
  return static_cast<uint8_t*>(&clk_mode_)[key];
}

} }  // namespace midipal::plugins
