---
title: 2 / Advanced Topics / Using the Copper In Interlaced Mode
manual: hardware
chapter: hardware
section: 2-advanced-topics-using-the-copper-in-interlaced-mode
functions: []
libraries: []
---

# 2 / Advanced Topics / Using the Copper In Interlaced Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An interlaced bitplane display has twice the normal number of vertical
lines on the screen.  Whereas a normal NTSC display has 262 lines, an
interlaced NTSC display has 524 lines.  PAL has 312 lines normally and 625
in interlaced mode.  In interlaced mode, the video beam scans the screen
twice from top to bottom, displaying, in the case of NTSC, 262 lines at a
time. During the first scan, the odd-numbered lines are displayed.  During
the second scan, the even-numbered lines are displayed and interlaced with
the odd-numbered ones.  The scanning circuitry thus treats an interlaced
display as two display fields, one containing the even-numbered lines and
one containing the odd-numbered lines. Figure 2-1 shows how an interlaced
display is stored in memory.




```c
         Odd field             Even field
         (time t)           (time t + 16.6ms)       Data in Memory
     -----------------      -----------------      -----------------
                                                   _________________
                                                  |                 |
                                                  |        1        |
                                                  |_________________|
                                                  |                 |
     _________________      _________________     |        2        |
    |                 |    |                 |    |_________________|
    |        1        |    |        2        |    |                 |
    |_________________|    |_________________|    |        3        |
    |                 |    |                 |    |_________________|
    |        3        |    |        4        |    |                 |
    |_________________|    |_________________|    |        4        |
    |                 |    |                 |    |_________________|
    |        5        |    |        6        |    |                 |
    |_________________|    |_________________|    |        5        |
                                                  |_________________|
                                                  |                 |
                                                  |        6        |
                                                  |_________________|


                 Figure 2-1: Interlaced Bitplane in RAM
```
The system retrieves data for bitplane displays by using pointers to the
starting address of the data in memory. As you can see, the starting
address for the even-numbered fields is one line greater than the starting
address for the odd-numbered fields. Therefore, the bitplane pointer must
contain a different value for alternate fields of the interlaced display.

Simply, the organization of the data in memory matches the apparent
organization on the screen (i.e., odd and even lines are interlaced
together). This is accomplished by having a separate
 [Copper instruction list](hardware/2-coprocessor-hardware-putting-together-a-copper.md)  for each field to manage displaying the data.

To get the Copper to execute the correct list, you set an interrupt to the
680x0 just after the first line of the display. When the interrupt is
executed, you change the contents of the  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md)  location register to
point to the second list. Then, during the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  interval,
 [COP1LC](hardware/2-using-the-copper-registers-location-registers.md)  will be automatically reset to point to the original list.

For more information about  [interlaced displays](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md) , see Chapter 3,
"Playfield Hardware."

