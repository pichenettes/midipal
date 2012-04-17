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
#define STR_RES_0XFE_FLT 2  // 0xfe flt
#define STR_RES_ARPEGGIO 3  // arpeggio
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
#define STR_RES_EAR_GAME 14  // ear game
#define STR_RES_MONITOR 15  // monitor
#define STR_RES_RANDOMIZ 16  // randomiz
#define STR_RES_CONTRLLR 17  // contrllr
#define STR_RES_SPLITTER 18  // splitter
#define STR_RES_DELAY 19  // delay
#define STR_RES_SCALE 20  // scale
#define STR_RES_SEQUENCR 21  // sequencr
#define STR_RES_CC_LFO 22  // cc lfo
#define STR_RES_NOTENUKE 23  // notenuke
#define STR_RES_SYSXDUMP 24  // sysxdump
#define STR_RES__RESET_ 25  // !reset!
#define STR_RES_SNDOFF 26  // sndOff
#define STR_RES_RSTCTR 27  // rstCtr
#define STR_RES_NOTOFF 28  // notOff
#define STR_RES_OMNOFF 29  // omnOff
#define STR_RES_OMNION 30  // omniOn
#define STR_RES_MONOON 31  // monoOn
#define STR_RES_POLYON 32  // polyOn
#define STR_RES_SYSX__ 33  // sysx..
#define STR_RES__SYSX_ 34  // .sysx.
#define STR_RES___SYSX 35  // ..sysx
#define STR_RES_START 36  // start
#define STR_RES_STOP 37  // stop
#define STR_RES_CONT_ 38  // cont.
#define STR_RES_RESET 39  // reset
#define STR_RES_CHN 40  // chn
#define STR_RES_ALL 41  // all
#define STR_RES_FLT 42  // flt
#define STR_RES_OFF 43  // off
#define STR_RES_ON 44  // on
#define STR_RES_NO 45  // no
#define STR_RES_YES 46  // yes
#define STR_RES_REC 47  // rec
#define STR_RES_DUB 48  // dub
#define STR_RES_TIE 49  // tie
#define STR_RES_RUN 50  // run
#define STR_RES_BPM 51  // bpm
#define STR_RES_GRV 52  // grv
#define STR_RES_AMT 53  // amt
#define STR_RES_TAP 54  // tap
#define STR_RES_SWG 55  // swg
#define STR_RES_SHF 56  // shf
#define STR_RES_PSH 57  // psh
#define STR_RES_LAG 58  // lag
#define STR_RES_HUM 59  // hum
#define STR_RES_MNK 60  // mnk
#define STR_RES_VAL 61  // val
#define STR_RES_NUM 62  // num
#define STR_RES_TYP 63  // typ
#define STR_RES_CC_ 64  // cc#
#define STR_RES_NRP 65  // nrp
#define STR_RES_MIN 66  // min
#define STR_RES_MAX 67  // max
#define STR_RES_LVL 68  // lvl
#define STR_RES_RST 69  // rst
#define STR_RES_SORRY___ 70  // sorry...
#define STR_RES_PERFECT_ 71  // perfect!
#define STR_RES_NOT_BAD_ 72  // not bad!
#define STR_RES_MOD 73  // mod
#define STR_RES_PTN 74  // ptn
#define STR_RES_EUC 75  // euc
#define STR_RES_INT 76  // int
#define STR_RES_EXT 77  // ext
#define STR_RES_CLK 78  // clk
#define STR_RES_PT1 79  // pt1
#define STR_RES_PT2 80  // pt2
#define STR_RES_PT3 81  // pt3
#define STR_RES_PT4 82  // pt4
#define STR_RES_CC1 83  // cc1
#define STR_RES_CC2 84  // cc2
#define STR_RES_CC3 85  // cc3
#define STR_RES_CC4 86  // cc4
#define STR_RES_CC5 87  // cc5
#define STR_RES_CC6 88  // cc6
#define STR_RES_CC7 89  // cc7
#define STR_RES_CC8 90  // cc8
#define STR_RES_INP 91  // inp
#define STR_RES_OUT 92  // out
#define STR_RES_SPL 93  // spl
#define STR_RES_LOW 94  // low
#define STR_RES_UPP 95  // upp
#define STR_RES__AMT 96  // amt
#define STR_RES_NOT 97  // not
#define STR_RES_VEL 98  // vel
#define STR_RES__C1 99  // #c1
#define STR_RES__C2 100  // #c2
#define STR_RES_CYC 101  // cyc
#define STR_RES_POL 102  // pol
#define STR_RES_RND 103  // rnd
#define STR_RES_STK 104  // stk
#define STR_RES__VEL 105  // vel
#define STR_RES_DIR 106  // dir
#define STR_RES_UP 107  // up
#define STR_RES_DWN 108  // dwn
#define STR_RES_U_D 109  // u&d
#define STR_RES__RND 110  // rnd
#define STR_RES_OCT 111  // oct
#define STR_RES_DUR 112  // dur
#define STR_RES_LAT 113  // lat
#define STR_RES_DIV 114  // div
#define STR_RES_DEN 115  // den
#define STR_RES_4_1 116  // 4/1
#define STR_RES_3_1 117  // 3/1
#define STR_RES_2_1 118  // 2/1
#define STR_RES_3_2 119  // 3/2
#define STR_RES_1_1 120  // 1/1
#define STR_RES_3_4 121  // 3/4
#define STR_RES_2_3 122  // 2/3
#define STR_RES_1_2 123  // 1/2
#define STR_RES_3_8 124  // 3/8
#define STR_RES_1_3 125  // 1/3
#define STR_RES_1_4 126  // 1/4
#define STR_RES_1_6 127  // 1/6
#define STR_RES_1_8 128  // 1/8
#define STR_RES__12 129  // /12
#define STR_RES__16 130  // /16
#define STR_RES__24 131  // /24
#define STR_RES__32 132  // /32
#define STR_RES__48 133  // /48
#define STR_RES__96 134  // /96
#define STR_RES_REP 135  // rep
#define STR_RES_TRS 136  // trs
#define STR_RES_DPL 137  // dpl
#define STR_RES_OFF_ 138  // off_
#define STR_RES_MIR 139  // mir
#define STR_RES_ALT 140  // alt
#define STR_RES_TRK 141  // trk
#define STR_RES___RND 142  // rnd
#define STR_RES_ROO 143  // roo
#define STR_RES_SCL 144  // scl
#define STR_RES_VOI 145  // voi
#define STR_RES_HRM 146  // hrm
#define STR_RES_CHR 147  // chr
#define STR_RES_ION 148  // ion
#define STR_RES_DOR 149  // dor
#define STR_RES_PHR 150  // phr
#define STR_RES_LYD 151  // lyd
#define STR_RES_MIX 152  // mix
#define STR_RES_AEO 153  // aeo
#define STR_RES_LOC 154  // loc
#define STR_RES_BMJ 155  // bmj
#define STR_RES_BMN 156  // bmn
#define STR_RES_PMJ 157  // pmj
#define STR_RES_PMN 158  // pmn
#define STR_RES_BHR 159  // bhr
#define STR_RES_SHR 160  // shr
#define STR_RES_RUP 161  // rup
#define STR_RES_TOD 162  // tod
#define STR_RES_RAG 163  // rag
#define STR_RES_KAA 164  // kaa
#define STR_RES_MEG 165  // meg
#define STR_RES_MLK 166  // mlk
#define STR_RES_DPK 167  // dpk
#define STR_RES_FLK 168  // flk
#define STR_RES_JAP 169  // jap
#define STR_RES_GAM 170  // gam
#define STR_RES_WHL 171  // whl
#define STR_RES_C 172  // C
#define STR_RES_C_ 173  // C#
#define STR_RES_D 174  // D
#define STR_RES_D_ 175  // D#
#define STR_RES_E 176  // E
#define STR_RES_F 177  // F
#define STR_RES_F_ 178  // F#
#define STR_RES_G 179  // G
#define STR_RES_G_ 180  // G#
#define STR_RES_A 181  // A
#define STR_RES_A_ 182  // A#
#define STR_RES_B 183  // B
#define STR_RES__C 184  // C
#define STR_RES_DB 185  // Db
#define STR_RES__D 186  // D
#define STR_RES_EB 187  // Eb
#define STR_RES__E 188  // E
#define STR_RES__F 189  // F
#define STR_RES_GB 190  // Gb
#define STR_RES__G 191  // G
#define STR_RES_AB 192  // Ab
#define STR_RES__A 193  // A
#define STR_RES_BB 194  // Bb
#define STR_RES__B 195  // B
#define STR_RES_KEY 196  // key
#define STR_RES__ 197  // 
#define STR_RES_STP 198  // stp
#define STR_RES_1 199  // 
#define STR_RES_2 200  // 
#define STR_RES_3 201  // 
#define STR_RES_4 202  // 
#define STR_RES_AM1 203  // am1
#define STR_RES_AM2 204  // am2
#define STR_RES_AM3 205  // am3
#define STR_RES_AM4 206  // am4
#define STR_RES_CE1 207  // ce1
#define STR_RES_CE2 208  // ce2
#define STR_RES_CE3 209  // ce3
#define STR_RES_CE4 210  // ce4
#define STR_RES_WF1 211  // wf1
#define STR_RES_WF2 212  // wf2
#define STR_RES_WF3 213  // wf3
#define STR_RES_WF4 214  // wf4
#define STR_RES_RT1 215  // rt1
#define STR_RES_RT2 216  // rt2
#define STR_RES_RT3 217  // rt3
#define STR_RES_RT4 218  // rt4
#define STR_RES_SY1 219  // sy1
#define STR_RES_SY2 220  // sy2
#define STR_RES_SY3 221  // sy3
#define STR_RES_SY4 222  // sy4
#define STR_RES_TRI 223  // tri
#define STR_RES_SQR 224  // sqr
#define STR_RES_RMP 225  // rmp
#define STR_RES_SIN 226  // sin
#define STR_RES_SI2 227  // si2
#define STR_RES_SI3 228  // si3
#define STR_RES_SI5 229  // si5
#define STR_RES_GG1 230  // gg1
#define STR_RES_GG2 231  // gg2
#define STR_RES_BT1 232  // bt1
#define STR_RES_BT2 233  // bt2
#define STR_RES_SP1 234  // sp1
#define STR_RES_SP2 235  // sp2
#define STR_RES_LP1 236  // lp1
#define STR_RES_LP2 237  // lp2
#define STR_RES_RS1 238  // rs1
#define STR_RES_RS2 239  // rs2
#define STR_RES_S_H 240  // s&h
#define STR_RES_RES 241  // res
#define STR_RES_FRE 242  // fre
#define STR_RES__NOT 243  // not
#define STR_RES_CHD 244  // chd
#define STR_RES_PRG 245  // prg
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
