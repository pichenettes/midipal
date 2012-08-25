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
#define STR_RES_TANPURA 25  // tanpura
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
#define STR_RES_REST 42  // rest
#define STR_RES_TIE 43  // tie
#define STR_RES_EXIT 44  // exit
#define STR_RES_FLT 45  // flt
#define STR_RES_OFF 46  // off
#define STR_RES_ON 47  // on
#define STR_RES_NO 48  // no
#define STR_RES_YES 49  // yes
#define STR_RES_REC 50  // rec
#define STR_RES_DUB 51  // dub
#define STR_RES__TIE 52  // tie
#define STR_RES_RUN 53  // run
#define STR_RES_BPM 54  // bpm
#define STR_RES_GRV 55  // grv
#define STR_RES_AMT 56  // amt
#define STR_RES_TAP 57  // tap
#define STR_RES_SWG 58  // swg
#define STR_RES_SHF 59  // shf
#define STR_RES_PSH 60  // psh
#define STR_RES_LAG 61  // lag
#define STR_RES_HUM 62  // hum
#define STR_RES_MNK 63  // mnk
#define STR_RES_VAL 64  // val
#define STR_RES_NUM 65  // num
#define STR_RES_TYP 66  // typ
#define STR_RES_CC_ 67  // cc#
#define STR_RES_NRP 68  // nrp
#define STR_RES_MIN 69  // min
#define STR_RES_MAX 70  // max
#define STR_RES_LVL 71  // lvl
#define STR_RES_RST 72  // rst
#define STR_RES_SORRY___ 73  // sorry...
#define STR_RES_PERFECT_ 74  // perfect!
#define STR_RES_NOT_BAD_ 75  // not bad!
#define STR_RES_MOD 76  // mod
#define STR_RES_PTN 77  // ptn
#define STR_RES_EUC 78  // euc
#define STR_RES_INT 79  // int
#define STR_RES_EXT 80  // ext
#define STR_RES_CLK 81  // clk
#define STR_RES_PT1 82  // pt1
#define STR_RES_PT2 83  // pt2
#define STR_RES_PT3 84  // pt3
#define STR_RES_PT4 85  // pt4
#define STR_RES_CC1 86  // cc1
#define STR_RES_CC2 87  // cc2
#define STR_RES_CC3 88  // cc3
#define STR_RES_CC4 89  // cc4
#define STR_RES_CC5 90  // cc5
#define STR_RES_CC6 91  // cc6
#define STR_RES_CC7 92  // cc7
#define STR_RES_CC8 93  // cc8
#define STR_RES_INP 94  // inp
#define STR_RES_OUT 95  // out
#define STR_RES_SPL 96  // spl
#define STR_RES_LOW 97  // low
#define STR_RES_UPP 98  // upp
#define STR_RES__AMT 99  // amt
#define STR_RES_NOT 100  // not
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
#define STR_RES_OCT 114  // oct
#define STR_RES_DUR 115  // dur
#define STR_RES_LAT 116  // lat
#define STR_RES_DIV 117  // div
#define STR_RES_DEN 118  // den
#define STR_RES_4_1 119  // 4/1
#define STR_RES_3_1 120  // 3/1
#define STR_RES_2_1 121  // 2/1
#define STR_RES_3_2 122  // 3/2
#define STR_RES_1_1 123  // 1/1
#define STR_RES_3_4 124  // 3/4
#define STR_RES_2_3 125  // 2/3
#define STR_RES_1_2 126  // 1/2
#define STR_RES_3_8 127  // 3/8
#define STR_RES_1_3 128  // 1/3
#define STR_RES_1_4 129  // 1/4
#define STR_RES_1_6 130  // 1/6
#define STR_RES_1_8 131  // 1/8
#define STR_RES__12 132  // /12
#define STR_RES__16 133  // /16
#define STR_RES__24 134  // /24
#define STR_RES__32 135  // /32
#define STR_RES__48 136  // /48
#define STR_RES__96 137  // /96
#define STR_RES_REP 138  // rep
#define STR_RES_TRS 139  // trs
#define STR_RES_DPL 140  // dpl
#define STR_RES_OFF_ 141  // off_
#define STR_RES_MIR 142  // mir
#define STR_RES_ALT 143  // alt
#define STR_RES_TRK 144  // trk
#define STR_RES___RND 145  // rnd
#define STR_RES_ROO 146  // roo
#define STR_RES_SCL 147  // scl
#define STR_RES_VOI 148  // voi
#define STR_RES_HRM 149  // hrm
#define STR_RES_CHR 150  // chr
#define STR_RES_ION 151  // ion
#define STR_RES_DOR 152  // dor
#define STR_RES_PHR 153  // phr
#define STR_RES_LYD 154  // lyd
#define STR_RES_MIX 155  // mix
#define STR_RES_AEO 156  // aeo
#define STR_RES_LOC 157  // loc
#define STR_RES_BMJ 158  // bmj
#define STR_RES_BMN 159  // bmn
#define STR_RES_PMJ 160  // pmj
#define STR_RES_PMN 161  // pmn
#define STR_RES_BHR 162  // bhr
#define STR_RES_SHR 163  // shr
#define STR_RES_RUP 164  // rup
#define STR_RES_TOD 165  // tod
#define STR_RES_RAG 166  // rag
#define STR_RES_KAA 167  // kaa
#define STR_RES_MEG 168  // meg
#define STR_RES_MLK 169  // mlk
#define STR_RES_DPK 170  // dpk
#define STR_RES_FLK 171  // flk
#define STR_RES_JAP 172  // jap
#define STR_RES_GAM 173  // gam
#define STR_RES_WHL 174  // whl
#define STR_RES_C 175  // C
#define STR_RES_C_ 176  // C#
#define STR_RES_D 177  // D
#define STR_RES_D_ 178  // D#
#define STR_RES_E 179  // E
#define STR_RES_F 180  // F
#define STR_RES_F_ 181  // F#
#define STR_RES_G 182  // G
#define STR_RES_G_ 183  // G#
#define STR_RES_A 184  // A
#define STR_RES_A_ 185  // A#
#define STR_RES_B 186  // B
#define STR_RES__C 187  // C
#define STR_RES_DB 188  // Db
#define STR_RES__D 189  // D
#define STR_RES_EB 190  // Eb
#define STR_RES__E 191  // E
#define STR_RES__F 192  // F
#define STR_RES_GB 193  // Gb
#define STR_RES__G 194  // G
#define STR_RES_AB 195  // Ab
#define STR_RES__A 196  // A
#define STR_RES_BB 197  // Bb
#define STR_RES__B 198  // B
#define STR_RES_KEY 199  // key
#define STR_RES__ 200  // 
#define STR_RES_STP 201  // stp
#define STR_RES_1 202  // 
#define STR_RES_2 203  // 
#define STR_RES_3 204  // 
#define STR_RES_4 205  // 
#define STR_RES_AM1 206  // am1
#define STR_RES_AM2 207  // am2
#define STR_RES_AM3 208  // am3
#define STR_RES_AM4 209  // am4
#define STR_RES_CE1 210  // ce1
#define STR_RES_CE2 211  // ce2
#define STR_RES_CE3 212  // ce3
#define STR_RES_CE4 213  // ce4
#define STR_RES_WF1 214  // wf1
#define STR_RES_WF2 215  // wf2
#define STR_RES_WF3 216  // wf3
#define STR_RES_WF4 217  // wf4
#define STR_RES_RT1 218  // rt1
#define STR_RES_RT2 219  // rt2
#define STR_RES_RT3 220  // rt3
#define STR_RES_RT4 221  // rt4
#define STR_RES_SY1 222  // sy1
#define STR_RES_SY2 223  // sy2
#define STR_RES_SY3 224  // sy3
#define STR_RES_SY4 225  // sy4
#define STR_RES_TRI 226  // tri
#define STR_RES_SQR 227  // sqr
#define STR_RES_RMP 228  // rmp
#define STR_RES_SIN 229  // sin
#define STR_RES_SI2 230  // si2
#define STR_RES_SI3 231  // si3
#define STR_RES_SI5 232  // si5
#define STR_RES_GG1 233  // gg1
#define STR_RES_GG2 234  // gg2
#define STR_RES_BT1 235  // bt1
#define STR_RES_BT2 236  // bt2
#define STR_RES_SP1 237  // sp1
#define STR_RES_SP2 238  // sp2
#define STR_RES_LP1 239  // lp1
#define STR_RES_LP2 240  // lp2
#define STR_RES_RS1 241  // rs1
#define STR_RES_RS2 242  // rs2
#define STR_RES_S_H 243  // s&h
#define STR_RES_PA 244  // pa
#define STR_RES_MA 245  // ma
#define STR_RES_NI 246  // ni
#define STR_RES_SA 247  // sa
#define STR_RES_RES 248  // res
#define STR_RES_FRE 249  // fre
#define STR_RES__NOT 250  // not
#define STR_RES_CHD 251  // chd
#define STR_RES_PRG 252  // prg
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
