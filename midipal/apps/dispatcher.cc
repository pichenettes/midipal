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
// Dispatcher app.

#include "midipal/apps/dispatcher.h"

#include "avrlib/random.h"

#include "midi/midi.h"

#include "midipal/notes.h"
#include "midipal/ui.h"
#include "midipal/voice_allocator.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t dispatcher_factory_data[4] PROGMEM = {
  0, 0, 0, 3
};

/* static */
uint8_t Dispatcher::input_channel_;

/* static */
uint8_t Dispatcher::mode_;

/* static */
uint8_t Dispatcher::base_channel_;

/* static */
uint8_t Dispatcher::num_voices_;

/* static */
uint8_t Dispatcher::counter_;

/* static */
const prog_AppInfo Dispatcher::app_info_ PROGMEM = {
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
  NULL, // uint8_t (*OnClick)();
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
  4, // settings_size
  SETTINGS_DISPATCHER, // settings_offset
  &input_channel_, // settings_data
  dispatcher_factory_data, // factory_data
  STR_RES_DISPATCH, // app_name
  true
};

/* static */
void Dispatcher::OnInit() {
  voice_allocator.Init();
  ui.AddPage(STR_RES_INP, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_MOD, STR_RES_CYC, 0, 4);
  ui.AddPage(STR_RES_OUT, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_NUM, UNIT_INTEGER, 1, 16);
  counter_ = 0;
}

/* static */
void Dispatcher::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  uint8_t type = status & 0xf0;
  uint8_t channel = status & 0x0f;
  // Pass-through real time messages and messages on other channels.
  if (type == 0xf0 || channel != input_channel_) {
    app.Send(status, data, data_size);
    return;
  }
  
  // Forward the global messages to all channels.
  if (type != 0x80 && type != 0x90 && type != 0xa0) {
    for (uint8_t i = 0; i < num_voices_; ++i) {
      app.Send(type | ((base_channel_ + i) & 0x0f), data, data_size);
    }
  }
  // That's it, the note specific messages have dedicated handlers.
}

/* static */
void Dispatcher::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != input_channel_) {
    return;
  }
  switch (mode_) {
    case DISPATCHER_CYCLIC:
      ++counter_;
      if (counter_ >= num_voices_) {
        counter_ = 0;
      }
      note_map.Put(note, counter_);
      break;

    case DISPATCHER_POLYPHONIC_ALLOCATOR:
      voice_allocator.set_size(num_voices_);
      note_map.Put(note, voice_allocator.NoteOn(note));
      break;
      
    case DISPATCHER_RANDOM:
      note_map.Put(note, Random::GetByte() % num_voices_);
      break;
    
    case DISPATCHER_STACK:
      note_map.Put(note, 0xff);
      break;
      
    case DISPATCHER_VELOCITY:
      note_map.Put(note, U8U8MulShift8(velocity << 1, num_voices_));
      break;
  }
  SendMessage(0x90, channel, note, velocity);
}

/* static */
void Dispatcher::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel != input_channel_) {
    return;
  }
  voice_allocator.NoteOff(note);
  SendMessage(0x80, channel, note, velocity);
}

/* static */
void Dispatcher::OnNoteAftertouch(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != input_channel_) {
    return;
  }
  SendMessage(0xa0, channel, note, velocity);
}

/* static */
void Dispatcher::SendMessage(
    uint8_t message,
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  NoteMapEntry* entry = note_map.Find(note);
  if (entry) {
    if (entry-> value == 0xff) {
      for (uint8_t i = 0; i < num_voices_; ++i) {
        app.Send3(message | ((base_channel_ + i) & 0x0f), note, velocity);
      }
    } else {
      app.Send3(message | ((base_channel_ + entry->value) & 0x0f), note, velocity);
    }
    if (message == 0x80) {
      entry->note = 0xff;
    }
  }
}

} }  // namespace midipal::apps
