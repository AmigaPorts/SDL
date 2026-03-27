---
title: A Register Summary / DDFSTOP, DDFSTRT
manual: hardware
chapter: hardware
section: a-register-summary-ddfstop-ddfstrt
functions: []
libraries: []
---

# A Register Summary / DDFSTOP, DDFSTRT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
DDFSTOP    094      W       A    Display data fetch stop (horiz. position)
DDFSTRT    092      W       A    Display data fetch start (horiz. position)


```c
                 These registers control the horizontal timing of the
                 beginning and end of the bitplane DMA display data
                 fetch.  The vertical bitplane DMA timing is identical
                 to the display windows described above.
                 The bitplane modulos are dependent on the bitplane
                 horizontal size and on this data-fetch window size.

                 Register bit assignment
                 -------------------------
                 BIT#  15,14,13,12,11,10,09,08,07,06,05,04,03,02,01,00
                       -----------------------------------------------
                 USE    X  X  X  X  X  X  X  X H8 H7 H6 H5 H4 H3  X  X

                  (Always set X bits to 0 to maintain upward compatibility)

                 The tables below show the start and stop timing for
                 different register contents.

                    DDFSTRT (left edge of display data fetch)
                    ----------------------------------------
                         PURPOSE        H8,H7,H6,H5,H4
                     -----------------  --------------
                     Extra wide (max) *  0  0  1  0  1
                     Wide                0  0  1  1  0
                     Normal              0  0  1  1  1
                     Narrow              0  1  0  0  0

                     DDFSTOP (right edge of display data fetch)
                     ------------------------------------------
                          PURPOSE        H8,H7,H6,H5,H4
                     ------------------  --------------
                     Narrow               1  1  0  0  1
                     Normal               1  1  0  1  0
                     Wide (max)           1  1  0  1  1
```
