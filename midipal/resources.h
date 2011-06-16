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
#define STR_RES_0XFE_FLT 0  // 0xfe flt
#define STR_RES_ARPEGGIO 1  // arpeggio
#define STR_RES_BPM_CNTR 2  // bpm cntr
#define STR_RES_CC_KNOB 3  // cc knob
#define STR_RES_CHORDMEM 4  // chordmem
#define STR_RES_CLOCK 5  // clock
#define STR_RES_MERGECHN 6  // mergechn
#define STR_RES_DISPATCH 7  // dispatch
#define STR_RES_DRUMS 8  // drums
#define STR_RES_EAR_GAME 9  // ear game
#define STR_RES_MONITOR 10  // monitor
#define STR_RES_RANDOMIZ 11  // randomiz
#define STR_RES_CONTRLLR 12  // contrllr
#define STR_RES_SPLITTER 13  // splitter
#define STR_RES_SNDOFF 14  // sndOff
#define STR_RES_RSTCTR 15  // rstCtr
#define STR_RES_NOTOFF 16  // notOff
#define STR_RES_OMNOFF 17  // omnOff
#define STR_RES_OMNION 18  // omniOn
#define STR_RES_MONOON 19  // monoOn
#define STR_RES_POLYON 20  // polyOn
#define STR_RES_SYSX__ 21  // sysx..
#define STR_RES__SYSX_ 22  // .sysx.
#define STR_RES___SYSX 23  // ..sysx
#define STR_RES_START 24  // start
#define STR_RES_STOP 25  // stop
#define STR_RES_CONT_ 26  // cont.
#define STR_RES_RESET 27  // reset
#define STR_RES_CHN 28  // chn
#define STR_RES_ALL 29  // all
#define STR_RES_FLT 30  // flt
#define STR_RES_OFF 31  // off
#define STR_RES_ON 32  // on
#define STR_RES_NO 33  // no
#define STR_RES_YES 34  // yes
#define STR_RES_RUN 35  // run
#define STR_RES_BPM 36  // bpm
#define STR_RES_GRV 37  // grv
#define STR_RES_AMT 38  // amt
#define STR_RES_SWG 39  // swg
#define STR_RES_SHF 40  // shf
#define STR_RES_PSH 41  // psh
#define STR_RES_LAG 42  // lag
#define STR_RES_HUM 43  // hum
#define STR_RES_MNK 44  // mnk
#define STR_RES_VAL 45  // val
#define STR_RES_NUM 46  // num
#define STR_RES_TYP 47  // typ
#define STR_RES_CC_ 48  // cc#
#define STR_RES_NRP 49  // nrp
#define STR_RES_MIN 50  // min
#define STR_RES_MAX 51  // max
#define STR_RES_LVL 52  // lvl
#define STR_RES_RST 53  // rst
#define STR_RES_SORRY___ 54  // sorry...
#define STR_RES_PERFECT_ 55  // perfect!
#define STR_RES_NOT_BAD_ 56  // not bad!
#define STR_RES_MOD 57  // mod
#define STR_RES_PTN 58  // ptn
#define STR_RES_EUC 59  // euc
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
#define STR_RES_OUT 76  // out
#define STR_RES_SPL 77  // spl
#define STR_RES_LOW 78  // low
#define STR_RES_UPP 79  // upp
#define STR_RES__AMT 80  //  amt
#define STR_RES_NOT 81  // not
#define STR_RES_VEL 82  // vel
#define STR_RES__C1 83  // #c1
#define STR_RES__C2 84  // #c2
#define STR_RES_CYC 85  // cyc
#define STR_RES_POL 86  // pol
#define STR_RES_RND 87  // rnd
#define STR_RES_STA 88  // sta
#define STR_RES_DIR 89  // dir
#define STR_RES_UP 90  // up
#define STR_RES_DWN 91  // dwn
#define STR_RES_U_D 92  // u&d
#define STR_RES__RND 93  //  rnd
#define STR_RES_OCT 94  // oct
#define STR_RES_DUR 95  // dur
#define STR_RES_DIV 96  // div
#define STR_RES_1_1 97  // 1/1
#define STR_RES_3_4 98  // 3/4
#define STR_RES_2_3 99  // 2/3
#define STR_RES_1_2 100  // 1/2
#define STR_RES_3_8 101  // 3/8
#define STR_RES_1_3 102  // 1/3
#define STR_RES_1_4 103  // 1/4
#define STR_RES_1_6 104  // 1/6
#define STR_RES_1_8 105  // 1/8
#define STR_RES__12 106  // /12
#define STR_RES__16 107  // /16
#define STR_RES__24 108  // /24
#define STR_RES__32 109  // /32
#define STR_RES__48 110  // /48
#define STR_RES__96 111  // /96
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
