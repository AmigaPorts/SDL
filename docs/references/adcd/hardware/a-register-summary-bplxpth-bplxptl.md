---
title: A Register Summary / BPLxPTH, BPLxPTL
manual: hardware
chapter: hardware
section: a-register-summary-bplxpth-bplxptl
functions: []
libraries: []
---

# A Register Summary / BPLxPTH, BPLxPTL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
BPLxPTH    0E0      W       A     Bitplane x pointer (high 3 bits)
BPLxPTL    0E2      W       A     Bitplane x pointer (low 15 bits)


```c
                 This pair of registers contains the 18-bit pointer to
                 the address of bitplane x (x=1,2,3,4,5,6) DMA data.
                 This pointer must be reinitialized by the processor
                 or copper to point to the beginning of bitplane data
                 every vertical blank time.
```
