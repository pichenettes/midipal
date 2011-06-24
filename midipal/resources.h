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
#define STR_RES_NOTENUKE 18  // notenuke
#define STR_RES__RESET_ 19  // !reset!
#define STR_RES_SNDOFF 20  // sndOff
#define STR_RES_RSTCTR 21  // rstCtr
#define STR_RES_NOTOFF 22  // notOff
#define STR_RES_OMNOFF 23  // omnOff
#define STR_RES_OMNION 24  // omniOn
#define STR_RES_MONOON 25  // monoOn
#define STR_RES_POLYON 26  // polyOn
#define STR_RES_SYSX__ 27  // sysx..
#define STR_RES__SYSX_ 28  // .sysx.
#define STR_RES___SYSX 29  // ..sysx
#define STR_RES_START 30  // start
#define STR_RES_STOP 31  // stop
#define STR_RES_CONT_ 32  // cont.
#define STR_RES_RESET 33  // reset
#define STR_RES_CHN 34  // chn
#define STR_RES_ALL 35  // all
#define STR_RES_FLT 36  // flt
#define STR_RES_OFF 37  // off
#define STR_RES_ON 38  // on
#define STR_RES_NO 39  // no
#define STR_RES_YES 40  // yes
#define STR_RES_RUN 41  // run
#define STR_RES_BPM 42  // bpm
#define STR_RES_GRV 43  // grv
#define STR_RES_AMT 44  // amt
#define STR_RES_SWG 45  // swg
#define STR_RES_SHF 46  // shf
#define STR_RES_PSH 47  // psh
#define STR_RES_LAG 48  // lag
#define STR_RES_HUM 49  // hum
#define STR_RES_MNK 50  // mnk
#define STR_RES_VAL 51  // val
#define STR_RES_NUM 52  // num
#define STR_RES_TYP 53  // typ
#define STR_RES_CC_ 54  // cc#
#define STR_RES_NRP 55  // nrp
#define STR_RES_MIN 56  // min
#define STR_RES_MAX 57  // max
#define STR_RES_LVL 58  // lvl
#define STR_RES_RST 59  // rst
#define STR_RES_SORRY___ 60  // sorry...
#define STR_RES_PERFECT_ 61  // perfect!
#define STR_RES_NOT_BAD_ 62  // not bad!
#define STR_RES_MOD 63  // mod
#define STR_RES_PTN 64  // ptn
#define STR_RES_EUC 65  // euc
#define STR_RES_INT 66  // int
#define STR_RES_EXT 67  // ext
#define STR_RES_CLK 68  // clk
#define STR_RES_PT1 69  // pt1
#define STR_RES_PT2 70  // pt2
#define STR_RES_PT3 71  // pt3
#define STR_RES_PT4 72  // pt4
#define STR_RES_CC1 73  // cc1
#define STR_RES_CC2 74  // cc2
#define STR_RES_CC3 75  // cc3
#define STR_RES_CC4 76  // cc4
#define STR_RES_CC5 77  // cc5
#define STR_RES_CC6 78  // cc6
#define STR_RES_CC7 79  // cc7
#define STR_RES_CC8 80  // cc8
#define STR_RES_INP 81  // inp
#define STR_RES_OUT 82  // out
#define STR_RES_SPL 83  // spl
#define STR_RES_LOW 84  // low
#define STR_RES_UPP 85  // upp
#define STR_RES__AMT 86  //  amt
#define STR_RES_NOT 87  // not
#define STR_RES_VEL 88  // vel
#define STR_RES__C1 89  // #c1
#define STR_RES__C2 90  // #c2
#define STR_RES_CYC 91  // cyc
#define STR_RES_POL 92  // pol
#define STR_RES_RND 93  // rnd
#define STR_RES_STA 94  // sta
#define STR_RES_DIR 95  // dir
#define STR_RES_UP 96  // up
#define STR_RES_DWN 97  // dwn
#define STR_RES_U_D 98  // u&d
#define STR_RES__RND 99  //  rnd
#define STR_RES_OCT 100  // oct
#define STR_RES_DUR 101  // dur
#define STR_RES_DIV 102  // div
#define STR_RES_4_1 103  // 4/1
#define STR_RES_3_1 104  // 3/1
#define STR_RES_2_1 105  // 2/1
#define STR_RES_3_2 106  // 3/2
#define STR_RES_1_1 107  // 1/1
#define STR_RES_3_4 108  // 3/4
#define STR_RES_2_3 109  // 2/3
#define STR_RES_1_2 110  // 1/2
#define STR_RES_3_8 111  // 3/8
#define STR_RES_1_3 112  // 1/3
#define STR_RES_1_4 113  // 1/4
#define STR_RES_1_6 114  // 1/6
#define STR_RES_1_8 115  // 1/8
#define STR_RES__12 116  // /12
#define STR_RES__16 117  // /16
#define STR_RES__24 118  // /24
#define STR_RES__32 119  // /32
#define STR_RES__48 120  // /48
#define STR_RES__96 121  // /96
#define STR_RES_REP 122  // rep
#define STR_RES_TRS 123  // trs
#define STR_RES_DPL 124  // dpl
#define STR_RES_OFF_ 125  // off_
#define STR_RES_MIR 126  // mir
#define STR_RES_ALT 127  // alt
#define STR_RES_TRK 128  // trk
#define STR_RES___RND 129  //   rnd
#define STR_RES_ROO 130  // roo
#define STR_RES_SCL 131  // scl
#define STR_RES_VOI 132  // voi
#define STR_RES_HRM 133  // hrm
#define STR_RES_CHR 134  // chr
#define STR_RES_ION 135  // ion
#define STR_RES_DOR 136  // dor
#define STR_RES_PHR 137  // phr
#define STR_RES_LYD 138  // lyd
#define STR_RES_MIX 139  // mix
#define STR_RES_AEO 140  // aeo
#define STR_RES_LOC 141  // loc
#define STR_RES_BMJ 142  // bmj
#define STR_RES_BMN 143  // bmn
#define STR_RES_PMJ 144  // pmj
#define STR_RES_PMN 145  // pmn
#define STR_RES_BHR 146  // bhr
#define STR_RES_SHR 147  // shr
#define STR_RES_RUP 148  // rup
#define STR_RES_TOD 149  // tod
#define STR_RES_RAG 150  // rag
#define STR_RES_KAA 151  // kaa
#define STR_RES_MEG 152  // meg
#define STR_RES_MLK 153  // mlk
#define STR_RES_DPK 154  // dpk
#define STR_RES_FLK 155  // flk
#define STR_RES_JAP 156  // jap
#define STR_RES_GAM 157  // gam
#define STR_RES_WHL 158  // whl
#define STR_RES_C 159  // C
#define STR_RES_C_ 160  // C#
#define STR_RES_D 161  // D
#define STR_RES_D_ 162  // D#
#define STR_RES_E 163  // E
#define STR_RES_F 164  // F
#define STR_RES_F_ 165  // F#
#define STR_RES_G 166  // G
#define STR_RES_G_ 167  // G#
#define STR_RES_A 168  // A
#define STR_RES_A_ 169  // A#
#define STR_RES_B 170  // B
#define STR_RES__C 171  //  C
#define STR_RES_DB 172  // Db
#define STR_RES__D 173  //  D
#define STR_RES_EB 174  // Eb
#define STR_RES__E 175  //  E
#define STR_RES__F 176  //  F
#define STR_RES_GB 177  // Gb
#define STR_RES__G 178  //  G
#define STR_RES_AB 179  // Ab
#define STR_RES__A 180  //  A
#define STR_RES_BB 181  // Bb
#define STR_RES__B 182  //  B
#define STR_RES_KEY 183  // key
#define STR_RES__ 184  //  
#define STR_RES_STP 185  // stp
#define STR_RES_1 186  // 
#define STR_RES_2 187  // 
#define STR_RES_3 188  // 
#define STR_RES_4 189  // 
#define STR_RES_AM1 190  // am1
#define STR_RES_AM2 191  // am2
#define STR_RES_AM3 192  // am3
#define STR_RES_AM4 193  // am4
#define STR_RES_CE1 194  // ce1
#define STR_RES_CE2 195  // ce2
#define STR_RES_CE3 196  // ce3
#define STR_RES_CE4 197  // ce4
#define STR_RES_WF1 198  // wf1
#define STR_RES_WF2 199  // wf2
#define STR_RES_WF3 200  // wf3
#define STR_RES_WF4 201  // wf4
#define STR_RES_RT1 202  // rt1
#define STR_RES_RT2 203  // rt2
#define STR_RES_RT3 204  // rt3
#define STR_RES_RT4 205  // rt4
#define STR_RES_SY1 206  // sy1
#define STR_RES_SY2 207  // sy2
#define STR_RES_SY3 208  // sy3
#define STR_RES_SY4 209  // sy4
#define STR_RES_TRI 210  // tri
#define STR_RES_SQR 211  // sqr
#define STR_RES_RMP 212  // rmp
#define STR_RES_SIN 213  // sin
#define STR_RES_SI2 214  // si2
#define STR_RES_SI3 215  // si3
#define STR_RES_SI5 216  // si5
#define STR_RES_GG1 217  // gg1
#define STR_RES_GG2 218  // gg2
#define STR_RES_BT1 219  // bt1
#define STR_RES_BT2 220  // bt2
#define STR_RES_SP1 221  // sp1
#define STR_RES_SP2 222  // sp2
#define STR_RES_LP1 223  // lp1
#define STR_RES_LP2 224  // lp2
#define STR_RES_RS1 225  // rs1
#define STR_RES_RS2 226  // rs2
#define STR_RES_S_H 227  // s&h
#define STR_RES_RES 228  // res
#define STR_RES_FRE 229  // fre
#define STR_RES__NOT 230  //  not
#define STR_RES_CHD 231  // chd
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
