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
// Main definitions.

#ifndef MIDIPAL_HARDWARE_CONFIG_H_
#define MIDIPAL_HARDWARE_CONFIG_H_

#include "avrlib/base.h"
#include "avrlib/gpio.h"
#include "avrlib/parallel_io.h"
#include "avrlib/serial.h"

namespace midipal {

using avrlib::Gpio;
using avrlib::PARALLEL_NIBBLE_HIGH;
using avrlib::ParallelPort;
using avrlib::PortB;
using avrlib::PortD;
using avrlib::PortC;
using avrlib::SerialPort0;

static const uint8_t kLcdWidth = 8;
static const uint8_t kLcdHeight = 1;

// MIDI
typedef SerialPort0 MidiPort;

// LCD
typedef Gpio<PortD, 2> LcdRsLine;
typedef Gpio<PortD, 3> LcdEnableLine;
typedef ParallelPort<PortD, PARALLEL_NIBBLE_HIGH> LcdDataBus;

// Encoder
typedef Gpio<PortB, 2> EncoderALine;
typedef Gpio<PortB, 1> EncoderBLine;
typedef Gpio<PortB, 0> EncoderClickLine;

#ifdef MIDIBUD_FIRMWARE
// Switches
typedef Gpio<PortC, 0> Switch1Line;
typedef Gpio<PortC, 1> Switch2Line;
typedef Gpio<PortC, 2> Switch3Line;
typedef Gpio<PortC, 3> Switch4Line;
typedef Gpio<PortB, 4> Switch5Line;
#endif

// LEDs
typedef Gpio<PortB, 3> LedOut;
typedef Gpio<PortB, 5> LedIn;

}  // namespace midipal

#endif  // MIDIPAL_HARDWARE_CONFIG_H_
