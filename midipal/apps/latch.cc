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

#include "midipal/apps/latch.h"

#include "midi/midi.h"

#include "midipal/notes.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const uint8_t kMaxHeldNotes = 32;

const prog_uint8_t latch_factory_data[8] PROGMEM = {
  0, 0, 0, 0, 0, 127, 0, 127
};

/* static */
uint8_t Latch::poly_mode_;

/* static */
uint8_t Latch::channel_min_;

/* static */
uint8_t Latch::channel_max_;

/* static */
uint8_t Latch::int_mode_;

/* static */
uint8_t Latch::int_note_min_;

/* static */
uint8_t Latch::int_note_max_;

/* static */
uint8_t Latch::int_velocity_min_;

/* static */
uint8_t Latch::int_velocity_max_;

/* static */
HeldNoteEntry* Latch::held_notes_;

/* static */
const prog_AppInfo Latch::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  &OnNoteOn, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  &OnNoteOff, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnAftertouch)(uint8_t, uint8_t);
  NULL, // void (*OnControlChange)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnProgramChange)(uint8_t, uint8_t);
  NULL, // void (*OnPitchBend)(uint8_t, uint16_t);
  NULL, // void (*OnSysExByte)(uint8_t);
  NULL, // void (*OnClock)();
  NULL, // void (*OnStart)();
  NULL, // void (*OnContinue)();
  NULL, // void (*OnStop)();
  NULL, // uint8_t (*CheckChannel)(uint8_t);
  NULL, // void (*OnRawByte)(uint8_t);
  &OnRawMidiData, // void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t);
  NULL, // uint8_t (*OnIncrement)(int8_t);
  NULL, // uint8_t (*OnClick)();
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
  NULL, // uint8_t (*OnRedraw)();
  &SetParameter, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  8, // settings_size
  SETTINGS_LATCH, // settings_offset
  &poly_mode_, // settings_data
  latch_factory_data, // factory_data
  STR_RES_LATCH, // app_name
  true
};

/* static */
void Latch::OnInit() {
  ui.AddPage(STR_RES_MOD, STR_RES_MONOON, 0, 1);
  ui.AddPage(STR_RES_CHG, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_CHL, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_INT, STR_RES_OFFI, 0, 2);
  ui.AddPage(STR_RES_NOG, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_NOL, UNIT_INTEGER, 0, 127);
  ui.AddPage(STR_RES_VEG, UNIT_INTEGER, 1, 127);
  ui.AddPage(STR_RES_VELL, UNIT_INTEGER, 1, 127);
  
  held_notes_ = static_cast<HeldNoteEntry*>(note_map.raw_data());
  
  for (uint8_t i = 0; i < kMaxHeldNotes; ++i) {
    held_notes_[i].note = 0xff;
    held_notes_[i].channel = 0xff;
  }
}

/* static */
void Latch::SetParameter(uint8_t key, uint8_t value) {
  if (key == 0) {
    // When the mode is changed; kill all notes.
    if (value != poly_mode_) {
      KillSustainedNotesByChannel(0xffff);
    }
  }
  static_cast<uint8_t*>(&poly_mode_)[key] = value;
  
  if (key <= 2) {
    uint16_t to_kill = 0;
    for (uint16_t i = 0; i < 16; ++i) {
      if (!is_active_channel(i)) {
        to_kill |= 1 << i;
      }
    }
    KillSustainedNotesByChannel(to_kill);
  }
}

/* static */
void Latch::KillSustainedNotesByChannel(uint16_t bitmask) {
  for (uint8_t i = 0; i < kMaxHeldNotes; ++i) {
    HeldNoteEntry& entry = held_notes_[i];
    bool is_valid = entry.note != 0xff && entry.channel != 0xff;
    bool destroy = is_valid && ((1 << uint16_t(entry.channel)) & bitmask);
    if (destroy) {
      app.Send3(0x80 | entry.channel, entry.note, 0);
      entry.channel = 0xff;
      entry.note = 0xff;
    }
  }
}

/* static */
void Latch::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  uint8_t type = status & 0xf0;
  if (type != 0x80 && type != 0x90) {
    app.Send(status, data, data_size);
  }
}

/* static */
void Latch::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  // Pass-through anything on the inactive channels.
  if (!is_active_channel(channel)) {
    app.Send3(0x90 | channel, note, velocity);
    return;
  }
  
  // Note-on with velocity zero is ignored.
  if (velocity == 0) {
    return;
  }
  
  // Check if the note is an int trigger.
  bool note_in_range = note >= int_note_min_ && note <= int_note_max_;
  bool velocity_in_range = velocity >= int_velocity_min_ && velocity <= int_velocity_max_;
  bool interrupt = note_in_range && velocity_in_range && int_mode_;
  
  if (interrupt) {
    KillSustainedNotesByChannel(
        int_mode_ == 1 ? 0xffff : (1 << uint16_t(channel)));
  } else {
    if (poly_mode_) {
      uint8_t index = 0xff;
      uint8_t blank_entry = 0xff;
      for (uint8_t i = 0; i < kMaxHeldNotes; ++i) {
        const HeldNoteEntry& entry = held_notes_[i];
        if (entry.channel == channel && entry.note == note) {
          index = i;
        }
        if (entry.channel == 0xff && entry.note == 0xff) {
          blank_entry = i;
        }
      }
      
      // The note has been played before. Stop it and remove it from the list.
      if (index != 0xff) {
        app.Send3(0x80 | channel, note, 0);
        held_notes_[index].channel = 0xff;
        held_notes_[index].note = 0xff;
      } else {
        if (blank_entry != 0xff) {
          held_notes_[blank_entry].channel = channel;
          held_notes_[blank_entry].note = note;
          app.Send3(0x90 | channel, note, velocity);
        }
      }
    } else {
      HeldNoteEntry& entry = held_notes_[channel];
      bool kill_old = false;
      bool play_new = false;
      
      kill_old = entry.note != 0xff && entry.note != note;
      play_new = entry.note != note;
      
      if (kill_old) {
        app.Send3(0x80 | channel, entry.note, 0);
      }
      if (play_new) {
        app.Send3(0x90 | channel, note, velocity);
      }
      
      // Replace with new note in map.
      entry.note = note;
      entry.channel = channel;
    }
  }
}

/* static */
void Latch::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  // Pass-through anything on the inactive channels.
  if (!is_active_channel(channel)) {
    app.Send3(0x80 | channel, note, velocity);
    return;
  }
}

} }  // namespace midipal::apps
