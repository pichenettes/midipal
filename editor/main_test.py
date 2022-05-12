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
# MIDIPal editor app.

import main


def test_conversion():
  modifiers = main.blank_midipal_data()
  modifiers[0]._channel_remap = True

  syx = main.midipal_data_to_syx(modifiers)
  modifiers = main.syx_to_midipal_data(syx.decode('latin1'))

  assert modifiers[0].enabled
  assert modifiers[0]._ranges[0] == (0, 127)
  assert modifiers[0]._ranges[1] == (0, 127)
  assert modifiers[0]._channel_remap == True
  assert not modifiers[1].enabled
  assert not modifiers[2].enabled
  assert not modifiers[3].enabled
