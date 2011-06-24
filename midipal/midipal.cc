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
#include "avrlib/watchdog_timer.h"

#include "midi/midi.h"
#include "midipal/app.h"
#include "midipal/clock.h"
#include "midipal/display.h"
#include "midipal/event_scheduler.h"
#include "midipal/midi_handler.h"
#include "midipal/note_stack.h"
#include "midipal/resources.h"
#include "midipal/ui.h"

using namespace avrlib;
using namespace midi;
using namespace midipal;

// Midi input.
Serial<MidiPort, 31250, BUFFERED, POLLED> midi_io;
MidiStreamParser<MidiHandler> midi_parser;

ISR(USART_RX_vect) {
  LedIn::High();
  midi_parser.PushByte(SerialInput<MidiPort>::ImmediateRead());
}

static uint8_t sub_clock;
static uint8_t sub_clock_2;
static volatile uint16_t clock_counter;

TIMER_2_TICK {
  ++clock_counter;
  uint8_t events = clock.Tick();
  if (events & 1) {
    app.OnInternalClockTick();
  }
  if (events & 2) {
    app.OnInternalClockStep();
  }
  if (MidiHandler::OutputBuffer::readable() && midi_io.writable()) {
    LedOut::High();
    midi_io.Overwrite(MidiHandler::OutputBuffer::ImmediateRead());
  }
  sub_clock = (sub_clock + 1) & 31;
  if (sub_clock == 0) {  // 2kHz
    lcd.Tick();
    ui.Poll();
    sub_clock_2 = ~sub_clock_2;
    if (sub_clock_2) {  // 1kHz
      TickSystemClock();
      LedOut::Low();
      LedIn::Low();
    }
  }
}

void Init() {
  sei();
  UCSR0B = 0;
  
  LedOut::set_mode(DIGITAL_OUTPUT);
  LedIn::set_mode(DIGITAL_OUTPUT);
  
  // Boot the app selector app.
  app.Launch(0);
  app.Init();

  // Now that the app selector app has booted, we can retrieve the
  // app to launch.
  uint8_t launch_app = app.GetParameter(0);
  app.Launch(launch_app);
  
  note_stack.Init();
  event_scheduler.Init();
  
  display.Init();
  ui.Init();
  
  // Initialize all the PWM outputs to 39kHz, phase correct mode.
  Timer<2>::set_prescaler(1);
  Timer<2>::set_mode(TIMER_FAST_PWM);
  Timer<2>::Start();

  lcd.Init();
  
  app.Init();

  midi_io.Init();
}

int main(void) {
  ResetWatchdog();
  Init();
  while (1) {
    display.Tick();
    ui.DoEvents();
  }
}
