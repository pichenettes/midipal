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

extern const prog_uint8_t* waveform_table[];

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
extern const prog_uint16_t lut_res_increments[] PROGMEM;
extern const prog_uint8_t chr_res_digits_10[] PROGMEM;
extern const prog_uint8_t chr_res_sequencer_icons[] PROGMEM;
extern const prog_uint8_t wav_res_lfo_waveforms[] PROGMEM;
#define STR_RES_SYNCLTCH 0  // syncltch
#define STR_RES_POLYSEQ 1  // polyseq
#define STR_RES_ARPEGGIO 2  // arpeggio
#define STR_RES_BPM_CNTR 3  // bpm cntr
#define STR_RES_CC_KNOB 4  // cc knob
#define STR_RES_CHORDMEM 5  // chordmem
#define STR_RES_CLOCK 6  // clock
#define STR_RES_DIVIDER 7  // divider
#define STR_RES_CHNFILTR 8  // chnfiltr
#define STR_RES_CHNMERGR 9  // chnmergr
#define STR_RES_USER_PRG 10  // user prg
#define STR_RES_DISPATCH 11  // dispatch
#define STR_RES_DRUMS 12  // drums
#define STR_RES_EAR_GAME 13  // ear game
#define STR_RES_MONITOR 14  // monitor
#define STR_RES_RANDOMIZ 15  // randomiz
#define STR_RES_CONTRLLR 16  // contrllr
#define STR_RES_SPLITTER 17  // splitter
#define STR_RES_DELAY 18  // delay
#define STR_RES_SCALE 19  // scale
#define STR_RES_SEQUENCR 20  // sequencr
#define STR_RES_CC_LFO 21  // cc lfo
#define STR_RES_TANPURA 22  // tanpura
#define STR_RES_SETTINGS 23  // settings
#define STR_RES_NOTENUKE 24  // notenuke
#define STR_RES_SYSXDUMP 25  // sysxdump
#define STR_RES__RESET_ 26  // !reset!
#define STR_RES___V1_3__ 27  // ¥ v1.3 ¥
#define STR_RES_SNDOFF 28  // sndOff
#define STR_RES_RSTCTR 29  // rstCtr
#define STR_RES_LCLCTR 30  // lclCtr
#define STR_RES_NOTOFF 31  // notOff
#define STR_RES_OMNOFF 32  // omnOff
#define STR_RES_OMNION 33  // omniOn
#define STR_RES_MONOON 34  // monoOn
#define STR_RES_POLYON 35  // polyOn
#define STR_RES_SYSX__ 36  // sysx..
#define STR_RES__SYSX_ 37  // .sysx.
#define STR_RES___SYSX 38  // ..sysx
#define STR_RES_START 39  // start
#define STR_RES_STOP 40  // stop
#define STR_RES_CONT_ 41  // cont.
#define STR_RES_RESET 42  // reset
#define STR_RES_CHN 43  // chn
#define STR_RES_CCC 44  // ccc
#define STR_RES_CLC 45  // clc
#define STR_RES_CLR 46  // clr
#define STR_RES_ALL 47  // all
#define STR_RES_REST 48  // rest
#define STR_RES_TIE 49  // tie
#define STR_RES_EXIT 50  // exit
#define STR_RES_OFF 51  // off
#define STR_RES_ON 52  // on
#define STR_RES_NO 53  // no
#define STR_RES_YES 54  // yes
#define STR_RES_XFE 55  // xFE
#define STR_RES_LET 56  // let
#define STR_RES_FLT 57  // flt
#define STR_RES_HLD 58  // hld
#define STR_RES__5S 59  // .5s
#define STR_RES__1S 60  // 1s
#define STR_RES__2S 61  // 2s
#define STR_RES_REC 62  // rec
#define STR_RES_DUB 63  // dub
#define STR_RES__TIE 64  // tie
#define STR_RES_RUN 65  // run
#define STR_RES_BPM 66  // bpm
#define STR_RES_GRV 67  // grv
#define STR_RES_AMT 68  // amt
#define STR_RES_TAP 69  // tap
#define STR_RES_SWG 70  // swg
#define STR_RES_SHF 71  // shf
#define STR_RES_PSH 72  // psh
#define STR_RES_LAG 73  // lag
#define STR_RES_HUM 74  // hum
#define STR_RES_MNK 75  // mnk
#define STR_RES_VAL 76  // val
#define STR_RES_NUM 77  // num
#define STR_RES_TYP 78  // typ
#define STR_RES_CC_ 79  // cc#
#define STR_RES_NRP 80  // nrp
#define STR_RES_MIN 81  // min
#define STR_RES_MAX 82  // max
#define STR_RES_LVL 83  // lvl
#define STR_RES_RST 84  // rst
#define STR_RES_SORRY___ 85  // sorry...
#define STR_RES_PERFECT_ 86  // perfect!
#define STR_RES_NOT_BAD_ 87  // not bad!
#define STR_RES_MOD 88  // mod
#define STR_RES_PTN 89  // ptn
#define STR_RES_LEN 90  // len
#define STR_RES_EUC 91  // euc
#define STR_RES_INT 92  // int
#define STR_RES_EXT 93  // ext
#define STR_RES_CLK 94  // clk
#define STR_RES_PT1 95  // pt1
#define STR_RES_PT2 96  // pt2
#define STR_RES_PT3 97  // pt3
#define STR_RES_PT4 98  // pt4
#define STR_RES_CC1 99  // cc1
#define STR_RES_CC2 100  // cc2
#define STR_RES_CC3 101  // cc3
#define STR_RES_CC4 102  // cc4
#define STR_RES_CC5 103  // cc5
#define STR_RES_CC6 104  // cc6
#define STR_RES_CC7 105  // cc7
#define STR_RES_CC8 106  // cc8
#define STR_RES_INP 107  // inp
#define STR_RES_OUT 108  // out
#define STR_RES_SPL 109  // spl
#define STR_RES_LOW 110  // low
#define STR_RES_UPP 111  // upp
#define STR_RES__AMT 112  // amt
#define STR_RES_NOT 113  // not
#define STR_RES_VEL 114  // vel
#define STR_RES__C1 115  // #c1
#define STR_RES__C2 116  // #c2
#define STR_RES_CYC 117  // cyc
#define STR_RES_POL 118  // pol
#define STR_RES_RND 119  // rnd
#define STR_RES_STK 120  // stk
#define STR_RES__VEL 121  // vel
#define STR_RES_DIR 122  // dir
#define STR_RES_UP 123  // up
#define STR_RES_DWN 124  // dwn
#define STR_RES_U_D 125  // u&d
#define STR_RES__RND 126  // rnd
#define STR_RES_OCT 127  // oct
#define STR_RES_DUR 128  // dur
#define STR_RES_LAT 129  // lat
#define STR_RES_DIV 130  // div
#define STR_RES_DEN 131  // den
#define STR_RES_4_1 132  // 4/1
#define STR_RES_3_1 133  // 3/1
#define STR_RES_2_1 134  // 2/1
#define STR_RES_3_2 135  // 3/2
#define STR_RES_1_1 136  // 1/1
#define STR_RES_3_4 137  // 3/4
#define STR_RES_2_3 138  // 2/3
#define STR_RES_1_2 139  // 1/2
#define STR_RES_3_8 140  // 3/8
#define STR_RES_1_3 141  // 1/3
#define STR_RES_1_4 142  // 1/4
#define STR_RES_1_6 143  // 1/6
#define STR_RES_1_8 144  // 1/8
#define STR_RES__12 145  // /12
#define STR_RES__16 146  // /16
#define STR_RES__24 147  // /24
#define STR_RES__32 148  // /32
#define STR_RES__48 149  // /48
#define STR_RES__96 150  // /96
#define STR_RES_REP 151  // rep
#define STR_RES_TRS 152  // trs
#define STR_RES_DPL 153  // dpl
#define STR_RES_OFF_ 154  // off_
#define STR_RES_MIR 155  // mir
#define STR_RES_ALT 156  // alt
#define STR_RES_TRK 157  // trk
#define STR_RES___RND 158  // rnd
#define STR_RES_ROO 159  // roo
#define STR_RES_SCL 160  // scl
#define STR_RES_VOI 161  // voi
#define STR_RES_HRM 162  // hrm
#define STR_RES_CHR 163  // chr
#define STR_RES_ION 164  // ion
#define STR_RES_DOR 165  // dor
#define STR_RES_PHR 166  // phr
#define STR_RES_LYD 167  // lyd
#define STR_RES_MIX 168  // mix
#define STR_RES_AEO 169  // aeo
#define STR_RES_LOC 170  // loc
#define STR_RES_BMJ 171  // bmj
#define STR_RES_BMN 172  // bmn
#define STR_RES_PMJ 173  // pmj
#define STR_RES_PMN 174  // pmn
#define STR_RES_BHR 175  // bhr
#define STR_RES_SHR 176  // shr
#define STR_RES_RUP 177  // rup
#define STR_RES_TOD 178  // tod
#define STR_RES_RAG 179  // rag
#define STR_RES_KAA 180  // kaa
#define STR_RES_MEG 181  // meg
#define STR_RES_MLK 182  // mlk
#define STR_RES_DPK 183  // dpk
#define STR_RES_FLK 184  // flk
#define STR_RES_JAP 185  // jap
#define STR_RES_GAM 186  // gam
#define STR_RES_WHL 187  // whl
#define STR_RES_KEY 188  // key
#define STR_RES__ 189  // 
#define STR_RES_STP 190  // stp
#define STR_RES_1 191  // 
#define STR_RES_2 192  // 
#define STR_RES_3 193  // 
#define STR_RES_4 194  // 
#define STR_RES_AM1 195  // am1
#define STR_RES_AM2 196  // am2
#define STR_RES_AM3 197  // am3
#define STR_RES_AM4 198  // am4
#define STR_RES_CE1 199  // ce1
#define STR_RES_CE2 200  // ce2
#define STR_RES_CE3 201  // ce3
#define STR_RES_CE4 202  // ce4
#define STR_RES_WF1 203  // wf1
#define STR_RES_WF2 204  // wf2
#define STR_RES_WF3 205  // wf3
#define STR_RES_WF4 206  // wf4
#define STR_RES_RT1 207  // rt1
#define STR_RES_RT2 208  // rt2
#define STR_RES_RT3 209  // rt3
#define STR_RES_RT4 210  // rt4
#define STR_RES_SY1 211  // sy1
#define STR_RES_SY2 212  // sy2
#define STR_RES_SY3 213  // sy3
#define STR_RES_SY4 214  // sy4
#define STR_RES_TRI 215  // tri
#define STR_RES_SQR 216  // sqr
#define STR_RES_RMP 217  // rmp
#define STR_RES_SIN 218  // sin
#define STR_RES_SI2 219  // si2
#define STR_RES_SI3 220  // si3
#define STR_RES_SI5 221  // si5
#define STR_RES_GG1 222  // gg1
#define STR_RES_GG2 223  // gg2
#define STR_RES_BT1 224  // bt1
#define STR_RES_BT2 225  // bt2
#define STR_RES_SP1 226  // sp1
#define STR_RES_SP2 227  // sp2
#define STR_RES_LP1 228  // lp1
#define STR_RES_LP2 229  // lp2
#define STR_RES_RS1 230  // rs1
#define STR_RES_RS2 231  // rs2
#define STR_RES_S_H 232  // s&h
#define STR_RES_PA 233  // pa
#define STR_RES_MA 234  // ma
#define STR_RES_NI 235  // ni
#define STR_RES_SA 236  // sa
#define STR_RES_RES 237  // res
#define STR_RES_FRE 238  // fre
#define STR_RES__NOT 239  // not
#define STR_RES_CHD 240  // chd
#define STR_RES_PRG 241  // prg
#define LUT_RES_ARPEGGIATOR_PATTERNS 0
#define LUT_RES_ARPEGGIATOR_PATTERNS_SIZE 22
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
#define LUT_RES_INCREMENTS 34
#define LUT_RES_INCREMENTS_SIZE 19
#define CHR_RES_DIGITS_10 0
#define CHR_RES_DIGITS_10_SIZE 56
#define CHR_RES_SEQUENCER_ICONS 1
#define CHR_RES_SEQUENCER_ICONS_SIZE 32
#define WAV_RES_LFO_WAVEFORMS 0
#define WAV_RES_LFO_WAVEFORMS_SIZE 2193
typedef avrlib::ResourcesManager<
    ResourceId,
    avrlib::ResourcesTables<
        string_table,
        lookup_table_table> > ResourcesManager; 

}  // namespace midipal

#endif  // MIDIPAL_RESOURCES_H_
