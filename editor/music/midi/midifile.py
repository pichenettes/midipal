#!/usr/bin/python2.5
#
# Copyright 2009 Olivier Gillet.
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
#
# -----------------------------------------------------------------------------
#
# Midifile Writer

"""Midifile writer.
"""

import struct


def PackInteger(value, size=4):
  """Packs a python integer into a n-byte big endian byte sequence."""
  return struct.pack('>%s' % {1: 'B', 2: 'H', 4: 'L'}[size], value)


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
  for i in xrange(len(output) - 1):
    output[i] |= 0x80
  output = ''.join(map(chr, output))
  return output

"""Classes representing a MIDI event, with a Serialize method which encodes
them into a string."""

class Event(object):
  def __init__(self):
    pass
    
  def Serialize(self, running_status):
    raise NotImplementedError


class MetaEvent(Event):
  def __init__(self, id, data):
    assert len(data) < 256
    self._id = id
    self._data = data
    
  def Serialize(self, running_status):
    return ''.join([
        '\xff',
        PackInteger(self._id, size=1),
        PackInteger(len(self._data), size=1),
        self._data]), None


class TextEvent(MetaEvent):
  def __init__(self, text):
    super(TextEvent, self).__init__(0x01, text)


class CopyrightInfoEvent(MetaEvent):
  def __init__(self, text):
    super(CopyrightInfoEvent, self).__init__(0x02, text)


class TrackNameEvent(MetaEvent):
  def __init__(self, text):
    super(TrackNameEvent, self).__init__(0x03, text)


class TrackInstrumentNameEvent(MetaEvent):
  def __init__(self, text):
    super(TrackInstrumentNameEvent, self).__init__(0x04, text)


class LyricEvent(MetaEvent):
  def __init__(self, text):
    super(LyricEvent, self).__init__(0x05, text)


class MarkerEvent(MetaEvent):
  def __init__(self, text):
    super(MarkerEvent, self).__init__(0x06, text)


class CuePointEvent(MetaEvent):
  def __init__(self, text):
    super(CuePointEvent, self).__init__(0x07, text)


class EndOfTrackEvent(MetaEvent):
  def __init__(self):
    super(EndOfTrackEvent, self).__init__(0x2f, '')


class TempoEvent(MetaEvent):
  def __init__(self, bpm):
    value = 60000000.0 / bpm
    data = PackInteger(int(value), size=4)[1:]
    super(TempoEvent, self).__init__(0x51, data)


class TimeSignatureEvent(MetaEvent):
  def __init__(self, numerator, denominator):
    data = ''.join([
        PackInteger(numerator, size=1),
        PackInteger(int(math.log(denominator) / math.log(2)), size=1),
        '\x16\x08'])
    super(TimeSignatureEvent, self).__init__(0x58, data)


class KeyEvent(MetaEvent):
  def __init__(self, sharp_flats, major_minor):
    data = ''.join([
        PackInteger(sharp_flats, size=1),
        PackInteger(major_minor, size=1)])
    super(TimeSignatureEvent, self).__init__(0x59, data)


class BlobEvent(MetaEvent):
  def __init__(self, blob):
    super(BlobEvent, self).__init__(0x7f, blob)


"""Classic channel-oriented messages."""

class ChannelEvent(Event):
  def __init__(self, mask, channel, data):
    self._channel = channel
    self._status = mask | (channel - 1)
    self._data = PackInteger(self._status, size=1) + data
    
  def Serialize(self, running_status):
    if self._status == running_status:
      return self._data[1:], self._status
    else:
      return self._data, self._status


class NoteOffEvent(ChannelEvent):
  def __init__(self, channel, note, velocity):
    data = PackInteger(note, size=1) + PackInteger(velocity, size=1)
    super(NoteOffEvent, self).__init__(0x80, channel, data)
    self._note = note
    self._velocity = velocity


class NoteOnEvent(ChannelEvent):
  def __init__(self, channel, note, velocity):
    data = PackInteger(note, size=1) + PackInteger(velocity, size=1)
    super(NoteOnEvent, self).__init__(0x90, channel, data)
    self._note = note
    self._velocity = velocity


class KeyAftertouchEvent(ChannelEvent):
  def __init__(self, channel, note, aftertouch):
    data = PackInteger(note, size=1) + PackInteger(aftertouch, size=1)
    super(KeyAftertouchEvent, self).__init__(0xa0, channel, data)
    self._note = note
    self._aftertouch = aftertouch


class ControlChangeEvent(ChannelEvent):
  def __init__(self, channel, controller, value):
    data = PackInteger(controller, size=1) + PackInteger(value, size=1)
    super(ControlChangeEvent, self).__init__(0xb0, channel, data)
    self._controller = controller
    self._value = value


class ProgramChangeEvent(ChannelEvent):
  def __init__(self, channel, program_number):
    data = PackInteger(program_number, size=1)
    super(ProgramChangeEvent, self).__init__(0xc0, channel, data)
    self._program_number = program_number


class ChannelAftertouchEvent(ChannelEvent):
  def __init__(self, channel, aftertouch):
    data = PackInteger(aftertouch, size=1)
    super(ChannelAftertouchEvent, self).__init__(0xd0, channel, data)
    self._aftertouch = aftertouch


class PitchBendEvent(ChannelEvent):
  def __init__(self, channel, pitch_bend_14_bits):
    data = PackInteger(pitch_bend_14_bits >> 7, size=1) + \
        PackInteger(pitch_bend_14_bits & 0x7f, size=1)
    super(PitchBendEvent, self).__init__(0xe0, channel, data)
    self._pitch_bend = pitch_bend_14_bits


class SystemEvent(Event):
  def __init__(self, id):
    self._id = id
    
  def Serialize(self, running_status):
    return PackInteger(self._id, size=1), running_status


class ClockEvent(SystemEvent):
  def __init__(self):
    super(ClockEvent, self).__init__(0xf8)


class StartEvent(SystemEvent):
  def __init__(self):
    super(StartEvent, self).__init__(0xfa)


class ContinueEvent(SystemEvent):
  def __init__(self):
    super(ContinueEvent, self).__init__(0xfb)


class StopEvent(SystemEvent):
  def __init__(self):
    super(StopEvent, self).__init__(0xfc)


# TODO(pichenettes): also support pauses within a block transmission (F7)
class SysExEvent(Event):
  def __init__(self, manufacturer_id, device_id, data):
    self._data = data
    self._message = ''.join([
        manufacturer_id,
        device_id,
        data,
        '\xf7'])
    assert all(ord(x) < 128 for x in self._message[:-1])
    self._raw_message = '\xf0' + self._message
    self._message = ''.join([
        '\xf0',
        PackVariableLengthInteger(len(self._message)),
        self._message])

  def Serialize(self, running_status):
    return self._message, None

  @property
  def raw_message(self):
    return self._raw_message


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


class Track(object):
  def __init__(self):
    self._events = []
    
  def AddEvent(self, time, event):
    self._events.append((time, event))

  def Sort(self):
    self._events = sorted(self._events)

  def Serialize(self):
    self.Sort()
    last_time, last_event = self._events[-1]
    if type(last_event) != EndOfTrackEvent:
      self._events.append((last_time + 1, EndOfTrackEvent()))
    data = []
    current_time = 0
    running_status = None
    for time, event in self._events:
      delta = time - current_time
      data.append(PackVariableLengthInteger(delta))
      event_data, running_status = event.Serialize(running_status)
      data.append(event_data)
      current_time = time
    return ''.join(data)
    
  def Write(self, file_object):
    file_object.write('MTrk')
    track_data = self.Serialize()
    file_object.write(PackInteger(len(track_data)))
    file_object.write(track_data)
    
  @property
  def events(self):
    return self._events

    
class MidiFile(object):
  def __init__(self, ppq=96):
    self._tracks = []
    self._ppq = ppq
  
  def AddTrack(self):
    new_track = Track()
    self._tracks.append(new_track)
    return new_track
    
  def _MergeTracks(self):
    new_track = Track()
    for track in self._tracks:
      for time_event in track.events:
        new_track.AddEvent(*time_event)
    new_track.Sort()
    return new_track
    
  def Write(self, file_object, format=0):
    tracks = self._tracks
    if format == 0:
      tracks = [self._MergeTracks()]

    # File header.
    file_object.write('MThd')
    file_object.write(PackInteger(6))
    file_object.write(PackInteger(format, size=2))
    if format == 0:
      file_object.write(PackInteger(1, size=2))
    else:
      file_object.write(PackInteger(len(self._tracks), size=2))
    file_object.write(PackInteger(self._ppq, size=2))
    
    # Tracks.
    for track in tracks:
      track.Write(file_object)


if __name__ == '__main__':
  m = MidiFile()
  t = m.AddTrack()
  t.AddEvent(0, TempoEvent(120.0))
  
  t = m.AddTrack()
  t.AddEvent(1, SysExEvent(
      '\x00\x20\x77',
      '\x00\x01',
      '\x7f\x7f' + Nibblize('\xff\x00\xcc')))
  
  f = file('output.mid', 'w')
  m.Write(f, format=0)
  f.close()
