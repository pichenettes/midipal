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
// Latch app.
//
// 02/09 - 9:30 PM .. 11:30 PM. Project setup, UI, interrupt logic.
// 03/09 - 7:00 PM .. 8:00 PM. Merge with latest code branch, tests.

#ifndef MIDIPAL_APPS_LATCH_H_
#define MIDIPAL_APPS_LATCH_H_

#include "midipal/app.h"
#include "midipal/note_map.h"

namespace midipal { namespace apps {

struct HeldNoteEntry {
  uint8_t note;
  uint8_t channel;
};

enum LatchMode {
  mode_MONO,
  mode_POLY,
  mode_CHORD
};

class Latch {
 public:
  Latch() { }

  static void OnInit();
  static void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
  static void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  static void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  static void SetParameter(uint8_t key, uint8_t value);
  
  static const prog_AppInfo app_info_;
  
 private:
  static void KillSustainedNotesByChannel(uint16_t bitmask);
  static bool is_active_channel(uint8_t channel) {
    return channel >= channel_min_ && channel <= channel_max_;
  }
  static void SendMessage(
      uint8_t message,
      uint8_t channel,
      uint8_t note,
      uint8_t velocity);
  
  static uint8_t mode_;
  static uint8_t channel_min_;
  static uint8_t channel_max_;
  static uint8_t int_mode_;
  static uint8_t int_note_min_;
  static uint8_t int_note_max_;
  static uint8_t int_velocity_min_;
  static uint8_t int_velocity_max_;
  
  static uint16_t kill_mask_;
  
  static HeldNoteEntry* held_notes_;
  
  DISALLOW_COPY_AND_ASSIGN(Latch);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_LATCH_H_
