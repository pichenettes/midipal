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
#define STR_RES_DELAY 14  // delay
#define STR_RES_SNDOFF 15  // sndOff
#define STR_RES_RSTCTR 16  // rstCtr
#define STR_RES_NOTOFF 17  // notOff
#define STR_RES_OMNOFF 18  // omnOff
#define STR_RES_OMNION 19  // omniOn
#define STR_RES_MONOON 20  // monoOn
#define STR_RES_POLYON 21  // polyOn
#define STR_RES_SYSX__ 22  // sysx..
#define STR_RES__SYSX_ 23  // .sysx.
#define STR_RES___SYSX 24  // ..sysx
#define STR_RES_START 25  // start
#define STR_RES_STOP 26  // stop
#define STR_RES_CONT_ 27  // cont.
#define STR_RES_RESET 28  // reset
#define STR_RES_CHN 29  // chn
#define STR_RES_ALL 30  // all
#define STR_RES_FLT 31  // flt
#define STR_RES_OFF 32  // off
#define STR_RES_ON 33  // on
#define STR_RES_NO 34  // no
#define STR_RES_YES 35  // yes
#define STR_RES_RUN 36  // run
#define STR_RES_BPM 37  // bpm
#define STR_RES_GRV 38  // grv
#define STR_RES_AMT 39  // amt
#define STR_RES_SWG 40  // swg
#define STR_RES_SHF 41  // shf
#define STR_RES_PSH 42  // psh
#define STR_RES_LAG 43  // lag
#define STR_RES_HUM 44  // hum
#define STR_RES_MNK 45  // mnk
#define STR_RES_VAL 46  // val
#define STR_RES_NUM 47  // num
#define STR_RES_TYP 48  // typ
#define STR_RES_CC_ 49  // cc#
#define STR_RES_NRP 50  // nrp
#define STR_RES_MIN 51  // min
#define STR_RES_MAX 52  // max
#define STR_RES_LVL 53  // lvl
#define STR_RES_RST 54  // rst
#define STR_RES_SORRY___ 55  // sorry...
#define STR_RES_PERFECT_ 56  // perfect!
#define STR_RES_NOT_BAD_ 57  // not bad!
#define STR_RES_MOD 58  // mod
#define STR_RES_PTN 59  // ptn
#define STR_RES_EUC 60  // euc
#define STR_RES_INT 61  // int
#define STR_RES_EXT 62  // ext
#define STR_RES_CLK 63  // clk
#define STR_RES_PT1 64  // pt1
#define STR_RES_PT2 65  // pt2
#define STR_RES_PT3 66  // pt3
#define STR_RES_PT4 67  // pt4
#define STR_RES_CC1 68  // cc1
#define STR_RES_CC2 69  // cc2
#define STR_RES_CC3 70  // cc3
#define STR_RES_CC4 71  // cc4
#define STR_RES_CC5 72  // cc5
#define STR_RES_CC6 73  // cc6
#define STR_RES_CC7 74  // cc7
#define STR_RES_CC8 75  // cc8
#define STR_RES_INP 76  // inp
#define STR_RES_OUT 77  // out
#define STR_RES_SPL 78  // spl
#define STR_RES_LOW 79  // low
#define STR_RES_UPP 80  // upp
#define STR_RES__AMT 81  //  amt
#define STR_RES_NOT 82  // not
#define STR_RES_VEL 83  // vel
#define STR_RES__C1 84  // #c1
#define STR_RES__C2 85  // #c2
#define STR_RES_CYC 86  // cyc
#define STR_RES_POL 87  // pol
#define STR_RES_RND 88  // rnd
#define STR_RES_STA 89  // sta
#define STR_RES_DIR 90  // dir
#define STR_RES_UP 91  // up
#define STR_RES_DWN 92  // dwn
#define STR_RES_U_D 93  // u&d
#define STR_RES__RND 94  //  rnd
#define STR_RES_OCT 95  // oct
#define STR_RES_DUR 96  // dur
#define STR_RES_DIV 97  // div
#define STR_RES_1_1 98  // 1/1
#define STR_RES_3_4 99  // 3/4
#define STR_RES_2_3 100  // 2/3
#define STR_RES_1_2 101  // 1/2
#define STR_RES_3_8 102  // 3/8
#define STR_RES_1_3 103  // 1/3
#define STR_RES_1_4 104  // 1/4
#define STR_RES_1_6 105  // 1/6
#define STR_RES_1_8 106  // 1/8
#define STR_RES__12 107  // /12
#define STR_RES__16 108  // /16
#define STR_RES__24 109  // /24
#define STR_RES__32 110  // /32
#define STR_RES__48 111  // /48
#define STR_RES__96 112  // /96
#define STR_RES_REP 113  // rep
#define STR_RES_TRS 114  // trs
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
