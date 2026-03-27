---
title: 8 Narrator Device / Device Interface
manual: devices
chapter: devices
section: 8-narrator-device-device-interface
functions: []
libraries: []
---

# 8 Narrator Device / Device Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The narrator device operates like all other Amiga devices.  To use the
narrator device, you must first open it.  This initializes certain global
areas, opens the audio device, allocates audio channels, and performs
other housekeeping functions.  Once open, the device is ready to receive
I/O commands (most typically [CMD_WRITE](autodocs-2.0/narrator-device-cmd-write.md) and[CMD_READ](autodocs-2.0/narrator-device-cmd-read.md)). Finally, when
finished, the user should close the device.  This will free some buffers
and allow the entire device to be expunged should the system require
memory.  See the [Introduction to Amiga System Devices](devices/1-introduction-to-amiga-system-devices-using-a-device.md) chapter for general
information on device usage.

The narrator device uses two extended I/O request structures: narrator_rb
for write commands (to produce speech output) and mouth_rb for read
commands (to receive mouth shape changes and word/syllable synchronization
events).  Both I/O request structures have been expanded (in a backwards
compatible fashion) for the V37 narrator device with several new fields
defined.


```c
    struct narrator_rb
    {
       struct IOStdReq  message; /* Standard IORequest Block       */
       UWORD   rate;             /* Speaking rate (words/minute)   */
       UWORD   pitch;            /* Baseline pitch in Hertz        */
       UWORD   mode;             /* Pitch mode                     */
       UWORD   sex;              /* Sex of voice                   */
       UBYTE   *ch_masks;        /* Pointer to audio allocation maps  */
       UWORD   nm_masks;         /* Number of audio allocation maps   */
       UWORD   volume;           /* Volume. 0 (off) thru 64        */
       UWORD   sampfreq;         /* Audio sampling frequency       */
       UBYTE   mouths;           /* If non-zero, generate mouths   */
       UBYTE   chanmask; /* Which ch mask used (internal - do not modify)*/
       UBYTE   numchan;  /* Num ch masks used (internal- do not modify) */
       UBYTE   flags;            /* New feature flags              */
       UBYTE   F0enthusiasm;     /* F0 excursion factor            */
       UBYTE   F0perturb;        /* Amount of F0 perturbation      */
       BYTE    F1adj;            /* F1 adjustment in +- 5% steps   */
       BYTE    F2adj;            /* F2 adjustment in +- 5% steps   */
       BYTE    F3adj;            /* F3 adjustment in +- 5% steps   */
       BYTE    A1adj;            /* A1 adjustment in decibels      */
       BYTE    A2adj;            /* A2 adjustment in decibels      */
       BYTE    A3adj;            /* A3 adjustment in decibels      */
       UBYTE   articulate;       /* Transition time multiplier     */
       UBYTE   centralize;       /* Degree of vowel centralization */
       char    *centphon;        /* Pointer to central ASCII phon  */
       BYTE    AVbias;           /* Amplitude of voicing bias      */
       BYTE    AFbias;           /* Amplitude of frication bias    */
       BYTE    priority;         /* Priority while speaking        */
       BYTE    pad1;             /* For alignment                  */
    };

    struct mouth_rb
    {
       struct  narrator_rb voice;/* Speech IORequest Block         */
       UBYTE   width;            /* Mouth width (returned value)   */
       UBYTE   height;           /* Mouth height (returned value)  */
       UBYTE   shape;            /* Internal use, do not modify    */
       UBYTE   sync;             /* Returned sync events           */
    };
```
Details on the meaning of the various fields of the two I/O request blocks
can be found in the [Writing to the Narrator Device](devices/8-narrator-device-writing-to-the-narrator-device.md) and
[Reading from the Narrator Device](devices/8-narrator-device-reading-from-the-narrator-device.md) sections later in this chapter.  See
the include file devices/[narrator.h](autodocs-2.0/includes-devices-narrator-h.md) for the complete structure definitions.

 [The Amiga Speech System](devices/8-device-interface-the-amiga-speech-system.md) 
 [Opening The Narrator Device](devices/8-device-interface-opening-the-narrator-device.md) 
 [Closing The Narrator Device](devices/8-device-interface-closing-the-narrator-device.md) 

