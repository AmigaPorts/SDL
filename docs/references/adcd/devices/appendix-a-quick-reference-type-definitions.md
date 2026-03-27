---
title: Appendix A. Quick Reference / Type Definitions
manual: devices
chapter: devices
section: appendix-a-quick-reference-type-definitions
functions: []
libraries: []
---

# Appendix A. Quick Reference / Type Definitions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's a collection of the C type definitions in this memo.  In the
"struct" type definitions, fields are filed in the order shown.  A UBYTE
field is packed into an 8-bit byte.  Programs should set all "pad" fields
to 0.


```c
    #define ID_SMUS MakeID('S', 'M', 'U', 'S')
    #define ID_SHDR MakeID('S', 'H', 'D', 'R')

    typedef struct {
```
	UWORD tempo;	/* tempo, 128ths quarter note/minute 		*/
	UBYTE volume;	/* overall playback volume 0 through 127 	*/
	UBYTE ctTrack;	/* count of tracks in the score			*/
	} SScoreHeader;

```c
    #define ID_NAME MakeID('N', 'A', 'M', 'E')
    /* NAME chunk contains a CHAR[], the musical score's name.		*/

    #define ID_Copyright MakeID('(', 'c', ')', ' ')
    /* "(c) " chunk contains a CHAR[], the FORM's copyright notice.	*/

    #define ID_AUTH MakeID('A', 'U', 'T', 'H')
    /* AUTH chunk contains a CHAR[], the name of the score's author.	*/

    #define ID_ANNO MakeID('A', 'N', 'N', 'O')
    /* ANNO chunk contains a CHAR[], author's text annotations.		*/

    #define ID_INS1 MakeID('I', 'N', 'S', '1')
    /* Values for the RefInstrument field "type".			*/

    #define INS1_Name 0	/* just use the name; ignore data1, data2	*/
    #define INS1_MIDI 1	/* <data1, data2> = MIDI <channel, preset>	*/


    typedef struct {
```
	UBYTE register;	    /* set this instrument register number 	*/
	UBYTE type;	    /* instrument reference type 		*/
	UBYTE data1, data2; /* depends on the "type" field 		*/
	CHAR  name[];	    /* instrument name 				*/
	} RefInstrument;

```c
    #define ID_TRAK MakeID('T', 'R', 'A', 'K')
    /* TRAK chunk contains an SEvent[].					*/

    /* SEvent: Simple musical event.					*/
    typedef struct {
```
	UBYTE sID;	/* SEvent type code				*/
	UBYTE data;	/* sID-dependent data				*/
	} SEvent;


    /* SEvent type codes "sID".						*/
    #define SID_FirstNote     0
    #define SID_LastNote    127	/* sIDs in the range SID_FirstNote through
				 * SID_LastNote (sign bit = 0) are notes.
				 * sID is the MIDI tone number (pitch).	*/
```c
    #define SID_Rest        128	/* a rest (same data format as a note).	*/

    #define SID_Instrument  129	/* set instrument number for this track.*/
    #define SID_TimeSig     130	/* set time signature for this track.	*/
    #define SID_KeySig      131	/* set key signature for this track.	*/
    #define SID_Dynamic     132	/* set volume for this track.		*/
    #define SID_MIDI_Chnl   133	/* set MIDI channel number (sequencers)	*/
    #define SID_MIDI_Preset 134	/* set MIDI preset number (sequencers)	*/
    #define SID_Clef        135	/* inline clef change.			*
```
				 * 0=Treble, 1=Bass, 2=Alto, 3=Tenor.	*/
```c
    #define SID_Tempo       136	/* Inline tempo in beats per minute.	*/

    /* SID values 144 through 159: reserved for Instant Music SEvents.	*/

    /* Remaining sID values up through 254: reserved for future
     * standardization.							*/

    #define SID_Mark        255	/* sID reserved for an end-mark in RAM.	*/

    /* SID_FirstNote..SID_LastNote, SID_Rest SEvents			*/

    typedef struct {
```
	UBYTE    tone;		/* MIDI tone number 0 to 127; 128 = rest */
	unsigned chord    :1,	/* 1 = a chorded note 			 */
```c
        	 tieOut   :1,	/* 1 = tied to the next note or chord 	 */
        	 nTuplet  :2,	/* 0 = none, 1 = triplet, 2 = quintuplet,
```
				 * 3 = septuplet 			 */
```c
        	 dot      :1,	/* dotted note; multiply duration by 3/2 */
        	 division :3;	/* basic note duration is 2-division:
```
				 * 0 = whole note, 1 = half note,
				 * 2 = quarter note, 7 = 128th note */
		} SNote;


```c
    #define noteChord  (1<<7)   /* note is chorded to next note          */

    #define noteTieOut (1<<6)   /* tied to next note/chord               */

    #define noteNShift 4        /* shift count for nTuplet field         */

    #define noteN3     (1<<noteNShift)  /* note is a triplet             */
    #define noteN5     (2<<noteNShift)  /* note is a quintuplet          */
    #define noteN7     (3<<noteNShift)  /* note is a septuplet           */

    #define noteNMask  noteN7   /* bit mask for the nTuplet field        */

    #define noteDot    (1<<3)   /* note is dotted                        */



    #define noteD1     0        /* whole note division                   */
    #define noteD2     1        /* half note division                    */
    #define noteD4     2        /* quarter note division                 */
    #define noteD8     3        /* eighth note division                  */
    #define noteD16    4        /* sixteenth note division               */
    #define noteD32    5        /* thirty-secondth note division         */
    #define noteD64    6        /* sixty-fourth note division            */
    #define noteD128   7        /* 1/128 note division                   */
    #define noteDMask  noteD128 /* bit mask for the division field       */


    #define noteDurMask 0x3F    /* mask for combined duration fields     */


    /* SID_Instrument SEvent                                             */
    /* "data" value is an instrument register number 0 through 255.      */

    /* SID_TimeSig SEvent                                                */
    typedef struct {
        UBYTE    type;          /* = SID_TimeSig                         */
        unsigned timeNSig :5,   /* time sig. "numerator" is timeNSig + 1 */
                 timeDSig :3;   /* time sig. "denominator" is 2^timeDSig: *
                                 * 0 = whole note, 1 = half note, 2 =     *
                                 * quarter note,.... 7 = 128th note      */
        } STimeSig;

    #define timeNMask  0xF8     /* bit mask for the timeNSig field       */
    #define timeNShift 3        /* shift count for  timeNSig field       */

    #define timeDMask  0x07     /* bit mask for the timeDSig field       */

    /* SID_KeySig SEvent                                                 */
    /* "data" value 0 = Cmaj; 1 through 7 = G,D,A,E,B,F#,C#;             *
     * 8 through 14 = F,Bb,Eb,Ab,Db,Gb,Cb.                               */

    /* SID_Dynamic SEvent                                                */
    /* "data" value is a MIDI key velocity 0..127.                       */
```
