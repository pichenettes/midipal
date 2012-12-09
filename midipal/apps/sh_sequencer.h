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
// A sequencer app inspired by the SH-101 sequencer.

#ifndef MIDIPAL_APPS_SH_SEQUENCER_H_
#define MIDIPAL_APPS_SH_SEQUENCER_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

static const uint8_t kShSequencerNumSteps = 100;

class ShSequencer {
 public:
  ShSequencer() { }

  static void OnInit();
  static void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  static void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  static void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  
  static void OnInternalClockTick();
  static void OnContinue();
  static void OnStart();
  static void OnStop();
  static void OnClock();
  
  static void OnControlChange(
      uint8_t channel,
      uint8_t controller,
      uint8_t value);
  static void OnPitchBend(uint8_t channel, uint16_t value);

  static uint8_t OnClick();
  static uint8_t OnIncrement(int8_t increment);
  static uint8_t OnRedraw();
  
  static void SetParameter(uint8_t key, uint8_t value);
  
#ifdef MIDIBUD_FIRMWARE
  static uint8_t OnSwitch(uint8_t pot);
#endif  
  
  static const prog_AppInfo app_info_;
  
 private:
  static void Stop();
  static void Start();
  static void Tick();
  
  static uint8_t running_;
  static uint8_t recording_;
  static uint8_t clk_mode_;
  static uint8_t bpm_;
  static uint8_t groove_template_;
  static uint8_t groove_amount_;
  static uint8_t clock_division_;  
  static uint8_t channel_;
  static uint8_t num_steps_;
  static uint8_t sequence_data_[kShSequencerNumSteps];
  static uint8_t slide_data_[kShSequencerNumSteps / 8 + 1];
  static uint8_t accent_data_[kShSequencerNumSteps / 8 + 1];
  
  static uint8_t midi_clock_prescaler_;
  static uint8_t tick_;
  static uint8_t step_;
  static uint8_t root_note_;
  static uint8_t last_note_;
  static uint8_t rec_mode_menu_option_;
  static uint8_t pending_note_;
  
  DISALLOW_COPY_AND_ASSIGN(ShSequencer);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_SH_SEQUENCER_H_
