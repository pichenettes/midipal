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
# MIDIPal filter data structure, with conversion to/from raw bytes, to HTML
# template parameters, and from HTTP request arguments.

MESSAGE_NAMES = [
  'note off',
  'note on',
  'poly aftertouch',
  'control change',
  'program change',
  'afertouch',
  'pitch bend',
  'realtime'
]

ACTIONS = [
  'Transform',
  'Pass and transform',
  'CCize',
  'Pass and CCize',
  'Filter out'
]

OPERATIONS = [
  'No modification',
  'Add',
  'Subtract',
  'Invert',
  'Set to',
  'Map to range',
  'Set to random',
  'Add random'
]

def clip_7bits(x):
  try:
    x = int(x)
  except Exception:
    x = 0
  return min(max(x, 0), 127)


def null(x):
  return 0


def clip_8bits(x):
  try:
    x = int(x)
    if x < 0:
      x += 256
  except Exception:
    x = 0
  return min(max(x, 0), 255)


def clip_4bits(x):
  try:
    x = int(x)
  except Exception:
    x = 0
  return min(max(x, 0), 15)


CLIP_FUNCTIONS = [
  (null, null),
  (clip_8bits, null),
  (clip_8bits, null),
  (null, null),
  (clip_7bits, clip_7bits),
  (clip_7bits, clip_7bits),
  (clip_7bits, clip_7bits),
  (clip_8bits, clip_8bits)
]


class Modifier(object):
  
  def __init__(self):
    self._channel_bitmask = 0
    self._message_type_bitmask = 0
    self._ranges = [(0, 127), (0, 127)]
    self._action = 0
    self._channel_remap = False
    self._channel_shift = 0
    self._delay = 0
    self._value_transformation = [(0, 0, 0), (0, 0, 0)]
    self.enabled = False
  
  def set_from_request(self, attributes):
    for i in range(16):
      if attributes('channel_%d' % i):
        self._channel_bitmask += (1 << i)
    for i in range(8):
      if attributes('message_%d' % i):
        self._message_type_bitmask += (1 << i)
    self._ranges = [
        (clip_7bits(attributes('value_a_min')),
         clip_7bits(attributes('value_a_max'))),
        (clip_7bits(attributes('value_b_min')),
         clip_7bits(attributes('value_b_max')))]
    self._action = int(attributes('action'))
    self._channel_remap = attributes('channel_action') == '1'
    if self._channel_remap:
      self._channel_shift = clip_4bits(
          clip_7bits(attributes('channel_shift')) - 1)
    else:
      self._channel_shift = clip_4bits(attributes('channel_shift'))
    self._delay = 0
    self._value_transformation = []
    for i in range(2):
      prefix = 'value_transformation_%d' % i
      op = int(attributes(prefix))
      fn1, fn2 = CLIP_FUNCTIONS[op]
      if attributes(prefix + '_preserve_zero'):
        op |= 0x80
      if attributes(prefix + '_wrap'):
        op |= 0x40
      if attributes(prefix + '_swap'):
        op |= 0x20
      argument_1 = fn1(attributes(prefix + '_argument_1'))
      argument_2 = fn2(attributes(prefix + '_argument_2'))
      self._value_transformation.append((op, argument_1, argument_2))
  
  def from_bytestream(self, bytes):
    self._channel_bitmask = bytes[0] | (bytes[1] << 8)
    self._message_type_bitmask = bytes[2]
    self._ranges[0] = bytes[3], bytes[4]
    self._ranges[1] = bytes[5], bytes[6]
    self._channel_remap = (bytes[7] & 0x10) != 0
    self._channel_shift = bytes[7] & 0xf
    if self._channel_remap:
      self._channel_shift += 1
    self._action = 0
    if bytes[7] & 0x20:
      self._action |= 2
    if bytes[7] & 0x40:
      self._action |= 1
    if bytes[7] & 0x80:
      self._action = 4
    self._value_transformation[0] = bytes[10], bytes[11], bytes[12]
    self._value_transformation[1] = bytes[13], bytes[14], bytes[15]
  
  def get_bytestream(self):
    bytes = [0] * 16
    bytes[0] = self._channel_bitmask & 255
    bytes[1] = self._channel_bitmask >> 8
    bytes[2] = self._message_type_bitmask
    bytes[3], bytes[4] = self._ranges[0]
    bytes[5], bytes[6] = self._ranges[1]
    bytes[7] = self._channel_shift
    if self._channel_remap:
      bytes[7] |= 0x10
    if self._action == 4:
      bytes[7] |= 0x80
    else:
      if self._action & 1:
        bytes[7] |= 0x40
      if self._action & 2:
        bytes[7] |= 0x20
    bytes[8] = 0
    bytes[9] = 0
    bytes[10], bytes[11], bytes[12] = self._value_transformation[0]
    bytes[13], bytes[14], bytes[15] = self._value_transformation[1]
    return ''.join(map(chr, bytes))
  
  def get_template_dict(self):
    d = {}
    
    channels = []
    for i in range(16):
      channels.append({
          'index': i,
          'text': str(i + 1) + ('<br />' if (i % 4) == 3 else ''),
          'checked': 'checked' if (1 << i) & self._channel_bitmask else ''
      })
    d['channels'] = channels
    
    messages = []
    for i in range(8):
      messages.append({
          'index': i,
          'text': MESSAGE_NAMES[i],
          'checked': 'checked' if (1 << i) & self._message_type_bitmask else ''
      })
    d['messages'] = messages
    d['ranges'] = {
        'value_a_min': self._ranges[0][0],
        'value_a_max': self._ranges[0][1],
        'value_b_min': self._ranges[1][0],
        'value_b_max': self._ranges[1][1]
    }
    
    actions = []
    for i in range(len(ACTIONS)):
      actions.append({
          'text': ACTIONS[i],
          'index': i,
          'selected': 'selected' if self._action == i else ''
      })
    d['actions'] = actions
    d['remap_channel'] = 'selected' if self._channel_remap else ''
    d['shift_channel'] = 'selected' if not self._channel_remap else ''
    d['channel_shift'] = self._channel_shift
    
    value_transformations = []
    for i in range(2):
      op = self._value_transformation[i][0]
      ops = []
      for j in range(len(OPERATIONS)):
        ops.append({
           'text': OPERATIONS[j],
           'index': j,
           'selected': 'selected' if (op & 0xf) == j else ''})
      value_transformations.append({
          'index': i,
          'ops': ops,
          'preserve_zero': 'checked' if op & 0x80 else '',
          'wrap': 'checked' if op & 0x40 else '',
          'swap': 'checked' if op & 0x20 else '',
          'argument_1': self._value_transformation[i][1],
          'argument_2': self._value_transformation[i][2]
      })
    d['value_transformations'] = value_transformations
    return d

