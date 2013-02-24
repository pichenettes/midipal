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
#define STR_RES_KBD 82  // kbd
#define STR_RES_CLK 83  // clk
#define STR_RES_PT1 84  // pt1
#define STR_RES_PT2 85  // pt2
#define STR_RES_PT3 86  // pt3
#define STR_RES_PT4 87  // pt4
#define STR_RES_CC1 88  // cc1
#define STR_RES_CC2 89  // cc2
#define STR_RES_CC3 90  // cc3
#define STR_RES_CC4 91  // cc4
#define STR_RES_CC5 92  // cc5
#define STR_RES_CC6 93  // cc6
#define STR_RES_CC7 94  // cc7
#define STR_RES_CC8 95  // cc8
#define STR_RES_INP 96  // inp
#define STR_RES_OUT 97  // out
#define STR_RES_SPL 98  // spl
#define STR_RES_LOW 99  // low
#define STR_RES_UPP 100  // upp
#define STR_RES__AMT 101  // amt
#define STR_RES_NOT 102  // not
#define STR_RES_VEL 103  // vel
#define STR_RES__C1 104  // #c1
#define STR_RES__C2 105  // #c2
#define STR_RES_CYC 106  // cyc
#define STR_RES_POL 107  // pol
#define STR_RES_RND 108  // rnd
#define STR_RES_STK 109  // stk
#define STR_RES__VEL 110  // vel
#define STR_RES_DIR 111  // dir
#define STR_RES_UP 112  // up
#define STR_RES_DWN 113  // dwn
#define STR_RES_U_D 114  // u&d
#define STR_RES__RND 115  // rnd
#define STR_RES_OCT 116  // oct
#define STR_RES_DUR 117  // dur
#define STR_RES_LAT 118  // lat
#define STR_RES_DIV 119  // div
#define STR_RES_DEN 120  // den
#define STR_RES_4_1 121  // 4/1
#define STR_RES_3_1 122  // 3/1
#define STR_RES_2_1 123  // 2/1
#define STR_RES_3_2 124  // 3/2
#define STR_RES_1_1 125  // 1/1
#define STR_RES_3_4 126  // 3/4
#define STR_RES_2_3 127  // 2/3
#define STR_RES_1_2 128  // 1/2
#define STR_RES_3_8 129  // 3/8
#define STR_RES_1_3 130  // 1/3
#define STR_RES_1_4 131  // 1/4
#define STR_RES_1_6 132  // 1/6
#define STR_RES_1_8 133  // 1/8
#define STR_RES__12 134  // /12
#define STR_RES__16 135  // /16
#define STR_RES__24 136  // /24
#define STR_RES__32 137  // /32
#define STR_RES__48 138  // /48
#define STR_RES__96 139  // /96
#define STR_RES_REP 140  // rep
#define STR_RES_TRS 141  // trs
#define STR_RES_DPL 142  // dpl
#define STR_RES_OFF_ 143  // off_
#define STR_RES_MIR 144  // mir
#define STR_RES_ALT 145  // alt
#define STR_RES_TRK 146  // trk
#define STR_RES___RND 147  // rnd
#define STR_RES_ROO 148  // roo
#define STR_RES_SCL 149  // scl
#define STR_RES_VOI 150  // voi
#define STR_RES_HRM 151  // hrm
#define STR_RES_CHR 152  // chr
#define STR_RES_ION 153  // ion
#define STR_RES_DOR 154  // dor
#define STR_RES_PHR 155  // phr
#define STR_RES_LYD 156  // lyd
#define STR_RES_MIX 157  // mix
#define STR_RES_AEO 158  // aeo
#define STR_RES_LOC 159  // loc
#define STR_RES_BMJ 160  // bmj
#define STR_RES_BMN 161  // bmn
#define STR_RES_PMJ 162  // pmj
#define STR_RES_PMN 163  // pmn
#define STR_RES_BHR 164  // bhr
#define STR_RES_SHR 165  // shr
#define STR_RES_RUP 166  // rup
#define STR_RES_TOD 167  // tod
#define STR_RES_RAG 168  // rag
#define STR_RES_KAA 169  // kaa
#define STR_RES_MEG 170  // meg
#define STR_RES_MLK 171  // mlk
#define STR_RES_DPK 172  // dpk
#define STR_RES_FLK 173  // flk
#define STR_RES_JAP 174  // jap
#define STR_RES_GAM 175  // gam
#define STR_RES_WHL 176  // whl
#define STR_RES_C 177  // C
#define STR_RES_C_ 178  // C#
#define STR_RES_D 179  // D
#define STR_RES_D_ 180  // D#
#define STR_RES_E 181  // E
#define STR_RES_F 182  // F
#define STR_RES_F_ 183  // F#
#define STR_RES_G 184  // G
#define STR_RES_G_ 185  // G#
#define STR_RES_A 186  // A
#define STR_RES_A_ 187  // A#
#define STR_RES_B 188  // B
#define STR_RES__C 189  // C
#define STR_RES_DB 190  // Db
#define STR_RES__D 191  // D
#define STR_RES_EB 192  // Eb
#define STR_RES__E 193  // E
#define STR_RES__F 194  // F
#define STR_RES_GB 195  // Gb
#define STR_RES__G 196  // G
#define STR_RES_AB 197  // Ab
#define STR_RES__A 198  // A
#define STR_RES_BB 199  // Bb
#define STR_RES__B 200  // B
#define STR_RES_KEY 201  // key
#define STR_RES__ 202  // 
#define STR_RES_STP 203  // stp
#define STR_RES_1 204  // 
#define STR_RES_2 205  // 
#define STR_RES_3 206  // 
#define STR_RES_4 207  // 
#define STR_RES_AM1 208  // am1
#define STR_RES_AM2 209  // am2
#define STR_RES_AM3 210  // am3
#define STR_RES_AM4 211  // am4
#define STR_RES_CE1 212  // ce1
#define STR_RES_CE2 213  // ce2
#define STR_RES_CE3 214  // ce3
#define STR_RES_CE4 215  // ce4
#define STR_RES_WF1 216  // wf1
#define STR_RES_WF2 217  // wf2
#define STR_RES_WF3 218  // wf3
#define STR_RES_WF4 219  // wf4
#define STR_RES_RT1 220  // rt1
#define STR_RES_RT2 221  // rt2
#define STR_RES_RT3 222  // rt3
#define STR_RES_RT4 223  // rt4
#define STR_RES_SY1 224  // sy1
#define STR_RES_SY2 225  // sy2
#define STR_RES_SY3 226  // sy3
#define STR_RES_SY4 227  // sy4
#define STR_RES_TRI 228  // tri
#define STR_RES_SQR 229  // sqr
#define STR_RES_RMP 230  // rmp
#define STR_RES_SIN 231  // sin
#define STR_RES_SI2 232  // si2
#define STR_RES_SI3 233  // si3
#define STR_RES_SI5 234  // si5
#define STR_RES_GG1 235  // gg1
#define STR_RES_GG2 236  // gg2
#define STR_RES_BT1 237  // bt1
#define STR_RES_BT2 238  // bt2
#define STR_RES_SP1 239  // sp1
#define STR_RES_SP2 240  // sp2
#define STR_RES_LP1 241  // lp1
#define STR_RES_LP2 242  // lp2
#define STR_RES_RS1 243  // rs1
#define STR_RES_RS2 244  // rs2
#define STR_RES_S_H 245  // s&h
#define STR_RES_PA 246  // pa
#define STR_RES_MA 247  // ma
#define STR_RES_NI 248  // ni
#define STR_RES_SA 249  // sa
#define STR_RES_RES 250  // res
#define STR_RES_FRE 251  // fre
#define STR_RES__NOT 252  // not
#define STR_RES_CHD 253  // chd
#define STR_RES_PRG 254  // prg
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
