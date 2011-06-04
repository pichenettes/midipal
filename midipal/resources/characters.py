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
#
# -----------------------------------------------------------------------------
#
# Custom characters definitions.

def StringImageToBytes(string_image):
  """Converts an "ASCII art" image into character definition data.

  The output is a list of bytes, and the image is made of spaces or . and X.
  """
  rows = [row.strip() for row in string_image.split('\n') if row.strip()]
  assert len(rows) == 8
  bytes = []
  for row in rows:
    int8 = 0
    assert len(row) == 5
    for char in row:
      int8 *= 2
      if char == 'X':
        int8 += 1
    int8 += 0  # 128 + 64 + 32
    bytes.append(int8)
  return bytes


def Convert(characters):
  return sum([StringImageToBytes(image) for image in characters], [])


digits_10 = [
"""
X....
X....
X....
X.XX.
.X..X
.X..X
.X..X
..XX.
""",
"""
X....
X....
X....
X.XX.
...X.
...X.
...X.
..XXX
""",
"""
X....
X....
X....
X.XX.
.X..X
...X.
..X..
.XXXX
""",
"""
X....
X....
X....
X.XX.
....X
...X.
....X
..XX.
""",
"""
X....
X....
X....
X..X.
..X..
.X.X.
.XXXX
...X.
""",
"""
X....
X....
X....
X.XXX
..X..
..XX.
....X
..XX.
""",
"""
X....
X....
X....
X..XX
..X..
..XXX
..X.X
..XXX
"""]

characters = [
    ('digits_10', Convert(digits_10))
]
