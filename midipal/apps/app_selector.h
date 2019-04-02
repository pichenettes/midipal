// Copyright 2011 Emilie Gillet.
//
// Author: Emilie Gillet (emilie.o.gillet@gmail.com)
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
// This app is responsible for configuring which app is active.

#ifndef MIDIPAL_APPS_APP_SELECTOR_H_
#define MIDIPAL_APPS_APP_SELECTOR_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class AppSelector {
 public:
  AppSelector() { }

  static void OnInit();
  static void OnRawByte(uint8_t byte);
  
  static uint8_t OnClick();
  static uint8_t OnIncrement(int8_t increment);
  static uint8_t OnRedraw();
  
  static const prog_AppInfo app_info_;
 
 private:
  static uint8_t active_app_;
  static uint8_t selected_item_;
  
  DISALLOW_COPY_AND_ASSIGN(AppSelector);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_APP_SELECTOR_H_
