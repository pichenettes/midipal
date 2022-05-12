# Copyright 2022 Emilie Gillet.
#
# Author: Emilie Gillet (emilie.o.gillet@gmail.com)
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
#
# -----------------------------------------------------------------------------
#
# SysEx data manipulation

def PackVariableLengthInteger(value):
  """Packs a python integer into a variable length byte sequence."""
  if value == 0:
    return '\x00'
  s = value
  output = []
  while value:
    to_write = value & 0x7f
    value = value >> 7
    output.insert(0, to_write)
  for i in range(len(output) - 1):
    output[i] |= 0x80
  output = ''.join(map(chr, output))
  return output


class SysExEvent(object):
  def __init__(self, manufacturer_id, device_id, data):
    self.data = data
    self.message = ''.join([
        manufacturer_id,
        device_id,
        data,
        '\xf7'])
    self.raw_message = '\xf0' + self.message
    assert all(ord(x) < 128 for x in self.message[:-1])
    self.message = ''.join([
        '\xf0',
        PackVariableLengthInteger(len(self.message)),
        self.message])

  def Serialize(self, running_status):
    return self.message, None


def Nibblize(data, add_checksum=True):
  """Converts a byte string into a nibble string. Also adds checksum"""
  output = []
  if add_checksum:
    tail = [chr(sum(ord(char) for char in data) % 256)]
  else:
    tail = []
  for char in map(ord, list(data) + tail):
    output.append(chr(char >> 4))
    output.append(chr(char & 0x0f))
  return ''.join(output)


