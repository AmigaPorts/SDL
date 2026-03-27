---
title: A Register Summary / DSKPTH, DSKPTL
manual: hardware
chapter: hardware
section: a-register-summary-dskpth-dskptl
functions: []
libraries: []
---

# A Register Summary / DSKPTH, DSKPTL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
DSKPTH     020      W      A( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) ) Disk pointer (high 3 bits,
```c
                                      high 5 bits if ECS)
```
DSKPTL     022      W       A     Disk pointer (low 15 bits)


                 This pair of registers contains the 18-bit
                 address of disk DMA data. These address registers
                 must be initialized by the processor or Copper
                 before disk DMA is enabled.
