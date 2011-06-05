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

#include "avrlib/gpio.h"
#include "avrlib/boot.h"
#include "avrlib/serial.h"
#include "avrlib/time.h"
#include "avrlib/timer.h"

#include "midi/midi.h"
#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/midi_handler.h"
#include "midipal/note_stack.h"
#include "midipal/plugin_manager.h"
#include "midipal/resources.h"
#include "midipal/ui.h"

using namespace avrlib;
using namespace midi;
using namespace midipal;

// Midi input.
Serial<MidiPort, 31250, BUFFERED, POLLED> midi_io;
MidiStreamParser<MidiHandler> midi_parser;

ISR(USART0_RX_vect) {
  midi_parser.PushByte(SerialInput<MidiPort>::ImmediateRead());
}

static uint8_t sub_clock;
static uint8_t sub_clock_2;
static uint16_t clock_counter;

TIMER_2_TICK {
  uint8_t events = clock.Tick();
  if (events & 1) {
    plugin_manager.active_plugin()->OnInternalClockTick();
  }
  if (events & 2) {
    plugin_manager.active_plugin()->OnInternalClockStep();
  }
  if (MidiHandler::OutputBuffer::readable() && midi_io.writable()) {
    midi_io.Overwrite(MidiHandler::OutputBuffer::ImmediateRead());
  }
  sub_clock = (sub_clock + 1) & 31;
  if (sub_clock == 0) {  // 2kHz
    lcd.Tick();
    ui.Poll();
    sub_clock_2 = ~sub_clock_2;
    if (sub_clock_2) {  // 1kHz
      TickSystemClock();
    }
  }
}

void Init() {
  sei();
  UCSR0B = 0;
  UCSR1B = 0;
  
  plugin_manager.set_active_plugin(8);
  note_stack.Init();
  display.Init();
  ui.Init();
  
  // Initialize all the PWM outputs to 39kHz, phase correct mode.
  Timer<2>::set_prescaler(1);
  Timer<2>::set_mode(TIMER_FAST_PWM);
  Timer<2>::Start();

  lcd.Init();
  
  plugin_manager.active_plugin()->OnLoad();
  plugin_manager.active_plugin()->OnIncrement(0);

  midi_io.Init();
}

int main(void) {
  Init();
  while (1) {
    display.Tick();
    ui.DoEvents();
  }
}
