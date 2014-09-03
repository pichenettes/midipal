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
#define STR_RES_LATCH 3  // latch
#define STR_RES_BPM_CNTR 4  // bpm cntr
#define STR_RES_CC_KNOB 5  // cc knob
#define STR_RES_CHORDMEM 6  // chordmem
#define STR_RES_CLOCK 7  // clock
#define STR_RES_DIVIDER 8  // divider
#define STR_RES_CHNFILTR 9  // chnfiltr
#define STR_RES_CHNMERGR 10  // chnmergr
#define STR_RES_USER_PRG 11  // user prg
#define STR_RES_DISPATCH 12  // dispatch
#define STR_RES_DRUMS 13  // drums
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
#define STR_RES___V1_4__ 27  // ¥ v1.4 ¥
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
#define STR_RES_CLN 46  // cln
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
#define STR_RES_REC 58  // rec
#define STR_RES_DUB 59  // dub
#define STR_RES__TIE 60  // tie
#define STR_RES_RUN 61  // run
#define STR_RES_BPM 62  // bpm
#define STR_RES_GRV 63  // grv
#define STR_RES_AMT 64  // amt
#define STR_RES_TAP 65  // tap
#define STR_RES_SWG 66  // swg
#define STR_RES_SHF 67  // shf
#define STR_RES_PSH 68  // psh
#define STR_RES_LAG 69  // lag
#define STR_RES_HUM 70  // hum
#define STR_RES_MNK 71  // mnk
#define STR_RES_VAL 72  // val
#define STR_RES_NUM 73  // num
#define STR_RES_TYP 74  // typ
#define STR_RES_CC_ 75  // cc#
#define STR_RES_NRP 76  // nrp
#define STR_RES_MIN 77  // min
#define STR_RES_MAX 78  // max
#define STR_RES_MOD 79  // mod
#define STR_RES_PTN 80  // ptn
#define STR_RES_LEN 81  // len
#define STR_RES_EUC 82  // euc
#define STR_RES_INT 83  // int
#define STR_RES_EXT 84  // ext
#define STR_RES_NOT 85  // not
#define STR_RES_CLK 86  // clk
#define STR_RES_PT1 87  // pt1
#define STR_RES_PT2 88  // pt2
#define STR_RES_PT3 89  // pt3
#define STR_RES_PT4 90  // pt4
#define STR_RES_CC1 91  // cc1
#define STR_RES_CC2 92  // cc2
#define STR_RES_CC3 93  // cc3
#define STR_RES_CC4 94  // cc4
#define STR_RES_CC5 95  // cc5
#define STR_RES_CC6 96  // cc6
#define STR_RES_CC7 97  // cc7
#define STR_RES_CC8 98  // cc8
#define STR_RES_INP 99  // inp
#define STR_RES_OUT 100  // out
#define STR_RES_SPL 101  // spl
#define STR_RES_LOW 102  // low
#define STR_RES_UPP 103  // upp
#define STR_RES__AMT 104  // amt
#define STR_RES__NOT 105  // not
#define STR_RES_VEL 106  // vel
#define STR_RES__C1 107  // #c1
#define STR_RES__C2 108  // #c2
#define STR_RES_CYC 109  // cyc
#define STR_RES_POL 110  // pol
#define STR_RES_RND 111  // rnd
#define STR_RES_STK 112  // stk
#define STR_RES__VEL 113  // vel
#define STR_RES_DIR 114  // dir
#define STR_RES_UP 115  // up
#define STR_RES_DWN 116  // dwn
#define STR_RES_U_D 117  // u&d
#define STR_RES__RND 118  // rnd
#define STR_RES_PLA 119  // pla
#define STR_RES_CHD 120  // chd
#define STR_RES_OCT 121  // oct
#define STR_RES_DUR 122  // dur
#define STR_RES_LAT 123  // lat
#define STR_RES_DIV 124  // div
#define STR_RES_DEN 125  // den
#define STR_RES_CHG 126  // ch>
#define STR_RES_CHL 127  // ch<
#define STR_RES_NOG 128  // no>
#define STR_RES_NOL 129  // no<
#define STR_RES_VEG 130  // ve>
#define STR_RES_VELL 131  // ve<<
#define STR_RES_OFFI 132  // offi
#define STR_RES_GLO 133  // glo
#define STR_RES_LOC 134  // loc
#define STR_RES_4_1 135  // 4/1
#define STR_RES_3_1 136  // 3/1
#define STR_RES_2_1 137  // 2/1
#define STR_RES_3_2 138  // 3/2
#define STR_RES_1_1 139  // 1/1
#define STR_RES_3_4 140  // 3/4
#define STR_RES_2_3 141  // 2/3
#define STR_RES_1_2 142  // 1/2
#define STR_RES_3_8 143  // 3/8
#define STR_RES_1_3 144  // 1/3
#define STR_RES_1_4 145  // 1/4
#define STR_RES_1_6 146  // 1/6
#define STR_RES_1_8 147  // 1/8
#define STR_RES__12 148  // /12
#define STR_RES__16 149  // /16
#define STR_RES__24 150  // /24
#define STR_RES__32 151  // /32
#define STR_RES__48 152  // /48
#define STR_RES__96 153  // /96
#define STR_RES_REP 154  // rep
#define STR_RES_TRS 155  // trs
#define STR_RES_DPL 156  // dpl
#define STR_RES_OFF_ 157  // off_
#define STR_RES_MIR 158  // mir
#define STR_RES_ALT 159  // alt
#define STR_RES_TRK 160  // trk
#define STR_RES___RND 161  // rnd
#define STR_RES_ROO 162  // roo
#define STR_RES_SCL 163  // scl
#define STR_RES_VOI 164  // voi
#define STR_RES_HRM 165  // hrm
#define STR_RES_CHR 166  // chr
#define STR_RES_ION 167  // ion
#define STR_RES_DOR 168  // dor
#define STR_RES_PHR 169  // phr
#define STR_RES_LYD 170  // lyd
#define STR_RES_MIX 171  // mix
#define STR_RES_AEO 172  // aeo
#define STR_RES__LOC 173  // loc
#define STR_RES_BMJ 174  // bmj
#define STR_RES_BMN 175  // bmn
#define STR_RES_PMJ 176  // pmj
#define STR_RES_PMN 177  // pmn
#define STR_RES_BHR 178  // bhr
#define STR_RES_SHR 179  // shr
#define STR_RES_RUP 180  // rup
#define STR_RES_TOD 181  // tod
#define STR_RES_RAG 182  // rag
#define STR_RES_KAA 183  // kaa
#define STR_RES_MEG 184  // meg
#define STR_RES_MLK 185  // mlk
#define STR_RES_DPK 186  // dpk
#define STR_RES_FLK 187  // flk
#define STR_RES_JAP 188  // jap
#define STR_RES_GAM 189  // gam
#define STR_RES_WHL 190  // whl
#define STR_RES_KEY 191  // key
#define STR_RES__ 192  // 
#define STR_RES_STP 193  // stp
#define STR_RES_1 194  // 
#define STR_RES_2 195  // 
#define STR_RES_3 196  // 
#define STR_RES_4 197  // 
#define STR_RES_AM1 198  // am1
#define STR_RES_AM2 199  // am2
#define STR_RES_AM3 200  // am3
#define STR_RES_AM4 201  // am4
#define STR_RES_CE1 202  // ce1
#define STR_RES_CE2 203  // ce2
#define STR_RES_CE3 204  // ce3
#define STR_RES_CE4 205  // ce4
#define STR_RES_WF1 206  // wf1
#define STR_RES_WF2 207  // wf2
#define STR_RES_WF3 208  // wf3
#define STR_RES_WF4 209  // wf4
#define STR_RES_RT1 210  // rt1
#define STR_RES_RT2 211  // rt2
#define STR_RES_RT3 212  // rt3
#define STR_RES_RT4 213  // rt4
#define STR_RES_SY1 214  // sy1
#define STR_RES_SY2 215  // sy2
#define STR_RES_SY3 216  // sy3
#define STR_RES_SY4 217  // sy4
#define STR_RES_TRI 218  // tri
#define STR_RES_SQR 219  // sqr
#define STR_RES_RMP 220  // rmp
#define STR_RES_SIN 221  // sin
#define STR_RES_SI2 222  // si2
#define STR_RES_SI3 223  // si3
#define STR_RES_SI5 224  // si5
#define STR_RES_GG1 225  // gg1
#define STR_RES_GG2 226  // gg2
#define STR_RES_BT1 227  // bt1
#define STR_RES_BT2 228  // bt2
#define STR_RES_SP1 229  // sp1
#define STR_RES_SP2 230  // sp2
#define STR_RES_LP1 231  // lp1
#define STR_RES_LP2 232  // lp2
#define STR_RES_RS1 233  // rs1
#define STR_RES_RS2 234  // rs2
#define STR_RES_S_H 235  // s&h
#define STR_RES_RES 236  // res
#define STR_RES_FRE 237  // fre
#define STR_RES___NOT 238  // not
#define STR_RES__CHD 239  // chd
#define STR_RES_PRG 240  // prg
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
