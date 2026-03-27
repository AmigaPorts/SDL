---
title: 8SVX.CHAN.PAN.doc / Optional Data Chunk PAN
manual: devices
chapter: devices
section: 8svx-chan-pan-doc-optional-data-chunk-pan
functions: []
libraries: []
---

# 8SVX.CHAN.PAN.doc / Optional Data Chunk PAN

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The optional data chunk PAN provides the neccessary information to create
a stereo sound using a single array of data. It is neccessary to replay
the sample simultaneously on two channels, at different volumes.


```c
    #define ID_PAN MakeID('P','A','N',' ')

    typedef sposition Fixed; /* 0 <= sposition <= Unity */

    /* Unity is elsewhere #defined as 10000L, and
     * refers to the maximum possible volume.
     * /

    /* Please note that "Fixed" (elsewhere #defined as LONG) is used to
     * allow for compatabilty between audio hardware of different
     * resolutions.
     * /
```
The "sposition" variable describes a position in the stereo field. The
numbers of discrete stereo positions available is equal to 1/2 the number
of discrete volumes for a single channel.

The sample must be played on both the right and left channels. The overall
volume of the sample is determined by the "volume" field in the
Voice8Header structure in the VHDR chunk.

The left channel volume = overall volume / (Unity / sposition).
 "  right   "       "   = overall volume - left channel volume.

For example:
	If sposition = Unity, the sample is panned all the way to the left.
	If sposition = 0, the sample is panned all the way to the right.
	If sposition = Unity/2, the sample is centered in the stereo field.

