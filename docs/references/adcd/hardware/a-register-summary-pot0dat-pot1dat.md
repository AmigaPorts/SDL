---
title: A Register Summary / POT0DAT, POT1DAT
manual: hardware
chapter: hardware
section: a-register-summary-pot0dat-pot1dat
functions: []
libraries: []
---

# A Register Summary / POT0DAT, POT1DAT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
POT0DAT    012      R      P( [E](hardware/c-ecs-hardware-and-graphics-library-interpretational.md) ) Pot counter data left pair (vert,horiz.)
POT1DAT    014      R      P( [E](hardware/c-ecs-hardware-and-graphics-library-interpretational.md) ) Pot counter data right pair (vert,horiz.)


```c
                 These addresses each read a pair of 8-bit pot counters.
                 (Four counters total.) The bit assignment for both
                 addresses is shown below. The counters are stopped by
                 signals from two controller connectors (left-right)
                 with two pins each.

                 BIT#  15,14,13,12,11,10,09,08  07,06,05,04,03,02,01,00
                 ----- ------------------------ -----------------------
                 RIGHT Y7 Y6 Y5 Y4 Y3 Y2 Y1 Y0  X7 X6 X5 X4 X3 X2 X1 X0
                 LEFT  Y7 Y6 Y5 Y4 Y3 Y2 Y1 Y0  X7 X6 X5 X4 X3 X2 X1 X0

                           CONNECTORS                PAULA
                         --------------------    ----------------
                         Loc. Dir. Sym   Pin     Pin#    Pin Name
                         ----  --- ----  ----    ----    --------
                         RIGHT  Y   RY    9      36      (POT1Y)
                         RIGHT  X   RX    5      35      (POT1X)
                         LEFT   Y   LY    9      33      (POT0Y)
                         LEFT   X   LX    5      32      (POT0X)
```
