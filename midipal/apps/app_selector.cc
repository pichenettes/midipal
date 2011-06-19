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

void AppSelector::OnRawByte(uint8_t byte) {
  SendNow(byte);
}

uint8_t AppSelector::OnClick() {
  SaveSettings();
  SystemReset(100);
  return 1;
}

uint8_t AppSelector::OnIncrement(int8_t increment) {
  active_app_ += increment;
  if (active_app_ < 1) {
    active_app_ = 1;
  } else if (active_app_ >= app_manager.num_apps()) {
    active_app_ = app_manager.num_apps() - 1;
  }
  return 1;
}

uint8_t AppSelector::OnRedraw() {
  ui.Clear();
  ResourcesManager::LoadStringResource(
      app_manager.app_name(active_app_),
      &line_buffer[0], 8);
  AlignLeft(&line_buffer[0], 8);
  ui.RefreshScreen();
  return 1;
}

} }  // namespace midipal::apps
