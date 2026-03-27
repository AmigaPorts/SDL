---
title: A Register Summary / BLTxPTH, BLTxPTL
manual: hardware
chapter: hardware
section: a-register-summary-bltxpth-bltxptl
functions: []
libraries: []
---

# A Register Summary / BLTxPTH, BLTxPTL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
BLTxPTH    050      W      A( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) ) Blitter pointer to x (high 3 bits,
```c
                                      5 bits if ECS)
```
BLTxPTL    052      W       A     Blitter pointer to x (low 15 bits)


```c
                 This pair of registers contains the 18-bit address
                 of blitter source (x=A,B,C) or destination (x=D)
                 DMA data.  This pointer must be preloaded with the
                 starting address of the data to be processed by
                 the blitter. After the blitter is finished, it
                 will contain the last data address (plus increment
                 and modulo).

                 LINE DRAW   BLTAPTL is used as an accumulator
                 LINE DRAW   register and must be preloaded with
                 LINE DRAW   the starting value of (2Y-X) where
                 LINE DRAW   Y/X is the line slope.  BLTCPT and
                 LINE DRAW   BLTDPT (both H and L) must be
                 LINE DRAW   preloaded with the starting address
                 LINE DRAW   of the line.
```
