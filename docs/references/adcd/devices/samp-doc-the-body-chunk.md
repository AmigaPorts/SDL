---
title: SAMP.doc / The BODY Chunk
manual: devices
chapter: devices
section: samp-doc-the-body-chunk
functions: []
libraries: []
---

# SAMP.doc / The BODY Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The "BODY" chunk is CONSIDERABLY different than the "8SVX" form. Like all
chunks it has an ID.


```c
    #define ID_BODY MakeID('B','O','D','Y')
```
Every wave has an 80 byte waveHeader, followed by its data. The waveHeader
structure is as follows:


```c
    typedef struct {
      ULONG  WaveSize;    /* total # of BYTES in the wave (MUST be even) */
      UWORD  MidiSampNum; /* ONLY USED for Midi Dumps */
      UBYTE  LoopType,    /* ONLY USED for Midi Dumps */
      InsType;            /* Used for searching for a certain instrument */
      ULONG  Period,      /* in nanoseconds at original pitch */
      Rate,               /* # of samples per second at original pitch */
      LoopStart,          /* an offset in BYTES (from the beginning of the
                             of the wave) where the looping portion of the
                               wave begins. Set to WaveSize if no loop. */
      LoopEnd;            /* an offset in BYTES (from the beginning of the
                             of the wave) where the looping portion of the
                             wave ends. Set to WaveSize if no loop. */
      UBYTE  RootNote,    /* the Midi Note # that plays back orig. pitch */
      VelStart;           /* 0 = NO velocity effect, 128 =
                                  negative direction, 64 = positive
                                  direction (it must be one of these 3) */
      UWORD VelTable[16]; /* contains 16 successive offset values
                                 in BYTES from the beginning of the wave */

     /* The ATAK and RLSE segments contain an EGPoint[] piece-wise
        linear envelope just like 8SVX. The structure of an EGPoint[]
        is the same as 8SVX. See that document for details. */

      ULONG  ATAKsize,    /* # of BYTES in subsequent ATAK envelope.
                                If 0, then no ATAK data for this wave. */
      RLSEsize,           /* # of BYTES in subsequent RLSE envelope
                                If 0, then no RLSE envelope follows */

     /* The FATK and FRLS segments contain an EGPoint[] piece-wise
        linear envelope for filtering purposes. This is included in
        the hope that future Amiga audio will incorporate a VCF
        (Voltage Controlled Filter). Until then, if you are doing any
        non-realtime digital filtering, you could store info here. */

     sizeOfFATK,          /* # of BYTES in FATK segment */
     sizeOfFRLS,          /* # of BYTES in FRLS segment */

     USERsize;            /*   # of BYTES in the following data
                                 segment (not including USERtype).
                                 If zero, then no user data */
     UWORD  USERtype;     /* See explanation below. If USERsize
                                = 0, then ignore this. */

    /* End of the waveHeader. */

    /* The data for any ATAK, RLSE, FATK, FRLS, USER, and the actual wave
       data for wave #1 follows in this order:
       Now list each EGPoint[] (if any) for the VCA's
       (Voltage Controlled Amp) attack portion.
       Now list each EGPoint[] for the VCA's (Voltage Controlled Amp)
       release portion.
       List EGPoints[] (if any) for FATK.
       List EGPoints[] if any for FRLS */
```
   /*  Now include the user data here if there is any.Just pad it out to an
   even number of bytes and have USERsize reflect that. Finally,here is the
   actual sample data for the wave. The size (in BYTES) of this data is
   WaveSize. It MUST be padded out to an even number of bytes. */


```c
    } WaveFormInfo;
```
 /* END OF WAVE #1 */

 /* The waveHeader and data for the next wave would now follow. It is

    the same form as the first wave */
In assembly,  the BODY chunk looks like this:

           CNOP 0,2
BodyHEADER dc.b 'BODY'
sizeOfBody dc.l  [total bytes in the BODY chunk not counting 8 byte header]

   ; Now for the first wave
WaveSize       dc.l  ;[total # of BYTES in this wave (MUST be even)]
MidiSampNum    dc.w  ;[from Midi Sample Dump]  ; ONLY USED for Midi Dumps
LoopType       dc.b  ;[0 or 1]                 ; ONLY USED for Midi Dumps
InsType        dc.b  0
Period         dc.l  ;[period in nanoseconds at original pitch]
Rate           dc.l  ;[# of samples per second at original pitch]
LoopStart      dc.l    ;[an offset in BYTES (from the beginning of the
```c
                       ; of the wave) to where the looping
                       ; portion of the wave begins.]
```
LoopEnd        dc.l    ;[an offset in BYTES (from the beginning of the
```c
                       ; of the wave) to where the looping
                       ; portion of the wave ends]
```
RootNote       dc.b    ;[the Midi Note # that plays back original pitch]
VelStart       dc.b    ;[0, 64, or 128]
VelTable       dc.w    ;[first velocity offset]

```c
               dc.w    ;[second velocity offset]...etc
               ds.w 14 ;...for a TOTAL of 16 velocity offsets
```
ATAKsize       dc.l  ;# of BYTES in subsequent ATAK envelope.
```c
                     ;If 0, then no ATAK data for this wave.
```
RLSEsize       dc.l  ;# of BYTES in subsequent RLSE envelope
```c
                     ;If 0, then no RLSE data
```
FATKsize       dc.l  ;# of BYTES in FATK segment
FRLSsize       dc.l  ;# of BYTES in FRLS segment
USERsize       dc.l  ;# of BYTES in the following User data
```c
                     ;segment (not including USERtype).
                     ;If zero, then no user data
```
USERtype       dc.w  ; See explanation below. If USERsize

```c
                  ; = 0, then ignore this.
```
  ;Now include the EGpoints[] (data) for the ATAK if any
  ;Now the EGpoints for the RLSE
  ;Now the EGpoints for the FATK
  ;Now the EGpoints for the FLSR
  ;Now include the user data here if there is any. Just pad
  ;it out to an even number of bytes.
  ;After the userdata (if any) is the actual sample data for
  ;the wave. The size (in BYTES) of this segment is WaveSize.
  ;It MUST be padded out to an even number of bytes.

  ; END OF WAVE #1

