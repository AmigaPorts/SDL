---
title: SAMP.doc / The MHDR Chunk
manual: devices
chapter: devices
section: samp-doc-the-mhdr-chunk
functions: []
libraries: []
---

# SAMP.doc / The MHDR Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The required "MHDR" chunk immediately follows the "SAMP" header and
consists of the following components:


```c
    #define ID_MHDR MakeID('M','H','D','R')

      /* MHDR size is dependant on the size of the imbedded PlayMap. */

       typedef struct{
        UBYTE NumOfWaves, /* The number of waves in this file */
          Format,         /* # of ORIGINAL significant bits from 8-28 */
          Flags,          /* Various bits indicate various functions */
          PlayMode,       /* determines play MODE of the PlayMap */
          NumOfChans,
          Pad,
          PlayMap[128*4], /* a map of which wave numbers to use for
                           each of 128 possible Midi Notes. Default to 4 */
        } MHDRChunk;
```
The PlayMap is an array of bytes representing wave numbers. There can be a
total of 255 waves in a "SAMP" file. They are numbered from 1 to 255. A
wave number of 0 is reserved to indicate "NO WAVE". The Midi Spec 1.0
designates that there are 128 possible note numbers (pitches), 0 to 127.
The size of an MHDR's PlayMap is determined by (NumOfChans * 128). For
example, if NumOfChans = 4, then an MHDR's PlayMap is 512 bytes. There are
4 bytes in the PlayMap for EACH of the 128 Midi Note numbers. For example,
the first 4 bytes in PlayMap pertain to Midi Note #0. Of those 4 bytes,
the first byte is the wave number to play back on Amiga audio channel 0.
The second byte is the wave number to play back on Amiga audio channel 1,
etc. In this way, a single Midi Note Number could simultaneously trigger a
sound event on each of the 4 Amiga audio channels. If NumOfChans is 1,
then the PlayMap is 128 bytes and each midi note has only 1 byte in the
PlayMap. The first byte pertains to midi note #0, the second pertains to
midi note #1, etc. In this case, a player program might elect to simply
play back the PlayMap wave number on any available amiga audio channel. If
NumOfChans = 0, then there is no imbedded PlayMap in the MHDR, no midi
note assignments for the waves, and an application should play back waves
on any channel at their default sampleRates.

In effect, the purpose of the PlayMap array is to determine which (if any)
waves are to be played back for each of the 128 possible Midi Note
Numbers. Usually, the MHDR's NumOfChans will be set to 4 since the Amiga
has 4 audio channels. For the rest of this document, the NumOfChans is
assumed to be 4.

As mentioned, there can be a total of 255 waves in a "SAMP" file, numbered
from 1 to 255. A PlayMap wave number of 0 is reserved to indicate that NO
WAVE number should be played back. Consider the following example:  The
first 4 bytes of PlayMap are  1,3,0,200.

If a sample playing program receives (from the serial port or another task
perhaps) Midi Note Number 0, the following should occur:

  1) The sampler plays back wave 1 on Amiga audio channel
```c
     number 0 (because the first PlayMap byte is 1).
```
  2) The sampler plays back wave 3 on Amiga audio channel
```c
     number 1 (because the second PlayMap byte is 3).
```
  3) The sampler does not effect Amiga audio channel 2 in
```c
     any way (because the third PlayMap byte is a 0).
```
  4) The sampler plays back wave 200 on Amiga audio channel

```c
     number 4 (because the fourth PlayMap byte is 200).
```
(This assumes INDEPENDANT CHANNEL play MODE to be discussed later in this
 document.)

All four of the PlayMap bytes could even be the same wave number. This
would cause that wave to be output of all 4 Amiga channels simultaneously.

NumOfWaves is simply the number of waves in the sound file.

Format is the number of significant bits in every sample of a wave. For
example, if Format = 8, then this means that the sample data is an 8 bit
format, and that every sample of the wave can be expressed by a single
BYTE. (A 16 bit sample would need a WORD for every sample point).

Each bit of the Flags byte, when set, means the following:

Bit #0 -
   File continued on another disc. This might occur if the SAMP file
   was too large to fit on 1 floppy. The accepted practice (as incor-
   porated by Yamaha's TX sampler and Casio's FZ-1 for example) is to
   dump as much as possible onto one disc and set a flag to indicate
   that more is on another disc's file. The name of the files must
   be the related. The continuation file should have its own SAMP header
   MHDR, and BODY chunks. This file could even have its continuation
   bit set, etc. Never chop a sample wave in half. Always close the
   file on 1 disc after the last wave which can be completely saved.
   Resume with the next wave within the BODY of the continuation file.
   Also, the NumOfWaves in each file's BODY should be the number saved
   on that disc (not the total number in all combined disk files).
   See the end of this document for filename conventions.

In C, here is how the PlayMap is used when receiving a midi note-on event:

   MapOffset = (UBYTE) MidiNoteNumber * numOfChans;
   /* MidiNoteNumber is the received note number (i.e. the second byte of
     a midi note-on event. numOfChans is from the SAMP MHDR. */
   chan0waveNum = (UBYTE) playMap[MapOffset];
   chan1waveNum = (UBYTE) playMap[MapOffset+1];
   chan2waveNum = (UBYTE) playMap[MapOffset+2];
   chan3waveNum = (UBYTE) playMap[MapOffset+3];

   if (chan0waveNum != 0)
   { /* get the pointer to wave #1's data, determine the values
```c
        that need to be passed to the audio device, and play this
        wave on Amiga audio channel #0 (if INDEPENDANT PlayMode) */
```
   }

   /* do the same with the other 3 channel's wave numbers */

In assembly, the "MHDR" structure looks like this:

             CNOP 0,2
MHDR        dc.b 'MHDR'
sizeOfMHDR  dc.l [this is 6 + (NumOfChans * 128) ]
NumOfWaves  dc.b [a byte count of # of waves in the file]
Format      dc.b [a byte count of # of significant bits in a sample point]
Flags       dc.b [bit mask]
PlayMode    dc.b [play MODE discussed later]
NumOfChans  dc.b [# of bytes per midi note for PlayMap]
PlayMap     ds.b [128 x NumOfChans bytes of initialized values]

and a received MidiNoteNumber is interpreted as follows:

   moveq   #0,d0
   move.b  MidiNoteNumber,d0  ;this is the received midi note #
   bmi.s   Illegal_Number     ;exit, as this is an illegal midi note #
   moveq   #0,d1
   move.b  NumOfChans,d1
   mulu.w  d1,d0              ;MidiNoteNumber x NumOfChans
   lea     PlayMap,a0
   adda.l  d0,a0
   move.b  (a0)+,chan0waveNum
   move.b  (a0)+,chan1waveNum
   move.b  (a0)+,chan2waveNum
   move.b  (a0),chan3waveNum

   tst.b   chan0waveNum
   beq.s   Chan1
 ;Now get the address of this wave number's sample data, determine the
 ;values that need to be passed to the audio device, and output the wave's
 ;data on Amiga chan 0 (assuming INDEPENDANT PlayMode).

Chan1 tst.b chan1waveNum
      beq.s Chan2
 ;do the same for the other wave numbers, etc.

