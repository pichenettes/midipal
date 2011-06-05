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

#ifndef MIDIPAL_PLUGINS_DRUM_SEQUENCER_H_
#define MIDIPAL_PLUGINS_DRUM_SEQUENCER_H_

#include "midipal/plugin.h"

namespace midipal { namespace plugins {

enum CLOCK_MODE {
  CLOCK_MODE_INTERNAL,
  CLOCK_MODE_EXTERNAL
};

class DrumSequencer : public PlugIn {
 public:
  DrumSequencer() { }

  virtual void OnLoad();
  virtual void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  virtual void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  virtual void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);

  virtual void OnContinue();
  virtual void OnStart();
  virtual void OnStop();
  virtual void OnClock();
  virtual void OnInternalClockTick();

  virtual void SetParameter(uint8_t key, uint8_t value);
  virtual uint8_t GetParameter(uint8_t key);
  
 protected:
  void Tick();

  virtual void OnInitImpl() { }
  virtual void ParseNotes() { }
  virtual void TickImpl() { }
  virtual uint8_t settings_base() { return 0; }
  
  uint8_t running_;
   
  uint8_t clk_mode_;
  uint8_t bpm_;
  uint8_t groove_template_;
  uint8_t groove_amount_;
  uint8_t channel_;
  uint8_t part_instrument_[4];
  
  uint8_t tick_;
  uint8_t idle_ticks_;
  
  DISALLOW_COPY_AND_ASSIGN(DrumSequencer);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_DRUM_SEQUENCER_H_
