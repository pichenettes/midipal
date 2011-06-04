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
static const prog_char str_res_sndoff[] PROGMEM = "sndOff";
static const prog_char str_res_rstctr[] PROGMEM = "rstCtr";
static const prog_char str_res_notoff[] PROGMEM = "notOff";
static const prog_char str_res_omnoff[] PROGMEM = "omnOff";
static const prog_char str_res_omnion[] PROGMEM = "omniOn";
static const prog_char str_res_monoon[] PROGMEM = "monoOn";
static const prog_char str_res_polyon[] PROGMEM = "polyOn";
static const prog_char str_res_sysx__[] PROGMEM = "sysx..";
static const prog_char str_res__sysx_[] PROGMEM = ".sysx.";
static const prog_char str_res___sysx[] PROGMEM = "..sysx";
static const prog_char str_res_start[] PROGMEM = "start";
static const prog_char str_res_stop[] PROGMEM = "stop";
static const prog_char str_res_cont_[] PROGMEM = "cont.";
static const prog_char str_res_reset[] PROGMEM = "reset";
static const prog_char str_res_chn[] PROGMEM = "chn";
static const prog_char str_res_all[] PROGMEM = "all";
static const prog_char str_res_1[] PROGMEM = "1";
static const prog_char str_res_2[] PROGMEM = "2";
static const prog_char str_res_3[] PROGMEM = "3";
static const prog_char str_res_4[] PROGMEM = "4";
static const prog_char str_res_5[] PROGMEM = "5";
static const prog_char str_res_6[] PROGMEM = "6";
static const prog_char str_res_7[] PROGMEM = "7";
static const prog_char str_res_8[] PROGMEM = "8";
static const prog_char str_res_9[] PROGMEM = "9";
static const prog_char str_res_10[] PROGMEM = "10";
static const prog_char str_res_11[] PROGMEM = "11";
static const prog_char str_res_12[] PROGMEM = "12";
static const prog_char str_res_13[] PROGMEM = "13";
static const prog_char str_res_14[] PROGMEM = "14";
static const prog_char str_res_15[] PROGMEM = "15";
static const prog_char str_res_16[] PROGMEM = "16";
static const prog_char str_res_flt[] PROGMEM = "flt";
static const prog_char str_res_off[] PROGMEM = "off";
static const prog_char str_res_on[] PROGMEM = "on";
static const prog_char str_res_no[] PROGMEM = "no";
static const prog_char str_res_yes[] PROGMEM = "yes";
static const prog_char str_res_run[] PROGMEM = "run";
static const prog_char str_res_bpm[] PROGMEM = "bpm";
static const prog_char str_res_grv[] PROGMEM = "grv";
static const prog_char str_res_amt[] PROGMEM = "amt";
static const prog_char str_res_swg[] PROGMEM = "swg";
static const prog_char str_res_shf[] PROGMEM = "shf";
static const prog_char str_res_psh[] PROGMEM = "psh";
static const prog_char str_res_lag[] PROGMEM = "lag";
static const prog_char str_res_hum[] PROGMEM = "hum";
static const prog_char str_res_mnk[] PROGMEM = "mnk";
static const prog_char str_res_val[] PROGMEM = "val";
static const prog_char str_res_cc_[] PROGMEM = "cc#";
static const prog_char str_res_min[] PROGMEM = "min";
static const prog_char str_res_max[] PROGMEM = "max";
static const prog_char str_res_lvl[] PROGMEM = "lvl";
static const prog_char str_res_num[] PROGMEM = "num";
static const prog_char str_res_rst[] PROGMEM = "rst";
static const prog_char str_res_sorry___[] PROGMEM = "sorry...";
static const prog_char str_res_perfect_[] PROGMEM = "perfect!";
static const prog_char str_res_not_bad_[] PROGMEM = "not bad!";


PROGMEM const prog_char* string_table[] = {
  str_res_midipal_,
  str_res_sndoff,
  str_res_rstctr,
  str_res_notoff,
  str_res_omnoff,
  str_res_omnion,
  str_res_monoon,
  str_res_polyon,
  str_res_sysx__,
  str_res__sysx_,
  str_res___sysx,
  str_res_start,
  str_res_stop,
  str_res_cont_,
  str_res_reset,
  str_res_chn,
  str_res_all,
  str_res_1,
  str_res_2,
  str_res_3,
  str_res_4,
  str_res_5,
  str_res_6,
  str_res_7,
  str_res_8,
  str_res_9,
  str_res_10,
  str_res_11,
  str_res_12,
  str_res_13,
  str_res_14,
  str_res_15,
  str_res_16,
  str_res_flt,
  str_res_off,
  str_res_on,
  str_res_no,
  str_res_yes,
  str_res_run,
  str_res_bpm,
  str_res_grv,
  str_res_amt,
  str_res_swg,
  str_res_shf,
  str_res_psh,
  str_res_lag,
  str_res_hum,
  str_res_mnk,
  str_res_val,
  str_res_cc_,
  str_res_min,
  str_res_max,
  str_res_lvl,
  str_res_num,
  str_res_rst,
  str_res_sorry___,
  str_res_perfect_,
  str_res_not_bad_,
};

const prog_uint16_t lut_res_arpeggiator_patterns[] PROGMEM = {
   21845,  30583,  62965,  46517,  28527,   2313,  18761,  21065,
   18725,  56283,  30431,  43281,  54553,  28609,  53505,
};
const prog_uint16_t lut_res_groove_swing[] PROGMEM = {
     127,    127,   -127,   -127,    127,    127,   -127,   -127,
     127,    127,   -127,   -127,    127,    127,   -127,   -127,
};
const prog_uint16_t lut_res_groove_shuffle[] PROGMEM = {
     127,   -127,    127,   -127,    127,   -127,    127,   -127,
     127,   -127,    127,   -127,    127,   -127,    127,   -127,
};
const prog_uint16_t lut_res_groove_push[] PROGMEM = {
     -63,    -63,    127,      0,   -127,      0,      0,     88,
       0,      0,     88,    -50,    -88,      0,     88,      0,
};
const prog_uint16_t lut_res_groove_lag[] PROGMEM = {
      19,     44,     93,     -4,     32,    -53,    -90,   -127,
     117,     32,   -102,    -53,    105,    -53,     93,    -53,
};
const prog_uint16_t lut_res_groove_human[] PROGMEM = {
      88,   -101,    107,    -95,     88,    -88,     50,    -38,
      65,    -88,    101,    -95,    101,   -127,     63,    -31,
};
const prog_uint16_t lut_res_groove_monkey[] PROGMEM = {
      70,    -84,     84,   -112,     84,    -98,    112,    -98,
      54,    -70,    127,    -84,    127,   -112,     84,    -84,
};


PROGMEM const prog_uint16_t* lookup_table_table[] = {
  lut_res_arpeggiator_patterns,
  lut_res_groove_swing,
  lut_res_groove_shuffle,
  lut_res_groove_push,
  lut_res_groove_lag,
  lut_res_groove_human,
  lut_res_groove_monkey,
};

const prog_uint8_t chr_res_digits_10[] PROGMEM = {
      16,     16,     16,     22,      9,      9,      9,      6,
      16,     16,     16,     22,      2,      2,      2,      7,
      16,     16,     16,     22,      9,      2,      4,     15,
      16,     16,     16,     22,      1,      2,      1,      6,
      16,     16,     16,     18,      4,     10,     15,      2,
      16,     16,     16,     23,      4,      6,      1,      6,
      16,     16,     16,     19,      4,      7,      5,      7,
};


const prog_uint8_t* character_table[] = {
  chr_res_digits_10,
};


}  // namespace midipal
