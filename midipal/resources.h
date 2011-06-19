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
extern const prog_uint8_t chr_res_sequencer_icons[] PROGMEM;
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
#define STR_RES_SEQUENCR 16  // sequencr
#define STR_RES_SNDOFF 17  // sndOff
#define STR_RES_RSTCTR 18  // rstCtr
#define STR_RES_NOTOFF 19  // notOff
#define STR_RES_OMNOFF 20  // omnOff
#define STR_RES_OMNION 21  // omniOn
#define STR_RES_MONOON 22  // monoOn
#define STR_RES_POLYON 23  // polyOn
#define STR_RES_SYSX__ 24  // sysx..
#define STR_RES__SYSX_ 25  // .sysx.
#define STR_RES___SYSX 26  // ..sysx
#define STR_RES_START 27  // start
#define STR_RES_STOP 28  // stop
#define STR_RES_CONT_ 29  // cont.
#define STR_RES_RESET 30  // reset
#define STR_RES_CHN 31  // chn
#define STR_RES_ALL 32  // all
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
#define STR_RES_MOD 60  // mod
#define STR_RES_PTN 61  // ptn
#define STR_RES_EUC 62  // euc
#define STR_RES_INT 63  // int
#define STR_RES_EXT 64  // ext
#define STR_RES_CLK 65  // clk
#define STR_RES_PT1 66  // pt1
#define STR_RES_PT2 67  // pt2
#define STR_RES_PT3 68  // pt3
#define STR_RES_PT4 69  // pt4
#define STR_RES_CC1 70  // cc1
#define STR_RES_CC2 71  // cc2
#define STR_RES_CC3 72  // cc3
#define STR_RES_CC4 73  // cc4
#define STR_RES_CC5 74  // cc5
#define STR_RES_CC6 75  // cc6
#define STR_RES_CC7 76  // cc7
#define STR_RES_CC8 77  // cc8
#define STR_RES_INP 78  // inp
#define STR_RES_OUT 79  // out
#define STR_RES_SPL 80  // spl
#define STR_RES_LOW 81  // low
#define STR_RES_UPP 82  // upp
#define STR_RES__AMT 83  //  amt
#define STR_RES_NOT 84  // not
#define STR_RES_VEL 85  // vel
#define STR_RES__C1 86  // #c1
#define STR_RES__C2 87  // #c2
#define STR_RES_CYC 88  // cyc
#define STR_RES_POL 89  // pol
#define STR_RES_RND 90  // rnd
#define STR_RES_STA 91  // sta
#define STR_RES_DIR 92  // dir
#define STR_RES_UP 93  // up
#define STR_RES_DWN 94  // dwn
#define STR_RES_U_D 95  // u&d
#define STR_RES__RND 96  //  rnd
#define STR_RES_OCT 97  // oct
#define STR_RES_DUR 98  // dur
#define STR_RES_DIV 99  // div
#define STR_RES_1_1 100  // 1/1
#define STR_RES_3_4 101  // 3/4
#define STR_RES_2_3 102  // 2/3
#define STR_RES_1_2 103  // 1/2
#define STR_RES_3_8 104  // 3/8
#define STR_RES_1_3 105  // 1/3
#define STR_RES_1_4 106  // 1/4
#define STR_RES_1_6 107  // 1/6
#define STR_RES_1_8 108  // 1/8
#define STR_RES__12 109  // /12
#define STR_RES__16 110  // /16
#define STR_RES__24 111  // /24
#define STR_RES__32 112  // /32
#define STR_RES__48 113  // /48
#define STR_RES__96 114  // /96
#define STR_RES_REP 115  // rep
#define STR_RES_TRS 116  // trs
#define STR_RES_OFF_ 117  // off_
#define STR_RES_MIR 118  // mir
#define STR_RES_ALT 119  // alt
#define STR_RES_TRK 120  // trk
#define STR_RES___RND 121  //   rnd
#define STR_RES_ROO 122  // roo
#define STR_RES_SCL 123  // scl
#define STR_RES_VOI 124  // voi
#define STR_RES_HRM 125  // hrm
#define STR_RES_CHR 126  // chr
#define STR_RES_ION 127  // ion
#define STR_RES_DOR 128  // dor
#define STR_RES_PHR 129  // phr
#define STR_RES_LYD 130  // lyd
#define STR_RES_MIX 131  // mix
#define STR_RES_AEO 132  // aeo
#define STR_RES_LOC 133  // loc
#define STR_RES_BMJ 134  // bmj
#define STR_RES_BMN 135  // bmn
#define STR_RES_PMJ 136  // pmj
#define STR_RES_PMN 137  // pmn
#define STR_RES_BHR 138  // bhr
#define STR_RES_SHR 139  // shr
#define STR_RES_RUP 140  // rup
#define STR_RES_TOD 141  // tod
#define STR_RES_RAG 142  // rag
#define STR_RES_KAA 143  // kaa
#define STR_RES_MEG 144  // meg
#define STR_RES_MLK 145  // mlk
#define STR_RES_DPK 146  // dpk
#define STR_RES_FLK 147  // flk
#define STR_RES_JAP 148  // jap
#define STR_RES_GAM 149  // gam
#define STR_RES_WHL 150  // whl
#define STR_RES_C 151  // C
#define STR_RES_C_ 152  // C#
#define STR_RES_D 153  // D
#define STR_RES_D_ 154  // D#
#define STR_RES_E 155  // E
#define STR_RES_F 156  // F
#define STR_RES_F_ 157  // F#
#define STR_RES_G 158  // G
#define STR_RES_G_ 159  // G#
#define STR_RES_A 160  // A
#define STR_RES_A_ 161  // A#
#define STR_RES_B 162  // B
#define STR_RES__C 163  //  C
#define STR_RES_DB 164  // Db
#define STR_RES__D 165  //  D
#define STR_RES_EB 166  // Eb
#define STR_RES__E 167  //  E
#define STR_RES__F 168  //  F
#define STR_RES_GB 169  // Gb
#define STR_RES__G 170  //  G
#define STR_RES_AB 171  // Ab
#define STR_RES__A 172  //  A
#define STR_RES_BB 173  // Bb
#define STR_RES__B 174  //  B
#define STR_RES__ 175  //  
#define STR_RES_STP 176  // stp
#define STR_RES_1 177  // 
#define STR_RES_2 178  // 
#define STR_RES_3 179  // 
#define STR_RES_4 180  // 
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
#define CHR_RES_SEQUENCER_ICONS 1
#define CHR_RES_SEQUENCER_ICONS_SIZE 32
typedef avrlib::ResourcesManager<
    ResourceId,
    avrlib::ResourcesTables<
        string_table,
        lookup_table_table> > ResourcesManager; 

}  // namespace midipal

#endif  // MIDIPAL_RESOURCES_H_
