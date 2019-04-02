// Copyright 2011 Emilie Gillet.
//
// Author: Emilie Gillet (emilie.o.gillet@gmail.com)
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
// Randomizer app.

#ifndef MIDIPAL_APPS_RANDOMIZER_H_
#define MIDIPAL_APPS_RANDOMIZER_H_

#include "midipal/app.h"
#include "midipal/note_map.h"

namespace midipal { namespace apps {

class Randomizer {
 public:
  Randomizer() { }

  static void OnInit();
  static void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  static void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  static void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  static void OnNoteAftertouch(uint8_t channel, uint8_t note, uint8_t velocity);
  
  static const prog_AppInfo app_info_;
  
 private:
  static void SendMessage(
      uint8_t message,
      uint8_t channel,
      uint8_t note,
      uint8_t velocity);
  static uint8_t ScaleModulationAmount(uint8_t amount);
  
  static uint8_t channel_;
  static uint8_t global_amount_;
  static uint8_t note_amount_;
  static uint8_t velocity_amount_;
  static uint8_t cc_amount_[2];
  static uint8_t cc_[2];
  
  DISALLOW_COPY_AND_ASSIGN(Randomizer);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_RANDOMIZER_H_
