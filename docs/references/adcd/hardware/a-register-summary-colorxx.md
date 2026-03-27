---
title: A Register Summary / COLORxx
manual: hardware
chapter: hardware
section: a-register-summary-colorxx
functions: []
libraries: []
---

# A Register Summary / COLORxx

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
COLORxx    180      W       D     Color table xx


```c
                 There are 32 of these registers (xx=00-31) and they
                 are sometimes collectively called the "color
                 palette."  They contain 12-bit codes representing
                 red, green, and blue colors for RGB systems.
                 One of these registers at a time is selected
                 (by the BPLxDAT serialized video code)
                 for presentation at the RGB video output pins.
                 The table below shows the color register bit usage.

                 BIT# 15,14,13,12,11,10,09,08,07,06,05,04,03,02,01,00
                      ----------- ----------- ----------- -----------
                 RGB  X  X  X  X  R3 R2 R1 R0 G3 G2 G1 G0 B3 B2 B1 B0

                 B=blue, G=green, R=red,
```
