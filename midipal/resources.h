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
#define STR_RES_SNDOFF 18  // sndOff
#define STR_RES_RSTCTR 19  // rstCtr
#define STR_RES_NOTOFF 20  // notOff
#define STR_RES_OMNOFF 21  // omnOff
#define STR_RES_OMNION 22  // omniOn
#define STR_RES_MONOON 23  // monoOn
#define STR_RES_POLYON 24  // polyOn
#define STR_RES_SYSX__ 25  // sysx..
#define STR_RES__SYSX_ 26  // .sysx.
#define STR_RES___SYSX 27  // ..sysx
#define STR_RES_START 28  // start
#define STR_RES_STOP 29  // stop
#define STR_RES_CONT_ 30  // cont.
#define STR_RES_RESET 31  // reset
#define STR_RES_CHN 32  // chn
#define STR_RES_ALL 33  // all
#define STR_RES_FLT 34  // flt
#define STR_RES_OFF 35  // off
#define STR_RES_ON 36  // on
#define STR_RES_NO 37  // no
#define STR_RES_YES 38  // yes
#define STR_RES_RUN 39  // run
#define STR_RES_BPM 40  // bpm
#define STR_RES_GRV 41  // grv
#define STR_RES_AMT 42  // amt
#define STR_RES_SWG 43  // swg
#define STR_RES_SHF 44  // shf
#define STR_RES_PSH 45  // psh
#define STR_RES_LAG 46  // lag
#define STR_RES_HUM 47  // hum
#define STR_RES_MNK 48  // mnk
#define STR_RES_VAL 49  // val
#define STR_RES_NUM 50  // num
#define STR_RES_TYP 51  // typ
#define STR_RES_CC_ 52  // cc#
#define STR_RES_NRP 53  // nrp
#define STR_RES_MIN 54  // min
#define STR_RES_MAX 55  // max
#define STR_RES_LVL 56  // lvl
#define STR_RES_RST 57  // rst
#define STR_RES_SORRY___ 58  // sorry...
#define STR_RES_PERFECT_ 59  // perfect!
#define STR_RES_NOT_BAD_ 60  // not bad!
#define STR_RES_MOD 61  // mod
#define STR_RES_PTN 62  // ptn
#define STR_RES_EUC 63  // euc
#define STR_RES_INT 64  // int
#define STR_RES_EXT 65  // ext
#define STR_RES_CLK 66  // clk
#define STR_RES_PT1 67  // pt1
#define STR_RES_PT2 68  // pt2
#define STR_RES_PT3 69  // pt3
#define STR_RES_PT4 70  // pt4
#define STR_RES_CC1 71  // cc1
#define STR_RES_CC2 72  // cc2
#define STR_RES_CC3 73  // cc3
#define STR_RES_CC4 74  // cc4
#define STR_RES_CC5 75  // cc5
#define STR_RES_CC6 76  // cc6
#define STR_RES_CC7 77  // cc7
#define STR_RES_CC8 78  // cc8
#define STR_RES_INP 79  // inp
#define STR_RES_OUT 80  // out
#define STR_RES_SPL 81  // spl
#define STR_RES_LOW 82  // low
#define STR_RES_UPP 83  // upp
#define STR_RES__AMT 84  //  amt
#define STR_RES_NOT 85  // not
#define STR_RES_VEL 86  // vel
#define STR_RES__C1 87  // #c1
#define STR_RES__C2 88  // #c2
#define STR_RES_CYC 89  // cyc
#define STR_RES_POL 90  // pol
#define STR_RES_RND 91  // rnd
#define STR_RES_STA 92  // sta
#define STR_RES_DIR 93  // dir
#define STR_RES_UP 94  // up
#define STR_RES_DWN 95  // dwn
#define STR_RES_U_D 96  // u&d
#define STR_RES__RND 97  //  rnd
#define STR_RES_OCT 98  // oct
#define STR_RES_DUR 99  // dur
#define STR_RES_DIV 100  // div
#define STR_RES_4_1 101  // 4/1
#define STR_RES_3_1 102  // 3/1
#define STR_RES_2_1 103  // 2/1
#define STR_RES_3_2 104  // 3/2
#define STR_RES_1_1 105  // 1/1
#define STR_RES_3_4 106  // 3/4
#define STR_RES_2_3 107  // 2/3
#define STR_RES_1_2 108  // 1/2
#define STR_RES_3_8 109  // 3/8
#define STR_RES_1_3 110  // 1/3
#define STR_RES_1_4 111  // 1/4
#define STR_RES_1_6 112  // 1/6
#define STR_RES_1_8 113  // 1/8
#define STR_RES__12 114  // /12
#define STR_RES__16 115  // /16
#define STR_RES__24 116  // /24
#define STR_RES__32 117  // /32
#define STR_RES__48 118  // /48
#define STR_RES__96 119  // /96
#define STR_RES_REP 120  // rep
#define STR_RES_TRS 121  // trs
#define STR_RES_OFF_ 122  // off_
#define STR_RES_MIR 123  // mir
#define STR_RES_ALT 124  // alt
#define STR_RES_TRK 125  // trk
#define STR_RES___RND 126  //   rnd
#define STR_RES_ROO 127  // roo
#define STR_RES_SCL 128  // scl
#define STR_RES_VOI 129  // voi
#define STR_RES_HRM 130  // hrm
#define STR_RES_CHR 131  // chr
#define STR_RES_ION 132  // ion
#define STR_RES_DOR 133  // dor
#define STR_RES_PHR 134  // phr
#define STR_RES_LYD 135  // lyd
#define STR_RES_MIX 136  // mix
#define STR_RES_AEO 137  // aeo
#define STR_RES_LOC 138  // loc
#define STR_RES_BMJ 139  // bmj
#define STR_RES_BMN 140  // bmn
#define STR_RES_PMJ 141  // pmj
#define STR_RES_PMN 142  // pmn
#define STR_RES_BHR 143  // bhr
#define STR_RES_SHR 144  // shr
#define STR_RES_RUP 145  // rup
#define STR_RES_TOD 146  // tod
#define STR_RES_RAG 147  // rag
#define STR_RES_KAA 148  // kaa
#define STR_RES_MEG 149  // meg
#define STR_RES_MLK 150  // mlk
#define STR_RES_DPK 151  // dpk
#define STR_RES_FLK 152  // flk
#define STR_RES_JAP 153  // jap
#define STR_RES_GAM 154  // gam
#define STR_RES_WHL 155  // whl
#define STR_RES_C 156  // C
#define STR_RES_C_ 157  // C#
#define STR_RES_D 158  // D
#define STR_RES_D_ 159  // D#
#define STR_RES_E 160  // E
#define STR_RES_F 161  // F
#define STR_RES_F_ 162  // F#
#define STR_RES_G 163  // G
#define STR_RES_G_ 164  // G#
#define STR_RES_A 165  // A
#define STR_RES_A_ 166  // A#
#define STR_RES_B 167  // B
#define STR_RES__C 168  //  C
#define STR_RES_DB 169  // Db
#define STR_RES__D 170  //  D
#define STR_RES_EB 171  // Eb
#define STR_RES__E 172  //  E
#define STR_RES__F 173  //  F
#define STR_RES_GB 174  // Gb
#define STR_RES__G 175  //  G
#define STR_RES_AB 176  // Ab
#define STR_RES__A 177  //  A
#define STR_RES_BB 178  // Bb
#define STR_RES__B 179  //  B
#define STR_RES__ 180  //  
#define STR_RES_STP 181  // stp
#define STR_RES_1 182  // 
#define STR_RES_2 183  // 
#define STR_RES_3 184  // 
#define STR_RES_4 185  // 
#define STR_RES_AM1 186  // am1
#define STR_RES_AM2 187  // am2
#define STR_RES_AM3 188  // am3
#define STR_RES_AM4 189  // am4
#define STR_RES_CE1 190  // ce1
#define STR_RES_CE2 191  // ce2
#define STR_RES_CE3 192  // ce3
#define STR_RES_CE4 193  // ce4
#define STR_RES_WF1 194  // wf1
#define STR_RES_WF2 195  // wf2
#define STR_RES_WF3 196  // wf3
#define STR_RES_WF4 197  // wf4
#define STR_RES_RT1 198  // rt1
#define STR_RES_RT2 199  // rt2
#define STR_RES_RT3 200  // rt3
#define STR_RES_RT4 201  // rt4
#define STR_RES_SY1 202  // sy1
#define STR_RES_SY2 203  // sy2
#define STR_RES_SY3 204  // sy3
#define STR_RES_SY4 205  // sy4
#define STR_RES_TRI 206  // tri
#define STR_RES_SQR 207  // sqr
#define STR_RES_RMP 208  // rmp
#define STR_RES_SIN 209  // sin
#define STR_RES_SI2 210  // si2
#define STR_RES_SI3 211  // si3
#define STR_RES_SI5 212  // si5
#define STR_RES_GR1 213  // gr1
#define STR_RES_GR2 214  // gr2
#define STR_RES_BT1 215  // bt1
#define STR_RES_BT2 216  // bt2
#define STR_RES_SP1 217  // sp1
#define STR_RES_SP2 218  // sp2
#define STR_RES_LP1 219  // lp1
#define STR_RES_LP2 220  // lp2
#define STR_RES_RS1 221  // rs1
#define STR_RES_RS2 222  // rs2
#define STR_RES_RES 223  // res
#define STR_RES_FRE 224  // fre
#define STR_RES__NOT 225  //  not
#define STR_RES_CHD 226  // chd
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
