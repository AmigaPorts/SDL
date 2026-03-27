---
title: 8SVX.CHAN.PAN.doc / Optional Data Chunk CHAN
manual: devices
chapter: devices
section: 8svx-chan-pan-doc-optional-data-chunk-chan
functions: []
libraries: []
---

# 8SVX.CHAN.PAN.doc / Optional Data Chunk CHAN

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This chunk is already written by the software for a popular stereo
sampler. To maintain the ability read these samples, its implementation
here is therefore limited to maintain compatability.

The optional data chunk CHAN gives the information neccessary to play a
sample on a specified channel, or combination of channels. This chunk
would be useful for programs employing stereo recording or playback of
sampled sounds.


```c
    #define RIGHT           4L
    #define LEFT            2L
    #define STEREO          6L

    #define ID_CHAN MakeID('C','H','A','N')

    typedef sampletype LONG;
```
If "sampletype" is RIGHT, the program reading the sample knows that it was
originally intended to play on a channel routed to the right speaker,
(channels 1 and 2 on the Amiga). If "sampletype" is LEFT, the left speaker
was intended (Amiga channels 0 and 3). It is left to the discretion of the
programmer to decide whether or not to play a sample when a channel on the
side designated by "sampletype" cannot be allocated.

If "sampletype" is STEREO, then the sample requires a pair of channels
routed to both speakers (Amiga pairs [0,1] and [2,3]). The BODY chunk for
stereo pairs contains both left and right information. To adhere to
existing conventions, sampling software should write first the LEFT
information, followed by the RIGHT. The LEFT and RIGHT information should
be equal in length.

Again, it is left to the programmer to decide what to do if a channel for
a stereo pair can't be allocated; wether to play the available channel
only, or to allocate another channels routed to the wrong speaker.

