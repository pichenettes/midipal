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
// Drum pattern generator app.

#include "midipal/apps/drum_pattern_generator.h"
#include "midipal/note_stack.h"

#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/notes.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

const prog_uint8_t drum_pattern_generator_factory_data[10] PROGMEM = {
  0, 0, 120, 0, 0, 9, 36, 40, 42, 56
};

// <static>
uint8_t DrumPatternGenerator::running_;
 
uint8_t DrumPatternGenerator::mode_;
uint8_t DrumPatternGenerator::clk_mode_;
uint8_t DrumPatternGenerator::bpm_;
uint8_t DrumPatternGenerator::groove_template_;
uint8_t DrumPatternGenerator::groove_amount_;
uint8_t DrumPatternGenerator::channel_;
uint8_t DrumPatternGenerator::part_instrument_[kNumDrumParts];

uint8_t DrumPatternGenerator::tick_;
uint8_t DrumPatternGenerator::idle_ticks_;

uint8_t DrumPatternGenerator::active_note_[kNumDrumParts];

uint8_t DrumPatternGenerator::euclidian_num_notes_[kNumDrumParts];
uint8_t DrumPatternGenerator::euclidian_num_steps_[kNumDrumParts];
uint8_t DrumPatternGenerator::euclidian_step_count_[kNumDrumParts];
uint16_t DrumPatternGenerator::euclidian_bitmask_[kNumDrumParts];

uint8_t DrumPatternGenerator::active_pattern_[kNumDrumParts];
uint8_t DrumPatternGenerator::step_count_;
uint16_t DrumPatternGenerator::bitmask_;
// </static>

/* static */
const prog_AppInfo DrumPatternGenerator::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  &OnNoteOn, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  &OnNoteOff, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnAftertouch)(uint8_t, uint8_t);
  NULL, // void (*OnControlChange)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnProgramChange)(uint8_t, uint8_t);
  NULL, // void (*OnPitchBend)(uint8_t, uint16_t);
  NULL, // void (*OnSysExByte)(uint8_t);
  &OnClock, // void (*OnClock)();
  &OnStart, // void (*OnStart)();
  &OnContinue, // void (*OnContinue)();
  &OnStop, // void (*OnStop)();
  NULL, // uint8_t (*CheckChannel)(uint8_t);
  NULL, // void (*OnRawByte)(uint8_t);
  &OnRawMidiData, // void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t);
  &OnInternalClockTick, // void (*OnInternalClockTick)();
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
  &SetParameter, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  10, // settings_size
  SETTINGS_DRUM_PATTERN_GENERATOR, // settings_offset
  &mode_, // settings_data
  drum_pattern_generator_factory_data, // factory_data
  STR_RES_DRUMS, // app_name
  true
};

static const prog_uint8_t sizes[12] PROGMEM = {
  0, 1, 2, 3, 4, 5, 6, 8, 10, 12, 14, 16  
};

/* static */
void DrumPatternGenerator::OnInit() {
  ui.AddPage(STR_RES_MOD, STR_RES_PTN, 0, 1);
  ui.AddClockPages();
  ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 15);
  for (uint8_t i = 0; i < kNumDrumParts; ++i) {
    ui.AddPage(STR_RES_PT1 + i, UNIT_NOTE, 20, 108);
  }
  clock.Update(bpm_, groove_template_, groove_amount_);
  clock.Start();
  
  memset(&active_pattern_[0], 0, kNumDrumParts);
  for (uint8_t i = 0; i < kNumDrumParts; ++i) {
    euclidian_num_notes_[i] = 0;
    euclidian_num_steps_[i] = 11; // 16 steps
  }
  idle_ticks_ = 96;
  running_ = 0;
}

/* static */
void DrumPatternGenerator::Reset() {
  step_count_ = 0;
  bitmask_ = 1;
  tick_ = 0;
}

/* static */
void DrumPatternGenerator::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel) {
  // Forward everything except note on for the selected channel.
  if (status != (0x80 | channel_) && 
      status != (0x90 | channel_)) {
    app.Send(status, data, data_size);
  }
}

/* static */
void DrumPatternGenerator::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

/* static */
void DrumPatternGenerator::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
    Reset();
  }
}

/* static */
void DrumPatternGenerator::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 0;
  }
  AllNotesOff();
}

/* static */
void DrumPatternGenerator::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    Tick();
  }
}

/* static */
void DrumPatternGenerator::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL && running_) {
    app.SendNow(0xf8);
    Tick();
  }
}

/* static */
void DrumPatternGenerator::OnNoteOn(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  if (clk_mode_ == CLOCK_MODE_INTERNAL) {
    // Reset the clock counter.
    if (idle_ticks_ >= 96) {
      clock.Start();
      Reset();
      running_ = 1;
      app.SendNow(0xfa);
    }
    idle_ticks_ = 0;
  }
  note_stack.NoteOn(note, velocity);
  if (mode_ == 0) {
    // Select pattern depending on played notes.
    for (uint8_t i = 0; i < note_stack.size(); ++i) {
      Note n = FactorizeMidiNote(note_stack.sorted_note(i).note);
      uint8_t part = (n.octave >= 7) ? 3 : (n.octave <= 3 ? 0 : n.octave - 3);
      active_pattern_[part] = n.note;
    }
  } else {
    // Select pattern depending on played notes.
    uint8_t previous_octave = 0xff;
    for (uint8_t i = 0; i < note_stack.size(); ++i) {
      Note n = FactorizeMidiNote(note_stack.sorted_note(i).note);
      uint8_t part = (n.octave >= 7) ? 3 : (n.octave <= 3 ? 0 : n.octave - 3);
      if (n.octave == previous_octave) {
        euclidian_num_steps_[part] = n.note;
      } else {
        euclidian_num_notes_[part] = n.note;
        euclidian_step_count_[part] = 0;
        euclidian_bitmask_[part] = 1;
      }
      previous_octave = n.octave;
    }
  }
}

/* static */
void DrumPatternGenerator::OnNoteOff(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity) {
  if (channel != channel_) {
    return;
  }
  note_stack.NoteOff(note);
}

/* static */
void DrumPatternGenerator::Tick() {
  if (!running_) {
    return;
  }
  ++tick_;
  
  // Stop the internal clock when no key has been pressed for the duration
  // of 1 bar.
  ++idle_ticks_;
  if (idle_ticks_ >= 96) {
    idle_ticks_ = 96;
    if (clk_mode_ == CLOCK_MODE_INTERNAL) {
      running_ = 0;
      AllNotesOff();
      app.SendNow(0xfc);
    }
  }
  if (tick_ == 6) {
    tick_ = 0;
    if (mode_ == 0) {
      // Preset pattern.
      uint8_t offset = 0;
      for (uint8_t part = 0; part < 4; ++part) {
        if (active_pattern_[part]) {
          idle_ticks_ = 0;
        }
        uint16_t pattern = ResourcesManager::Lookup<uint16_t, uint8_t>(
              lut_res_drum_patterns, active_pattern_[part] + offset);
        offset += 12;
        if (pattern & bitmask_) {
          TriggerNote(part);
        }
      }
      ++step_count_;
      bitmask_ <<= 1;
      if (step_count_ == 16) {
        step_count_ = 0;
        bitmask_ = 1;
      }
    } else {
      // Euclidian pattern.
      for (uint8_t part = 0; part < kNumDrumParts; ++part) {
        // Skip the muted parts.
        if (euclidian_num_notes_[part]) {
          // Continue running the sequencer as long as something is playing.
          idle_ticks_ = 0;
          uint16_t pattern = ResourcesManager::Lookup<uint16_t, uint8_t>(
              lut_res_euclidian_patterns,
              euclidian_num_notes_[part] + euclidian_num_steps_[part] * 12);
          uint16_t mask = euclidian_bitmask_[part];
          if (pattern & mask) {
            TriggerNote(part);
          }
        }
        ++euclidian_step_count_[part];
        euclidian_bitmask_[part] <<= 1;
        if (euclidian_step_count_[part] == ResourcesManager::Lookup<
                uint16_t, uint8_t>(sizes, euclidian_num_steps_[part])) {
          euclidian_step_count_[part] = 0;
          euclidian_bitmask_[part] = 1;
        }
      }
    }
  } else if (tick_ == 3) {
    AllNotesOff();
  }
}

/* static */
void DrumPatternGenerator::TriggerNote(uint8_t part) {
  app.Send3(0x90 | channel_, part_instrument_[part], 0x64);
  active_note_[part] = part_instrument_[part];
}

/* static */
void DrumPatternGenerator::AllNotesOff() {
  for (uint8_t part = 0; part < kNumDrumParts; ++part) {
    if (active_note_[part]) {
      app.Send3(0x80 | channel_, part_instrument_[part], 0);
      active_note_[part] = 0;
    }
  }
}

/* static */
void DrumPatternGenerator::SetParameter(uint8_t key, uint8_t value) {
  static_cast<uint8_t*>(&mode_)[key] = value;
  if (key < 5) {
    clock.Update(bpm_, groove_template_, groove_amount_);
  }
}

} }  // namespace midipal::apps
