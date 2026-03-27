---
title: SAMP.doc / Making the Velocity Table
manual: devices
chapter: devices
section: samp-doc-making-the-velocity-table
functions: []
libraries: []
---

# SAMP.doc / Making the Velocity Table

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The 16 entries in the velocity table should be within the oneShot portion
of the sample (ie not in the looping portion). THe first offset,
VelTable[0] should be set to zero (in order to play back from the
beginning of the data). The subsequent values should be increasing
numbers. If you are using a graphic editor, try choosing offsets that will
keep you within the initial attack portion of the wave. In practice, these
values will be relatively close together within the wave. Always set the
offsets so that when they are added to the sample start point, the
resulting address points to a sample value of zero (a zero crossing
point). This will eliminate pops and clicks at the beginning of the
playback.

In addition, the start of the wave should be on a sample with a value of
zero. The last sample of the oneShot portion and the first sample of the
looping portion should be approximately equal, (or zero points). The same
is true of the first and last samples of the looping portion. Finally, try
to keep the slopes of the end of the oneShot, the beginning of the
looping, and the end of the looping section, approximately equal. All this
will eliminate noise on the audio output and provide "seamless" looping.

