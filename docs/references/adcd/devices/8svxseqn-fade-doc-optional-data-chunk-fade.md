---
title: 8SVXSEQN.FADE.doc / Optional Data Chunk FADE
manual: devices
chapter: devices
section: 8svxseqn-fade-doc-optional-data-chunk-fade
functions: []
libraries: []
---

# 8SVXSEQN.FADE.doc / Optional Data Chunk FADE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The FADE chunk defines at what loop number the sound should begin to fade
away to silence. It is possible to finish a sample of music in much the
same way as commercial music does today. A FADE chunk consists of one
ULONG value which has a number in it. This number corresponds to the loop
number at which the fade should begin.

eg. You may have a waveform containing 50 loops. A FADE definition of 45
will specify that once loop 45 is reached, fading to zero volume should
begin. The rate at which this fade takes place is determined by the length
of time left to play. The playing software should do a calculation based
on the following...

Length of all remaining sequences including current sequence (in bytes)

divided by

the current playback rate in samples per second

= time remaining.

Begin stepping the volume down at a rate which will hit zero volume just
as the waveform finishes.

The raw data in a file may look like this.


 'F-A-D-E'  [ Size ]   Loop No.  'B-O-D-Y'   Size   Data..

  46414445  00000004   0000002D   424F4459 000BE974 01010101 01010101 etc


                          ^
                          Start fading when loop number 45 is reached.
	#define ID_FADE MakeID('F','A','D','E')

Although order shouldn't make much difference, it is a general rule of
thumb that SEQN should come before FADE and FADE should be last before the
BODY.

Stereo waveforms would have CHAN,SEQN,FADE,BODY in that order.

