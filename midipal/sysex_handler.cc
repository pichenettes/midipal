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
// Class handling MIDIpal-specific SysEx messages.

#include "midipal/sysex_handler.h"

#include <avr/eeprom.h>
#include <avr/pgmspace.h>

#include "avrlib/op.h"
#include "avrlib/serial.h"
#include "avrlib/time.h"
#include "avrlib/watchdog_timer.h"

#include "midipal/app.h"
#include "midipal/hardware_config.h"
#include "midipal/ui.h"

namespace midipal {

using namespace avrlib;

/* static */
uint8_t SysExHandler::buffer_[kSysExTransferBlockSize + 4];

/* static */
uint16_t SysExHandler::bytes_received_;

/* static */
uint16_t SysExHandler::expected_size_;

/* static */
uint8_t SysExHandler::state_;

/* static */
uint8_t SysExHandler::checksum_;

/* static */
uint8_t SysExHandler::command_[2];

static const prog_char header[] PROGMEM = {
  0xf0,  // <SysEx>
  0x00, 0x21, 0x02,  // Mutable Instruments manufacturer ID.
  0x00, 0x03,  // Product ID for MIDIpal.
  // Then:
  // * Command byte:
  // - 0x01: data transfer
  // - 0x02: change current app
  // - 0x11: data request
  // * Argument byte:
  // - Block size ; 0 for app change request.
  // * 16-bits address in program memory.
};

/* static */
void SysExHandler::ParseCommand() {
  bytes_received_ = 0;
  state_ = RECEIVING_DATA;
  switch (command_[0]) {
    case 0x01:  // Data transfer
      expected_size_ = command_[1] + 2;
      break;
    
    case 0x02:
    case 0x03:
      expected_size_ = 0;
      break;

    case 0x11:
      expected_size_ = 2;
      break;
      
    default:
      state_ = RECEIVING_FOOTER;
      break;
  }
}

/* static */
void SysExHandler::AcceptCommand() {
  Word address;
  address.bytes[0] = buffer_[0];
  address.bytes[1] = buffer_[1];
  void* p = (void*)(address.value);
  switch (command_[0]) {
    case 0x01:  // Data transfer
      eeprom_write_block(&buffer_[2], p, command_[1]);
      app.LoadSettings();
      break;
    case 0x02:
      app.Launch(0);
      app.Init();
      app.SetParameter(0, command_[1]);
      app.SaveSettings();
      SystemReset(100);
      while (1);
      break;
    case 0x03:
      app.SetParameter(0, command_[1]);
    case 0x11:
      SendBlock((void*)(address.value), command_[1]);
      break;
  }
}

/* static */
void SysExHandler::SendBlock(void* address, uint8_t size) {
  // Wait until the MIDI queue is flushed.
  Serial<MidiPort, 31250, DISABLED, POLLED> midi_output;
  
  uint16_t remaining_size = size;
  uint8_t* p = (uint8_t*)(address);
  if (remaining_size == 0) {
    remaining_size = kEepromSize - (uint16_t)(address);
  }
  while (remaining_size) {
    uint8_t block_size = (remaining_size > kSysExTransferBlockSize) ? 
      kSysExTransferBlockSize : remaining_size;
    
    // Outputs the SysEx header.
    for (uint8_t i = 0; i < sizeof(header); ++i) {
      midi_output.Write(pgm_read_byte(header + i));
    }
    // Command: transfer.
    midi_output.Write(0x01);
    // Argument: size
    midi_output.Write(block_size);

    // First two bytes of data: address.
    {
      Word address;
      address.value = (uint16_t)(void*)(p);
      buffer_[0] = address.bytes[0];
      buffer_[1] = address.bytes[1];
    }
    // And then the data.
    eeprom_read_block(&buffer_[2], p, block_size);

    // Send the data and the checksum.
    uint8_t checksum = 0;
    for (uint8_t i = 0; i < block_size + 2; ++i) {
      checksum += buffer_[i];
      midi_output.Write(U8ShiftRight4(buffer_[i]));
      midi_output.Write(buffer_[i] & 0x0f);
    }

    midi_output.Write(U8ShiftRight4(checksum));
    midi_output.Write(checksum & 0x0f);

    midi_output.Write(0xf7);  // </SysEx>
    
    remaining_size -= block_size;
    p += block_size;
    if (remaining_size) {
      // Space blocks by 150ms.
      ConstantDelay(150);
    }
  }
}

/* static */
void SysExHandler::Receive(uint8_t byte) {
  if (byte == 0xf0) {
    checksum_ = 0;
    bytes_received_ = 0;
    state_ = RECEIVING_HEADER;
  }
  switch (state_) {
    case RECEIVING_HEADER:
      if (pgm_read_byte(header + bytes_received_) == \
          byte) {
        bytes_received_++;
        if (bytes_received_ >= sizeof(header)) {
          state_ = RECEIVING_COMMAND;
          bytes_received_ = 0;
        }
      } else {
        state_ = RECEIVING_FOOTER;
      }
      break;

    case RECEIVING_COMMAND:
      command_[bytes_received_++] = byte;
      if (bytes_received_ == 2) {
        ParseCommand();
      }
      break;

    case RECEIVING_DATA:
      {
        uint16_t i = bytes_received_ >> 1;
        if (bytes_received_ & 1) {
          buffer_[i] |= byte & 0xf;
          if (i < expected_size_) {
            checksum_ += buffer_[i];
          }
        } else {
          buffer_[i] = U8ShiftLeft4(byte);
        }
        bytes_received_++;
        if (bytes_received_ >= (1 + expected_size_) * 2) {
          state_ = RECEIVING_FOOTER;
        }
      }
    break;

  case RECEIVING_FOOTER:
    if (byte == 0xf7 &&
        checksum_ == buffer_[expected_size_]) {
      AcceptCommand();
    } else {
      state_ = RECEPTION_ERROR;
    }
    break;
  }
}

/* extern */
SysExHandler sysex_handler;

}  // namespace midipal
