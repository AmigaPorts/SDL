---
title: Standard Data and Property Chunks / Required Property SHDR
manual: devices
chapter: devices
section: standard-data-and-property-chunks-required-property-shdr
functions: []
libraries: []
---

# Standard Data and Property Chunks / Required Property SHDR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The required property "SHDR" holds an SScoreHeader as defined in these C
declarations and following documentation.  An SHDR specifies global
information for the score.  It must appear before the [TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md)s in a FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md).

```c
    #define ID_SMUS MakeID('S', 'M', 'U', 'S')
    #define ID_SHDR MakeID('S', 'H', 'D', 'R')

    typedef struct {
```
	UWORD tempo;	/* tempo, 128ths quarter note/minute */
	UBYTE volume;	/* overall playback volume 0 through 127 */
	UBYTE ctTrack;	/* count of tracks in the score */
	} SScoreHeader;

[Implementation details.  In the C struct definitions in this memo, fields
are filed in the order shown.  A UBYTE field is packed into an 8-bit byte.
Programs should set all "pad" fields to 0.  MakeID is a C macro defined in
the main IFF document and in the source file [IFF.h](devices/devices-iffp-iff-h.md).]

The field tempo gives the nominal tempo for all tracks in the score.  It
is expressed in 128ths of a quarter note per minute, i.e., 1 represents 1
quarter note per 128 minutes while 12800 represents 100 quarter notes per
minute.  You may think of this as a fixed point fraction with a 9-bit
integer part and a 7-bit fractional part (to the right of the point).  A
coarse-tempoed program may simply shift tempo right by 7 bits to get a
whole number of quarter notes per minute.  The tempo field can store tempi
in the range 0 up to 512.  The playback program may adjust this tempo,
perhaps under user control.

Actually, this global tempo could actually be just an initial tempo if
there are any "set tempo" [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md)s inside the score (see [TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md), below).  Or
the global tempo could be scaled by "scale tempo" SEvents inside the
score.  These are potential extensions that can safely be ignored by
current programs.  [See [More SEvents To Be Defined](devices/standard-data-and-property-chunks-more-sevents-to-be-defined.md), below.]

The field volume gives an overall nominal playback volume for all tracks
in the score.  The range of volume values 0 through 127 is like a MIDI key
velocity value.  The playback program may adjust this volume, perhaps
under direction of a user "volume control".

Actually, this global volume level could be scaled by dynamic-mark [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md)s
inside the score (see [TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md), below).

The field ctTrack holds the count of tracks, i.e., the number of [TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md)
chunks in the FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md) (see below).  This information helps the reader
prepare for the following data.

A playback program will typically load the score and call a driver routine
PlayScore(tracks, tempo, volume), supplying the tempo and volume from the
[SHDR](devices/standard-data-and-property-chunks-required-property-shdr.md)  chunk.

