---
title: SAMP.doc / Interpreting the Playmode
manual: devices
chapter: devices
section: samp-doc-interpreting-the-playmode
functions: []
libraries: []
---

# SAMP.doc / Interpreting the Playmode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

PlayMode specifies how the bytes in the PlayMap are to be interpreted.
Remember that a PlayMap byte of 0 means "No Wave to Play".


    #define INDEPENDANT 0
    #define MULTI       1
    #define STEREO      2
    #define PAN         3
PlayMode types:

 INDEPENDANT(0)-The wave #s for a midi note are to be output on

                Amiga audio channels 0, 1, 2, and 3 respectively.
                If the NumOfChans is < 4, then only use that many channels.
 MULTI      (1)-The first wave # (first of the PlayMap bytes) for a

                midi note is to be output on any free channel. The other
                wave numbers are ignored. If all four channels are in
                play, the application can decide whether to "steal" a
                channel.
 STEREO     (2)-The first wave # (first of the PlayMap bytes) is to be

```c
                output of the Left stereo jack (channel 1 or 3) and if
                there is a second wave number (the second of the PlayMap
                bytes), it is to be output the Right jack (channel 2 or 4).
                The other wave numbers are ignored.
```
 PAN        (3)-This is just like STEREO except that the volume of wave 1

```c
                should start at its initial volume (midi velocity) and
                fade to 0. At the same rate, wave 2 should start at 0
                volume and rise to wave #1's initial level. The net
                effect is that the waves "cross" from Left to Right in
                the stereo field. This is most effective when the wave
                numbers are the same. (ie the same wave) The application
                program should set the rate. Also, the application can
                reverse the stereo direction (ie Right to Left fade).
```
The most important wave # to be played back by a midi note should be the
first of the PlayMap bytes. If the NumOfChans > 1, the second PlayMap byte
should be a defined wave number as well (even if it is deliberately set to
the same value as the first byte). This insures that all 4 PlayModes will
have some effect on a given SAMP file. Also, an application should allow
the user to change the PlayMode at will. The PlayMode stored in the SAMP
file is only a default or initial set-up condition.

