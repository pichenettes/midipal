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
// Class responsible for switching between the various apps.

#include "midipal/app_manager.h"

#include "midipal/apps/active_sensing_filter.h"
#include "midipal/apps/app_selector.h"
#include "midipal/apps/arpeggiator.h"
#include "midipal/apps/bpm_meter.h"
#include "midipal/apps/cc_knob.h"
#include "midipal/apps/chord_memory.h"
#include "midipal/apps/clock_source.h"
#include "midipal/apps/combiner.h"
#include "midipal/apps/controller.h"
#include "midipal/apps/dispatcher.h"
#include "midipal/apps/drum_pattern_generator.h"
#include "midipal/apps/ear_training_game.h"
#include "midipal/apps/monitor.h"
#include "midipal/apps/randomizer.h"
#include "midipal/apps/splitter.h"

namespace midipal {

apps::ActiveSensingFilter active_sensing_filter;
apps::AppSelector app_selector;
apps::Arpeggiator arpeggiator;
apps::BpmMeter bpm_meter;
apps::CcKnob cc_knob;
apps::ChordMemory chord_memory;
apps::ClockSource clock_source;
apps::Combiner combiner;
apps::Controller controller;
apps::Dispatcher dispatcher;
apps::DrumPatternGenerator drum_pattern_generator;
apps::EarTrainingGame ear_training_game;
apps::Monitor monitor;
apps::Randomizer randomizer;
apps::Splitter splitter;

App* registry[] = {
  &app_selector,
  &monitor,
  &active_sensing_filter,
  &bpm_meter,
  &clock_source,
  &cc_knob,
  &controller,
  &ear_training_game,
  &drum_pattern_generator,
  &splitter,
  &randomizer,
  &chord_memory,
  &dispatcher,
  &combiner,
  &arpeggiator
};

/* extern */
AppManager app_manager;

/* static */
App* AppManager::active_app_;

/* static */
void AppManager::set_active_app(uint8_t index) {
  active_app_ = registry[index];
}

/* static */
uint8_t AppManager::num_apps() {
  return sizeof(registry) / sizeof(App*);
}

/* static */
uint8_t AppManager::app_name(uint8_t index) {
  return registry[index]->app_name();
}

}  // namespace midipal
