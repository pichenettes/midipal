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
#define STR_RES_SETTINGS 21  // settings
#define STR_RES_NOTENUKE 22  // notenuke
#define STR_RES_SYSXDUMP 23  // sysxdump
#define STR_RES__RESET_ 24  // !reset!
#define STR_RES___V1_4__ 25  // ¥ v1.4 ¥
#define STR_RES_SNDOFF 26  // sndOff
#define STR_RES_RSTCTR 27  // rstCtr
#define STR_RES_LCLCTR 28  // lclCtr
#define STR_RES_NOTOFF 29  // notOff
#define STR_RES_OMNOFF 30  // omnOff
#define STR_RES_OMNION 31  // omniOn
#define STR_RES_MONOON 32  // monoOn
#define STR_RES_POLYON 33  // polyOn
#define STR_RES_SYSX__ 34  // sysx..
#define STR_RES__SYSX_ 35  // .sysx.
#define STR_RES___SYSX 36  // ..sysx
#define STR_RES_START 37  // start
#define STR_RES_STOP 38  // stop
#define STR_RES_CONT_ 39  // cont.
#define STR_RES_RESET 40  // reset
#define STR_RES_CHN 41  // chn
#define STR_RES_CCC 42  // ccc
#define STR_RES_CLC 43  // clc
#define STR_RES_CLN 44  // cln
#define STR_RES_ALL 45  // all
#define STR_RES_REST 46  // rest
#define STR_RES_TIE 47  // tie
#define STR_RES_EXIT 48  // exit
#define STR_RES_OFF 49  // off
#define STR_RES_ON 50  // on
#define STR_RES_NO 51  // no
#define STR_RES_YES 52  // yes
#define STR_RES_XFE 53  // xFE
#define STR_RES_LET 54  // let
#define STR_RES_FLT 55  // flt
#define STR_RES_REC 56  // rec
#define STR_RES_DUB 57  // dub
#define STR_RES__TIE 58  // tie
#define STR_RES_RUN 59  // run
#define STR_RES_BPM 60  // bpm
#define STR_RES_GRV 61  // grv
#define STR_RES_AMT 62  // amt
#define STR_RES_TAP 63  // tap
#define STR_RES_SWG 64  // swg
#define STR_RES_SHF 65  // shf
#define STR_RES_PSH 66  // psh
#define STR_RES_LAG 67  // lag
#define STR_RES_HUM 68  // hum
#define STR_RES_MNK 69  // mnk
#define STR_RES_VAL 70  // val
#define STR_RES_NUM 71  // num
#define STR_RES_TYP 72  // typ
#define STR_RES_CC_ 73  // cc#
#define STR_RES_NRP 74  // nrp
#define STR_RES_MIN 75  // min
#define STR_RES_MAX 76  // max
#define STR_RES_MOD 77  // mod
#define STR_RES_PTN 78  // ptn
#define STR_RES_LEN 79  // len
#define STR_RES_EUC 80  // euc
#define STR_RES_INT 81  // int
#define STR_RES_EXT 82  // ext
#define STR_RES_NOT 83  // not
#define STR_RES_CLK 84  // clk
#define STR_RES_PT1 85  // pt1
#define STR_RES_PT2 86  // pt2
#define STR_RES_PT3 87  // pt3
#define STR_RES_PT4 88  // pt4
#define STR_RES_CC1 89  // cc1
#define STR_RES_CC2 90  // cc2
#define STR_RES_CC3 91  // cc3
#define STR_RES_CC4 92  // cc4
#define STR_RES_INP 93  // inp
#define STR_RES_OUT 94  // out
#define STR_RES_SPL 95  // spl
#define STR_RES_LOW 96  // low
#define STR_RES_UPP 97  // upp
#define STR_RES__AMT 98  // amt
#define STR_RES__NOT 99  // not
#define STR_RES_VEL 100  // vel
#define STR_RES__C1 101  // #c1
#define STR_RES__C2 102  // #c2
#define STR_RES_CYC 103  // cyc
#define STR_RES_POL 104  // pol
#define STR_RES_RND 105  // rnd
#define STR_RES_STK 106  // stk
#define STR_RES__VEL 107  // vel
#define STR_RES_DIR 108  // dir
#define STR_RES_UP 109  // up
#define STR_RES_DWN 110  // dwn
#define STR_RES_U_D 111  // u&d
#define STR_RES__RND 112  // rnd
#define STR_RES_PLA 113  // pla
#define STR_RES_CHD 114  // chd
#define STR_RES_OCT 115  // oct
#define STR_RES_DUR 116  // dur
#define STR_RES_LAT 117  // lat
#define STR_RES_DIV 118  // div
#define STR_RES_DEN 119  // den
#define STR_RES_CHG 120  // ch>
#define STR_RES_CHL 121  // ch<
#define STR_RES_NOG 122  // no>
#define STR_RES_NOL 123  // no<
#define STR_RES_VEG 124  // ve>
#define STR_RES_VELL 125  // ve<<
#define STR_RES_OFFI 126  // offi
#define STR_RES_GLO 127  // glo
#define STR_RES_LOC 128  // loc
#define STR_RES_4_1 129  // 4/1
#define STR_RES_3_1 130  // 3/1
#define STR_RES_2_1 131  // 2/1
#define STR_RES_3_2 132  // 3/2
#define STR_RES_1_1 133  // 1/1
#define STR_RES_3_4 134  // 3/4
#define STR_RES_2_3 135  // 2/3
#define STR_RES_1_2 136  // 1/2
#define STR_RES_3_8 137  // 3/8
#define STR_RES_1_3 138  // 1/3
#define STR_RES_1_4 139  // 1/4
#define STR_RES_1_6 140  // 1/6
#define STR_RES_1_8 141  // 1/8
#define STR_RES__12 142  // /12
#define STR_RES__16 143  // /16
#define STR_RES__24 144  // /24
#define STR_RES__32 145  // /32
#define STR_RES__48 146  // /48
#define STR_RES__96 147  // /96
#define STR_RES_REP 148  // rep
#define STR_RES_TRS 149  // trs
#define STR_RES_DPL 150  // dpl
#define STR_RES_OFF_ 151  // off_
#define STR_RES_MIR 152  // mir
#define STR_RES_ALT 153  // alt
#define STR_RES_TRK 154  // trk
#define STR_RES___RND 155  // rnd
#define STR_RES_ROO 156  // roo
#define STR_RES_SCL 157  // scl
#define STR_RES_VOI 158  // voi
#define STR_RES_HRM 159  // hrm
#define STR_RES_CHR 160  // chr
#define STR_RES_ION 161  // ion
#define STR_RES_DOR 162  // dor
#define STR_RES_PHR 163  // phr
#define STR_RES_LYD 164  // lyd
#define STR_RES_MIX 165  // mix
#define STR_RES_AEO 166  // aeo
#define STR_RES__LOC 167  // loc
#define STR_RES_BMJ 168  // bmj
#define STR_RES_BMN 169  // bmn
#define STR_RES_PMJ 170  // pmj
#define STR_RES_PMN 171  // pmn
#define STR_RES_BHR 172  // bhr
#define STR_RES_SHR 173  // shr
#define STR_RES_RUP 174  // rup
#define STR_RES_TOD 175  // tod
#define STR_RES_RAG 176  // rag
#define STR_RES_KAA 177  // kaa
#define STR_RES_MEG 178  // meg
#define STR_RES_MLK 179  // mlk
#define STR_RES_DPK 180  // dpk
#define STR_RES_FLK 181  // flk
#define STR_RES_JAP 182  // jap
#define STR_RES_GAM 183  // gam
#define STR_RES_WHL 184  // whl
#define STR_RES_KEY 185  // key
#define STR_RES__ 186  // 
#define STR_RES_STP 187  // stp
#define STR_RES_1 188  // 
#define STR_RES_2 189  // 
#define STR_RES_3 190  // 
#define STR_RES_4 191  // 
#define STR_RES_AM1 192  // am1
#define STR_RES_AM2 193  // am2
#define STR_RES_AM3 194  // am3
#define STR_RES_AM4 195  // am4
#define STR_RES_CE1 196  // ce1
#define STR_RES_CE2 197  // ce2
#define STR_RES_CE3 198  // ce3
#define STR_RES_CE4 199  // ce4
#define STR_RES_WF1 200  // wf1
#define STR_RES_WF2 201  // wf2
#define STR_RES_WF3 202  // wf3
#define STR_RES_WF4 203  // wf4
#define STR_RES_RT1 204  // rt1
#define STR_RES_RT2 205  // rt2
#define STR_RES_RT3 206  // rt3
#define STR_RES_RT4 207  // rt4
#define STR_RES_SY1 208  // sy1
#define STR_RES_SY2 209  // sy2
#define STR_RES_SY3 210  // sy3
#define STR_RES_SY4 211  // sy4
#define STR_RES_TRI 212  // tri
#define STR_RES_SQR 213  // sqr
#define STR_RES_RMP 214  // rmp
#define STR_RES_SIN 215  // sin
#define STR_RES_SI2 216  // si2
#define STR_RES_SI3 217  // si3
#define STR_RES_SI5 218  // si5
#define STR_RES_GG1 219  // gg1
#define STR_RES_GG2 220  // gg2
#define STR_RES_BT1 221  // bt1
#define STR_RES_BT2 222  // bt2
#define STR_RES_SP1 223  // sp1
#define STR_RES_SP2 224  // sp2
#define STR_RES_LP1 225  // lp1
#define STR_RES_LP2 226  // lp2
#define STR_RES_RS1 227  // rs1
#define STR_RES_RS2 228  // rs2
#define STR_RES_S_H 229  // s&h
#define STR_RES_RES 230  // res
#define STR_RES_FRE 231  // fre
#define STR_RES___NOT 232  // not
#define STR_RES__CHD 233  // chd
#define STR_RES_MON 234  // mon
#define STR_RES__POL 235  // pol
#define STR_RES_CHO 236  // cho
#define STR_RES_PRG 237  // prg
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
