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
// Chord memory app.

#include "midipal/apps/chord_memory.h"

#include "midi/midi.h"

#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t chord_memory_factory_data[kMaxChordNotes + 2] PROGMEM = {
  0, 4, 60, 63, 67, 70, 48, 48, 48, 48, 48, 48,
};

/* static */
uint8_t ChordMemory::channel_;

/* static */
uint8_t ChordMemory::num_notes_;

/* static */
uint8_t ChordMemory::chord_[kMaxChordNotes];

/* static */
uint8_t ChordMemory::root_;

/* static */
const prog_AppInfo ChordMemory::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  &OnNoteOn, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  &OnNoteOff, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  &OnNoteAftertouch, // void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
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
  NULL, // void (*OnInternalClockTick)();
  NULL, // void (*OnInternalClockStep)();
  NULL, // uint8_t (*OnIncrement)(int8_t);
  &OnClick, // uint8_t (*OnClick)();
#ifdef MIDIBUD_FIRMWARE
  NULL, // uint8_t (*OnSwitch)(uint8_t);
#else
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
#endif
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  NULL, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  kMaxChordNotes + 2, // settings_size
  SETTINGS_CHORD_MEMORY, // settings_offset
  &channel_, // settings_data
  chord_memory_factory_data, // factory_data
  STR_RES_CHORDMEM, // app_name
  true
};

/* static */
void ChordMemory::OnInit() {
  ui.AddPage(STR_RES_CHN, UNIT_INTEGER_ALL, 0, 16);
}

/* static */
void ChordMemory::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  uint8_t type = status & 0xf0;
  if (type != 0x80 && type != 0x90 && type != 0xa0) {
    app.Send(status, data, data_size);
  }
}

/* static */
uint8_t ChordMemory::OnClick() {
  if (!ui.editing()) {
    num_notes_ = 0;
  } else {
    app.SaveSettings();
  }
  return 0;
}

/* static */
void ChordMemory::PlayChord(
    uint8_t type,
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (num_notes_ == 0) {
    app.Send3(type | channel, note, velocity);
  } else {
    for (uint8_t i = 0; i < num_notes_; ++i) {
      int16_t n = note;
      n += chord_[i] - chord_[0];
      while (n < 0) {
        n += 12;
      }
      while (n > 127) {
        n -= 12;
      }
      app.Send3(type | channel, static_cast<uint8_t>(n), velocity);
    }
  }
}

/* static */
void ChordMemory::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel_ && channel_ != (channel + 1)) {
    app.Send3(0x90 | channel, note, velocity);
  } else {
    // Record mode.
    if (ui.editing()) {
      chord_[num_notes_++] = note;
      // Rotate buffer of recorded notes to avoid overflow ; but do not
      // touch the first note.
      if (num_notes_ == kMaxChordNotes) {
        for (uint8_t i = 1; i < kMaxChordNotes - 1; ++i) {
          chord_[i] = chord_[i + 1];
        }
        num_notes_ = kMaxChordNotes - 1;
      }
      app.Send3(0x90 | channel, note, velocity);
    } else {
      PlayChord(0x90, channel, note, velocity);
    }
  }
}

/* static */
void ChordMemory::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  if ((channel_ && channel_ != (channel + 1)) || ui.editing()) {
    app.Send3(0x80 | channel, note, velocity);
  } else {
    PlayChord(0x80, channel, note, velocity);
  }
}

/* static */
void ChordMemory::OnNoteAftertouch(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if ((channel_ && channel_ != (channel + 1)) || ui.editing()) {
    app.Send3(0xa0 | channel, note, velocity);
  } else {
    PlayChord(0xa0, channel, note, velocity);
  }
}

} }  // namespace midipal::apps
