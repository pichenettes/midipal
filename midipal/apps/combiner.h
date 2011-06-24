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
// Channel merger app.

#ifndef MIDIPAL_APPS_COMBINER_H_
#define MIDIPAL_APPS_COMBINER_H_

#include "midipal/app.h"
#include "midipal/note_map.h"

namespace midipal { namespace apps {

class Combiner {
 public:
  Combiner() { }

  static void OnInit();
  static void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
 
  static const prog_AppInfo app_info_;
 
 private:
  static uint8_t input_channel_;
  static uint8_t num_channels_;
  static uint8_t output_channel_;

  DISALLOW_COPY_AND_ASSIGN(Combiner);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_COMBINER_H_
