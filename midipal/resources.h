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
#define STR_RES_MONITOR 13  // monitor
#define STR_RES_RANDOMIZ 14  // randomiz
#define STR_RES_CONTRLLR 15  // contrllr
#define STR_RES_SPLITTER 16  // splitter
#define STR_RES_DELAY 17  // delay
#define STR_RES_SCALE 18  // scale
#define STR_RES_SEQUENCR 19  // sequencr
#define STR_RES_CC_LFO 20  // cc lfo
#define STR_RES_TANPURA 21  // tanpura
#define STR_RES_SETTINGS 22  // settings
#define STR_RES_NOTENUKE 23  // notenuke
#define STR_RES_SYSXDUMP 24  // sysxdump
#define STR_RES__RESET_ 25  // !reset!
#define STR_RES___V1_4__ 26  // ¥ v1.4 ¥
#define STR_RES_SNDOFF 27  // sndOff
#define STR_RES_RSTCTR 28  // rstCtr
#define STR_RES_LCLCTR 29  // lclCtr
#define STR_RES_NOTOFF 30  // notOff
#define STR_RES_OMNOFF 31  // omnOff
#define STR_RES_OMNION 32  // omniOn
#define STR_RES_MONOON 33  // monoOn
#define STR_RES_POLYON 34  // polyOn
#define STR_RES_SYSX__ 35  // sysx..
#define STR_RES__SYSX_ 36  // .sysx.
#define STR_RES___SYSX 37  // ..sysx
#define STR_RES_START 38  // start
#define STR_RES_STOP 39  // stop
#define STR_RES_CONT_ 40  // cont.
#define STR_RES_RESET 41  // reset
#define STR_RES_CHN 42  // chn
#define STR_RES_CCC 43  // ccc
#define STR_RES_CLC 44  // clc
#define STR_RES_CLN 45  // cln
#define STR_RES_ALL 46  // all
#define STR_RES_REST 47  // rest
#define STR_RES_TIE 48  // tie
#define STR_RES_EXIT 49  // exit
#define STR_RES_OFF 50  // off
#define STR_RES_ON 51  // on
#define STR_RES_NO 52  // no
#define STR_RES_YES 53  // yes
#define STR_RES_XFE 54  // xFE
#define STR_RES_LET 55  // let
#define STR_RES_FLT 56  // flt
#define STR_RES_REC 57  // rec
#define STR_RES_DUB 58  // dub
#define STR_RES__TIE 59  // tie
#define STR_RES_RUN 60  // run
#define STR_RES_BPM 61  // bpm
#define STR_RES_GRV 62  // grv
#define STR_RES_AMT 63  // amt
#define STR_RES_TAP 64  // tap
#define STR_RES_SWG 65  // swg
#define STR_RES_SHF 66  // shf
#define STR_RES_PSH 67  // psh
#define STR_RES_LAG 68  // lag
#define STR_RES_HUM 69  // hum
#define STR_RES_MNK 70  // mnk
#define STR_RES_VAL 71  // val
#define STR_RES_NUM 72  // num
#define STR_RES_TYP 73  // typ
#define STR_RES_CC_ 74  // cc#
#define STR_RES_NRP 75  // nrp
#define STR_RES_MIN 76  // min
#define STR_RES_MAX 77  // max
#define STR_RES_MOD 78  // mod
#define STR_RES_PTN 79  // ptn
#define STR_RES_LEN 80  // len
#define STR_RES_EUC 81  // euc
#define STR_RES_INT 82  // int
#define STR_RES_EXT 83  // ext
#define STR_RES_CLK 84  // clk
#define STR_RES_PT1 85  // pt1
#define STR_RES_PT2 86  // pt2
#define STR_RES_PT3 87  // pt3
#define STR_RES_PT4 88  // pt4
#define STR_RES_CC1 89  // cc1
#define STR_RES_CC2 90  // cc2
#define STR_RES_CC3 91  // cc3
#define STR_RES_CC4 92  // cc4
#define STR_RES_CC5 93  // cc5
#define STR_RES_CC6 94  // cc6
#define STR_RES_CC7 95  // cc7
#define STR_RES_CC8 96  // cc8
#define STR_RES_INP 97  // inp
#define STR_RES_OUT 98  // out
#define STR_RES_SPL 99  // spl
#define STR_RES_LOW 100  // low
#define STR_RES_UPP 101  // upp
#define STR_RES__AMT 102  // amt
#define STR_RES_NOT 103  // not
#define STR_RES_VEL 104  // vel
#define STR_RES__C1 105  // #c1
#define STR_RES__C2 106  // #c2
#define STR_RES_CYC 107  // cyc
#define STR_RES_POL 108  // pol
#define STR_RES_RND 109  // rnd
#define STR_RES_STK 110  // stk
#define STR_RES__VEL 111  // vel
#define STR_RES_DIR 112  // dir
#define STR_RES_UP 113  // up
#define STR_RES_DWN 114  // dwn
#define STR_RES_U_D 115  // u&d
#define STR_RES__RND 116  // rnd
#define STR_RES_PLA 117  // pla
#define STR_RES_CHD 118  // chd
#define STR_RES_OCT 119  // oct
#define STR_RES_DUR 120  // dur
#define STR_RES_LAT 121  // lat
#define STR_RES_DIV 122  // div
#define STR_RES_DEN 123  // den
#define STR_RES_4_1 124  // 4/1
#define STR_RES_3_1 125  // 3/1
#define STR_RES_2_1 126  // 2/1
#define STR_RES_3_2 127  // 3/2
#define STR_RES_1_1 128  // 1/1
#define STR_RES_3_4 129  // 3/4
#define STR_RES_2_3 130  // 2/3
#define STR_RES_1_2 131  // 1/2
#define STR_RES_3_8 132  // 3/8
#define STR_RES_1_3 133  // 1/3
#define STR_RES_1_4 134  // 1/4
#define STR_RES_1_6 135  // 1/6
#define STR_RES_1_8 136  // 1/8
#define STR_RES__12 137  // /12
#define STR_RES__16 138  // /16
#define STR_RES__24 139  // /24
#define STR_RES__32 140  // /32
#define STR_RES__48 141  // /48
#define STR_RES__96 142  // /96
#define STR_RES_REP 143  // rep
#define STR_RES_TRS 144  // trs
#define STR_RES_DPL 145  // dpl
#define STR_RES_OFF_ 146  // off_
#define STR_RES_MIR 147  // mir
#define STR_RES_ALT 148  // alt
#define STR_RES_TRK 149  // trk
#define STR_RES___RND 150  // rnd
#define STR_RES_ROO 151  // roo
#define STR_RES_SCL 152  // scl
#define STR_RES_VOI 153  // voi
#define STR_RES_HRM 154  // hrm
#define STR_RES_CHR 155  // chr
#define STR_RES_ION 156  // ion
#define STR_RES_DOR 157  // dor
#define STR_RES_PHR 158  // phr
#define STR_RES_LYD 159  // lyd
#define STR_RES_MIX 160  // mix
#define STR_RES_AEO 161  // aeo
#define STR_RES_LOC 162  // loc
#define STR_RES_BMJ 163  // bmj
#define STR_RES_BMN 164  // bmn
#define STR_RES_PMJ 165  // pmj
#define STR_RES_PMN 166  // pmn
#define STR_RES_BHR 167  // bhr
#define STR_RES_SHR 168  // shr
#define STR_RES_RUP 169  // rup
#define STR_RES_TOD 170  // tod
#define STR_RES_RAG 171  // rag
#define STR_RES_KAA 172  // kaa
#define STR_RES_MEG 173  // meg
#define STR_RES_MLK 174  // mlk
#define STR_RES_DPK 175  // dpk
#define STR_RES_FLK 176  // flk
#define STR_RES_JAP 177  // jap
#define STR_RES_GAM 178  // gam
#define STR_RES_WHL 179  // whl
#define STR_RES_KEY 180  // key
#define STR_RES__ 181  // 
#define STR_RES_STP 182  // stp
#define STR_RES_1 183  // 
#define STR_RES_2 184  // 
#define STR_RES_3 185  // 
#define STR_RES_4 186  // 
#define STR_RES_AM1 187  // am1
#define STR_RES_AM2 188  // am2
#define STR_RES_AM3 189  // am3
#define STR_RES_AM4 190  // am4
#define STR_RES_CE1 191  // ce1
#define STR_RES_CE2 192  // ce2
#define STR_RES_CE3 193  // ce3
#define STR_RES_CE4 194  // ce4
#define STR_RES_WF1 195  // wf1
#define STR_RES_WF2 196  // wf2
#define STR_RES_WF3 197  // wf3
#define STR_RES_WF4 198  // wf4
#define STR_RES_RT1 199  // rt1
#define STR_RES_RT2 200  // rt2
#define STR_RES_RT3 201  // rt3
#define STR_RES_RT4 202  // rt4
#define STR_RES_SY1 203  // sy1
#define STR_RES_SY2 204  // sy2
#define STR_RES_SY3 205  // sy3
#define STR_RES_SY4 206  // sy4
#define STR_RES_TRI 207  // tri
#define STR_RES_SQR 208  // sqr
#define STR_RES_RMP 209  // rmp
#define STR_RES_SIN 210  // sin
#define STR_RES_SI2 211  // si2
#define STR_RES_SI3 212  // si3
#define STR_RES_SI5 213  // si5
#define STR_RES_GG1 214  // gg1
#define STR_RES_GG2 215  // gg2
#define STR_RES_BT1 216  // bt1
#define STR_RES_BT2 217  // bt2
#define STR_RES_SP1 218  // sp1
#define STR_RES_SP2 219  // sp2
#define STR_RES_LP1 220  // lp1
#define STR_RES_LP2 221  // lp2
#define STR_RES_RS1 222  // rs1
#define STR_RES_RS2 223  // rs2
#define STR_RES_S_H 224  // s&h
#define STR_RES_PA 225  // pa
#define STR_RES_MA 226  // ma
#define STR_RES_NI 227  // ni
#define STR_RES_SA 228  // sa
#define STR_RES_RES 229  // res
#define STR_RES_FRE 230  // fre
#define STR_RES__NOT 231  // not
#define STR_RES__CHD 232  // chd
#define STR_RES_PRG 233  // prg
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
