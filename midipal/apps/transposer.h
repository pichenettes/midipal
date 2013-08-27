// Copyright 2012 Olivier Gillet.
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
// Transposer app.

#ifndef MIDIPAL_APPS_TRANSPOSER_H_
#define MIDIPAL_APPS_TRANSPOSER_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class Transposer {
 public:
  Transposer() { }

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

 protected:
  static uint8_t channel_;
  static int8_t transposition_;
  
  DISALLOW_COPY_AND_ASSIGN(Transposer);
};

} }  // namespace midipal::apps

#endif  // MIDIPAL_APPS_TRANSPOSER_H_
