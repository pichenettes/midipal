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
// MIDI clock generator plug-in.

#ifndef MIDIPAL_PLUGINS_CLOCK_SOURCE_
#define MIDIPAL_PLUGINS_CLOCK_SOURCE_

#include "midipal/plugin.h"

namespace midipal { namespace plugins {

class ClockSource : public PlugIn {
 public:
  ClockSource() { }

  virtual void OnLoad();
  virtual void OnStart();
  virtual void OnStop();
  virtual void OnContinue();
  virtual void OnRawByte(uint8_t byte);
  
  virtual void SetParameter(uint8_t key, uint8_t value);
  virtual uint8_t GetParameter(uint8_t key);
  
  virtual void OnInternalClockTick();

 private:
  void UpdateCursor();
  void Stop();
  void Start();
  
  uint8_t running_;
  uint8_t bpm_;
  uint8_t groove_template_;
  uint8_t groove_amount_;
  
  DISALLOW_COPY_AND_ASSIGN(ClockSource);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_CLOCK_SOURCE_
