#!/usr/bin/python2.5
#
# Copyright 2011 Olivier Gillet.
#
# Author: Olivier Gillet (ol.gillet@gmail.com)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

"""SysEx file creation from raw data."""

import cStringIO

from music.midi import midifile


class SysExOptions(object):
  def __init__(
      self,
      page_size,
      delay,
      manufacturer_id,
      device_id,
      update_command,
      reset_command):
    self.page_size = page_size
    self.delay = delay
    self.manufacturer_id = manufacturer_id
    self.device_id = device_id
    self.update_command = update_command
    self.reset_command = reset_command


def CreateSysExFile(data, options):
  size = len(data)
  page_size = options.page_size
  delay = options.delay
  page_size *= 2  # Converts from words to bytes
  # The first SysEx block must not start at 0! Sequencers like Logic play the
  # first SysEx block everytime stop/play is pressed.
  time = 1
  syx_data = []
  for i in xrange(0, size, page_size):
    block = ''.join(map(chr, data[i:i+page_size]))
    padding = page_size - len(block)
    block += '\x00' * padding
    event = midifile.SysExEvent(
        options.manufacturer_id,
        options.device_id,
        options.update_command + midifile.Nibblize(block))
    syx_data.append(event.raw_message)
    # ms -> s -> beats -> ticks
    time += int(delay / 1000.0 / 0.5 * 96)
  event = midifile.SysExEvent(
      options.manufacturer_id,
      options.device_id,
      options.reset_command)
  syx_data.append(event.raw_message)
  
  f = cStringIO.StringIO()
  f.write(''.join(syx_data))
  data = f.getvalue()
  f.close()
  return data
