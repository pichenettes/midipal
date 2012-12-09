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
// Base class implemented by all the "Apps" running on the Midipal.

#include "midipal/app.h"

#include <avr/eeprom.h>

#include "avrlib/serial.h"

#include "midipal/display.h"
#include "midipal/hardware_config.h"
#include "midipal/event_scheduler.h"
#include "midipal/midi_handler.h"

#include "midipal/apps/app_selector.h"
#include "midipal/apps/arpeggiator.h"
#include "midipal/apps/bpm_meter.h"
#include "midipal/apps/cc_knob.h"
#include "midipal/apps/chord_memory.h"
#include "midipal/apps/clock_divider.h"
#include "midipal/apps/clock_source.h"
#include "midipal/apps/clock_source_hd.h"
#include "midipal/apps/clock_source_live.h"
#include "midipal/apps/combiner.h"
#include "midipal/apps/controller.h"
#include "midipal/apps/delay.h"
#include "midipal/apps/dispatcher.h"
#include "midipal/apps/drum_pattern_generator.h"
#include "midipal/apps/ear_training_game.h"
#include "midipal/apps/filter.h"
#include "midipal/apps/generic_filter.h"
#include "midipal/apps/lfo.h"
#include "midipal/apps/monitor.h"
#include "midipal/apps/poly_sequencer.h"
#include "midipal/apps/randomizer.h"
#include "midipal/apps/scale_processor.h"
#include "midipal/apps/sequencer.h"
#include "midipal/apps/sh_sequencer.h"
#include "midipal/apps/sync_latch.h"
#include "midipal/apps/settings.h"
#include "midipal/apps/splitter.h"
#include "midipal/apps/tanpura.h"

namespace midipal {

/* extern */
const prog_uint8_t midi_clock_tick_per_step[17] PROGMEM = {
  192, 144, 96, 72, 64, 48, 36, 32, 24, 16, 12, 8, 6, 4, 3, 2, 1
};
  
using namespace avrlib;

Serial<MidiPort, 31250, DISABLED, POLLED> midi_out;

/* static */
AppInfo App::app_info_;

#ifdef POLY_SEQUENCER_FIRMWARE

const AppInfo* registry[] = {
  &apps::AppSelector::app_info_,
  &apps::Monitor::app_info_,
  &apps::PolySequencer::app_info_,
  &apps::ClockSource::app_info_,
  &apps::SyncLatch::app_info_,
};

#else

const AppInfo* registry[] = {
  &apps::AppSelector::app_info_,
  
  &apps::Monitor::app_info_,
  &apps::BpmMeter::app_info_,
  
  &apps::Filter::app_info_,
  &apps::Splitter::app_info_,
  &apps::Dispatcher::app_info_,
  &apps::Combiner::app_info_,

  &apps::ClockDivider::app_info_,
  &apps::SyncLatch::app_info_,
#ifdef USE_HD_CLOCK
  &apps::ClockSourceHD::app_info_,
#else
  &apps::ClockSource::app_info_,
#endif  // USE_HD_CLOCK

  &apps::CcKnob::app_info_,
#ifndef MIDIBUD_FIRMWARE
  &apps::Controller::app_info_,
#endif
  &apps::DrumPatternGenerator::app_info_,
  &apps::Randomizer::app_info_,
  &apps::ChordMemory::app_info_,
  &apps::Arpeggiator::app_info_,
  &apps::Delay::app_info_,
  &apps::ScaleProcessor::app_info_,
#ifdef USE_SH_SEQUENCER
  &apps::ShSequencer::app_info_,
#else
  &apps::Sequencer::app_info_,
#endif  // USE_SH_SEQUENCER
  &apps::Lfo::app_info_,

#ifdef USE_TANPURA
  &apps::Tanpura::app_info_,
#else
  &apps::EarTrainingGame::app_info_,
#endif  // USE_TANPURA
  
  &apps::GenericFilter::app_info_,
  &apps::Settings::app_info_
};

#endif  // POLY_SEQUENCER_FIRMWARE


/* static */
void App::Init() {
  // Load settings.
  LoadSettings();
  OnIncrement(0);
  OnInit();
}

/* static */
void App::SaveSettings() {
  eeprom_write_block(
      settings_data(),
      (void*)(settings_offset()),
      settings_size());
}

/* static */
void App::LoadSettings() {
  eeprom_read_block(
      settings_data(),
      (void*)(settings_offset()),
      settings_size());
}

/* static */
void App::SaveSetting(uint16_t index) {
  eeprom_write_byte(
      (uint8_t*)(settings_offset()) + index,
      settings_data()[index]);
}

/* static */
void App::ResetToFactorySettings() {
  memcpy_P(
      settings_data(),
      factory_data(),
      settings_size());
  SaveSettings();
}

/* static */
void App::Launch(uint8_t app_index) {
  memcpy_P(&app_info_, registry[app_index], sizeof(AppInfo));
}

/* static */
void App::SaveSettingWord(uint16_t setting_id, uint16_t value) {
  eeprom_write_word((uint16_t*)(setting_id), value);
}

/* static */
void App::SendNow(uint8_t byte) {
  LedOut::High();
  midi_out.Write(byte);
}

/* static */
void App::Send3(uint8_t a, uint8_t b, uint8_t c) {
  FlushOutputBuffer(3);
  MidiHandler::OutputBuffer::Write(a);
  MidiHandler::OutputBuffer::Write(b);
  MidiHandler::OutputBuffer::Write(c);
}

/* static */
void App::Send(uint8_t status, uint8_t* data, uint8_t size) {
  FlushOutputBuffer(size);
  MidiHandler::OutputBuffer::Write(status);
  if (size) {
    MidiHandler::OutputBuffer::Write(*data++);
    --size;
  }
  if (size) {
    MidiHandler::OutputBuffer::Write(*data++);
    --size;
  }
}

/* static */
void App::FlushOutputBuffer(uint8_t requested_size) {
  while (MidiHandler::OutputBuffer::writable() < requested_size) {
    display.set_status('!');
    midi_out.Write(MidiHandler::OutputBuffer::Read());
  }
}

/* static */
void App::SendLater(uint8_t note, uint8_t velocity, uint8_t when, uint8_t tag) {
  event_scheduler.Schedule(note, velocity, when, tag);
}

/* static */
void App::SendScheduledNotes(uint8_t channel) {
  uint8_t current = event_scheduler.root();
  while (current) {
    const SchedulerEntry& entry = event_scheduler.entry(current);
    if (entry.when) {
      break;
    }
    if (entry.note != kZombieSlot) {
      if (entry.velocity == 0) {
        Send3(0x80 | channel, entry.note, 0);
      } else {
        Send3(0x90 | channel, entry.note, entry.velocity);
      }
    }
    current = entry.next;
  }
  event_scheduler.Tick();
}

/* static */
void App::FlushQueue(uint8_t channel) {
  while (event_scheduler.size()) {
    SendScheduledNotes(channel);
  }
}

/* static */
uint8_t App::num_apps() {
  return sizeof(registry) / sizeof(AppInfo*);
}

/* extern */
App app;

}  // namespace midipal
