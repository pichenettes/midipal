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
extern const prog_uint16_t lut_res_scale_0[] PROGMEM;
extern const prog_uint16_t lut_res_scale_1[] PROGMEM;
extern const prog_uint16_t lut_res_scale_2[] PROGMEM;
extern const prog_uint16_t lut_res_scale_3[] PROGMEM;
extern const prog_uint16_t lut_res_scale_4[] PROGMEM;
extern const prog_uint16_t lut_res_scale_5[] PROGMEM;
extern const prog_uint16_t lut_res_scale_6[] PROGMEM;
extern const prog_uint16_t lut_res_scale_7[] PROGMEM;
extern const prog_uint16_t lut_res_scale_8[] PROGMEM;
extern const prog_uint16_t lut_res_scale_9[] PROGMEM;
extern const prog_uint16_t lut_res_scale_10[] PROGMEM;
extern const prog_uint16_t lut_res_scale_11[] PROGMEM;
extern const prog_uint16_t lut_res_scale_12[] PROGMEM;
extern const prog_uint16_t lut_res_scale_13[] PROGMEM;
extern const prog_uint16_t lut_res_scale_14[] PROGMEM;
extern const prog_uint16_t lut_res_scale_15[] PROGMEM;
extern const prog_uint16_t lut_res_scale_16[] PROGMEM;
extern const prog_uint16_t lut_res_scale_18[] PROGMEM;
extern const prog_uint16_t lut_res_scale_19[] PROGMEM;
extern const prog_uint16_t lut_res_scale_20[] PROGMEM;
extern const prog_uint16_t lut_res_scale_21[] PROGMEM;
extern const prog_uint16_t lut_res_scale_22[] PROGMEM;
extern const prog_uint16_t lut_res_scale_23[] PROGMEM;
extern const prog_uint16_t lut_res_scale_24[] PROGMEM;
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
#define STR_RES_SCALE 15  // scale
#define STR_RES_SNDOFF 16  // sndOff
#define STR_RES_RSTCTR 17  // rstCtr
#define STR_RES_NOTOFF 18  // notOff
#define STR_RES_OMNOFF 19  // omnOff
#define STR_RES_OMNION 20  // omniOn
#define STR_RES_MONOON 21  // monoOn
#define STR_RES_POLYON 22  // polyOn
#define STR_RES_SYSX__ 23  // sysx..
#define STR_RES__SYSX_ 24  // .sysx.
#define STR_RES___SYSX 25  // ..sysx
#define STR_RES_START 26  // start
#define STR_RES_STOP 27  // stop
#define STR_RES_CONT_ 28  // cont.
#define STR_RES_RESET 29  // reset
#define STR_RES_CHN 30  // chn
#define STR_RES_ALL 31  // all
#define STR_RES_FLT 32  // flt
#define STR_RES_OFF 33  // off
#define STR_RES_ON 34  // on
#define STR_RES_NO 35  // no
#define STR_RES_YES 36  // yes
#define STR_RES_RUN 37  // run
#define STR_RES_BPM 38  // bpm
#define STR_RES_GRV 39  // grv
#define STR_RES_AMT 40  // amt
#define STR_RES_SWG 41  // swg
#define STR_RES_SHF 42  // shf
#define STR_RES_PSH 43  // psh
#define STR_RES_LAG 44  // lag
#define STR_RES_HUM 45  // hum
#define STR_RES_MNK 46  // mnk
#define STR_RES_VAL 47  // val
#define STR_RES_NUM 48  // num
#define STR_RES_TYP 49  // typ
#define STR_RES_CC_ 50  // cc#
#define STR_RES_NRP 51  // nrp
#define STR_RES_MIN 52  // min
#define STR_RES_MAX 53  // max
#define STR_RES_LVL 54  // lvl
#define STR_RES_RST 55  // rst
#define STR_RES_SORRY___ 56  // sorry...
#define STR_RES_PERFECT_ 57  // perfect!
#define STR_RES_NOT_BAD_ 58  // not bad!
#define STR_RES_MOD 59  // mod
#define STR_RES_PTN 60  // ptn
#define STR_RES_EUC 61  // euc
#define STR_RES_INT 62  // int
#define STR_RES_EXT 63  // ext
#define STR_RES_CLK 64  // clk
#define STR_RES_PT1 65  // pt1
#define STR_RES_PT2 66  // pt2
#define STR_RES_PT3 67  // pt3
#define STR_RES_PT4 68  // pt4
#define STR_RES_CC1 69  // cc1
#define STR_RES_CC2 70  // cc2
#define STR_RES_CC3 71  // cc3
#define STR_RES_CC4 72  // cc4
#define STR_RES_CC5 73  // cc5
#define STR_RES_CC6 74  // cc6
#define STR_RES_CC7 75  // cc7
#define STR_RES_CC8 76  // cc8
#define STR_RES_INP 77  // inp
#define STR_RES_OUT 78  // out
#define STR_RES_SPL 79  // spl
#define STR_RES_LOW 80  // low
#define STR_RES_UPP 81  // upp
#define STR_RES__AMT 82  //  amt
#define STR_RES_NOT 83  // not
#define STR_RES_VEL 84  // vel
#define STR_RES__C1 85  // #c1
#define STR_RES__C2 86  // #c2
#define STR_RES_CYC 87  // cyc
#define STR_RES_POL 88  // pol
#define STR_RES_RND 89  // rnd
#define STR_RES_STA 90  // sta
#define STR_RES_DIR 91  // dir
#define STR_RES_UP 92  // up
#define STR_RES_DWN 93  // dwn
#define STR_RES_U_D 94  // u&d
#define STR_RES__RND 95  //  rnd
#define STR_RES_OCT 96  // oct
#define STR_RES_DUR 97  // dur
#define STR_RES_DIV 98  // div
#define STR_RES_1_1 99  // 1/1
#define STR_RES_3_4 100  // 3/4
#define STR_RES_2_3 101  // 2/3
#define STR_RES_1_2 102  // 1/2
#define STR_RES_3_8 103  // 3/8
#define STR_RES_1_3 104  // 1/3
#define STR_RES_1_4 105  // 1/4
#define STR_RES_1_6 106  // 1/6
#define STR_RES_1_8 107  // 1/8
#define STR_RES__12 108  // /12
#define STR_RES__16 109  // /16
#define STR_RES__24 110  // /24
#define STR_RES__32 111  // /32
#define STR_RES__48 112  // /48
#define STR_RES__96 113  // /96
#define STR_RES_REP 114  // rep
#define STR_RES_TRS 115  // trs
#define STR_RES_OFF_ 116  // off_
#define STR_RES_MIR 117  // mir
#define STR_RES_ALT 118  // alt
#define STR_RES_TRK 119  // trk
#define STR_RES___RND 120  //   rnd
#define STR_RES_ROO 121  // roo
#define STR_RES_SCL 122  // scl
#define STR_RES_VOI 123  // voi
#define STR_RES_HRM 124  // hrm
#define STR_RES_CHR 125  // chr
#define STR_RES_ION 126  // ion
#define STR_RES_DOR 127  // dor
#define STR_RES_PHR 128  // phr
#define STR_RES_LYD 129  // lyd
#define STR_RES_MIX 130  // mix
#define STR_RES_AEO 131  // aeo
#define STR_RES_LOC 132  // loc
#define STR_RES_BMJ 133  // bmj
#define STR_RES_BMN 134  // bmn
#define STR_RES_PMJ 135  // pmj
#define STR_RES_PMN 136  // pmn
#define STR_RES_BHR 137  // bhr
#define STR_RES_SHR 138  // shr
#define STR_RES_RUP 139  // rup
#define STR_RES_TOD 140  // tod
#define STR_RES_RAG 141  // rag
#define STR_RES_KAA 142  // kaa
#define STR_RES_MEG 143  // meg
#define STR_RES_MLK 144  // mlk
#define STR_RES_DPK 145  // dpk
#define STR_RES_FLK 146  // flk
#define STR_RES_JAP 147  // jap
#define STR_RES_GAM 148  // gam
#define STR_RES_WHL 149  // whl
#define STR_RES_C 150  // C
#define STR_RES_C_ 151  // C#
#define STR_RES_D 152  // D
#define STR_RES_D_ 153  // D#
#define STR_RES_E 154  // E
#define STR_RES_F 155  // F
#define STR_RES_F_ 156  // F#
#define STR_RES_G 157  // G
#define STR_RES_G_ 158  // G#
#define STR_RES_A 159  // A
#define STR_RES_A_ 160  // A#
#define STR_RES_B 161  // B
#define STR_RES__C 162  //  C
#define STR_RES_DB 163  // Db
#define STR_RES__D 164  //  D
#define STR_RES_EB 165  // Eb
#define STR_RES__E 166  //  E
#define STR_RES__F 167  //  F
#define STR_RES_GB 168  // Gb
#define STR_RES__G 169  //  G
#define STR_RES_AB 170  // Ab
#define STR_RES__A 171  //  A
#define STR_RES_BB 172  // Bb
#define STR_RES__B 173  //  B
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
#define LUT_RES_SCALE_0 9
#define LUT_RES_SCALE_0_SIZE 12
#define LUT_RES_SCALE_1 10
#define LUT_RES_SCALE_1_SIZE 12
#define LUT_RES_SCALE_2 11
#define LUT_RES_SCALE_2_SIZE 12
#define LUT_RES_SCALE_3 12
#define LUT_RES_SCALE_3_SIZE 12
#define LUT_RES_SCALE_4 13
#define LUT_RES_SCALE_4_SIZE 12
#define LUT_RES_SCALE_5 14
#define LUT_RES_SCALE_5_SIZE 12
#define LUT_RES_SCALE_6 15
#define LUT_RES_SCALE_6_SIZE 12
#define LUT_RES_SCALE_7 16
#define LUT_RES_SCALE_7_SIZE 12
#define LUT_RES_SCALE_8 17
#define LUT_RES_SCALE_8_SIZE 12
#define LUT_RES_SCALE_9 18
#define LUT_RES_SCALE_9_SIZE 12
#define LUT_RES_SCALE_10 19
#define LUT_RES_SCALE_10_SIZE 12
#define LUT_RES_SCALE_11 20
#define LUT_RES_SCALE_11_SIZE 12
#define LUT_RES_SCALE_12 21
#define LUT_RES_SCALE_12_SIZE 12
#define LUT_RES_SCALE_13 22
#define LUT_RES_SCALE_13_SIZE 12
#define LUT_RES_SCALE_14 23
#define LUT_RES_SCALE_14_SIZE 12
#define LUT_RES_SCALE_15 24
#define LUT_RES_SCALE_15_SIZE 12
#define LUT_RES_SCALE_16 25
#define LUT_RES_SCALE_16_SIZE 12
#define LUT_RES_SCALE_17 26
#define LUT_RES_SCALE_17_SIZE 12
#define LUT_RES_SCALE_18 27
#define LUT_RES_SCALE_18_SIZE 12
#define LUT_RES_SCALE_19 28
#define LUT_RES_SCALE_19_SIZE 12
#define LUT_RES_SCALE_20 29
#define LUT_RES_SCALE_20_SIZE 12
#define LUT_RES_SCALE_21 30
#define LUT_RES_SCALE_21_SIZE 12
#define LUT_RES_SCALE_22 31
#define LUT_RES_SCALE_22_SIZE 12
#define LUT_RES_SCALE_23 32
#define LUT_RES_SCALE_23_SIZE 12
#define LUT_RES_SCALE_24 33
#define LUT_RES_SCALE_24_SIZE 12
#define CHR_RES_DIGITS_10 0
#define CHR_RES_DIGITS_10_SIZE 56
typedef avrlib::ResourcesManager<
    ResourceId,
    avrlib::ResourcesTables<
        string_table,
        lookup_table_table> > ResourcesManager; 

}  // namespace midipal

#endif  // MIDIPAL_RESOURCES_H_
