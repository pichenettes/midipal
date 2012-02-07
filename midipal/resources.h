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
#define STR_RES_0XFE_FLT 0  // 0xfe flt
#define STR_RES_ARPEGGIO 1  // arpeggio
#define STR_RES_BPM_CNTR 2  // bpm cntr
#define STR_RES_CC_KNOB 3  // cc knob
#define STR_RES_CHORDMEM 4  // chordmem
#define STR_RES_CLOCK 5  // clock
#define STR_RES_DIVIDER 6  // divider
#define STR_RES_CHNFILTR 7  // chnfiltr
#define STR_RES_CHNMERGR 8  // chnmergr
#define STR_RES_USER_PRG 9  // user prg
#define STR_RES_DISPATCH 10  // dispatch
#define STR_RES_DRUMS 11  // drums
#define STR_RES_EAR_GAME 12  // ear game
#define STR_RES_MONITOR 13  // monitor
#define STR_RES_RANDOMIZ 14  // randomiz
#define STR_RES_CONTRLLR 15  // contrllr
#define STR_RES_SPLITTER 16  // splitter
#define STR_RES_DELAY 17  // delay
#define STR_RES_SCALE 18  // scale
#define STR_RES_SEQUENCR 19  // sequencr
#define STR_RES_CC_LFO 20  // cc lfo
#define STR_RES_NOTENUKE 21  // notenuke
#define STR_RES_SYSXDUMP 22  // sysxdump
#define STR_RES_SYNCLTCH 23  // syncltch
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
#define STR_RES_FLT 41  // flt
#define STR_RES_OFF 42  // off
#define STR_RES_ON 43  // on
#define STR_RES_NO 44  // no
#define STR_RES_YES 45  // yes
#define STR_RES_RUN 46  // run
#define STR_RES_BPM 47  // bpm
#define STR_RES_GRV 48  // grv
#define STR_RES_AMT 49  // amt
#define STR_RES_TAP 50  // tap
#define STR_RES_SWG 51  // swg
#define STR_RES_SHF 52  // shf
#define STR_RES_PSH 53  // psh
#define STR_RES_LAG 54  // lag
#define STR_RES_HUM 55  // hum
#define STR_RES_MNK 56  // mnk
#define STR_RES_VAL 57  // val
#define STR_RES_NUM 58  // num
#define STR_RES_TYP 59  // typ
#define STR_RES_CC_ 60  // cc#
#define STR_RES_NRP 61  // nrp
#define STR_RES_MIN 62  // min
#define STR_RES_MAX 63  // max
#define STR_RES_LVL 64  // lvl
#define STR_RES_RST 65  // rst
#define STR_RES_SORRY___ 66  // sorry...
#define STR_RES_PERFECT_ 67  // perfect!
#define STR_RES_NOT_BAD_ 68  // not bad!
#define STR_RES_MOD 69  // mod
#define STR_RES_PTN 70  // ptn
#define STR_RES_EUC 71  // euc
#define STR_RES_INT 72  // int
#define STR_RES_EXT 73  // ext
#define STR_RES_CLK 74  // clk
#define STR_RES_PT1 75  // pt1
#define STR_RES_PT2 76  // pt2
#define STR_RES_PT3 77  // pt3
#define STR_RES_PT4 78  // pt4
#define STR_RES_CC1 79  // cc1
#define STR_RES_CC2 80  // cc2
#define STR_RES_CC3 81  // cc3
#define STR_RES_CC4 82  // cc4
#define STR_RES_CC5 83  // cc5
#define STR_RES_CC6 84  // cc6
#define STR_RES_CC7 85  // cc7
#define STR_RES_CC8 86  // cc8
#define STR_RES_INP 87  // inp
#define STR_RES_OUT 88  // out
#define STR_RES_SPL 89  // spl
#define STR_RES_LOW 90  // low
#define STR_RES_UPP 91  // upp
#define STR_RES__AMT 92  // amt
#define STR_RES_NOT 93  // not
#define STR_RES_VEL 94  // vel
#define STR_RES__C1 95  // #c1
#define STR_RES__C2 96  // #c2
#define STR_RES_CYC 97  // cyc
#define STR_RES_POL 98  // pol
#define STR_RES_RND 99  // rnd
#define STR_RES_STK 100  // stk
#define STR_RES__VEL 101  // vel
#define STR_RES_DIR 102  // dir
#define STR_RES_UP 103  // up
#define STR_RES_DWN 104  // dwn
#define STR_RES_U_D 105  // u&d
#define STR_RES__RND 106  // rnd
#define STR_RES_OCT 107  // oct
#define STR_RES_DUR 108  // dur
#define STR_RES_DIV 109  // div
#define STR_RES_DEN 110  // den
#define STR_RES_4_1 111  // 4/1
#define STR_RES_3_1 112  // 3/1
#define STR_RES_2_1 113  // 2/1
#define STR_RES_3_2 114  // 3/2
#define STR_RES_1_1 115  // 1/1
#define STR_RES_3_4 116  // 3/4
#define STR_RES_2_3 117  // 2/3
#define STR_RES_1_2 118  // 1/2
#define STR_RES_3_8 119  // 3/8
#define STR_RES_1_3 120  // 1/3
#define STR_RES_1_4 121  // 1/4
#define STR_RES_1_6 122  // 1/6
#define STR_RES_1_8 123  // 1/8
#define STR_RES__12 124  // /12
#define STR_RES__16 125  // /16
#define STR_RES__24 126  // /24
#define STR_RES__32 127  // /32
#define STR_RES__48 128  // /48
#define STR_RES__96 129  // /96
#define STR_RES_REP 130  // rep
#define STR_RES_TRS 131  // trs
#define STR_RES_DPL 132  // dpl
#define STR_RES_OFF_ 133  // off_
#define STR_RES_MIR 134  // mir
#define STR_RES_ALT 135  // alt
#define STR_RES_TRK 136  // trk
#define STR_RES___RND 137  // rnd
#define STR_RES_ROO 138  // roo
#define STR_RES_SCL 139  // scl
#define STR_RES_VOI 140  // voi
#define STR_RES_HRM 141  // hrm
#define STR_RES_CHR 142  // chr
#define STR_RES_ION 143  // ion
#define STR_RES_DOR 144  // dor
#define STR_RES_PHR 145  // phr
#define STR_RES_LYD 146  // lyd
#define STR_RES_MIX 147  // mix
#define STR_RES_AEO 148  // aeo
#define STR_RES_LOC 149  // loc
#define STR_RES_BMJ 150  // bmj
#define STR_RES_BMN 151  // bmn
#define STR_RES_PMJ 152  // pmj
#define STR_RES_PMN 153  // pmn
#define STR_RES_BHR 154  // bhr
#define STR_RES_SHR 155  // shr
#define STR_RES_RUP 156  // rup
#define STR_RES_TOD 157  // tod
#define STR_RES_RAG 158  // rag
#define STR_RES_KAA 159  // kaa
#define STR_RES_MEG 160  // meg
#define STR_RES_MLK 161  // mlk
#define STR_RES_DPK 162  // dpk
#define STR_RES_FLK 163  // flk
#define STR_RES_JAP 164  // jap
#define STR_RES_GAM 165  // gam
#define STR_RES_WHL 166  // whl
#define STR_RES_C 167  // C
#define STR_RES_C_ 168  // C#
#define STR_RES_D 169  // D
#define STR_RES_D_ 170  // D#
#define STR_RES_E 171  // E
#define STR_RES_F 172  // F
#define STR_RES_F_ 173  // F#
#define STR_RES_G 174  // G
#define STR_RES_G_ 175  // G#
#define STR_RES_A 176  // A
#define STR_RES_A_ 177  // A#
#define STR_RES_B 178  // B
#define STR_RES__C 179  // C
#define STR_RES_DB 180  // Db
#define STR_RES__D 181  // D
#define STR_RES_EB 182  // Eb
#define STR_RES__E 183  // E
#define STR_RES__F 184  // F
#define STR_RES_GB 185  // Gb
#define STR_RES__G 186  // G
#define STR_RES_AB 187  // Ab
#define STR_RES__A 188  // A
#define STR_RES_BB 189  // Bb
#define STR_RES__B 190  // B
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
#define STR_RES__NOT 238  // not
#define STR_RES_CHD 239  // chd
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
