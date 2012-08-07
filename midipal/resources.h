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
#define STR_RES_NOTENUKE 22  // notenuke
#define STR_RES_SYSXDUMP 23  // sysxdump
#define STR_RES__RESET_ 24  // !reset!
#define STR_RES_SNDOFF 25  // sndOff
#define STR_RES_RSTCTR 26  // rstCtr
#define STR_RES_NOTOFF 27  // notOff
#define STR_RES_OMNOFF 28  // omnOff
#define STR_RES_OMNION 29  // omniOn
#define STR_RES_MONOON 30  // monoOn
#define STR_RES_POLYON 31  // polyOn
#define STR_RES_SYSX__ 32  // sysx..
#define STR_RES__SYSX_ 33  // .sysx.
#define STR_RES___SYSX 34  // ..sysx
#define STR_RES_START 35  // start
#define STR_RES_STOP 36  // stop
#define STR_RES_CONT_ 37  // cont.
#define STR_RES_RESET 38  // reset
#define STR_RES_CHN 39  // chn
#define STR_RES_ALL 40  // all
#define STR_RES_REST 41  // rest
#define STR_RES_TIE 42  // tie
#define STR_RES_EXIT 43  // exit
#define STR_RES_FLT 44  // flt
#define STR_RES_OFF 45  // off
#define STR_RES_ON 46  // on
#define STR_RES_NO 47  // no
#define STR_RES_YES 48  // yes
#define STR_RES_REC 49  // rec
#define STR_RES_DUB 50  // dub
#define STR_RES__TIE 51  // tie
#define STR_RES_RUN 52  // run
#define STR_RES_BPM 53  // bpm
#define STR_RES_GRV 54  // grv
#define STR_RES_AMT 55  // amt
#define STR_RES_TAP 56  // tap
#define STR_RES_SWG 57  // swg
#define STR_RES_SHF 58  // shf
#define STR_RES_PSH 59  // psh
#define STR_RES_LAG 60  // lag
#define STR_RES_HUM 61  // hum
#define STR_RES_MNK 62  // mnk
#define STR_RES_VAL 63  // val
#define STR_RES_NUM 64  // num
#define STR_RES_TYP 65  // typ
#define STR_RES_CC_ 66  // cc#
#define STR_RES_NRP 67  // nrp
#define STR_RES_MIN 68  // min
#define STR_RES_MAX 69  // max
#define STR_RES_LVL 70  // lvl
#define STR_RES_RST 71  // rst
#define STR_RES_SORRY___ 72  // sorry...
#define STR_RES_PERFECT_ 73  // perfect!
#define STR_RES_NOT_BAD_ 74  // not bad!
#define STR_RES_MOD 75  // mod
#define STR_RES_PTN 76  // ptn
#define STR_RES_EUC 77  // euc
#define STR_RES_INT 78  // int
#define STR_RES_EXT 79  // ext
#define STR_RES_CLK 80  // clk
#define STR_RES_PT1 81  // pt1
#define STR_RES_PT2 82  // pt2
#define STR_RES_PT3 83  // pt3
#define STR_RES_PT4 84  // pt4
#define STR_RES_CC1 85  // cc1
#define STR_RES_CC2 86  // cc2
#define STR_RES_CC3 87  // cc3
#define STR_RES_CC4 88  // cc4
#define STR_RES_CC5 89  // cc5
#define STR_RES_CC6 90  // cc6
#define STR_RES_CC7 91  // cc7
#define STR_RES_CC8 92  // cc8
#define STR_RES_INP 93  // inp
#define STR_RES_OUT 94  // out
#define STR_RES_SPL 95  // spl
#define STR_RES_LOW 96  // low
#define STR_RES_UPP 97  // upp
#define STR_RES__AMT 98  // amt
#define STR_RES_NOT 99  // not
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
#define STR_RES_OCT 113  // oct
#define STR_RES_DUR 114  // dur
#define STR_RES_LAT 115  // lat
#define STR_RES_DIV 116  // div
#define STR_RES_DEN 117  // den
#define STR_RES_4_1 118  // 4/1
#define STR_RES_3_1 119  // 3/1
#define STR_RES_2_1 120  // 2/1
#define STR_RES_3_2 121  // 3/2
#define STR_RES_1_1 122  // 1/1
#define STR_RES_3_4 123  // 3/4
#define STR_RES_2_3 124  // 2/3
#define STR_RES_1_2 125  // 1/2
#define STR_RES_3_8 126  // 3/8
#define STR_RES_1_3 127  // 1/3
#define STR_RES_1_4 128  // 1/4
#define STR_RES_1_6 129  // 1/6
#define STR_RES_1_8 130  // 1/8
#define STR_RES__12 131  // /12
#define STR_RES__16 132  // /16
#define STR_RES__24 133  // /24
#define STR_RES__32 134  // /32
#define STR_RES__48 135  // /48
#define STR_RES__96 136  // /96
#define STR_RES_REP 137  // rep
#define STR_RES_TRS 138  // trs
#define STR_RES_DPL 139  // dpl
#define STR_RES_OFF_ 140  // off_
#define STR_RES_MIR 141  // mir
#define STR_RES_ALT 142  // alt
#define STR_RES_TRK 143  // trk
#define STR_RES___RND 144  // rnd
#define STR_RES_ROO 145  // roo
#define STR_RES_SCL 146  // scl
#define STR_RES_VOI 147  // voi
#define STR_RES_HRM 148  // hrm
#define STR_RES_CHR 149  // chr
#define STR_RES_ION 150  // ion
#define STR_RES_DOR 151  // dor
#define STR_RES_PHR 152  // phr
#define STR_RES_LYD 153  // lyd
#define STR_RES_MIX 154  // mix
#define STR_RES_AEO 155  // aeo
#define STR_RES_LOC 156  // loc
#define STR_RES_BMJ 157  // bmj
#define STR_RES_BMN 158  // bmn
#define STR_RES_PMJ 159  // pmj
#define STR_RES_PMN 160  // pmn
#define STR_RES_BHR 161  // bhr
#define STR_RES_SHR 162  // shr
#define STR_RES_RUP 163  // rup
#define STR_RES_TOD 164  // tod
#define STR_RES_RAG 165  // rag
#define STR_RES_KAA 166  // kaa
#define STR_RES_MEG 167  // meg
#define STR_RES_MLK 168  // mlk
#define STR_RES_DPK 169  // dpk
#define STR_RES_FLK 170  // flk
#define STR_RES_JAP 171  // jap
#define STR_RES_GAM 172  // gam
#define STR_RES_WHL 173  // whl
#define STR_RES_C 174  // C
#define STR_RES_C_ 175  // C#
#define STR_RES_D 176  // D
#define STR_RES_D_ 177  // D#
#define STR_RES_E 178  // E
#define STR_RES_F 179  // F
#define STR_RES_F_ 180  // F#
#define STR_RES_G 181  // G
#define STR_RES_G_ 182  // G#
#define STR_RES_A 183  // A
#define STR_RES_A_ 184  // A#
#define STR_RES_B 185  // B
#define STR_RES__C 186  // C
#define STR_RES_DB 187  // Db
#define STR_RES__D 188  // D
#define STR_RES_EB 189  // Eb
#define STR_RES__E 190  // E
#define STR_RES__F 191  // F
#define STR_RES_GB 192  // Gb
#define STR_RES__G 193  // G
#define STR_RES_AB 194  // Ab
#define STR_RES__A 195  // A
#define STR_RES_BB 196  // Bb
#define STR_RES__B 197  // B
#define STR_RES_KEY 198  // key
#define STR_RES__ 199  // 
#define STR_RES_STP 200  // stp
#define STR_RES_1 201  // 
#define STR_RES_2 202  // 
#define STR_RES_3 203  // 
#define STR_RES_4 204  // 
#define STR_RES_AM1 205  // am1
#define STR_RES_AM2 206  // am2
#define STR_RES_AM3 207  // am3
#define STR_RES_AM4 208  // am4
#define STR_RES_CE1 209  // ce1
#define STR_RES_CE2 210  // ce2
#define STR_RES_CE3 211  // ce3
#define STR_RES_CE4 212  // ce4
#define STR_RES_WF1 213  // wf1
#define STR_RES_WF2 214  // wf2
#define STR_RES_WF3 215  // wf3
#define STR_RES_WF4 216  // wf4
#define STR_RES_RT1 217  // rt1
#define STR_RES_RT2 218  // rt2
#define STR_RES_RT3 219  // rt3
#define STR_RES_RT4 220  // rt4
#define STR_RES_SY1 221  // sy1
#define STR_RES_SY2 222  // sy2
#define STR_RES_SY3 223  // sy3
#define STR_RES_SY4 224  // sy4
#define STR_RES_TRI 225  // tri
#define STR_RES_SQR 226  // sqr
#define STR_RES_RMP 227  // rmp
#define STR_RES_SIN 228  // sin
#define STR_RES_SI2 229  // si2
#define STR_RES_SI3 230  // si3
#define STR_RES_SI5 231  // si5
#define STR_RES_GG1 232  // gg1
#define STR_RES_GG2 233  // gg2
#define STR_RES_BT1 234  // bt1
#define STR_RES_BT2 235  // bt2
#define STR_RES_SP1 236  // sp1
#define STR_RES_SP2 237  // sp2
#define STR_RES_LP1 238  // lp1
#define STR_RES_LP2 239  // lp2
#define STR_RES_RS1 240  // rs1
#define STR_RES_RS2 241  // rs2
#define STR_RES_S_H 242  // s&h
#define STR_RES_RES 243  // res
#define STR_RES_FRE 244  // fre
#define STR_RES__NOT 245  // not
#define STR_RES_CHD 246  // chd
#define STR_RES_PRG 247  // prg
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
