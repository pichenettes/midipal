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
#define STR_RES__RESET_ 23  // !reset!
#define STR_RES_SNDOFF 24  // sndOff
#define STR_RES_RSTCTR 25  // rstCtr
#define STR_RES_NOTOFF 26  // notOff
#define STR_RES_OMNOFF 27  // omnOff
#define STR_RES_OMNION 28  // omniOn
#define STR_RES_MONOON 29  // monoOn
#define STR_RES_POLYON 30  // polyOn
#define STR_RES_SYSX__ 31  // sysx..
#define STR_RES__SYSX_ 32  // .sysx.
#define STR_RES___SYSX 33  // ..sysx
#define STR_RES_START 34  // start
#define STR_RES_STOP 35  // stop
#define STR_RES_CONT_ 36  // cont.
#define STR_RES_RESET 37  // reset
#define STR_RES_CHN 38  // chn
#define STR_RES_ALL 39  // all
#define STR_RES_FLT 40  // flt
#define STR_RES_OFF 41  // off
#define STR_RES_ON 42  // on
#define STR_RES_NO 43  // no
#define STR_RES_YES 44  // yes
#define STR_RES_RUN 45  // run
#define STR_RES_BPM 46  // bpm
#define STR_RES_GRV 47  // grv
#define STR_RES_AMT 48  // amt
#define STR_RES_TAP 49  // tap
#define STR_RES_SWG 50  // swg
#define STR_RES_SHF 51  // shf
#define STR_RES_PSH 52  // psh
#define STR_RES_LAG 53  // lag
#define STR_RES_HUM 54  // hum
#define STR_RES_MNK 55  // mnk
#define STR_RES_VAL 56  // val
#define STR_RES_NUM 57  // num
#define STR_RES_TYP 58  // typ
#define STR_RES_CC_ 59  // cc#
#define STR_RES_NRP 60  // nrp
#define STR_RES_MIN 61  // min
#define STR_RES_MAX 62  // max
#define STR_RES_LVL 63  // lvl
#define STR_RES_RST 64  // rst
#define STR_RES_SORRY___ 65  // sorry...
#define STR_RES_PERFECT_ 66  // perfect!
#define STR_RES_NOT_BAD_ 67  // not bad!
#define STR_RES_MOD 68  // mod
#define STR_RES_PTN 69  // ptn
#define STR_RES_EUC 70  // euc
#define STR_RES_INT 71  // int
#define STR_RES_EXT 72  // ext
#define STR_RES_CLK 73  // clk
#define STR_RES_PT1 74  // pt1
#define STR_RES_PT2 75  // pt2
#define STR_RES_PT3 76  // pt3
#define STR_RES_PT4 77  // pt4
#define STR_RES_CC1 78  // cc1
#define STR_RES_CC2 79  // cc2
#define STR_RES_CC3 80  // cc3
#define STR_RES_CC4 81  // cc4
#define STR_RES_CC5 82  // cc5
#define STR_RES_CC6 83  // cc6
#define STR_RES_CC7 84  // cc7
#define STR_RES_CC8 85  // cc8
#define STR_RES_INP 86  // inp
#define STR_RES_OUT 87  // out
#define STR_RES_SPL 88  // spl
#define STR_RES_LOW 89  // low
#define STR_RES_UPP 90  // upp
#define STR_RES__AMT 91  // amt
#define STR_RES_NOT 92  // not
#define STR_RES_VEL 93  // vel
#define STR_RES__C1 94  // #c1
#define STR_RES__C2 95  // #c2
#define STR_RES_CYC 96  // cyc
#define STR_RES_POL 97  // pol
#define STR_RES_RND 98  // rnd
#define STR_RES_STK 99  // stk
#define STR_RES__VEL 100  // vel
#define STR_RES_DIR 101  // dir
#define STR_RES_UP 102  // up
#define STR_RES_DWN 103  // dwn
#define STR_RES_U_D 104  // u&d
#define STR_RES__RND 105  // rnd
#define STR_RES_OCT 106  // oct
#define STR_RES_DUR 107  // dur
#define STR_RES_DIV 108  // div
#define STR_RES_4_1 109  // 4/1
#define STR_RES_3_1 110  // 3/1
#define STR_RES_2_1 111  // 2/1
#define STR_RES_3_2 112  // 3/2
#define STR_RES_1_1 113  // 1/1
#define STR_RES_3_4 114  // 3/4
#define STR_RES_2_3 115  // 2/3
#define STR_RES_1_2 116  // 1/2
#define STR_RES_3_8 117  // 3/8
#define STR_RES_1_3 118  // 1/3
#define STR_RES_1_4 119  // 1/4
#define STR_RES_1_6 120  // 1/6
#define STR_RES_1_8 121  // 1/8
#define STR_RES__12 122  // /12
#define STR_RES__16 123  // /16
#define STR_RES__24 124  // /24
#define STR_RES__32 125  // /32
#define STR_RES__48 126  // /48
#define STR_RES__96 127  // /96
#define STR_RES_REP 128  // rep
#define STR_RES_TRS 129  // trs
#define STR_RES_DPL 130  // dpl
#define STR_RES_OFF_ 131  // off_
#define STR_RES_MIR 132  // mir
#define STR_RES_ALT 133  // alt
#define STR_RES_TRK 134  // trk
#define STR_RES___RND 135  // rnd
#define STR_RES_ROO 136  // roo
#define STR_RES_SCL 137  // scl
#define STR_RES_VOI 138  // voi
#define STR_RES_HRM 139  // hrm
#define STR_RES_CHR 140  // chr
#define STR_RES_ION 141  // ion
#define STR_RES_DOR 142  // dor
#define STR_RES_PHR 143  // phr
#define STR_RES_LYD 144  // lyd
#define STR_RES_MIX 145  // mix
#define STR_RES_AEO 146  // aeo
#define STR_RES_LOC 147  // loc
#define STR_RES_BMJ 148  // bmj
#define STR_RES_BMN 149  // bmn
#define STR_RES_PMJ 150  // pmj
#define STR_RES_PMN 151  // pmn
#define STR_RES_BHR 152  // bhr
#define STR_RES_SHR 153  // shr
#define STR_RES_RUP 154  // rup
#define STR_RES_TOD 155  // tod
#define STR_RES_RAG 156  // rag
#define STR_RES_KAA 157  // kaa
#define STR_RES_MEG 158  // meg
#define STR_RES_MLK 159  // mlk
#define STR_RES_DPK 160  // dpk
#define STR_RES_FLK 161  // flk
#define STR_RES_JAP 162  // jap
#define STR_RES_GAM 163  // gam
#define STR_RES_WHL 164  // whl
#define STR_RES_C 165  // C
#define STR_RES_C_ 166  // C#
#define STR_RES_D 167  // D
#define STR_RES_D_ 168  // D#
#define STR_RES_E 169  // E
#define STR_RES_F 170  // F
#define STR_RES_F_ 171  // F#
#define STR_RES_G 172  // G
#define STR_RES_G_ 173  // G#
#define STR_RES_A 174  // A
#define STR_RES_A_ 175  // A#
#define STR_RES_B 176  // B
#define STR_RES__C 177  // C
#define STR_RES_DB 178  // Db
#define STR_RES__D 179  // D
#define STR_RES_EB 180  // Eb
#define STR_RES__E 181  // E
#define STR_RES__F 182  // F
#define STR_RES_GB 183  // Gb
#define STR_RES__G 184  // G
#define STR_RES_AB 185  // Ab
#define STR_RES__A 186  // A
#define STR_RES_BB 187  // Bb
#define STR_RES__B 188  // B
#define STR_RES_KEY 189  // key
#define STR_RES__ 190  // 
#define STR_RES_STP 191  // stp
#define STR_RES_1 192  // 
#define STR_RES_2 193  // 
#define STR_RES_3 194  // 
#define STR_RES_4 195  // 
#define STR_RES_AM1 196  // am1
#define STR_RES_AM2 197  // am2
#define STR_RES_AM3 198  // am3
#define STR_RES_AM4 199  // am4
#define STR_RES_CE1 200  // ce1
#define STR_RES_CE2 201  // ce2
#define STR_RES_CE3 202  // ce3
#define STR_RES_CE4 203  // ce4
#define STR_RES_WF1 204  // wf1
#define STR_RES_WF2 205  // wf2
#define STR_RES_WF3 206  // wf3
#define STR_RES_WF4 207  // wf4
#define STR_RES_RT1 208  // rt1
#define STR_RES_RT2 209  // rt2
#define STR_RES_RT3 210  // rt3
#define STR_RES_RT4 211  // rt4
#define STR_RES_SY1 212  // sy1
#define STR_RES_SY2 213  // sy2
#define STR_RES_SY3 214  // sy3
#define STR_RES_SY4 215  // sy4
#define STR_RES_TRI 216  // tri
#define STR_RES_SQR 217  // sqr
#define STR_RES_RMP 218  // rmp
#define STR_RES_SIN 219  // sin
#define STR_RES_SI2 220  // si2
#define STR_RES_SI3 221  // si3
#define STR_RES_SI5 222  // si5
#define STR_RES_GG1 223  // gg1
#define STR_RES_GG2 224  // gg2
#define STR_RES_BT1 225  // bt1
#define STR_RES_BT2 226  // bt2
#define STR_RES_SP1 227  // sp1
#define STR_RES_SP2 228  // sp2
#define STR_RES_LP1 229  // lp1
#define STR_RES_LP2 230  // lp2
#define STR_RES_RS1 231  // rs1
#define STR_RES_RS2 232  // rs2
#define STR_RES_S_H 233  // s&h
#define STR_RES_RES 234  // res
#define STR_RES_FRE 235  // fre
#define STR_RES__NOT 236  // not
#define STR_RES_CHD 237  // chd
#define STR_RES_PRG 238  // prg
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
