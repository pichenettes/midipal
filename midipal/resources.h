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
#define STR_RES_NOTENUKE 23  // notenuke
#define STR_RES_SYSXDUMP 24  // sysxdump
#define STR_RES__RESET_ 25  // !reset!
#define STR_RES___V1_2__ 26  // ¥ v1.2 ¥
#define STR_RES_SNDOFF 27  // sndOff
#define STR_RES_RSTCTR 28  // rstCtr
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
#define STR_RES_ALL 42  // all
#define STR_RES_REST 43  // rest
#define STR_RES_TIE 44  // tie
#define STR_RES_EXIT 45  // exit
#define STR_RES_FLT 46  // flt
#define STR_RES_OFF 47  // off
#define STR_RES_ON 48  // on
#define STR_RES_NO 49  // no
#define STR_RES_YES 50  // yes
#define STR_RES_REC 51  // rec
#define STR_RES_DUB 52  // dub
#define STR_RES__TIE 53  // tie
#define STR_RES_RUN 54  // run
#define STR_RES_BPM 55  // bpm
#define STR_RES_GRV 56  // grv
#define STR_RES_AMT 57  // amt
#define STR_RES_TAP 58  // tap
#define STR_RES_SWG 59  // swg
#define STR_RES_SHF 60  // shf
#define STR_RES_PSH 61  // psh
#define STR_RES_LAG 62  // lag
#define STR_RES_HUM 63  // hum
#define STR_RES_MNK 64  // mnk
#define STR_RES_VAL 65  // val
#define STR_RES_NUM 66  // num
#define STR_RES_TYP 67  // typ
#define STR_RES_CC_ 68  // cc#
#define STR_RES_NRP 69  // nrp
#define STR_RES_MIN 70  // min
#define STR_RES_MAX 71  // max
#define STR_RES_LVL 72  // lvl
#define STR_RES_RST 73  // rst
#define STR_RES_SORRY___ 74  // sorry...
#define STR_RES_PERFECT_ 75  // perfect!
#define STR_RES_NOT_BAD_ 76  // not bad!
#define STR_RES_MOD 77  // mod
#define STR_RES_PTN 78  // ptn
#define STR_RES_EUC 79  // euc
#define STR_RES_INT 80  // int
#define STR_RES_EXT 81  // ext
#define STR_RES_CLK 82  // clk
#define STR_RES_PT1 83  // pt1
#define STR_RES_PT2 84  // pt2
#define STR_RES_PT3 85  // pt3
#define STR_RES_PT4 86  // pt4
#define STR_RES_CC1 87  // cc1
#define STR_RES_CC2 88  // cc2
#define STR_RES_CC3 89  // cc3
#define STR_RES_CC4 90  // cc4
#define STR_RES_CC5 91  // cc5
#define STR_RES_CC6 92  // cc6
#define STR_RES_CC7 93  // cc7
#define STR_RES_CC8 94  // cc8
#define STR_RES_INP 95  // inp
#define STR_RES_OUT 96  // out
#define STR_RES_SPL 97  // spl
#define STR_RES_LOW 98  // low
#define STR_RES_UPP 99  // upp
#define STR_RES__AMT 100  // amt
#define STR_RES_NOT 101  // not
#define STR_RES_VEL 102  // vel
#define STR_RES__C1 103  // #c1
#define STR_RES__C2 104  // #c2
#define STR_RES_CYC 105  // cyc
#define STR_RES_POL 106  // pol
#define STR_RES_RND 107  // rnd
#define STR_RES_STK 108  // stk
#define STR_RES__VEL 109  // vel
#define STR_RES_DIR 110  // dir
#define STR_RES_UP 111  // up
#define STR_RES_DWN 112  // dwn
#define STR_RES_U_D 113  // u&d
#define STR_RES__RND 114  // rnd
#define STR_RES_OCT 115  // oct
#define STR_RES_DUR 116  // dur
#define STR_RES_LAT 117  // lat
#define STR_RES_DIV 118  // div
#define STR_RES_DEN 119  // den
#define STR_RES_4_1 120  // 4/1
#define STR_RES_3_1 121  // 3/1
#define STR_RES_2_1 122  // 2/1
#define STR_RES_3_2 123  // 3/2
#define STR_RES_1_1 124  // 1/1
#define STR_RES_3_4 125  // 3/4
#define STR_RES_2_3 126  // 2/3
#define STR_RES_1_2 127  // 1/2
#define STR_RES_3_8 128  // 3/8
#define STR_RES_1_3 129  // 1/3
#define STR_RES_1_4 130  // 1/4
#define STR_RES_1_6 131  // 1/6
#define STR_RES_1_8 132  // 1/8
#define STR_RES__12 133  // /12
#define STR_RES__16 134  // /16
#define STR_RES__24 135  // /24
#define STR_RES__32 136  // /32
#define STR_RES__48 137  // /48
#define STR_RES__96 138  // /96
#define STR_RES_REP 139  // rep
#define STR_RES_TRS 140  // trs
#define STR_RES_DPL 141  // dpl
#define STR_RES_OFF_ 142  // off_
#define STR_RES_MIR 143  // mir
#define STR_RES_ALT 144  // alt
#define STR_RES_TRK 145  // trk
#define STR_RES___RND 146  // rnd
#define STR_RES_ROO 147  // roo
#define STR_RES_SCL 148  // scl
#define STR_RES_VOI 149  // voi
#define STR_RES_HRM 150  // hrm
#define STR_RES_CHR 151  // chr
#define STR_RES_ION 152  // ion
#define STR_RES_DOR 153  // dor
#define STR_RES_PHR 154  // phr
#define STR_RES_LYD 155  // lyd
#define STR_RES_MIX 156  // mix
#define STR_RES_AEO 157  // aeo
#define STR_RES_LOC 158  // loc
#define STR_RES_BMJ 159  // bmj
#define STR_RES_BMN 160  // bmn
#define STR_RES_PMJ 161  // pmj
#define STR_RES_PMN 162  // pmn
#define STR_RES_BHR 163  // bhr
#define STR_RES_SHR 164  // shr
#define STR_RES_RUP 165  // rup
#define STR_RES_TOD 166  // tod
#define STR_RES_RAG 167  // rag
#define STR_RES_KAA 168  // kaa
#define STR_RES_MEG 169  // meg
#define STR_RES_MLK 170  // mlk
#define STR_RES_DPK 171  // dpk
#define STR_RES_FLK 172  // flk
#define STR_RES_JAP 173  // jap
#define STR_RES_GAM 174  // gam
#define STR_RES_WHL 175  // whl
#define STR_RES_C 176  // C
#define STR_RES_C_ 177  // C#
#define STR_RES_D 178  // D
#define STR_RES_D_ 179  // D#
#define STR_RES_E 180  // E
#define STR_RES_F 181  // F
#define STR_RES_F_ 182  // F#
#define STR_RES_G 183  // G
#define STR_RES_G_ 184  // G#
#define STR_RES_A 185  // A
#define STR_RES_A_ 186  // A#
#define STR_RES_B 187  // B
#define STR_RES__C 188  // C
#define STR_RES_DB 189  // Db
#define STR_RES__D 190  // D
#define STR_RES_EB 191  // Eb
#define STR_RES__E 192  // E
#define STR_RES__F 193  // F
#define STR_RES_GB 194  // Gb
#define STR_RES__G 195  // G
#define STR_RES_AB 196  // Ab
#define STR_RES__A 197  // A
#define STR_RES_BB 198  // Bb
#define STR_RES__B 199  // B
#define STR_RES_KEY 200  // key
#define STR_RES__ 201  // 
#define STR_RES_STP 202  // stp
#define STR_RES_1 203  // 
#define STR_RES_2 204  // 
#define STR_RES_3 205  // 
#define STR_RES_4 206  // 
#define STR_RES_AM1 207  // am1
#define STR_RES_AM2 208  // am2
#define STR_RES_AM3 209  // am3
#define STR_RES_AM4 210  // am4
#define STR_RES_CE1 211  // ce1
#define STR_RES_CE2 212  // ce2
#define STR_RES_CE3 213  // ce3
#define STR_RES_CE4 214  // ce4
#define STR_RES_WF1 215  // wf1
#define STR_RES_WF2 216  // wf2
#define STR_RES_WF3 217  // wf3
#define STR_RES_WF4 218  // wf4
#define STR_RES_RT1 219  // rt1
#define STR_RES_RT2 220  // rt2
#define STR_RES_RT3 221  // rt3
#define STR_RES_RT4 222  // rt4
#define STR_RES_SY1 223  // sy1
#define STR_RES_SY2 224  // sy2
#define STR_RES_SY3 225  // sy3
#define STR_RES_SY4 226  // sy4
#define STR_RES_TRI 227  // tri
#define STR_RES_SQR 228  // sqr
#define STR_RES_RMP 229  // rmp
#define STR_RES_SIN 230  // sin
#define STR_RES_SI2 231  // si2
#define STR_RES_SI3 232  // si3
#define STR_RES_SI5 233  // si5
#define STR_RES_GG1 234  // gg1
#define STR_RES_GG2 235  // gg2
#define STR_RES_BT1 236  // bt1
#define STR_RES_BT2 237  // bt2
#define STR_RES_SP1 238  // sp1
#define STR_RES_SP2 239  // sp2
#define STR_RES_LP1 240  // lp1
#define STR_RES_LP2 241  // lp2
#define STR_RES_RS1 242  // rs1
#define STR_RES_RS2 243  // rs2
#define STR_RES_S_H 244  // s&h
#define STR_RES_PA 245  // pa
#define STR_RES_MA 246  // ma
#define STR_RES_NI 247  // ni
#define STR_RES_SA 248  // sa
#define STR_RES_RES 249  // res
#define STR_RES_FRE 250  // fre
#define STR_RES__NOT 251  // not
#define STR_RES_CHD 252  // chd
#define STR_RES_PRG 253  // prg
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
