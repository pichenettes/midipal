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

typedef uint16_t ResourceId;

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
#define STR_RES___V1_2__ 27  // ¥ v1.2 ¥
#define STR_RES_SNDOFF 28  // sndOff
#define STR_RES_RSTCTR 29  // rstCtr
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
#define STR_RES_ALL 43  // all
#define STR_RES_REST 44  // rest
#define STR_RES_TIE 45  // tie
#define STR_RES_EXIT 46  // exit
#define STR_RES_OFF 47  // off
#define STR_RES_ON 48  // on
#define STR_RES_NO 49  // no
#define STR_RES_YES 50  // yes
#define STR_RES_XFE 51  // xFE
#define STR_RES_LET 52  // let
#define STR_RES_FLT 53  // flt
#define STR_RES_HLD 54  // hld
#define STR_RES__5S 55  // .5s
#define STR_RES__1S 56  // 1s
#define STR_RES__2S 57  // 2s
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
#define STR_RES_LVL 79  // lvl
#define STR_RES_RST 80  // rst
#define STR_RES_SORRY___ 81  // sorry...
#define STR_RES_PERFECT_ 82  // perfect!
#define STR_RES_NOT_BAD_ 83  // not bad!
#define STR_RES_MOD 84  // mod
#define STR_RES_PTN 85  // ptn
#define STR_RES_EUC 86  // euc
#define STR_RES_INT 87  // int
#define STR_RES_EXT 88  // ext
#define STR_RES_CLK 89  // clk
#define STR_RES_PT1 90  // pt1
#define STR_RES_PT2 91  // pt2
#define STR_RES_PT3 92  // pt3
#define STR_RES_PT4 93  // pt4
#define STR_RES_CC1 94  // cc1
#define STR_RES_CC2 95  // cc2
#define STR_RES_CC3 96  // cc3
#define STR_RES_CC4 97  // cc4
#define STR_RES_CC5 98  // cc5
#define STR_RES_CC6 99  // cc6
#define STR_RES_CC7 100  // cc7
#define STR_RES_CC8 101  // cc8
#define STR_RES_INP 102  // inp
#define STR_RES_OUT 103  // out
#define STR_RES_SPL 104  // spl
#define STR_RES_LOW 105  // low
#define STR_RES_UPP 106  // upp
#define STR_RES__AMT 107  // amt
#define STR_RES_NOT 108  // not
#define STR_RES_VEL 109  // vel
#define STR_RES__C1 110  // #c1
#define STR_RES__C2 111  // #c2
#define STR_RES_CYC 112  // cyc
#define STR_RES_POL 113  // pol
#define STR_RES_RND 114  // rnd
#define STR_RES_STK 115  // stk
#define STR_RES__VEL 116  // vel
#define STR_RES_DIR 117  // dir
#define STR_RES_UP 118  // up
#define STR_RES_DWN 119  // dwn
#define STR_RES_U_D 120  // u&d
#define STR_RES__RND 121  // rnd
#define STR_RES_OCT 122  // oct
#define STR_RES_DUR 123  // dur
#define STR_RES_LAT 124  // lat
#define STR_RES_DIV 125  // div
#define STR_RES_DEN 126  // den
#define STR_RES_4_1 127  // 4/1
#define STR_RES_3_1 128  // 3/1
#define STR_RES_2_1 129  // 2/1
#define STR_RES_3_2 130  // 3/2
#define STR_RES_1_1 131  // 1/1
#define STR_RES_3_4 132  // 3/4
#define STR_RES_2_3 133  // 2/3
#define STR_RES_1_2 134  // 1/2
#define STR_RES_3_8 135  // 3/8
#define STR_RES_1_3 136  // 1/3
#define STR_RES_1_4 137  // 1/4
#define STR_RES_1_6 138  // 1/6
#define STR_RES_1_8 139  // 1/8
#define STR_RES__12 140  // /12
#define STR_RES__16 141  // /16
#define STR_RES__24 142  // /24
#define STR_RES__32 143  // /32
#define STR_RES__48 144  // /48
#define STR_RES__96 145  // /96
#define STR_RES_REP 146  // rep
#define STR_RES_TRS 147  // trs
#define STR_RES_DPL 148  // dpl
#define STR_RES_OFF_ 149  // off_
#define STR_RES_MIR 150  // mir
#define STR_RES_ALT 151  // alt
#define STR_RES_TRK 152  // trk
#define STR_RES___RND 153  // rnd
#define STR_RES_ROO 154  // roo
#define STR_RES_SCL 155  // scl
#define STR_RES_VOI 156  // voi
#define STR_RES_HRM 157  // hrm
#define STR_RES_CHR 158  // chr
#define STR_RES_ION 159  // ion
#define STR_RES_DOR 160  // dor
#define STR_RES_PHR 161  // phr
#define STR_RES_LYD 162  // lyd
#define STR_RES_MIX 163  // mix
#define STR_RES_AEO 164  // aeo
#define STR_RES_LOC 165  // loc
#define STR_RES_BMJ 166  // bmj
#define STR_RES_BMN 167  // bmn
#define STR_RES_PMJ 168  // pmj
#define STR_RES_PMN 169  // pmn
#define STR_RES_BHR 170  // bhr
#define STR_RES_SHR 171  // shr
#define STR_RES_RUP 172  // rup
#define STR_RES_TOD 173  // tod
#define STR_RES_RAG 174  // rag
#define STR_RES_KAA 175  // kaa
#define STR_RES_MEG 176  // meg
#define STR_RES_MLK 177  // mlk
#define STR_RES_DPK 178  // dpk
#define STR_RES_FLK 179  // flk
#define STR_RES_JAP 180  // jap
#define STR_RES_GAM 181  // gam
#define STR_RES_WHL 182  // whl
#define STR_RES_C 183  // C
#define STR_RES_C_ 184  // C#
#define STR_RES_D 185  // D
#define STR_RES_D_ 186  // D#
#define STR_RES_E 187  // E
#define STR_RES_F 188  // F
#define STR_RES_F_ 189  // F#
#define STR_RES_G 190  // G
#define STR_RES_G_ 191  // G#
#define STR_RES_A 192  // A
#define STR_RES_A_ 193  // A#
#define STR_RES_B 194  // B
#define STR_RES__C 195  // C
#define STR_RES_DB 196  // Db
#define STR_RES__D 197  // D
#define STR_RES_EB 198  // Eb
#define STR_RES__E 199  // E
#define STR_RES__F 200  // F
#define STR_RES_GB 201  // Gb
#define STR_RES__G 202  // G
#define STR_RES_AB 203  // Ab
#define STR_RES__A 204  // A
#define STR_RES_BB 205  // Bb
#define STR_RES__B 206  // B
#define STR_RES_KEY 207  // key
#define STR_RES__ 208  // 
#define STR_RES_STP 209  // stp
#define STR_RES_1 210  // 
#define STR_RES_2 211  // 
#define STR_RES_3 212  // 
#define STR_RES_4 213  // 
#define STR_RES_AM1 214  // am1
#define STR_RES_AM2 215  // am2
#define STR_RES_AM3 216  // am3
#define STR_RES_AM4 217  // am4
#define STR_RES_CE1 218  // ce1
#define STR_RES_CE2 219  // ce2
#define STR_RES_CE3 220  // ce3
#define STR_RES_CE4 221  // ce4
#define STR_RES_WF1 222  // wf1
#define STR_RES_WF2 223  // wf2
#define STR_RES_WF3 224  // wf3
#define STR_RES_WF4 225  // wf4
#define STR_RES_RT1 226  // rt1
#define STR_RES_RT2 227  // rt2
#define STR_RES_RT3 228  // rt3
#define STR_RES_RT4 229  // rt4
#define STR_RES_SY1 230  // sy1
#define STR_RES_SY2 231  // sy2
#define STR_RES_SY3 232  // sy3
#define STR_RES_SY4 233  // sy4
#define STR_RES_TRI 234  // tri
#define STR_RES_SQR 235  // sqr
#define STR_RES_RMP 236  // rmp
#define STR_RES_SIN 237  // sin
#define STR_RES_SI2 238  // si2
#define STR_RES_SI3 239  // si3
#define STR_RES_SI5 240  // si5
#define STR_RES_GG1 241  // gg1
#define STR_RES_GG2 242  // gg2
#define STR_RES_BT1 243  // bt1
#define STR_RES_BT2 244  // bt2
#define STR_RES_SP1 245  // sp1
#define STR_RES_SP2 246  // sp2
#define STR_RES_LP1 247  // lp1
#define STR_RES_LP2 248  // lp2
#define STR_RES_RS1 249  // rs1
#define STR_RES_RS2 250  // rs2
#define STR_RES_S_H 251  // s&h
#define STR_RES_PA 252  // pa
#define STR_RES_MA 253  // ma
#define STR_RES_NI 254  // ni
#define STR_RES_SA 255  // sa
#define STR_RES_RES 256  // res
#define STR_RES_FRE 257  // fre
#define STR_RES__NOT 258  // not
#define STR_RES_CHD 259  // chd
#define STR_RES_PRG 260  // prg
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
