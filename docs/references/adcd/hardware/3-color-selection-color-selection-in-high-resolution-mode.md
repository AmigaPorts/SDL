---
title: 3 / Color Selection / Color Selection in High Resolution Mode
manual: hardware
chapter: hardware
section: 3-color-selection-color-selection-in-high-resolution-mode
functions: []
libraries: []
---

# 3 / Color Selection / Color Selection in High Resolution Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Table 3-18 shows playfield color selection in high resolution mode. If the
bit combinations from the playfields are as shown, the color is taken from
the color register number indicated.



```c
               Single               Dual               Color
              Playfield          Playfields           Register
         (Bitplanes 4,3,2,1)                           Number
         -----------------------------------------------------

                                 Playfield 1
                               (Bitplanes 3,1)

                0000                 00 *                0 **
                0001                 01                  1
                0010                 10                  2
                0011                 11                  3

                0100                  -                  4
                0101              NOT USED               5
                0110            IN THIS MODE             6
                0111                  -                  7

                                 Playfield 2
                               (Bitplanes 4,2)

                1000                 00 *                8
                1001                 01                  9
                1010                 10                 10
                1011                 11                 11

                1100                  -                 12
                1101              NOT USED              13
                1110            IN THIS MODE            14
                1111                  -                 15

         ________________

         * Selects "transparent" mode.

         ** Color register 0 always defines the background color.


                 Table 3-18: High resolution Color Selection
```
