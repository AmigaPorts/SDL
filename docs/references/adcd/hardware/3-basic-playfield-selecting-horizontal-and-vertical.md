---
title: 3 / Basic Playfield / Selecting Horizontal and Vertical Resolution
manual: hardware
chapter: hardware
section: 3-basic-playfield-selecting-horizontal-and-vertical
functions: []
libraries: []
---

# 3 / Basic Playfield / Selecting Horizontal and Vertical Resolution

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Standard home television screens are best suited for low resolution
displays. Low resolution mode provides 320 pixels for each horizontal
line. High resolution monochrome and RGB monitors can produce displays in
high resolution mode, which provides 640 pixels for each horizontal line.
If you define an object in low resolution mode and then display it in high
resolution mode, the object will be only half as wide.

To set horizontal resolution mode, you write to bit 15, HIRES, in register
 [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md) :

   High resolution mode -- write 1 to bit 15.
   Low resolution mode -- write 0 to bit 15.

Note that in high resolution mode, you can have up to four bitplanes in
the playfield and, therefore, up to 16 colors.

Interlaced mode allows twice as much data to be displayed in the same
vertical area as in non-interlaced mode. This is accomplished by doubling
the number of lines appearing on the video screen. The following table
shows the number of lines required to fill a normal, non-overscan screen.




                              NTSC      PAL
                              ----      ---
          Non-interlaced      200       256
          Interlaced          400       512


        Table 3-6: Lines in a Normal Playfield
In interlaced mode, the scanning circuitry vertically offsets the start of
every other field by half a scan line.

           _____________________
  line 1 _|_____________________|_
```c
          |_____________________| \
          |      _________      |  \
          |      _________      |   \
          |                     |    \
          |      Odd Field      |     \   _____________________
          |      _________      |      \_|_____________________|_ Line 1
          |      _________      |       _|_|___________________|_ Line 2
          |_____________________|      / |                     |
          |_____________________|     /  | |                   |
          |_____________________|    /   |    Video Display    |
                                    /    | | (400 lines NTSC   |
           _____________________   /     |    512 lines PAL)   |
```
  line 2 _|_____________________|_/      | |                   |


```c
          |_____________________|        |                     |
          |      _________      |        |\|/                  |
          |      _________      |        |_____________________|
          |                     |
          |      Even Field     |      Same physical space as used
          |      _________      |       by a 200-line (256) PAL),
          |      _________      |         noninterlaced display.
          |_____________________|
          |_____________________|
          |_____________________|


                         Figure 3-5: Interlacing
```
Even though interlaced mode requires a modest amount of extra work in
setting registers (as you will see later on in this section), it provides
fine tuning that is needed for certain graphics effects. Consider the
diagonal line in Figure 3-6 as it appears in non-interlaced and interlaced
modes. Interlacing eliminates much of the jaggedness or "staircasing" in
the edges of the line.



              ___________________        ___________________
             |#|#| | | | | | | | |      |#|#|_|_|_|_|_|_|_|_|
             |#|#|_|_|_|_|_|_|_|_|      |_|#|#|_|_|_|_|_|_|_|
             | | |#|#| | | | | | |      |_|_|#|#|_|_|_|_|_|_|
             |_|_|#|#|_|_|_|_|_|_|      |_|_|_|#|#|_|_|_|_|_|
             | | | | |#|#| | | | |      |_|_|_|_|#|#|_|_|_|_|
             |_|_|_|_|#|#|_|_|_|_|      |_|_|_|_|_|#|#|_|_|_|
             | | | | | | |#|#| | |      |_|_|_|_|_|_|#|#|_|_|
             |_|_|_|_|_|_|#|#|_|_|      |_|_|_|_|_|_|_|#|#|_|
             | | | | | | | | |#|#|      |_|_|_|_|_|_|_|_|#|#|
             |_|_|_|_|_|_|_|_|#|#|      |_|_|_|_|_|_|_|_|_|#|

                non-interlaced               interlaced


         Figure 3-6: Effect of Interlaced Mode on Edges of Object
When you use the special blitter DMA channel to draw lines or polygons
onto an interlaced playfield, the playfield is treated as one display,
rather than as odd and even fields. Therefore, you still get the smoother
edges provided by interlacing.

To set interlaced or non-interlaced mode, you write to bit 2, LACE, in
register  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md) :

   Interlaced mode -- write 1 to bit 2.
   Non-interlaced mode -- write 0 to bit 2.

As explained above in  [Setting the Number of Bitplanes](hardware/3-bitplanes-and-color-selecting-the-number-of-bitplanes.md) , bits in
 [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  are not independently settable.

The following example shows how to specify high resolution and interlaced
modes.


```c
        MOVE.W  #$A204,[BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)+CUSTOM   ; Write to it
```
The example above also sets the following parameters that are also
controlled through register  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md) :

   [*](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md)   High resolution mode is enabled.
   [*](hardware/3-bitplanes-and-color-selecting-the-number-of-bitplanes.md)   Two bitplanes are used.
   [*](hardware/3-advanced-topics-hold-and-modify-mode.md)   Hold-and-modify mode is disabled.
   [*](hardware/3-forming-a-dual-playfield-display-activating-dual.md)   Single-playfield mode is enabled.
   [*](hardware/3-forming-a-basic-playfield-enabling-the-color-display.md)   Composite video color is enabled.
   [*](hardware/3-playfield-hardware-summary-of-playfield-registers.md)   Genlock audio is disabled.
   [*](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md)   Light pen is disabled.
   [*](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md)   Interlaced mode is enabled.
   [*](hardware/3-playfield-hardware-summary-of-playfield-registers.md)   External resynchronization is disabled.

The amount of memory you need to allocate for each bitplane depends upon
the resolution modes you have selected, because high resolution or
interlaced playfields contain more data and require larger bitplanes.

