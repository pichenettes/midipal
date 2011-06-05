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
// Splitter plug-in.

#ifndef MIDIPAL_PLUGINS_SPLITTER_H_
#define MIDIPAL_PLUGINS_SPLITTER_H_

#include "midipal/plugin.h"

namespace midipal { namespace plugins {

class Splitter : public PlugIn {
 public:
  Splitter() { }

  virtual void OnLoad();
  virtual void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  virtual void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  virtual void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  virtual void OnAftertouch(uint8_t channel, uint8_t note, uint8_t velocity);

  virtual void SetParameter(uint8_t key, uint8_t value);
  virtual uint8_t GetParameter(uint8_t key);
  
 private:
  void Split(uint8_t type, uint8_t channel, uint8_t note, uint8_t velocity);
  uint8_t input_channel_;
  uint8_t split_point_;
  uint8_t lower_channel_;
  uint8_t upper_channel_;
  
  DISALLOW_COPY_AND_ASSIGN(Splitter);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_SPLITTER_H_
