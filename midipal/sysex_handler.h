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
// Class handling MIDIpal-specific SysEx messages.

#ifndef MIDIPAL_SYSEX_HANDLER_H_
#define MIDIPAL_SYSEX_HANDLER_H_

#include "avrlib/base.h"

namespace midipal {

static const uint16_t kSysExTransferBlockSize = 32;
static const uint16_t kEepromSize = 1024;

enum SysExReceptionState {
  RECEIVING_HEADER = 0,
  RECEIVING_COMMAND = 1,
  RECEIVING_DATA = 2,
  RECEIVING_FOOTER = 3,
  RECEPTION_OK = 4,
  RECEPTION_ERROR = 5,
};

class SysExHandler {
 public:
  static void Receive(uint8_t byte);
  static void SendBlock(void* address, uint8_t size);
  
 private:
  static void ParseCommand();
  static void AcceptCommand();

  static void CopyScratchArea();

  static uint8_t buffer_[kSysExTransferBlockSize + 4];
  static uint16_t bytes_received_;
  static uint16_t expected_size_;
  static uint8_t state_;
  static uint8_t checksum_;
  static uint8_t command_[2];
};

extern SysExHandler sysex_handler;

}  // namespace midipal:

#endif // MIDIPAL_SYSEX_HANDLER_H_
