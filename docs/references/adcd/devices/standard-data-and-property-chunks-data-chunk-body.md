---
title: Standard Data and Property Chunks / Data Chunk BODY
manual: devices
chapter: devices
section: standard-data-and-property-chunks-data-chunk-body
functions: []
libraries: []
---

# Standard Data and Property Chunks / Data Chunk BODY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The BODY chunk contains the audio data samples.


```c
    #define ID_BODY MakeID('B', 'O', 'D', 'Y')

    typedef character BYTE;  /* 8 bit signed number, -128 through 127. */
    /* BODY chunk contains a BYTE[], array of audio data samples.      */
```
The BODY contains data samples grouped by octave.  Within each octave are
one-shot and repeat portions.  Figure 2 depicts this arrangement of
samples for an 8SVX where oneShotHiSamples = 24, repeatHiSamples = 16,
samplesPerHiCycle = 8, and ctOctave = 3.  The major divisions are octaves,
the intermediate divisions separate the one-shot and repeat portions, and
the minor divisions are cycles.



        +-+-+-+-+-+---+---+---+---+---+------+------+------+------+------+
        | | | | | |   |   |   |   |   |      |      |      |      |      |
        |     |   |           |       |                    |             |
        |  O  | R |  One-shot | Repeat|       One-shot     |    Repeat   |
        |         |                   |                                  |
        |         |                   |                                  |
        |hi octave|    middle octave  |            low octave            |
        +---------+-------------------+----------------------------------+

        Figure 2. BODY subdivisions.
In general, the BODY has ctOctave octaves of data.  The highest frequency
octave comes first, comprising the fewest samples: oneShotHiSamples +
repeatHiSamples.  Each successive octave contains twice as many samples as
the next higher octave but the same number of cycles.  The lowest
frequency octave comes last with the most samples: 2^(ctOctave-1) *
(oneShotHiSamples + repeatHiSamples).

The number of samples in the BODY chunk is


```c
        ( 2^0 + ... + 2^(ctOctave-1) ) * (oneShotHiSamples + repeatHiSamples)
```
Figure 3, below, looks closer at an example waveform within one octave of
a different BODY chunk.  In this example, oneShotHiSamples /
samplesPerHiCycle = 2 cycles and repeatHiSamples / samplesPerHiCycle = 1
cycle.

        ^
(volume)|              |        /\   |        /\   |


```c
        |              |       |  \  |       |  \  |
        |     /\       |       |   \ |       |   \ |
        |    /  \    /\|       /    \|       /    \|
        +---/----\--/--+------/------+------/------+
        |\ /      \/   |\    |       |\    |       |
        | V            | \   |       | \   |       |
        |              |  \ /        |  \ /        |
        |              |   V         |   V         |
        +--------------+-------------+-------------+----> (time)
           one-shot         repeat        repeat

           Figure 3. Example waveform.
```
To avoid playback "clicks" the one-shot part should begin with a small
sample value, and  flow smoothly into the repeat part.  The end of the
repeat part should flow smoothly into the beginning of the next repeat
part.

If the [VHDR](devices/standard-data-and-property-chunks-required-property-vhdr.md) field sCompression != sCmpNone, the BODY chunk is just an
array of data bytes to feed through the specified decompresser function.
All this stuff about sample sizes, octaves, and repeat parts applies to
the decompressed data.

Be sure to follow an odd-length BODY chunk with a 0 pad byte.

