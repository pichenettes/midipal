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


#ifndef MIDIPAL_RESOURCES_H_
#define MIDIPAL_RESOURCES_H_


#include "avrlib/base.h"

#include <avr/pgmspace.h>


#include "avrlib/resources_manager.h"
namespace midipal {

typedef uint8_t ResourceId;

extern const prog_char* string_table[];

extern const prog_uint16_t* lookup_table_table[];

extern const prog_uint8_t* character_table[];

extern const prog_uint16_t lut_res_arpeggiator_patterns[] PROGMEM;
extern const prog_uint16_t lut_res_drum_patterns[] PROGMEM;
extern const prog_uint16_t lut_res_groove_swing[] PROGMEM;
extern const prog_uint16_t lut_res_groove_shuffle[] PROGMEM;
extern const prog_uint16_t lut_res_groove_push[] PROGMEM;
extern const prog_uint16_t lut_res_groove_lag[] PROGMEM;
extern const prog_uint16_t lut_res_groove_human[] PROGMEM;
extern const prog_uint16_t lut_res_groove_monkey[] PROGMEM;
extern const prog_uint16_t lut_res_euclidian_patterns[] PROGMEM;
extern const prog_uint8_t chr_res_digits_10[] PROGMEM;
#define STR_RES_MIDIPAL_ 0  // midipal!
#define STR_RES_SNDOFF 1  // sndOff
#define STR_RES_RSTCTR 2  // rstCtr
#define STR_RES_NOTOFF 3  // notOff
#define STR_RES_OMNOFF 4  // omnOff
#define STR_RES_OMNION 5  // omniOn
#define STR_RES_MONOON 6  // monoOn
#define STR_RES_POLYON 7  // polyOn
#define STR_RES_SYSX__ 8  // sysx..
#define STR_RES__SYSX_ 9  // .sysx.
#define STR_RES___SYSX 10  // ..sysx
#define STR_RES_START 11  // start
#define STR_RES_STOP 12  // stop
#define STR_RES_CONT_ 13  // cont.
#define STR_RES_RESET 14  // reset
#define STR_RES_CHN 15  // chn
#define STR_RES_ALL 16  // all
#define STR_RES_1 17  // 1
#define STR_RES_2 18  // 2
#define STR_RES_3 19  // 3
#define STR_RES_4 20  // 4
#define STR_RES_5 21  // 5
#define STR_RES_6 22  // 6
#define STR_RES_7 23  // 7
#define STR_RES_8 24  // 8
#define STR_RES_9 25  // 9
#define STR_RES_10 26  // 10
#define STR_RES_11 27  // 11
#define STR_RES_12 28  // 12
#define STR_RES_13 29  // 13
#define STR_RES_14 30  // 14
#define STR_RES_15 31  // 15
#define STR_RES_16 32  // 16
#define STR_RES_FLT 33  // flt
#define STR_RES_OFF 34  // off
#define STR_RES_ON 35  // on
#define STR_RES_NO 36  // no
#define STR_RES_YES 37  // yes
#define STR_RES_RUN 38  // run
#define STR_RES_BPM 39  // bpm
#define STR_RES_GRV 40  // grv
#define STR_RES_AMT 41  // amt
#define STR_RES_SWG 42  // swg
#define STR_RES_SHF 43  // shf
#define STR_RES_PSH 44  // psh
#define STR_RES_LAG 45  // lag
#define STR_RES_HUM 46  // hum
#define STR_RES_MNK 47  // mnk
#define STR_RES_VAL 48  // val
#define STR_RES_NUM 49  // num
#define STR_RES_TYP 50  // typ
#define STR_RES_CC_ 51  // cc#
#define STR_RES_NRP 52  // nrp
#define STR_RES_MIN 53  // min
#define STR_RES_MAX 54  // max
#define STR_RES_LVL 55  // lvl
#define STR_RES_RST 56  // rst
#define STR_RES_SORRY___ 57  // sorry...
#define STR_RES_PERFECT_ 58  // perfect!
#define STR_RES_NOT_BAD_ 59  // not bad!
#define STR_RES_INT 60  // int
#define STR_RES_EXT 61  // ext
#define STR_RES_CLK 62  // clk
#define STR_RES_PT1 63  // pt1
#define STR_RES_PT2 64  // pt2
#define STR_RES_PT3 65  // pt3
#define STR_RES_PT4 66  // pt4
#define STR_RES_CC1 67  // cc1
#define STR_RES_CC2 68  // cc2
#define STR_RES_CC3 69  // cc3
#define STR_RES_CC4 70  // cc4
#define STR_RES_CC5 71  // cc5
#define STR_RES_CC6 72  // cc6
#define STR_RES_CC7 73  // cc7
#define STR_RES_CC8 74  // cc8
#define STR_RES_INP 75  // inp
#define STR_RES_SPL 76  // spl
#define STR_RES_LOW 77  // low
#define STR_RES_UPP 78  // upp
#define LUT_RES_ARPEGGIATOR_PATTERNS 0
#define LUT_RES_ARPEGGIATOR_PATTERNS_SIZE 15
#define LUT_RES_DRUM_PATTERNS 1
#define LUT_RES_DRUM_PATTERNS_SIZE 48
#define LUT_RES_GROOVE_SWING 2
#define LUT_RES_GROOVE_SWING_SIZE 16
#define LUT_RES_GROOVE_SHUFFLE 3
#define LUT_RES_GROOVE_SHUFFLE_SIZE 16
#define LUT_RES_GROOVE_PUSH 4
#define LUT_RES_GROOVE_PUSH_SIZE 16
#define LUT_RES_GROOVE_LAG 5
#define LUT_RES_GROOVE_LAG_SIZE 16
#define LUT_RES_GROOVE_HUMAN 6
#define LUT_RES_GROOVE_HUMAN_SIZE 16
#define LUT_RES_GROOVE_MONKEY 7
#define LUT_RES_GROOVE_MONKEY_SIZE 16
#define LUT_RES_EUCLIDIAN_PATTERNS 8
#define LUT_RES_EUCLIDIAN_PATTERNS_SIZE 144
#define CHR_RES_DIGITS_10 0
#define CHR_RES_DIGITS_10_SIZE 56
typedef avrlib::ResourcesManager<
    ResourceId,
    avrlib::ResourcesTables<
        string_table,
        lookup_table_table> > ResourcesManager; 

}  // namespace midipal

#endif  // MIDIPAL_RESOURCES_H_
