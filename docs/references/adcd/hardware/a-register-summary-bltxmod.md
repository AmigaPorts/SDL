---
title: A Register Summary / BLTxMOD
manual: hardware
chapter: hardware
section: a-register-summary-bltxmod
functions: []
libraries: []
---

# A Register Summary / BLTxMOD

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
BLTxMOD    064      W       A     Blitter modulo x


```c
                 This register contains the modulo for blitter
                 source (x=A,B,C) or destination (x=D).  A modulo
                 is a number that is automatically added to the
                 address at the end of each line, to make the
                 address point to the start of the next line.  Each
                 source or destination has its own modulo, allowing
                 each to be a different size, while an identical
                 area of each is used in the blitter operation.

                 LINE DRAW   BLTAMOD and BLTBMOD are used as slope
                 LINE DRAW   storage registers and must be preloaded
                 LINE DRAW   with the values (4Y-4X) and (4Y)
                 LINE DRAW   respectively.  Y/X= line slope.
                 LINE DRAW   BLTCMOD and BLTDMOD must both be
                 LINE DRAW   preloaded with the width (in bytes)
                 LINE DRAW   of the image into which the line is
                 LINE DRAW   being drawn (normally two times the
                 LINE DRAW   screen width in words).
```
