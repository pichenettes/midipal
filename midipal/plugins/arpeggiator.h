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
// Arpeggiator plug-in.

#ifndef MIDIPAL_PLUGINS_ARPEGGIATOR_H_
#define MIDIPAL_PLUGINS_ARPEGGIATOR_H_

#include "midipal/plugin.h"

namespace midipal { namespace plugins {

class Arpeggiator : public PlugIn {
 public:
  Arpeggiator() { }

  void OnInit();
  void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);

  void OnContinue();
  void OnStart();
  void OnStop();
  void OnClock();
  void OnInternalClockTick();

  void SetParameter(uint8_t key, uint8_t value);
  
  uint8_t settings_size() { return 10; }
  uint8_t settings_offset() { return SETTINGS_ARPEGGIATOR; }
  uint8_t* settings_data() { return &clk_mode_; }

 protected:
  void Tick();
  void Start();
  void StartArpeggio();
  void StepArpeggio();
  
  uint8_t running_;
   
  uint8_t clk_mode_;
  uint8_t bpm_;
  uint8_t groove_template_;
  uint8_t groove_amount_;
  uint8_t channel_;
  uint8_t direction_;
  uint8_t num_octaves_;
  uint8_t pattern_;
  uint8_t clock_division_;
  uint8_t duration_;
  
  uint8_t midi_clock_prescaler_;
  
  uint8_t tick_;
  uint8_t idle_ticks_;
  uint16_t bitmask_;
  int8_t current_direction_;
  int8_t current_octave_;
  int8_t current_step_;
  
  DISALLOW_COPY_AND_ASSIGN(Arpeggiator);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_ARPEGGIATOR_H_
