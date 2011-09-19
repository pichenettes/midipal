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
#define STR_RES_DISPATCH 9  // dispatch
#define STR_RES_DRUMS 10  // drums
#define STR_RES_EAR_GAME 11  // ear game
#define STR_RES_MONITOR 12  // monitor
#define STR_RES_RANDOMIZ 13  // randomiz
#define STR_RES_CONTRLLR 14  // contrllr
#define STR_RES_SPLITTER 15  // splitter
#define STR_RES_DELAY 16  // delay
#define STR_RES_SCALE 17  // scale
#define STR_RES_SEQUENCR 18  // sequencr
#define STR_RES_CC_LFO 19  // cc lfo
#define STR_RES_NOTENUKE 20  // notenuke
#define STR_RES_SYSXDUMP 21  // sysxdump
#define STR_RES__RESET_ 22  // !reset!
#define STR_RES_SNDOFF 23  // sndOff
#define STR_RES_RSTCTR 24  // rstCtr
#define STR_RES_NOTOFF 25  // notOff
#define STR_RES_OMNOFF 26  // omnOff
#define STR_RES_OMNION 27  // omniOn
#define STR_RES_MONOON 28  // monoOn
#define STR_RES_POLYON 29  // polyOn
#define STR_RES_SYSX__ 30  // sysx..
#define STR_RES__SYSX_ 31  // .sysx.
#define STR_RES___SYSX 32  // ..sysx
#define STR_RES_START 33  // start
#define STR_RES_STOP 34  // stop
#define STR_RES_CONT_ 35  // cont.
#define STR_RES_RESET 36  // reset
#define STR_RES_CHN 37  // chn
#define STR_RES_ALL 38  // all
#define STR_RES_FLT 39  // flt
#define STR_RES_OFF 40  // off
#define STR_RES_ON 41  // on
#define STR_RES_NO 42  // no
#define STR_RES_YES 43  // yes
#define STR_RES_RUN 44  // run
#define STR_RES_BPM 45  // bpm
#define STR_RES_GRV 46  // grv
#define STR_RES_AMT 47  // amt
#define STR_RES_TAP 48  // tap
#define STR_RES_SWG 49  // swg
#define STR_RES_SHF 50  // shf
#define STR_RES_PSH 51  // psh
#define STR_RES_LAG 52  // lag
#define STR_RES_HUM 53  // hum
#define STR_RES_MNK 54  // mnk
#define STR_RES_VAL 55  // val
#define STR_RES_NUM 56  // num
#define STR_RES_TYP 57  // typ
#define STR_RES_CC_ 58  // cc#
#define STR_RES_NRP 59  // nrp
#define STR_RES_MIN 60  // min
#define STR_RES_MAX 61  // max
#define STR_RES_LVL 62  // lvl
#define STR_RES_RST 63  // rst
#define STR_RES_SORRY___ 64  // sorry...
#define STR_RES_PERFECT_ 65  // perfect!
#define STR_RES_NOT_BAD_ 66  // not bad!
#define STR_RES_MOD 67  // mod
#define STR_RES_PTN 68  // ptn
#define STR_RES_EUC 69  // euc
#define STR_RES_INT 70  // int
#define STR_RES_EXT 71  // ext
#define STR_RES_CLK 72  // clk
#define STR_RES_PT1 73  // pt1
#define STR_RES_PT2 74  // pt2
#define STR_RES_PT3 75  // pt3
#define STR_RES_PT4 76  // pt4
#define STR_RES_CC1 77  // cc1
#define STR_RES_CC2 78  // cc2
#define STR_RES_CC3 79  // cc3
#define STR_RES_CC4 80  // cc4
#define STR_RES_CC5 81  // cc5
#define STR_RES_CC6 82  // cc6
#define STR_RES_CC7 83  // cc7
#define STR_RES_CC8 84  // cc8
#define STR_RES_INP 85  // inp
#define STR_RES_OUT 86  // out
#define STR_RES_SPL 87  // spl
#define STR_RES_LOW 88  // low
#define STR_RES_UPP 89  // upp
#define STR_RES__AMT 90  // amt
#define STR_RES_NOT 91  // not
#define STR_RES_VEL 92  // vel
#define STR_RES__C1 93  // #c1
#define STR_RES__C2 94  // #c2
#define STR_RES_CYC 95  // cyc
#define STR_RES_POL 96  // pol
#define STR_RES_RND 97  // rnd
#define STR_RES_STK 98  // stk
#define STR_RES__VEL 99  // vel
#define STR_RES_DIR 100  // dir
#define STR_RES_UP 101  // up
#define STR_RES_DWN 102  // dwn
#define STR_RES_U_D 103  // u&d
#define STR_RES__RND 104  // rnd
#define STR_RES_OCT 105  // oct
#define STR_RES_DUR 106  // dur
#define STR_RES_DIV 107  // div
#define STR_RES_4_1 108  // 4/1
#define STR_RES_3_1 109  // 3/1
#define STR_RES_2_1 110  // 2/1
#define STR_RES_3_2 111  // 3/2
#define STR_RES_1_1 112  // 1/1
#define STR_RES_3_4 113  // 3/4
#define STR_RES_2_3 114  // 2/3
#define STR_RES_1_2 115  // 1/2
#define STR_RES_3_8 116  // 3/8
#define STR_RES_1_3 117  // 1/3
#define STR_RES_1_4 118  // 1/4
#define STR_RES_1_6 119  // 1/6
#define STR_RES_1_8 120  // 1/8
#define STR_RES__12 121  // /12
#define STR_RES__16 122  // /16
#define STR_RES__24 123  // /24
#define STR_RES__32 124  // /32
#define STR_RES__48 125  // /48
#define STR_RES__96 126  // /96
#define STR_RES_REP 127  // rep
#define STR_RES_TRS 128  // trs
#define STR_RES_DPL 129  // dpl
#define STR_RES_OFF_ 130  // off_
#define STR_RES_MIR 131  // mir
#define STR_RES_ALT 132  // alt
#define STR_RES_TRK 133  // trk
#define STR_RES___RND 134  // rnd
#define STR_RES_ROO 135  // roo
#define STR_RES_SCL 136  // scl
#define STR_RES_VOI 137  // voi
#define STR_RES_HRM 138  // hrm
#define STR_RES_CHR 139  // chr
#define STR_RES_ION 140  // ion
#define STR_RES_DOR 141  // dor
#define STR_RES_PHR 142  // phr
#define STR_RES_LYD 143  // lyd
#define STR_RES_MIX 144  // mix
#define STR_RES_AEO 145  // aeo
#define STR_RES_LOC 146  // loc
#define STR_RES_BMJ 147  // bmj
#define STR_RES_BMN 148  // bmn
#define STR_RES_PMJ 149  // pmj
#define STR_RES_PMN 150  // pmn
#define STR_RES_BHR 151  // bhr
#define STR_RES_SHR 152  // shr
#define STR_RES_RUP 153  // rup
#define STR_RES_TOD 154  // tod
#define STR_RES_RAG 155  // rag
#define STR_RES_KAA 156  // kaa
#define STR_RES_MEG 157  // meg
#define STR_RES_MLK 158  // mlk
#define STR_RES_DPK 159  // dpk
#define STR_RES_FLK 160  // flk
#define STR_RES_JAP 161  // jap
#define STR_RES_GAM 162  // gam
#define STR_RES_WHL 163  // whl
#define STR_RES_C 164  // C
#define STR_RES_C_ 165  // C#
#define STR_RES_D 166  // D
#define STR_RES_D_ 167  // D#
#define STR_RES_E 168  // E
#define STR_RES_F 169  // F
#define STR_RES_F_ 170  // F#
#define STR_RES_G 171  // G
#define STR_RES_G_ 172  // G#
#define STR_RES_A 173  // A
#define STR_RES_A_ 174  // A#
#define STR_RES_B 175  // B
#define STR_RES__C 176  // C
#define STR_RES_DB 177  // Db
#define STR_RES__D 178  // D
#define STR_RES_EB 179  // Eb
#define STR_RES__E 180  // E
#define STR_RES__F 181  // F
#define STR_RES_GB 182  // Gb
#define STR_RES__G 183  // G
#define STR_RES_AB 184  // Ab
#define STR_RES__A 185  // A
#define STR_RES_BB 186  // Bb
#define STR_RES__B 187  // B
#define STR_RES_KEY 188  // key
#define STR_RES__ 189  // 
#define STR_RES_STP 190  // stp
#define STR_RES_1 191  // 
#define STR_RES_2 192  // 
#define STR_RES_3 193  // 
#define STR_RES_4 194  // 
#define STR_RES_AM1 195  // am1
#define STR_RES_AM2 196  // am2
#define STR_RES_AM3 197  // am3
#define STR_RES_AM4 198  // am4
#define STR_RES_CE1 199  // ce1
#define STR_RES_CE2 200  // ce2
#define STR_RES_CE3 201  // ce3
#define STR_RES_CE4 202  // ce4
#define STR_RES_WF1 203  // wf1
#define STR_RES_WF2 204  // wf2
#define STR_RES_WF3 205  // wf3
#define STR_RES_WF4 206  // wf4
#define STR_RES_RT1 207  // rt1
#define STR_RES_RT2 208  // rt2
#define STR_RES_RT3 209  // rt3
#define STR_RES_RT4 210  // rt4
#define STR_RES_SY1 211  // sy1
#define STR_RES_SY2 212  // sy2
#define STR_RES_SY3 213  // sy3
#define STR_RES_SY4 214  // sy4
#define STR_RES_TRI 215  // tri
#define STR_RES_SQR 216  // sqr
#define STR_RES_RMP 217  // rmp
#define STR_RES_SIN 218  // sin
#define STR_RES_SI2 219  // si2
#define STR_RES_SI3 220  // si3
#define STR_RES_SI5 221  // si5
#define STR_RES_GG1 222  // gg1
#define STR_RES_GG2 223  // gg2
#define STR_RES_BT1 224  // bt1
#define STR_RES_BT2 225  // bt2
#define STR_RES_SP1 226  // sp1
#define STR_RES_SP2 227  // sp2
#define STR_RES_LP1 228  // lp1
#define STR_RES_LP2 229  // lp2
#define STR_RES_RS1 230  // rs1
#define STR_RES_RS2 231  // rs2
#define STR_RES_S_H 232  // s&h
#define STR_RES_RES 233  // res
#define STR_RES_FRE 234  // fre
#define STR_RES__NOT 235  // not
#define STR_RES_CHD 236  // chd
#define LUT_RES_ARPEGGIATOR_PATTERNS 0
#define LUT_RES_ARPEGGIATOR_PATTERNS_SIZE 15
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
