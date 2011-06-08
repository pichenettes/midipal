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
#define STR_RES_FLT 17  // flt
#define STR_RES_OFF 18  // off
#define STR_RES_ON 19  // on
#define STR_RES_NO 20  // no
#define STR_RES_YES 21  // yes
#define STR_RES_RUN 22  // run
#define STR_RES_BPM 23  // bpm
#define STR_RES_GRV 24  // grv
#define STR_RES_AMT 25  // amt
#define STR_RES_SWG 26  // swg
#define STR_RES_SHF 27  // shf
#define STR_RES_PSH 28  // psh
#define STR_RES_LAG 29  // lag
#define STR_RES_HUM 30  // hum
#define STR_RES_MNK 31  // mnk
#define STR_RES_VAL 32  // val
#define STR_RES_NUM 33  // num
#define STR_RES_TYP 34  // typ
#define STR_RES_CC_ 35  // cc#
#define STR_RES_NRP 36  // nrp
#define STR_RES_MIN 37  // min
#define STR_RES_MAX 38  // max
#define STR_RES_LVL 39  // lvl
#define STR_RES_RST 40  // rst
#define STR_RES_SORRY___ 41  // sorry...
#define STR_RES_PERFECT_ 42  // perfect!
#define STR_RES_NOT_BAD_ 43  // not bad!
#define STR_RES_MOD 44  // mod
#define STR_RES_PTN 45  // ptn
#define STR_RES_EUC 46  // euc
#define STR_RES_INT 47  // int
#define STR_RES_EXT 48  // ext
#define STR_RES_CLK 49  // clk
#define STR_RES_PT1 50  // pt1
#define STR_RES_PT2 51  // pt2
#define STR_RES_PT3 52  // pt3
#define STR_RES_PT4 53  // pt4
#define STR_RES_CC1 54  // cc1
#define STR_RES_CC2 55  // cc2
#define STR_RES_CC3 56  // cc3
#define STR_RES_CC4 57  // cc4
#define STR_RES_CC5 58  // cc5
#define STR_RES_CC6 59  // cc6
#define STR_RES_CC7 60  // cc7
#define STR_RES_CC8 61  // cc8
#define STR_RES_INP 62  // inp
#define STR_RES_SPL 63  // spl
#define STR_RES_LOW 64  // low
#define STR_RES_UPP 65  // upp
#define STR_RES_NOT 66  // not
#define STR_RES_VEL 67  // vel
#define STR_RES__C1 68  // #c1
#define STR_RES__C2 69  // #c2
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
