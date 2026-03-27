---
title: SAMP.doc / An EGpoint (Envelope Generator)
manual: devices
chapter: devices
section: samp-doc-an-egpoint-envelope-generator
functions: []
libraries: []
---

# SAMP.doc / An EGpoint (Envelope Generator)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A single EGpoint is a 6 byte structure as follows:

EGpoint1: dc.w ;[the duration in milliseconds]

```c
          dc.l ;[the volume factor - fixed point,16 bits to the left of the
               ;decimal point and 16 to the right.]
```
The volume factor is a fixed point where 1.0 ($00010000) represents the
MAXIMUM volume possible. (i.e. No volume factor should exceed this value.)
The last EGpoint in the ATAK is always the sustain point. Each EG's volume
is determined from 0.0, not as a difference from the previous EG's volume.
I hope that this clears up the ambiguity in the original 8SVX document.
So, to recreate an amplifier envelope like this:


                                /\
                               /  \____
                              /        \
                             /          \

                             |  | |   |  |
                              1  2  3   4
Stages 1, 2, and 3 would be in the ATAK data, like so:

;Stage 1
dc.w  100       ;take 100ms
dc.l  $00004000 ;go to this volume
dc.w  100
dc.l  $00008000
dc.w  100
dc.l  $0000C000
dc.w  100
dc.l  $00010000 ;the "peak" of our attack is full volume
;Stage 2
dc.w  100
dc.l  $0000C000 ;back off to this level
dc.l  100
dc.l  $00008000 ;this is where we hold (SUSTAIN) until the note

```c
                ;is turned off. (We are now holding at stage 3)
```
Now the RLSE data would specify stage 4 as follows:
dc.w  100
dc.l  $00004000
dc.w  100
dc.l  $00000000 ;the volume is 0

