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

volatile uint8_t num_clock_ticks = 0;
volatile uint8_t num_clock_steps = 0;

ISR(TIMER1_OVF_vect, ISR_NOBLOCK) {
  static uint8_t sub_clock;
  
  // 4kHz
  if (MidiHandler::OutputBuffer::readable() && midi_io.writable()) {
    LedOut::High();
    midi_io.Overwrite(MidiHandler::OutputBuffer::ImmediateRead());
  }
  if (midi_io.readable()) {
    midi_parser.PushByte(midi_io.ImmediateRead());
  }
  
  while (num_clock_ticks) {
    --num_clock_ticks;
    app.OnInternalClockTick();
  }
  
  while (num_clock_steps) {
    --num_clock_steps;
    app.OnInternalClockStep();
  }
  
  sub_clock = (sub_clock + 1) & 3;
  if ((sub_clock & 1) == 0) {
    // 2kHz
    ui.Poll();
    if ((sub_clock & 3) == 0) {
      TickSystemClock();
      LedOut::Low();
      LedIn::Low();
    }
  }
}

ISR(TIMER2_OVF_vect) {
  // 78kHz
  uint8_t events = clock.Tick();
  if (events & 1) {
    ++num_clock_ticks;
  }
  if (events & 2) {
    ++num_clock_steps;
  }
}

void Init() {
  sei();
  UCSR0B = 0;
  
  LedOut::set_mode(DIGITAL_OUTPUT);
  LedIn::set_mode(DIGITAL_OUTPUT);
  
  note_stack.Init();
  event_scheduler.Init();
  
  // Boot the app selector app.
  app.Launch(0);
  app.Init();

  // Now that the app selector app has booted, we can retrieve the
  // app to launch.
  uint8_t launch_app = app.GetParameter(0);
  if (launch_app >= app.num_apps()) {
    launch_app = 0;
    app.SetParameter(0, launch_app);
  }
  app.Launch(launch_app);
  
  ui.Init();
  
  // Configure the timers.
  Timer<2>::set_prescaler(1);
  Timer<2>::set_mode(TIMER_FAST_PWM);
  Timer<2>::Start();
  Timer<1>::set_prescaler(2);
  Timer<1>::set_mode(TIMER_PWM_PHASE_CORRECT);
  Timer<1>::Start();
  app.Init();
  midi_io.Init();
}

int main(void) {
  ResetWatchdog();
  Init();
  while (1) {
    ui.DoEvents();
  }
}
