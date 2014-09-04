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
#define STR_RES_NOT 84  // not
#define STR_RES_CLK 85  // clk
#define STR_RES_PT1 86  // pt1
#define STR_RES_PT2 87  // pt2
#define STR_RES_PT3 88  // pt3
#define STR_RES_PT4 89  // pt4
#define STR_RES_CC1 90  // cc1
#define STR_RES_CC2 91  // cc2
#define STR_RES_CC3 92  // cc3
#define STR_RES_CC4 93  // cc4
#define STR_RES_INP 94  // inp
#define STR_RES_OUT 95  // out
#define STR_RES_SPL 96  // spl
#define STR_RES_LOW 97  // low
#define STR_RES_UPP 98  // upp
#define STR_RES__AMT 99  // amt
#define STR_RES__NOT 100  // not
#define STR_RES_VEL 101  // vel
#define STR_RES__C1 102  // #c1
#define STR_RES__C2 103  // #c2
#define STR_RES_CYC 104  // cyc
#define STR_RES_POL 105  // pol
#define STR_RES_RND 106  // rnd
#define STR_RES_STK 107  // stk
#define STR_RES__VEL 108  // vel
#define STR_RES_DIR 109  // dir
#define STR_RES_UP 110  // up
#define STR_RES_DWN 111  // dwn
#define STR_RES_U_D 112  // u&d
#define STR_RES__RND 113  // rnd
#define STR_RES_PLA 114  // pla
#define STR_RES_CHD 115  // chd
#define STR_RES_OCT 116  // oct
#define STR_RES_DUR 117  // dur
#define STR_RES_LAT 118  // lat
#define STR_RES_DIV 119  // div
#define STR_RES_DEN 120  // den
#define STR_RES_CHG 121  // ch>
#define STR_RES_CHL 122  // ch<
#define STR_RES_NOG 123  // no>
#define STR_RES_NOL 124  // no<
#define STR_RES_VEG 125  // ve>
#define STR_RES_VELL 126  // ve<<
#define STR_RES_OFFI 127  // offi
#define STR_RES_GLO 128  // glo
#define STR_RES_LOC 129  // loc
#define STR_RES_4_1 130  // 4/1
#define STR_RES_3_1 131  // 3/1
#define STR_RES_2_1 132  // 2/1
#define STR_RES_3_2 133  // 3/2
#define STR_RES_1_1 134  // 1/1
#define STR_RES_3_4 135  // 3/4
#define STR_RES_2_3 136  // 2/3
#define STR_RES_1_2 137  // 1/2
#define STR_RES_3_8 138  // 3/8
#define STR_RES_1_3 139  // 1/3
#define STR_RES_1_4 140  // 1/4
#define STR_RES_1_6 141  // 1/6
#define STR_RES_1_8 142  // 1/8
#define STR_RES__12 143  // /12
#define STR_RES__16 144  // /16
#define STR_RES__24 145  // /24
#define STR_RES__32 146  // /32
#define STR_RES__48 147  // /48
#define STR_RES__96 148  // /96
#define STR_RES_REP 149  // rep
#define STR_RES_TRS 150  // trs
#define STR_RES_DPL 151  // dpl
#define STR_RES_OFF_ 152  // off_
#define STR_RES_MIR 153  // mir
#define STR_RES_ALT 154  // alt
#define STR_RES_TRK 155  // trk
#define STR_RES___RND 156  // rnd
#define STR_RES_ROO 157  // roo
#define STR_RES_SCL 158  // scl
#define STR_RES_VOI 159  // voi
#define STR_RES_HRM 160  // hrm
#define STR_RES_CHR 161  // chr
#define STR_RES_ION 162  // ion
#define STR_RES_DOR 163  // dor
#define STR_RES_PHR 164  // phr
#define STR_RES_LYD 165  // lyd
#define STR_RES_MIX 166  // mix
#define STR_RES_AEO 167  // aeo
#define STR_RES__LOC 168  // loc
#define STR_RES_BMJ 169  // bmj
#define STR_RES_BMN 170  // bmn
#define STR_RES_PMJ 171  // pmj
#define STR_RES_PMN 172  // pmn
#define STR_RES_BHR 173  // bhr
#define STR_RES_SHR 174  // shr
#define STR_RES_RUP 175  // rup
#define STR_RES_TOD 176  // tod
#define STR_RES_RAG 177  // rag
#define STR_RES_KAA 178  // kaa
#define STR_RES_MEG 179  // meg
#define STR_RES_MLK 180  // mlk
#define STR_RES_DPK 181  // dpk
#define STR_RES_FLK 182  // flk
#define STR_RES_JAP 183  // jap
#define STR_RES_GAM 184  // gam
#define STR_RES_WHL 185  // whl
#define STR_RES_KEY 186  // key
#define STR_RES__ 187  // 
#define STR_RES_STP 188  // stp
#define STR_RES_1 189  // 
#define STR_RES_2 190  // 
#define STR_RES_3 191  // 
#define STR_RES_4 192  // 
#define STR_RES_AM1 193  // am1
#define STR_RES_AM2 194  // am2
#define STR_RES_AM3 195  // am3
#define STR_RES_AM4 196  // am4
#define STR_RES_CE1 197  // ce1
#define STR_RES_CE2 198  // ce2
#define STR_RES_CE3 199  // ce3
#define STR_RES_CE4 200  // ce4
#define STR_RES_WF1 201  // wf1
#define STR_RES_WF2 202  // wf2
#define STR_RES_WF3 203  // wf3
#define STR_RES_WF4 204  // wf4
#define STR_RES_RT1 205  // rt1
#define STR_RES_RT2 206  // rt2
#define STR_RES_RT3 207  // rt3
#define STR_RES_RT4 208  // rt4
#define STR_RES_SY1 209  // sy1
#define STR_RES_SY2 210  // sy2
#define STR_RES_SY3 211  // sy3
#define STR_RES_SY4 212  // sy4
#define STR_RES_TRI 213  // tri
#define STR_RES_SQR 214  // sqr
#define STR_RES_RMP 215  // rmp
#define STR_RES_SIN 216  // sin
#define STR_RES_SI2 217  // si2
#define STR_RES_SI3 218  // si3
#define STR_RES_SI5 219  // si5
#define STR_RES_GG1 220  // gg1
#define STR_RES_GG2 221  // gg2
#define STR_RES_BT1 222  // bt1
#define STR_RES_BT2 223  // bt2
#define STR_RES_SP1 224  // sp1
#define STR_RES_SP2 225  // sp2
#define STR_RES_LP1 226  // lp1
#define STR_RES_LP2 227  // lp2
#define STR_RES_RS1 228  // rs1
#define STR_RES_RS2 229  // rs2
#define STR_RES_S_H 230  // s&h
#define STR_RES_RES 231  // res
#define STR_RES_FRE 232  // fre
#define STR_RES___NOT 233  // not
#define STR_RES__CHD 234  // chd
#define STR_RES_MON 235  // mon
#define STR_RES__POL 236  // pol
#define STR_RES_CHO 237  // cho
#define STR_RES_PA 238  // pa
#define STR_RES_MA 239  // ma
#define STR_RES_NI 240  // ni
#define STR_RES_SA 241  // sa
#define STR_RES_PRG 242  // prg
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
