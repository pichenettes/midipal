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
// Setup app.

#include "midipal/apps/app_selector.h"

#include "avrlib/string.h"
#include "avrlib/watchdog_timer.h"

#include "midi/midi.h"

#include "midipal/app_manager.h"
#include "midipal/display.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

void AppSelector::OnInit() {
  selected_item_ = active_app_;
}

void AppSelector::OnRawByte(uint8_t byte) {
  SendNow(byte);
}

uint8_t AppSelector::OnClick() {
  if (selected_item_ == app_manager.num_apps()) {
    for (uint8_t i = 1; i < app_manager.num_apps(); ++i) {
      app_manager.mutable_app(i)->ResetToFactorySettings();
    }
    active_app_ = 0;
  } else {
    active_app_ = selected_item_;
  }
  SaveSettings();
  SystemReset(100);
  return 1;
}

uint8_t AppSelector::OnIncrement(int8_t increment) {
  selected_item_ += increment;
  if (selected_item_ < 1) {
    selected_item_ = 1;
  } else if (selected_item_ > app_manager.num_apps()) {
    selected_item_ = app_manager.num_apps();
  }
  return 1;
}

uint8_t AppSelector::OnRedraw() {
  ui.Clear();
  if (selected_item_ == app_manager.num_apps()) {
    ResourcesManager::LoadStringResource(
        STR_RES__RESET_,
        &line_buffer[0], 8);
  } else {
    ResourcesManager::LoadStringResource(
        app_manager.mutable_app(selected_item_)->app_name(),
        &line_buffer[0], 8);
  }
  AlignLeft(&line_buffer[0], 8);
  ui.RefreshScreen();
  return 1;
}

} }  // namespace midipal::apps
