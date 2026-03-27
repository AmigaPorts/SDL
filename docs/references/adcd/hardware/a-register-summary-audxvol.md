---
title: A Register Summary / AUDxVOL
manual: hardware
chapter: hardware
section: a-register-summary-audxvol
functions: []
libraries: []
---

# A Register Summary / AUDxVOL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
AUDxVOL    0A8      W       P      Audio channel x volume


```c
                 This register contains the volume setting for
                 audio channel x.  Bits 6,5,4,3,2,1,0 specify 65
                 linear volume levels as shown below.

                 Bit#    Use
                 ----    --------------------------
                  15-07  Not used
                  06     Forces volume to max (64 ones, no zeros)
                  05-00  Sets one of 64 levels (000000=no output
                         (111111=63 1s, one 0)
```
