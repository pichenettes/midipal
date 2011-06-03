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
// Resources definitions.
//
// Automatically generated with:
// make resources


#include "resources.h"

namespace midipal {

static const prog_char str_res_midipal_[] PROGMEM = "midipal!";


PROGMEM const prog_char* string_table[] = {
  str_res_midipal_,
};



PROGMEM const prog_uint16_t* lookup_table_table[] = {
};

const prog_uint8_t chr_res_special_characters[] PROGMEM = {
       2,      3,      3,      2,      2,     14,     30,     12,
       0,      0,      0,      4,      4,     14,     17,     31,
       4,     14,     21,      4,      4,      4,      4,      0,
       0,      4,      4,      4,      4,     21,     14,      4,
       0,      0,      0,      8,     21,      2,      0,      0,
       8,     20,      9,     21,      3,      5,     17,     14,
      14,     17,     27,     29,     21,     23,     17,      0,
};


const prog_uint8_t* character_table[] = {
  chr_res_special_characters,
};


}  // namespace midipal
