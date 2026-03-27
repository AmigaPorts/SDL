---
title: SAMP.doc / Making A Transpose Table
manual: devices
chapter: devices
section: samp-doc-making-a-transpose-table
functions: []
libraries: []
---

# SAMP.doc / Making A Transpose Table

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In order to allow a wave to playback over a range of musical notes, (+/-
semitones), its playback rate must be raised or lowered by a set amount.
From one semitone to the next, this set amount is by a factor of the 12th
root of 2 (assuming a western, equal-tempered scale). Here is a table that
shows what factor would need to be multiplied by the sampling rate in
order to transpose the wave's pitch.

    Pitch in relation to the Root     Multiply Rate by this amount
   -------------------------------   ------------------------------
     DOWN 6     semitones              0.5
     DOWN 5 1/2 semitones              0.529731547
     DOWN 5     semitones              0.561231024
     DOWN 4 1/2 semitones              0.594603557
     DOWN 4     semitones              0.629960525
     DOWN 3 1/2 semitones              0.667419927
     DOWN 3     semitones              0.707106781
     DOWN 2 1/2 semitones              0.749153538
     DOWN 2     semitones              0.793700526
     DOWN 1 1/2 semitones              0.840896415
     DOWN 1     semitones              0.890898718
     DOWN 1/2   semitone               0.943874312
  ORIGINAL_PITCH                       1.0           /* rootnote's pitch */

     UP   1/2   semitone               1.059463094
     UP   1     semitones              1.122562048
     UP   1 1/2 semitones              1.189207115
     UP   2     semitones              1.259921050
     UP   2 1/2 semitones              1.334839854
     UP   3     semitones              1.414213562
     UP   3 1/2 semitones              1.498307077
     UP   4     semitones              1.587401052
     UP   4 1/2 semitones              1.681792830
     UP   5     semitones              1.781797436
     UP   5 1/2 semitones              1.887748625
     UP   6     semitones              2
For example, if the wave's Rate is 18000 hz, and you wish to play the wave
UP 1 semitone, then the playback rate is:


```c
    18000 x 1.122562048 = 20206.11686 hz
```
The sampling period for the Amiga is therefore:


```c
    (1/20206.11686)/.279365 = .000177151
```
and to send it to the Audio Device, it is rounded and expressed in micro-
seconds: 177

Obviously, this involves floating point math which can be time consuming
and impractical for outputing sound in real-time.  A better method is to
construct a transpose table that contains the actual periods already
calculated for every semitone.  The drawback of this method is that you
need a table for EVERY DIFFERENT Rate in the SAMP file.  If all the Rates
in the file happened to be the same, then only one table would be needed.
Let's assume that this is the case, and that the Rate = 18000 hz. Here is
a table containing enough entries to transpose the waves +/- 6 semitones.

  Pitch in relation to the Root     Amiga Period (assuming rate = 18000 hz)
  -----------------------------     ---------------------------------------

```c
    Transposition_table[TRANS_TABLE_SIZE]={
    /* DOWN 6     semitones  */            398,
    /* DOWN 5 1/2 semitones  */            375,
    /* DOWN 5     semitones  */            354,
    /* DOWN 4 1/2 semitones  */            334,
    /* DOWN 4     semitones  */            316,
    /* DOWN 3 1/2 semitones  */            298,
    /* DOWN 3     semitones  */            281,
    /* DOWN 2 1/2 semitones  */            265,
    /* DOWN 2     semitones  */            251,
    /* DOWN 1 1/2 semitones  */            236,
    /* DOWN 1     semitones  */            223,
    /* DOWN 1/2   semitone   */            211,
    /* ORIGINAL_PITCH        */            199,    /* rootnote's pitch */
    /* UP   1/2   semitone   */            187,
    /* UP   1     semitones  */            177,
    /* UP   1 1/2 semitones  */            167,
    /* UP   2     semitones  */            157,
    /* UP   2 1/2 semitones  */            148,
    /* UP   3     semitones  */            141,
    /* UP   3 1/2 semitones  */            133,
     /* Since the minimum Amiga period = 127 the following
        are actually out of range. */
    /* UP   4     semitones  */            125,
    /* UP   4 1/2 semitones  */            118,
    /* UP   5     semitones  */            112,
    /* UP   5 1/2 semitones  */            105,
    /* UP   6     semitones  */            99   };
```
Let's assume that (according to the PlayMap) midi note #40 is set to play
wave number 3. Upon examining wave 3's structure, we discover that the
Rate = 18000, and the RootNote = 38. Here is how the Amiga sampling period
is calulated using the above 18000hz "transpose chart" in C:


   /* MidiNoteNumber is the received midi note's number (here 40) */

   #define ORIGINAL_PITCH     TRANS_TABLE_SIZE/2 + 1
  /* TRANS_TABLE_SIZE is the number of entries in the transposition table

```c
     (dynamic, ie this can change with the application) */
```
  transposeAmount = (LONG) (MidiNoteNumber - rootNote);

                                             /* make it a SIGNED LONG */
  amigaPeriod     = Transposition_table[ORIGINAL_PITCH + transposeAmount];


In assembly, the 18000hz transpose chart and above example would be:


Table       dc.w  398
            dc.w  375
            dc.w  354
            dc.w  334
            dc.w  316
            dc.w  298
            dc.w  281
            dc.w  265
            dc.w  251
            dc.w  236
            dc.w  223
            dc.w  211
ORIGINAL_PITCH  dc.w  199   ; rootnote's pitch
            dc.w  187
            dc.w  177
            dc.w  167
            dc.w  157
            dc.w  148
            dc.w  141
            dc.w  133
 ; Since the minimum Amiga period = 127, the following
 ; are actually out of range.

            dc.w  125
            dc.w  118
            dc.w  112
            dc.w  105
            dc.w  99
  lea     ORIGINAL_PITCH,a0
  move.b  MidiNoteNumber,d0  ;the received note number
  sub.b   RootNote,d0        ;subtract the wave's root note
  ext.w   d0
  ext.l   d0                 ;make it a signed LONG
  add.l   d0,d0              ;x 2 in order to fetch a WORD
  adda.l  d0,a0
  move.w  (a0),d0            ;the Amiga Period (WORD)


Note that these examples don't check to see if the transpose amount is
beyond the number of entries in the transpose table. Nor do they check if
the periods in the table are out of range of the Amiga hardware.

