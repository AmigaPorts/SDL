---
title: 3 / Color Selection Registers / Color Selection in Low Resolution Mode
manual: hardware
chapter: hardware
section: 3-color-selection-registers-color-selection-in-low
functions: []
libraries: []
---

# 3 / Color Selection Registers / Color Selection in Low Resolution Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Table 3-17 shows playfield color selection in low resolution mode. If the
bit combinations from the playfields are as shown, the color is taken from
the color register number indicated.


             Single Playfield                  DualPlayfields
                                                                  Color
       Normal Mode       Hold-and-modify Mode                    Register
  (Bitplanes 5,4,3,2,1)  (Bitplanes 4,3,2,1)                      Number
  -----------------------------------------------------------------------


```c
                                                 Playfield 1
                                              (Bitplanes 5,3,1)

          00000                 0000                 000            0 *
          00001                 0001                 001            1
          00010                 0010                 010            2
          00011                 0011                 011            3
          00100                 0100                 100            4
          00101                 0101                 101            5
          00110                 0100                 110            6
          00111                 0111                 111            7

                                                 Playfield 2
                                              (Bitplanes 6,4,2)

          01000                 1000                 000 **         8
          01001                 1001                 001            9
          01010                 1010                 010           10
          01011                 1011                 011           11
          01100                 1100                 100           12
          01101                 1101                 101           13
          01110                 1110                 110           14
          01111                 1111                 111           15
          10000                  -                    -            16
          10001                  -                    -            17
          10010                  -                    -            18
          10011                  -                    -            19
          10100                 NOT                  NOT           20
          10101                 USED                 USED          21
          10110                 IN                   IN            22
          10111                 THIS                 THIS          23
          11000                 MODE                 MODE          24
          11001                  -                    -            25
          11010                  -                    -            26
          11011                  -                    -            27
          11100                  -                    -            28
          11101                  -                    -            29
          11110                  -                    -            30
          11111                  -                    -            31
```
  ________________

  * Color register 0 always defines the background color.
  ** Selects ``transparent'' mode instead of selecting color register 8.



               Table 3-17: Low resolution Color Selection
