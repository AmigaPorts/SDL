---
title: A Register Summary / AUDxPER
manual: hardware
chapter: hardware
section: a-register-summary-audxper
functions: []
libraries: []
---

# A Register Summary / AUDxPER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
AUDxPER    0A6      W      P( [E](hardware/c-ecs-hardware-and-graphics-library-interpretational.md) )  Audio channel x Period


```c
                 This register contains the period (rate) of
                 audio channel x DMA data transfer.
                 The minimum period is 124 color clocks. This means
                 that the smallest number that should be placed in
                 this register is 124 decimal.  This corresponds to
                 a maximum sample frequency of 28.86 khz.
```
