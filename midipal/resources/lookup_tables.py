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
# Lookup table definitions.

import numpy

lookup_tables = []

"""----------------------------------------------------------------------------
Arpeggiator patterns
----------------------------------------------------------------------------"""

def XoxTo16BitInt(pattern):
  uint16 = 0
  i = 0
  for char in pattern:
    if char == 'o':
      uint16 += (2 ** i)
      i += 1
    elif char == '-':
      i += 1
  assert i == 16
  return uint16


def ConvertPatterns(patterns):
  return [XoxTo16BitInt(pattern) for pattern in patterns]


lookup_tables.append(
  ('arpeggiator_patterns', ConvertPatterns([
      'o-o- o-o- o-o- o-o-',
      'ooo- ooo- ooo- ooo-',
      'o-o- oooo o-o- oooo',
      'o-o- oo-o o-o- oo-o',
      'oooo -oo- oooo -oo-',

      'o--o ---- o--o ----',
      'o--o --o- o--o --o-',
      'o--o --o- -o-- o-o-',
      'o-o- -o-- o--o --o-',
      'oo-o o-oo oo-o o-oo',
      
      'oooo o-oo -oo- ooo-',
      'o--- o--- o--o -o-o',
      'o--o o--- o-o- o-oo',
      'o--- --oo oooo -oo-',
      'o--- ---- o--- o-oo',
      ])))

lookup_tables.append(
  ('drum_patterns', ConvertPatterns([
      '----------------',
      'o---o---o--o--o-',
      'o---o---o---o---',
      'o--o--o-o--o--o-',
      'o-------o-o-----',
      'o-------o-------',
      'o--o--o--o--o-o-',
      'o-o-----o-------',
      'o-----o-o--o-o--',
      'o-----o---o-----',
      'o-----o---o--o-o',
      'o-----o-o-----o-',

      '----------------',
      '-o--o--o------o-',
      '----o-------o---',
      '----o----o--o---',
      '----o-o-----o---',
      '----o--o----o--o',
      '----o--o-o--o---',
      '----o----o--o---',
      '--oo----o--o--o-',
      '----o---------o-',
      '----o------o--o-',
      '----o-------o--o',

      '----------------',
      'o--o--o-o--o--o-',
      'o---o---o---o---',
      '--ooo-o---ooo-o-',
      'o-o-o-o-o-o-o-o-',
      '--o---o---o---o-',
      'ooooo---ooooo-o-',
      'o-o---o-o-o---o-',
      'o-o-o-ooo-o-o-oo',
      'ooo-ooo-ooo-ooo-',
      '-o----o---o--oo-',
      'oooooooooooooooo',

      '----------------',
      '---o--o----o--o-',
      'o-------o-o-o-o-',
      '--------o--o--o-',
      '----o-------oooo',
      '--o----o--o--o-o',
      '---o--o-----o---',
      'o---o---o-----o-',
      'o--o--o---o-o---',
      'o-o-o-o-o-o-o-o-',
      '---oo-o----oo-o-',
      'o-o--o-o-o---oo-'])))


"""----------------------------------------------------------------------------
Groove templates
----------------------------------------------------------------------------"""

def ConvertGrooveTemplate(values):
  # Center
  values = numpy.array(values)
  values -= values.mean()
  # Scale
  scale = numpy.abs(values).max() / 127.0
  values /= scale
  values = values.astype(int)
  # Fix rounding error
  values[8] -= values.sum()
  return values

lookup_tables.extend([
    ('groove_swing', ConvertGrooveTemplate(
      [1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1])),
    ('groove_shuffle', ConvertGrooveTemplate(
      [1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1])),
    ('groove_push', ConvertGrooveTemplate(
      [-0.5, -0.5, 1, 0, -1, 0, 0, 0.7, 0, 0, 0.7, -0.4, -0.7, 0, 0.7, 0.0])),
    ('groove_lag', ConvertGrooveTemplate(
      [0.1, 0.2, 0.4, 0, 0.15, -0.2, -0.35, -0.5,
       0.5, 0.15, -0.4, -0.2, 0.45, -0.2, 0.4, -0.2])),
    ('groove_human', ConvertGrooveTemplate(
      [0.7, -0.8, 0.85, -0.75, 0.7, -0.7,  0.4, -0.3,
       0.5, -0.7, 0.8, -0.75, 0.8, -1, 0.5, -0.25])),
    ('groove_monkey', ConvertGrooveTemplate(
      [0.5, -0.6, 0.6, -0.8, 0.6, -0.7, 0.8, -0.7,
       0.4, -0.5, 0.9, -0.6, 0.9, -0.8, 0.6, -0.6]))])


"""----------------------------------------------------------------------------
Euclidian patterns
----------------------------------------------------------------------------"""

def Flatten(l):
  if hasattr(l, 'pop'):
    for item in l:
      for j in Flatten(item):
        yield j
  else:
    yield l


def EuclidianPattern(k, n):
  pattern = [[1]] * k + [[0]] * (n - k)
  while k:
    cut = min(k, len(pattern) - k)
    k, pattern = cut, [pattern[i] + pattern[k + i] for i in xrange(cut)] + \
        pattern[cut:k] + pattern[k + cut:]
  return pattern
  
table = []
durations = [0, 1, 2, 3, 4, 6, 7, 8, 10, 12, 14, 16]
for num_steps in durations:
  for num_notes in durations:
    bitmask = 0
    for i, bit in enumerate(Flatten(EuclidianPattern(num_notes, num_steps))):
      if bit:
        bitmask |= (1 << i)
    table.append(bitmask)

lookup_tables.append(('euclidian_patterns', table))


"""----------------------------------------------------------------------------
Scales
----------------------------------------------------------------------------"""

unprocessed_scales = [
  [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11],  # Chromatic
  [0, 2, 4, 5, 7, 9, 11],  # Ionian
  [0, 2, 3, 5, 7, 9, 10],  # Dorian
  [0, 1, 3, 5, 7, 8, 10],  # Phryigan
  [0, 2, 4, 6, 7, 9, 11],  # Lydian
  [0, 2, 4, 5, 7, 9, 10],  # Mixolydian
  [0, 2, 3, 5, 7, 8, 10],  # Aeolian
  [0, 1, 3, 5, 6, 8, 10],  # Locrian
  [0, 3, 4, 7, 9, 10],     # Blues major
  [0, 3, 5, 6, 7, 10],     # Blues minor
  [0, 2, 4, 7, 9],         # Pentatonic major
  [0, 3, 5, 7, 10],        # Pentatonic minor
  
  [0, 1, 4, 5, 7, 8, 11],     # Bhairav
  [0, 1, 4, 6, 7, 8, 11],     # Shri
  [0, 1, 3, 5, 7, 10, 11],    # Rupavati
  [0, 1, 3, 6, 7, 8, 11],     # Todi
  [0, 2, 4, 5, 9, 10, 11],    # Rageshri
  [0, 2, 3, 5, 7, 9, 10],     # Kaafi
  [0, 2, 5, 7, 9],            # Megh
  [0, 3, 5, 8, 10],           # Malkauns
  [0, 3, 4, 6, 8, 10],        # Deepak

  [0, 1, 3, 4, 5, 7, 8, 10],  # Folk
  [0, 1, 5, 7, 8],            # Japanese
  [0, 1, 3, 7, 8],            # Gamelan
  [0, 2, 4, 6, 8, 10],        # Whole tone 
]

for index, unprocessed_scale in enumerate(unprocessed_scales):
  unprocessed_scale = numpy.array(unprocessed_scale)
  scale = numpy.arange(0, 12)
  for i in xrange(12):
    scale[i] = unprocessed_scale[numpy.argmin(numpy.abs(unprocessed_scale - i))]
  lookup_tables.append(('scale_%d' % index, scale))
