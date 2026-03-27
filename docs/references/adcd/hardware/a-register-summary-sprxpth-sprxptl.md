---
title: A Register Summary / SPRxPTH, SPRxPTL
manual: hardware
chapter: hardware
section: a-register-summary-sprxpth-sprxptl
functions: []
libraries: []
---

# A Register Summary / SPRxPTH, SPRxPTL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
SPRxPTH    120      W       A     Sprite x pointer (high 3 bits)
SPRxPTL    122      W       A     Sprite x pointer (low 15 bits)


```c
                 This pair of registers contains the 18-bit address
                 of sprite x (x=0,1,2,3,4,5,6,7) DMA data. These address
                 registers must be initialized by the processor or Copper
                 every vertical blank time.
```
