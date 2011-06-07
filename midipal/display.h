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
// Instance of the display class, configured for the Midipal project.

#ifndef MIDIPAL_DISPLAY_H_
#define MIDIPAL_DISPLAY_H_

#include "avrlib/devices/buffered_display.h"
#include "avrlib/devices/hd44780_lcd.h"

#include "midipal/hardware_config.h"

using avrlib::BufferedDisplay;
using avrlib::Hd44780Lcd;

namespace midipal {
  
typedef Hd44780Lcd<
    LcdRsLine,
    LcdEnableLine,
    LcdDataBus,
    kLcdWidth,
    kLcdHeight> Lcd;
extern Lcd lcd;
extern BufferedDisplay<Lcd> display;

extern char line_buffer[];

}  // namespace midipal

#endif // MIDIPAL_DISPLAY_H_
