#!/usr/bin/env python
#
# Copyright 2007 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import cStringIO

import webapp2

from google.appengine.ext import webapp
from google.appengine.ext.webapp import util
from google.appengine.ext.webapp import template

from music.midi import midifile

TEMPLATE_PATH = os.path.join(os.path.dirname(__file__), 'templates')

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

MIDIPAL_BLOCK_SIZE = 32
MUTABLE_INSTRUMENTS_MFR_ID = '\x00\x21\x02'
DEVICE_ID = '\x00\x03'
MIDIPAL_BASE_SCRATCH_ADDRESS = 896

def clip_7bits(x):
  try:
    x = int(x)
  except Exception, e:
    x = 0
  return min(max(x, 0), 127)


def null(x):
  return 0


def clip_8bits(x):
  try:
    x = int(x)
    if x < 0:
      x += 256
  except Exception, e:
    x = 0
  return min(max(x, 0), 255)


def clip_4bits(x):
  try:
    x = int(x)
  except Exception, e:
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
    for i in xrange(16):
      if attributes('channel_%d' % i):
        self._channel_bitmask += (1 << i)
    for i in xrange(8):
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
    for i in xrange(2):
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
    for i in xrange(16):
      channels.append({
          'index': i,
          'text': str(i + 1) + ('<br />' if (i % 4) == 3 else ''),
          'checked': 'checked' if (1 << i) & self._channel_bitmask else ''
      })
    d['channels'] = channels
    
    messages = []
    for i in xrange(8):
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
    for i in xrange(len(ACTIONS)):
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
    for i in xrange(2):
      op = self._value_transformation[i][0]
      ops = []
      for j in xrange(len(OPERATIONS)):
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

class RetrieveHandler(webapp.RequestHandler):
  
  def get(self):
    self.response.headers['Content-Type'] = 'text/html'
    template_path = os.path.join(TEMPLATE_PATH, 'retrieve.html')
    self.response.out.write(template.render(template_path, {}))


class MainHandler(webapp.RequestHandler):

  def show_edit_page(self, filters):
    self.response.headers['Content-Type'] = 'text/html'
    template_path = os.path.join(TEMPLATE_PATH, 'index.html')
    filters_dicts = []
    for i, f in enumerate(filters):
      d = f.get_template_dict()
      d['index'] = i
      d['index_base_one'] = i + 1
      d['checked'] = 'checked' if f.enabled else ''
      filters_dicts.append(d)

    template_data = {
      'title': 'MIDIpal programmer',
      'filters': filters_dicts,
      'extra_body_tags': 'onLoad=hideControls();'
    }
    self.response.out.write(template.render(template_path, template_data))
    

  def get(self):
    filters = [Modifier() for i in xrange(4)]
    filters[0].enabled = True
    self.show_edit_page(filters)


  def parse_sysex(self, data):
    # Strip 0xf0 and 0xf7
    blocks = [x.strip('\xf7') for x in data.split('\xf0') if x]
    # Strip manufacturer id and 2 command bytes + 4 nibbles of address
    # + 2 nibbles of checksum
    data = ''.join([x[11:-2] for x in blocks])
    # Renibblize
    data = map(ord, data)
    data = [x * 16 + y for (x, y) in zip(data[::2], data[1::2])]
    modifiers = []
    for i in xrange(4):
      m = Modifier()
      default_bytestream = m.get_bytestream()
      filter_data, data = data[:16], data[16:]
      m.enabled = ''.join(map(chr, filter_data)) != default_bytestream
      m.from_bytestream(filter_data)
      modifiers.append(m)
    return modifiers


  def convert_to_sysex(self, modifiers):
    data = ''.join([m.get_bytestream() for m in modifiers])

    syx_data = []
    for i in xrange(0, len(data), MIDIPAL_BLOCK_SIZE):
      address = MIDIPAL_BASE_SCRATCH_ADDRESS + i
      block = data[i:i+MIDIPAL_BLOCK_SIZE]
      block += '\x00' * (MIDIPAL_BLOCK_SIZE - len(block))
      block = chr(address & 0xff) + chr(address >> 8) + block
      event = midifile.SysExEvent(
          MUTABLE_INSTRUMENTS_MFR_ID,
          DEVICE_ID,
          '\x01\x20' + midifile.Nibblize(block))
      syx_data.append(event.raw_message)
      
    # Add a comment to notify the MIDIpal that the block received in the
    # scratch area has to be copied to the current custom program area.
    event = midifile.SysExEvent(
        MUTABLE_INSTRUMENTS_MFR_ID,
        DEVICE_ID,
        '\x73\x00' + midifile.Nibblize(''))
    syx_data.append(event.raw_message)
    
    f = cStringIO.StringIO()
    f.write(''.join(syx_data))
    data = f.getvalue()
    f.close()
    return data


  def post(self):
    if self.request.get('syx'):
      self.show_edit_page(self.parse_sysex(self.request.get('syx')))
      return

    modifiers = []
    for i in xrange(4):
      m = Modifier()
      prefix = 'filter_%d_' % i
      if self.request.get(prefix + 'enabled'):
        m.set_from_request(lambda x: self.request.get(prefix + x))
      modifiers.append(m)
    
    self.response.headers['Content-Type'] = 'application/octet-stream'
    self.response.headers['Content-disposition'] = \
        'attachment; filename=user_program.syx'
    self.response.out.write(self.convert_to_sysex(modifiers))


application = webapp.WSGIApplication([('/', MainHandler), ('/syx', RetrieveHandler)])
