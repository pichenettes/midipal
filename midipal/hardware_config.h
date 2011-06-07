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
using avrlib::PortC;
using avrlib::SerialPort0;

static const uint8_t kLcdWidth = 8;
static const uint8_t kLcdHeight = 1;

// MIDI
typedef SerialPort0 MidiPort;

// LCD
typedef Gpio<PortC, 2> LcdRsLine;
typedef Gpio<PortC, 3> LcdEnableLine;
typedef ParallelPort<PortC, PARALLEL_NIBBLE_HIGH> LcdDataBus;

// Encoder
typedef Gpio<PortB, 1> EncoderALine;
typedef Gpio<PortB, 0> EncoderBLine;
typedef Gpio<PortB, 2> EncoderClickLine;


}  // namespace midipal

#endif  // MIDIPAL_HARDWARE_CONFIG_H_
