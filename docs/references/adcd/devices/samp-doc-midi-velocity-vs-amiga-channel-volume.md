---
title: SAMP.doc / MIDI Velocity vs. Amiga Channel Volume
manual: devices
chapter: devices
section: samp-doc-midi-velocity-vs-amiga-channel-volume
functions: []
libraries: []
---

# SAMP.doc / MIDI Velocity vs. Amiga Channel Volume

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The legal range for Midi Velocity bytes is 0 to 127. (A midi velocity of 0
should ALWAYS be interpreted as a note off).

The legal range for Amiga channel volume is 0 to 64. Since this is half of
the midi range, a received midi velocity should be divided by 2 and add 1
(but only AFTER checking for a received midi velocity of 0).

An example of how to implement a received midi velocity in C:


```c
    If ( ReceivedVelocity != 0 && ReceivedVelocity < 128 )
    {   /* the velocity byte of a midi message */
        If (velStart != 0)
        {
            tableEntry = ReceivedVelocity / 8;
            If (velStart == 64)
            {    /* Is it POSITIVE */
                 startOfWave = SamplePtr + velTable[tableEntry];
                             /* ^where to find the sample start point */
            }
            If (velStart == 128)
            {    /* Is it NEGATIVE */
                 startOfWave = SamplePtr + velTable[15 - tableEntry];
            }
            volume = (receivedVelocity/2 + 1;  /* playback volume */
            /* Now playback the wave */
        }
    }
```
In assembly,


```c
    lea      SampleData,a0        ;the start addr of the sample data
    moveq    #0,d0
    move.b   ReceivedVelocity,d0  ;the velocity byte of a midi message
    beq      A_NoteOff            ;If zero, branch to a routine to
                                  ;process a note-off message.

    bmi      Illegal_Vol          ;exit if received velocity > 127
    ;---Check for velocity start feature ON, and direction
    move.b   VelStart,d1
    beq.s    Volume               ;skip the velocity offset routine if 0
    bmi.s    NegativeVel          ;is it NEGATIVE? (128)

    ;---Positive velocity offset
    move.l   d0,d1                ;duplicate velocity
    lsr.b    #3,d1                ;divide by 8
    add.b    d1,d1                ;x 2 because we need to fetch a word
    lea      VelTable,a1     ;start at table's HEAD
    adda.l   d1,a1                ;go forward
    move.w   (a1),d1              ;get the velocity offet
    adda.l   d1,a0          ;where to start actual playback
    bra.s    Volume
```
  NegativeVel:
```c
    ;---Negative velocity offset
    move.l   d0,d1                ;duplicate velocity
    lsr.b    #3,d1                ;divide by 8
    add.b    d1,d1                ;x 2 because we need to fetch a word
    lea      VelTable+30,a1  ;start at table's END
    suba.l   d1,a1                ;go backwards
    move.w   (a1),d1              ;get the velocity offset
    adda.l   d1,a0          ;where to start actual playback

    ;---Convert Midi velocity to an Amiga volume
```
  Volume  lsr.b    #1,d0          ;divide by 2

```c
          addq.b   #1,d0          ;an equivalent Amiga volume
```
   ;---Now a0 and d0 are the address of sample start, and volume

