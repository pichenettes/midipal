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
// Sequencer app.

#ifndef MIDIPAL_APPS_POLY_SEQUENCER_H_
#define MIDIPAL_APPS_POLY_SEQUENCER_H_

#include "midipal/app.h"

namespace midipal { namespace apps {
  
static const uint8_t kPSNumTracks = 6;
static const uint8_t kPSNumSteps = 128;


class PolySequencer {
 public:
  PolySequencer() { }

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

  static uint8_t OnClick();
  static uint8_t OnIncrement(int8_t increment);
  static uint8_t OnRedraw();

  static void SetParameter(uint8_t key, uint8_t value);
  
  static const prog_AppInfo app_info_;
  
 private:
  // Record a note (midi note#) ; 0xfe for tie ; 0xff for rest.
  static void Record(uint8_t note);
  static void Stop();
  static void Start();
  static void Tick();
  
  static uint8_t running_;
  static uint8_t recording_;
  static uint8_t overdubbing_;
  static uint8_t clk_mode_;
  static uint8_t bpm_;
  static uint8_t groove_template_;
  static uint8_t groove_amount_;
  static uint8_t clock_division_;  
  static uint8_t channel_;
  static uint8_t num_steps_;
  static uint8_t sequence_data_[kPSNumSteps * kPSNumTracks];
  
  static uint8_t midi_clock_prescaler_;
  static uint8_t tick_;
  static uint8_t step_;
  static uint8_t edit_step_;
  static uint8_t root_note_;
  static uint8_t last_note_;
  static uint8_t previous_rec_note_;
  static uint8_t rec_mode_menu_option_;
  static uint8_t pending_notes_[kPSNumTracks];
  static uint8_t pending_notes_transposed_[kPSNumTracks];
  
  DISALLOW_COPY_AND_ASSIGN(PolySequencer);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_POLY_SEQUENCER_H_
