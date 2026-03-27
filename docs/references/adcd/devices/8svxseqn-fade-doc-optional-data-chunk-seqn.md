---
title: 8SVXSEQN.FADE.doc / Optional Data Chunk SEQN
manual: devices
chapter: devices
section: 8svxseqn-fade-doc-optional-data-chunk-seqn
functions: []
libraries: []
---

# 8SVXSEQN.FADE.doc / Optional Data Chunk SEQN

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The optional data chunk SEQN gives the information necessary to play a
sample in a sequence of defined blocks. To have a segment repeat twice,
the definition occurs twice in the list.

This list consists of pairs of ULONG "loop start" and "end" definitions
which are offsets from the start of the waveform. The locations or values
must be LONGWORD aligned (divisable by 4).

To determine how many loop definitions in a given file, simply divide the
SEQN chunk size by 8.

E.g., if chunk size == 40 ... number of loops = (40 / 8) .. equals 5 loops.

The raw data in a file might look like this...

'S-E-Q-N' [ size ] [     Loop 1    ] [     Loop 2    ] [     Loop 3    ]

 5345514E 00000028 00000000 00000C00 00000000 00000C00 00000C08 00002000


```c
             ^
             ^     'Haaaallelujah..' 'Haaaallelujah..'   'Hallelujah..'
             ^
             ^
             40 bytes decimal / 8 = 5 loop or segments


      [     Loop 4    ] [    Loop 5     ]'B-O-D-Y'   Size     Data

      00000C08 00002000 00002008 00003000 424F4459 000BE974 010101010101010

        'Hallelujah..'  'Halleeeelujah..'
```
In a waveform containing SEQN chunks, the oneShotHiSamples should be set
to 0 and the repeatHiSamples should equal the BODY length (divided by 2 if
STEREO).

Remember the locations of the start and end of each segment or loop should
be LONGWORD aligned.

If the waveform is Stereo, treat the values and locations in exactly the
same way. In other words, if a loop starts at location 400 within a Stereo
waveform, you start the sound at the 400th byte position in the left data
and the 400th byte position in the right data simultaneously.

	#define ID_SEQN MakeID('S','E','Q','N')

