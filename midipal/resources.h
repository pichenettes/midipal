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
#define STR_RES_TAP 46  // tap
#define STR_RES_SWG 47  // swg
#define STR_RES_SHF 48  // shf
#define STR_RES_PSH 49  // psh
#define STR_RES_LAG 50  // lag
#define STR_RES_HUM 51  // hum
#define STR_RES_MNK 52  // mnk
#define STR_RES_VAL 53  // val
#define STR_RES_NUM 54  // num
#define STR_RES_TYP 55  // typ
#define STR_RES_CC_ 56  // cc#
#define STR_RES_NRP 57  // nrp
#define STR_RES_MIN 58  // min
#define STR_RES_MAX 59  // max
#define STR_RES_LVL 60  // lvl
#define STR_RES_RST 61  // rst
#define STR_RES_SORRY___ 62  // sorry...
#define STR_RES_PERFECT_ 63  // perfect!
#define STR_RES_NOT_BAD_ 64  // not bad!
#define STR_RES_MOD 65  // mod
#define STR_RES_PTN 66  // ptn
#define STR_RES_EUC 67  // euc
#define STR_RES_INT 68  // int
#define STR_RES_EXT 69  // ext
#define STR_RES_CLK 70  // clk
#define STR_RES_PT1 71  // pt1
#define STR_RES_PT2 72  // pt2
#define STR_RES_PT3 73  // pt3
#define STR_RES_PT4 74  // pt4
#define STR_RES_CC1 75  // cc1
#define STR_RES_CC2 76  // cc2
#define STR_RES_CC3 77  // cc3
#define STR_RES_CC4 78  // cc4
#define STR_RES_CC5 79  // cc5
#define STR_RES_CC6 80  // cc6
#define STR_RES_CC7 81  // cc7
#define STR_RES_CC8 82  // cc8
#define STR_RES_INP 83  // inp
#define STR_RES_OUT 84  // out
#define STR_RES_SPL 85  // spl
#define STR_RES_LOW 86  // low
#define STR_RES_UPP 87  // upp
#define STR_RES__AMT 88  //  amt
#define STR_RES_NOT 89  // not
#define STR_RES_VEL 90  // vel
#define STR_RES__C1 91  // #c1
#define STR_RES__C2 92  // #c2
#define STR_RES_CYC 93  // cyc
#define STR_RES_POL 94  // pol
#define STR_RES_RND 95  // rnd
#define STR_RES_STA 96  // sta
#define STR_RES_DIR 97  // dir
#define STR_RES_UP 98  // up
#define STR_RES_DWN 99  // dwn
#define STR_RES_U_D 100  // u&d
#define STR_RES__RND 101  //  rnd
#define STR_RES_OCT 102  // oct
#define STR_RES_DUR 103  // dur
#define STR_RES_DIV 104  // div
#define STR_RES_4_1 105  // 4/1
#define STR_RES_3_1 106  // 3/1
#define STR_RES_2_1 107  // 2/1
#define STR_RES_3_2 108  // 3/2
#define STR_RES_1_1 109  // 1/1
#define STR_RES_3_4 110  // 3/4
#define STR_RES_2_3 111  // 2/3
#define STR_RES_1_2 112  // 1/2
#define STR_RES_3_8 113  // 3/8
#define STR_RES_1_3 114  // 1/3
#define STR_RES_1_4 115  // 1/4
#define STR_RES_1_6 116  // 1/6
#define STR_RES_1_8 117  // 1/8
#define STR_RES__12 118  // /12
#define STR_RES__16 119  // /16
#define STR_RES__24 120  // /24
#define STR_RES__32 121  // /32
#define STR_RES__48 122  // /48
#define STR_RES__96 123  // /96
#define STR_RES_REP 124  // rep
#define STR_RES_TRS 125  // trs
#define STR_RES_DPL 126  // dpl
#define STR_RES_OFF_ 127  // off_
#define STR_RES_MIR 128  // mir
#define STR_RES_ALT 129  // alt
#define STR_RES_TRK 130  // trk
#define STR_RES___RND 131  //   rnd
#define STR_RES_ROO 132  // roo
#define STR_RES_SCL 133  // scl
#define STR_RES_VOI 134  // voi
#define STR_RES_HRM 135  // hrm
#define STR_RES_CHR 136  // chr
#define STR_RES_ION 137  // ion
#define STR_RES_DOR 138  // dor
#define STR_RES_PHR 139  // phr
#define STR_RES_LYD 140  // lyd
#define STR_RES_MIX 141  // mix
#define STR_RES_AEO 142  // aeo
#define STR_RES_LOC 143  // loc
#define STR_RES_BMJ 144  // bmj
#define STR_RES_BMN 145  // bmn
#define STR_RES_PMJ 146  // pmj
#define STR_RES_PMN 147  // pmn
#define STR_RES_BHR 148  // bhr
#define STR_RES_SHR 149  // shr
#define STR_RES_RUP 150  // rup
#define STR_RES_TOD 151  // tod
#define STR_RES_RAG 152  // rag
#define STR_RES_KAA 153  // kaa
#define STR_RES_MEG 154  // meg
#define STR_RES_MLK 155  // mlk
#define STR_RES_DPK 156  // dpk
#define STR_RES_FLK 157  // flk
#define STR_RES_JAP 158  // jap
#define STR_RES_GAM 159  // gam
#define STR_RES_WHL 160  // whl
#define STR_RES_C 161  // C
#define STR_RES_C_ 162  // C#
#define STR_RES_D 163  // D
#define STR_RES_D_ 164  // D#
#define STR_RES_E 165  // E
#define STR_RES_F 166  // F
#define STR_RES_F_ 167  // F#
#define STR_RES_G 168  // G
#define STR_RES_G_ 169  // G#
#define STR_RES_A 170  // A
#define STR_RES_A_ 171  // A#
#define STR_RES_B 172  // B
#define STR_RES__C 173  //  C
#define STR_RES_DB 174  // Db
#define STR_RES__D 175  //  D
#define STR_RES_EB 176  // Eb
#define STR_RES__E 177  //  E
#define STR_RES__F 178  //  F
#define STR_RES_GB 179  // Gb
#define STR_RES__G 180  //  G
#define STR_RES_AB 181  // Ab
#define STR_RES__A 182  //  A
#define STR_RES_BB 183  // Bb
#define STR_RES__B 184  //  B
#define STR_RES_KEY 185  // key
#define STR_RES__ 186  //  
#define STR_RES_STP 187  // stp
#define STR_RES_1 188  // 
#define STR_RES_2 189  // 
#define STR_RES_3 190  // 
#define STR_RES_4 191  // 
#define STR_RES_AM1 192  // am1
#define STR_RES_AM2 193  // am2
#define STR_RES_AM3 194  // am3
#define STR_RES_AM4 195  // am4
#define STR_RES_CE1 196  // ce1
#define STR_RES_CE2 197  // ce2
#define STR_RES_CE3 198  // ce3
#define STR_RES_CE4 199  // ce4
#define STR_RES_WF1 200  // wf1
#define STR_RES_WF2 201  // wf2
#define STR_RES_WF3 202  // wf3
#define STR_RES_WF4 203  // wf4
#define STR_RES_RT1 204  // rt1
#define STR_RES_RT2 205  // rt2
#define STR_RES_RT3 206  // rt3
#define STR_RES_RT4 207  // rt4
#define STR_RES_SY1 208  // sy1
#define STR_RES_SY2 209  // sy2
#define STR_RES_SY3 210  // sy3
#define STR_RES_SY4 211  // sy4
#define STR_RES_TRI 212  // tri
#define STR_RES_SQR 213  // sqr
#define STR_RES_RMP 214  // rmp
#define STR_RES_SIN 215  // sin
#define STR_RES_SI2 216  // si2
#define STR_RES_SI3 217  // si3
#define STR_RES_SI5 218  // si5
#define STR_RES_GG1 219  // gg1
#define STR_RES_GG2 220  // gg2
#define STR_RES_BT1 221  // bt1
#define STR_RES_BT2 222  // bt2
#define STR_RES_SP1 223  // sp1
#define STR_RES_SP2 224  // sp2
#define STR_RES_LP1 225  // lp1
#define STR_RES_LP2 226  // lp2
#define STR_RES_RS1 227  // rs1
#define STR_RES_RS2 228  // rs2
#define STR_RES_S_H 229  // s&h
#define STR_RES_RES 230  // res
#define STR_RES_FRE 231  // fre
#define STR_RES__NOT 232  //  not
#define STR_RES_CHD 233  // chd
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
