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
#define STR_RES_CHNFILTR 6  // chnfiltr
#define STR_RES_CHNMERGR 7  // chnmergr
#define STR_RES_DISPATCH 8  // dispatch
#define STR_RES_DRUMS 9  // drums
#define STR_RES_EAR_GAME 10  // ear game
#define STR_RES_MONITOR 11  // monitor
#define STR_RES_RANDOMIZ 12  // randomiz
#define STR_RES_CONTRLLR 13  // contrllr
#define STR_RES_SPLITTER 14  // splitter
#define STR_RES_DELAY 15  // delay
#define STR_RES_SCALE 16  // scale
#define STR_RES_SEQUENCR 17  // sequencr
#define STR_RES_CC_LFO 18  // cc lfo
#define STR_RES_NOTENUKE 19  // notenuke
#define STR_RES__RESET_ 20  // !reset!
#define STR_RES_SNDOFF 21  // sndOff
#define STR_RES_RSTCTR 22  // rstCtr
#define STR_RES_NOTOFF 23  // notOff
#define STR_RES_OMNOFF 24  // omnOff
#define STR_RES_OMNION 25  // omniOn
#define STR_RES_MONOON 26  // monoOn
#define STR_RES_POLYON 27  // polyOn
#define STR_RES_SYSX__ 28  // sysx..
#define STR_RES__SYSX_ 29  // .sysx.
#define STR_RES___SYSX 30  // ..sysx
#define STR_RES_START 31  // start
#define STR_RES_STOP 32  // stop
#define STR_RES_CONT_ 33  // cont.
#define STR_RES_RESET 34  // reset
#define STR_RES_CHN 35  // chn
#define STR_RES_ALL 36  // all
#define STR_RES_FLT 37  // flt
#define STR_RES_OFF 38  // off
#define STR_RES_ON 39  // on
#define STR_RES_NO 40  // no
#define STR_RES_YES 41  // yes
#define STR_RES_RUN 42  // run
#define STR_RES_BPM 43  // bpm
#define STR_RES_GRV 44  // grv
#define STR_RES_AMT 45  // amt
#define STR_RES_SWG 46  // swg
#define STR_RES_SHF 47  // shf
#define STR_RES_PSH 48  // psh
#define STR_RES_LAG 49  // lag
#define STR_RES_HUM 50  // hum
#define STR_RES_MNK 51  // mnk
#define STR_RES_VAL 52  // val
#define STR_RES_NUM 53  // num
#define STR_RES_TYP 54  // typ
#define STR_RES_CC_ 55  // cc#
#define STR_RES_NRP 56  // nrp
#define STR_RES_MIN 57  // min
#define STR_RES_MAX 58  // max
#define STR_RES_LVL 59  // lvl
#define STR_RES_RST 60  // rst
#define STR_RES_SORRY___ 61  // sorry...
#define STR_RES_PERFECT_ 62  // perfect!
#define STR_RES_NOT_BAD_ 63  // not bad!
#define STR_RES_MOD 64  // mod
#define STR_RES_PTN 65  // ptn
#define STR_RES_EUC 66  // euc
#define STR_RES_INT 67  // int
#define STR_RES_EXT 68  // ext
#define STR_RES_CLK 69  // clk
#define STR_RES_PT1 70  // pt1
#define STR_RES_PT2 71  // pt2
#define STR_RES_PT3 72  // pt3
#define STR_RES_PT4 73  // pt4
#define STR_RES_CC1 74  // cc1
#define STR_RES_CC2 75  // cc2
#define STR_RES_CC3 76  // cc3
#define STR_RES_CC4 77  // cc4
#define STR_RES_CC5 78  // cc5
#define STR_RES_CC6 79  // cc6
#define STR_RES_CC7 80  // cc7
#define STR_RES_CC8 81  // cc8
#define STR_RES_INP 82  // inp
#define STR_RES_OUT 83  // out
#define STR_RES_SPL 84  // spl
#define STR_RES_LOW 85  // low
#define STR_RES_UPP 86  // upp
#define STR_RES__AMT 87  //  amt
#define STR_RES_NOT 88  // not
#define STR_RES_VEL 89  // vel
#define STR_RES__C1 90  // #c1
#define STR_RES__C2 91  // #c2
#define STR_RES_CYC 92  // cyc
#define STR_RES_POL 93  // pol
#define STR_RES_RND 94  // rnd
#define STR_RES_STA 95  // sta
#define STR_RES_DIR 96  // dir
#define STR_RES_UP 97  // up
#define STR_RES_DWN 98  // dwn
#define STR_RES_U_D 99  // u&d
#define STR_RES__RND 100  //  rnd
#define STR_RES_OCT 101  // oct
#define STR_RES_DUR 102  // dur
#define STR_RES_DIV 103  // div
#define STR_RES_4_1 104  // 4/1
#define STR_RES_3_1 105  // 3/1
#define STR_RES_2_1 106  // 2/1
#define STR_RES_3_2 107  // 3/2
#define STR_RES_1_1 108  // 1/1
#define STR_RES_3_4 109  // 3/4
#define STR_RES_2_3 110  // 2/3
#define STR_RES_1_2 111  // 1/2
#define STR_RES_3_8 112  // 3/8
#define STR_RES_1_3 113  // 1/3
#define STR_RES_1_4 114  // 1/4
#define STR_RES_1_6 115  // 1/6
#define STR_RES_1_8 116  // 1/8
#define STR_RES__12 117  // /12
#define STR_RES__16 118  // /16
#define STR_RES__24 119  // /24
#define STR_RES__32 120  // /32
#define STR_RES__48 121  // /48
#define STR_RES__96 122  // /96
#define STR_RES_REP 123  // rep
#define STR_RES_TRS 124  // trs
#define STR_RES_DPL 125  // dpl
#define STR_RES_OFF_ 126  // off_
#define STR_RES_MIR 127  // mir
#define STR_RES_ALT 128  // alt
#define STR_RES_TRK 129  // trk
#define STR_RES___RND 130  //   rnd
#define STR_RES_ROO 131  // roo
#define STR_RES_SCL 132  // scl
#define STR_RES_VOI 133  // voi
#define STR_RES_HRM 134  // hrm
#define STR_RES_CHR 135  // chr
#define STR_RES_ION 136  // ion
#define STR_RES_DOR 137  // dor
#define STR_RES_PHR 138  // phr
#define STR_RES_LYD 139  // lyd
#define STR_RES_MIX 140  // mix
#define STR_RES_AEO 141  // aeo
#define STR_RES_LOC 142  // loc
#define STR_RES_BMJ 143  // bmj
#define STR_RES_BMN 144  // bmn
#define STR_RES_PMJ 145  // pmj
#define STR_RES_PMN 146  // pmn
#define STR_RES_BHR 147  // bhr
#define STR_RES_SHR 148  // shr
#define STR_RES_RUP 149  // rup
#define STR_RES_TOD 150  // tod
#define STR_RES_RAG 151  // rag
#define STR_RES_KAA 152  // kaa
#define STR_RES_MEG 153  // meg
#define STR_RES_MLK 154  // mlk
#define STR_RES_DPK 155  // dpk
#define STR_RES_FLK 156  // flk
#define STR_RES_JAP 157  // jap
#define STR_RES_GAM 158  // gam
#define STR_RES_WHL 159  // whl
#define STR_RES_C 160  // C
#define STR_RES_C_ 161  // C#
#define STR_RES_D 162  // D
#define STR_RES_D_ 163  // D#
#define STR_RES_E 164  // E
#define STR_RES_F 165  // F
#define STR_RES_F_ 166  // F#
#define STR_RES_G 167  // G
#define STR_RES_G_ 168  // G#
#define STR_RES_A 169  // A
#define STR_RES_A_ 170  // A#
#define STR_RES_B 171  // B
#define STR_RES__C 172  //  C
#define STR_RES_DB 173  // Db
#define STR_RES__D 174  //  D
#define STR_RES_EB 175  // Eb
#define STR_RES__E 176  //  E
#define STR_RES__F 177  //  F
#define STR_RES_GB 178  // Gb
#define STR_RES__G 179  //  G
#define STR_RES_AB 180  // Ab
#define STR_RES__A 181  //  A
#define STR_RES_BB 182  // Bb
#define STR_RES__B 183  //  B
#define STR_RES_KEY 184  // key
#define STR_RES__ 185  //  
#define STR_RES_STP 186  // stp
#define STR_RES_1 187  // 
#define STR_RES_2 188  // 
#define STR_RES_3 189  // 
#define STR_RES_4 190  // 
#define STR_RES_AM1 191  // am1
#define STR_RES_AM2 192  // am2
#define STR_RES_AM3 193  // am3
#define STR_RES_AM4 194  // am4
#define STR_RES_CE1 195  // ce1
#define STR_RES_CE2 196  // ce2
#define STR_RES_CE3 197  // ce3
#define STR_RES_CE4 198  // ce4
#define STR_RES_WF1 199  // wf1
#define STR_RES_WF2 200  // wf2
#define STR_RES_WF3 201  // wf3
#define STR_RES_WF4 202  // wf4
#define STR_RES_RT1 203  // rt1
#define STR_RES_RT2 204  // rt2
#define STR_RES_RT3 205  // rt3
#define STR_RES_RT4 206  // rt4
#define STR_RES_SY1 207  // sy1
#define STR_RES_SY2 208  // sy2
#define STR_RES_SY3 209  // sy3
#define STR_RES_SY4 210  // sy4
#define STR_RES_TRI 211  // tri
#define STR_RES_SQR 212  // sqr
#define STR_RES_RMP 213  // rmp
#define STR_RES_SIN 214  // sin
#define STR_RES_SI2 215  // si2
#define STR_RES_SI3 216  // si3
#define STR_RES_SI5 217  // si5
#define STR_RES_GG1 218  // gg1
#define STR_RES_GG2 219  // gg2
#define STR_RES_BT1 220  // bt1
#define STR_RES_BT2 221  // bt2
#define STR_RES_SP1 222  // sp1
#define STR_RES_SP2 223  // sp2
#define STR_RES_LP1 224  // lp1
#define STR_RES_LP2 225  // lp2
#define STR_RES_RS1 226  // rs1
#define STR_RES_RS2 227  // rs2
#define STR_RES_S_H 228  // s&h
#define STR_RES_RES 229  // res
#define STR_RES_FRE 230  // fre
#define STR_RES__NOT 231  //  not
#define STR_RES_CHD 232  // chd
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
