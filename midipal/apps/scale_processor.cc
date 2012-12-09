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
// Scale processor app.

#include "midipal/apps/scale_processor.h"

#include "avrlib/random.h"

#include "midipal/display.h"

#include "midipal/clock.h"
#include "midipal/event_scheduler.h"
#include "midipal/note_stack.h"
#include "midipal/notes.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

enum VoiceMode {
  VOICE_MODE_OFF,
  VOICE_MODE_MIRROR,
  VOICE_MODE_ALTERNATE,
  VOICE_MODE_TRACK,
  VOICE_MODE_RANDOM,
};
  
using namespace avrlib;

const prog_uint8_t scale_processor_factory_data[6] PROGMEM = {
  0, 0, 1, 0, -12, 0
};

/* <static> */
uint8_t ScaleProcessor::channel_;
uint8_t ScaleProcessor::root_;
uint8_t ScaleProcessor::scale_;
uint8_t ScaleProcessor::original_;
uint8_t ScaleProcessor::voice_1_;
uint8_t ScaleProcessor::voice_2_;

uint8_t ScaleProcessor::lowest_note_;
uint8_t ScaleProcessor::previous_note_;
uint8_t ScaleProcessor::voice_2_note_;
uint8_t ScaleProcessor::flip_;
/* </static> */

/* static */
const prog_AppInfo ScaleProcessor::app_info_ PROGMEM = {
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
  6, // settings_size
  SETTINGS_SCALE_PROCESSOR, // settings_offset
  &channel_, // settings_data
  scale_processor_factory_data, // factory_data
  STR_RES_SCALE, // app_name
  true
};

/* static */
void ScaleProcessor::OnInit() {
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  ui.AddPage(STR_RES_ROO, STR_RES_C, 0, 24);
  ui.AddPage(STR_RES_SCL, STR_RES_CHR, 0, 24);
  ui.AddPage(STR_RES_TRS, UNIT_SIGNED_INTEGER, -24, 24);
  ui.AddPage(STR_RES_VOI, UNIT_SIGNED_INTEGER, -24, 24);
  ui.AddPage(STR_RES_HRM, STR_RES_OFF_, 0, 4);
  previous_note_ = 0;
  flip_ = 0;
}

/* static */
void ScaleProcessor::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  // Forward everything except note on for the selected channel.
  if (status != (0x80 | channel_) && 
      status != (0x90 | channel_) &&
      status != (0xa0 | channel_)) {
    app.Send(status, data, data_size);
  }
}

/* static */
void ScaleProcessor::OnNoteOn(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  note_stack.NoteOn(note, velocity);
  lowest_note_ = FactorizeMidiNote(note_stack.sorted_note(0).note).note;
  ProcessNoteMessage(0x90, note, velocity);
}

/* static */
void ScaleProcessor::OnNoteOff(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  note_stack.NoteOff(note);
  ProcessNoteMessage(0x80, note, velocity);
}

/* static */
void ScaleProcessor::OnNoteAftertouch(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  ProcessNoteMessage(0xa0, note, velocity);
}

/* static */
void ScaleProcessor::ProcessNoteMessage(
    uint8_t message,
    uint8_t note,
    uint8_t velocity) {
  note = Transpose(note, original_);
  
  if (root_ == 24) {
    // Dynamic root mode.
    if (message == 0x90) {
      note_map.Put(note, Constraint(note, lowest_note_, scale_));
    }
    NoteMapEntry* entry = note_map.Find(note);
    if (entry) {
      app.Send3(message | channel_, entry->value, velocity);
      if (voice_1_) {
        app.Send3(
            message | channel_,
            Transpose(entry->value, voice_1_),
            velocity);
      }
    }
    return;
  }
  
  // Static root.
  app.Send3(
      message | channel_,
      Constraint(note, root_, scale_),
      velocity);
  
  if (voice_1_) {
    app.Send3(
        message | channel_,
        Constraint(Transpose(note, voice_1_), root_, scale_),
        velocity);
  }
  if (voice_2_) {
    if (message == 0x90) {
      if (previous_note_ == 0) {
        voice_2_note_ = note;
      } else {
        int16_t voice_2_note = voice_2_note_;
        int16_t delta = static_cast<int16_t>(note) - previous_note_;
        switch (voice_2_) {
          case VOICE_MODE_MIRROR:
            voice_2_note -= delta;
            break;
          case VOICE_MODE_ALTERNATE:
            flip_ ^= 1;
            voice_2_note += flip_ ? delta : -delta;
            break;
          case VOICE_MODE_TRACK:
            voice_2_note += U8U8MulShift8(Random::GetByte(), 5) - 2;
            break;
          case VOICE_MODE_RANDOM:
            voice_2_note = static_cast<int16_t>(note) + \
                U8U8MulShift8(Random::GetByte(), 14) - 7;
            break;
        }
        while (voice_2_note > static_cast<int16_t>(note) + 24) {
          voice_2_note -= 12;
        }
        while (voice_2_note < static_cast<int16_t>(note) - 24) {
          voice_2_note += 12;
        }
        voice_2_note_ = Clip(voice_2_note, 0, 127);
      }
      previous_note_ = note;
      voice_2_note_ = Constraint(voice_2_note_, root_, scale_);
      note_map.Put(note, voice_2_note_);
    }
    
    NoteMapEntry* entry = note_map.Find(note);
    if (entry) {
      app.Send3(message | channel_, entry->value, velocity);
      if (message == 0x80) {
        entry->note = 0xff;
      }
    }
  }
}

} }  // namespace midipal::apps
