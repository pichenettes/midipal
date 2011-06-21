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
#define STR_RES_MERGECHN 6  // mergechn
#define STR_RES_DISPATCH 7  // dispatch
#define STR_RES_DRUMS 8  // drums
#define STR_RES_EAR_GAME 9  // ear game
#define STR_RES_MONITOR 10  // monitor
#define STR_RES_RANDOMIZ 11  // randomiz
#define STR_RES_CONTRLLR 12  // contrllr
#define STR_RES_SPLITTER 13  // splitter
#define STR_RES_DELAY 14  // delay
#define STR_RES_SCALE 15  // scale
#define STR_RES_SEQUENCR 16  // sequencr
#define STR_RES_CC_LFO 17  // cc lfo
#define STR_RES__RESET_ 18  // !reset!
#define STR_RES_SNDOFF 19  // sndOff
#define STR_RES_RSTCTR 20  // rstCtr
#define STR_RES_NOTOFF 21  // notOff
#define STR_RES_OMNOFF 22  // omnOff
#define STR_RES_OMNION 23  // omniOn
#define STR_RES_MONOON 24  // monoOn
#define STR_RES_POLYON 25  // polyOn
#define STR_RES_SYSX__ 26  // sysx..
#define STR_RES__SYSX_ 27  // .sysx.
#define STR_RES___SYSX 28  // ..sysx
#define STR_RES_START 29  // start
#define STR_RES_STOP 30  // stop
#define STR_RES_CONT_ 31  // cont.
#define STR_RES_RESET 32  // reset
#define STR_RES_CHN 33  // chn
#define STR_RES_ALL 34  // all
#define STR_RES_FLT 35  // flt
#define STR_RES_OFF 36  // off
#define STR_RES_ON 37  // on
#define STR_RES_NO 38  // no
#define STR_RES_YES 39  // yes
#define STR_RES_RUN 40  // run
#define STR_RES_BPM 41  // bpm
#define STR_RES_GRV 42  // grv
#define STR_RES_AMT 43  // amt
#define STR_RES_SWG 44  // swg
#define STR_RES_SHF 45  // shf
#define STR_RES_PSH 46  // psh
#define STR_RES_LAG 47  // lag
#define STR_RES_HUM 48  // hum
#define STR_RES_MNK 49  // mnk
#define STR_RES_VAL 50  // val
#define STR_RES_NUM 51  // num
#define STR_RES_TYP 52  // typ
#define STR_RES_CC_ 53  // cc#
#define STR_RES_NRP 54  // nrp
#define STR_RES_MIN 55  // min
#define STR_RES_MAX 56  // max
#define STR_RES_LVL 57  // lvl
#define STR_RES_RST 58  // rst
#define STR_RES_SORRY___ 59  // sorry...
#define STR_RES_PERFECT_ 60  // perfect!
#define STR_RES_NOT_BAD_ 61  // not bad!
#define STR_RES_MOD 62  // mod
#define STR_RES_PTN 63  // ptn
#define STR_RES_EUC 64  // euc
#define STR_RES_INT 65  // int
#define STR_RES_EXT 66  // ext
#define STR_RES_CLK 67  // clk
#define STR_RES_PT1 68  // pt1
#define STR_RES_PT2 69  // pt2
#define STR_RES_PT3 70  // pt3
#define STR_RES_PT4 71  // pt4
#define STR_RES_CC1 72  // cc1
#define STR_RES_CC2 73  // cc2
#define STR_RES_CC3 74  // cc3
#define STR_RES_CC4 75  // cc4
#define STR_RES_CC5 76  // cc5
#define STR_RES_CC6 77  // cc6
#define STR_RES_CC7 78  // cc7
#define STR_RES_CC8 79  // cc8
#define STR_RES_INP 80  // inp
#define STR_RES_OUT 81  // out
#define STR_RES_SPL 82  // spl
#define STR_RES_LOW 83  // low
#define STR_RES_UPP 84  // upp
#define STR_RES__AMT 85  //  amt
#define STR_RES_NOT 86  // not
#define STR_RES_VEL 87  // vel
#define STR_RES__C1 88  // #c1
#define STR_RES__C2 89  // #c2
#define STR_RES_CYC 90  // cyc
#define STR_RES_POL 91  // pol
#define STR_RES_RND 92  // rnd
#define STR_RES_STA 93  // sta
#define STR_RES_DIR 94  // dir
#define STR_RES_UP 95  // up
#define STR_RES_DWN 96  // dwn
#define STR_RES_U_D 97  // u&d
#define STR_RES__RND 98  //  rnd
#define STR_RES_OCT 99  // oct
#define STR_RES_DUR 100  // dur
#define STR_RES_DIV 101  // div
#define STR_RES_4_1 102  // 4/1
#define STR_RES_3_1 103  // 3/1
#define STR_RES_2_1 104  // 2/1
#define STR_RES_3_2 105  // 3/2
#define STR_RES_1_1 106  // 1/1
#define STR_RES_3_4 107  // 3/4
#define STR_RES_2_3 108  // 2/3
#define STR_RES_1_2 109  // 1/2
#define STR_RES_3_8 110  // 3/8
#define STR_RES_1_3 111  // 1/3
#define STR_RES_1_4 112  // 1/4
#define STR_RES_1_6 113  // 1/6
#define STR_RES_1_8 114  // 1/8
#define STR_RES__12 115  // /12
#define STR_RES__16 116  // /16
#define STR_RES__24 117  // /24
#define STR_RES__32 118  // /32
#define STR_RES__48 119  // /48
#define STR_RES__96 120  // /96
#define STR_RES_REP 121  // rep
#define STR_RES_TRS 122  // trs
#define STR_RES_OFF_ 123  // off_
#define STR_RES_MIR 124  // mir
#define STR_RES_ALT 125  // alt
#define STR_RES_TRK 126  // trk
#define STR_RES___RND 127  //   rnd
#define STR_RES_ROO 128  // roo
#define STR_RES_SCL 129  // scl
#define STR_RES_VOI 130  // voi
#define STR_RES_HRM 131  // hrm
#define STR_RES_CHR 132  // chr
#define STR_RES_ION 133  // ion
#define STR_RES_DOR 134  // dor
#define STR_RES_PHR 135  // phr
#define STR_RES_LYD 136  // lyd
#define STR_RES_MIX 137  // mix
#define STR_RES_AEO 138  // aeo
#define STR_RES_LOC 139  // loc
#define STR_RES_BMJ 140  // bmj
#define STR_RES_BMN 141  // bmn
#define STR_RES_PMJ 142  // pmj
#define STR_RES_PMN 143  // pmn
#define STR_RES_BHR 144  // bhr
#define STR_RES_SHR 145  // shr
#define STR_RES_RUP 146  // rup
#define STR_RES_TOD 147  // tod
#define STR_RES_RAG 148  // rag
#define STR_RES_KAA 149  // kaa
#define STR_RES_MEG 150  // meg
#define STR_RES_MLK 151  // mlk
#define STR_RES_DPK 152  // dpk
#define STR_RES_FLK 153  // flk
#define STR_RES_JAP 154  // jap
#define STR_RES_GAM 155  // gam
#define STR_RES_WHL 156  // whl
#define STR_RES_C 157  // C
#define STR_RES_C_ 158  // C#
#define STR_RES_D 159  // D
#define STR_RES_D_ 160  // D#
#define STR_RES_E 161  // E
#define STR_RES_F 162  // F
#define STR_RES_F_ 163  // F#
#define STR_RES_G 164  // G
#define STR_RES_G_ 165  // G#
#define STR_RES_A 166  // A
#define STR_RES_A_ 167  // A#
#define STR_RES_B 168  // B
#define STR_RES__C 169  //  C
#define STR_RES_DB 170  // Db
#define STR_RES__D 171  //  D
#define STR_RES_EB 172  // Eb
#define STR_RES__E 173  //  E
#define STR_RES__F 174  //  F
#define STR_RES_GB 175  // Gb
#define STR_RES__G 176  //  G
#define STR_RES_AB 177  // Ab
#define STR_RES__A 178  //  A
#define STR_RES_BB 179  // Bb
#define STR_RES__B 180  //  B
#define STR_RES__ 181  //  
#define STR_RES_STP 182  // stp
#define STR_RES_1 183  // 
#define STR_RES_2 184  // 
#define STR_RES_3 185  // 
#define STR_RES_4 186  // 
#define STR_RES_AM1 187  // am1
#define STR_RES_AM2 188  // am2
#define STR_RES_AM3 189  // am3
#define STR_RES_AM4 190  // am4
#define STR_RES_CE1 191  // ce1
#define STR_RES_CE2 192  // ce2
#define STR_RES_CE3 193  // ce3
#define STR_RES_CE4 194  // ce4
#define STR_RES_WF1 195  // wf1
#define STR_RES_WF2 196  // wf2
#define STR_RES_WF3 197  // wf3
#define STR_RES_WF4 198  // wf4
#define STR_RES_RT1 199  // rt1
#define STR_RES_RT2 200  // rt2
#define STR_RES_RT3 201  // rt3
#define STR_RES_RT4 202  // rt4
#define STR_RES_SY1 203  // sy1
#define STR_RES_SY2 204  // sy2
#define STR_RES_SY3 205  // sy3
#define STR_RES_SY4 206  // sy4
#define STR_RES_TRI 207  // tri
#define STR_RES_SQR 208  // sqr
#define STR_RES_RMP 209  // rmp
#define STR_RES_SIN 210  // sin
#define STR_RES_SI2 211  // si2
#define STR_RES_SI3 212  // si3
#define STR_RES_SI5 213  // si5
#define STR_RES_GG1 214  // gg1
#define STR_RES_GG2 215  // gg2
#define STR_RES_BT1 216  // bt1
#define STR_RES_BT2 217  // bt2
#define STR_RES_SP1 218  // sp1
#define STR_RES_SP2 219  // sp2
#define STR_RES_LP1 220  // lp1
#define STR_RES_LP2 221  // lp2
#define STR_RES_RS1 222  // rs1
#define STR_RES_RS2 223  // rs2
#define STR_RES_S_H 224  // s&h
#define STR_RES_RES 225  // res
#define STR_RES_FRE 226  // fre
#define STR_RES__NOT 227  //  not
#define STR_RES_CHD 228  // chd
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
