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
// Dispatcher plug-in.

#include "midipal/apps/dispatcher.h"

#include "avrlib/random.h"

#include "midi/midi.h"

#include "midipal/resources.h"
#include "midipal/ui.h"
#include "midipal/voice_allocator.h"

namespace midipal { namespace apps {

using namespace avrlib;

void Dispatcher::OnInit() {
  voice_allocator.Init();
  ui.AddPage(STR_RES_INP, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_MOD, STR_RES_CYC, 0, 3);
  ui.AddPage(STR_RES_OUT, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_NUM, UNIT_INTEGER, 1, 16);
  counter_ = 0;
}

void Dispatcher::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  uint8_t type = status & 0xf0;
  uint8_t channel = status & 0x0f;
  // Pass-through real time messages and messages on other channels.
  if (type == 0xf0 || channel != input_channel_) {
    Send(status, data, data_size);
    return;
  }
  
  // Forward the global messages to all channels.
  if (type != 0x80 && type != 0x90 && type != 0xa0) {
    for (uint8_t i = 0; i < num_voices_; ++i) {
      Send(type | ((base_channel_ + i) & 0x0f), data, data_size);
    }
  }
  // That's it, the note specific messages have dedicated handlers.
}

void Dispatcher::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  switch (mode_) {
    case DISPATCHER_CYCLIC:
      ++counter_;
      if (counter_ >= num_voices_) {
        counter_ = 0;
      }
      map_.Put(note, (counter_ + base_channel_) & 0xf);
      break;

    case DISPATCHER_POLYPHONIC_ALLOCATOR:
      voice_allocator.set_size(num_voices_);
      map_.Put(note, voice_allocator.NoteOn(note));
      break;
      
    case DISPATCHER_RANDOM:
      map_.Put(note, Random::GetByte() % num_voices_);
      break;
    
    case DISPATCHER_STACK:
      map_.Put(note, 0xff);
      break;
  }
  SendMessage(0x90, channel, note, velocity);
}

void Dispatcher::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  voice_allocator.NoteOff(note);
  SendMessage(0x80, channel, note, velocity);
}

void Dispatcher::OnAftertouch(uint8_t channel, uint8_t note, uint8_t velocity) {
  SendMessage(0xa0, channel, note, velocity);
}

void Dispatcher::SendMessage(
    uint8_t message,
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  NoteMapEntry* entry = map_.Find(note);
  if (entry) {
    if (entry-> value == 0xff) {
      for (uint8_t i = 0; i < num_voices_; ++i) {
        Send3(message | ((base_channel_ + i) & 0x0f), note, velocity);
      }
    } else {
      Send3(message | (entry->value & 0x0f), note, velocity);
    }
    if (message == 0x80) {
      entry->note = 0xff;
    }
  }
}

} }  // namespace midipal::plugins
