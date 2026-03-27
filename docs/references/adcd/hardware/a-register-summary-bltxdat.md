---
title: A Register Summary / BLTxDAT
manual: hardware
chapter: hardware
section: a-register-summary-bltxdat
functions: []
libraries: []
---

# A Register Summary / BLTxDAT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
BLTxDAT    074      W       A     Blitter source x data register


```c
                 This register holds source x (x=A,B,C) data for
                 use by the blitter. It is normally loaded by the
                 blitter DMA channel; however, it may also be
                 preloaded by the microprocessor.

                 LINE DRAW   BLTADAT is used as an index register
                 LINE DRAW   and must be preloaded with 8000.
                 LINE DRAW   BLTBDAT is used for texture; it must
                 LINE DRAW   be preloaded with FF if no texture
                 LINE DRAW   (solid line) is desired.
```
