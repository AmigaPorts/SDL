---
title: 3 / / Bitplanes and Color / The Color Table
manual: hardware
chapter: hardware
section: 3-bitplanes-and-color-the-color-table
functions: []
libraries: []
---

# 3 / / Bitplanes and Color / The Color Table

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The color table contains 32 registers, and you may load a different color
into each of the registers. Here is a condensed view of the contents of
the color table:




```c
     Register Name   Contents                Meaning
     -------------   --------                -------
       [COLOR00](hardware/3-coding-for-correct-coloring-a-one-or-two-color-playfield.md)        12 bits        User-defined color for the
                                     background area and borders.

       COLOR01        12 bits        User-defined color number 1
                                     (For example, the alternate color
                                     selection for a two-color playfield).

       COLOR02        12 bits        User-defined color number 2.

          .              .
          .              .
          .	         .

       COLOR31	      12 bits	     User-defined color number 31.


              Table 3-2: Portion of the Color Table
```
 [COLOR00](hardware/3-coding-for-correct-coloring-a-one-or-two-color-playfield.md)  is always reserved for the background color. The background color
shows in any area on the display where there is no other object present
and is also displayed outside the defined display window, in the border
area.

   Genlocks and the background color.
   ---------------------------------
   If you are using the optional genlock board for  [video input](hardware/3-advanced-topics-using-an-external-video-source.md)  from a
   camera, VCR, or laser disk, the background color will be replaced by
   the incoming video display.

Twelve bits of color selection allow you to define, for each of the 32
registers, one of 4,096 possible colors, as shown in Table 3-3.




                  Bits            Color
                  ----            -----
                  Bits 15 - 12    Unused
                  Bits 11 - 8     Red
                  Bits 7 - 4      Green
                  Bits 3 - 0      Blue


       Table 3-3: Contents of the Color Registers
Table 3-4 shows some sample color register bit assignments and the
resulting colors. At the end of the chapter is a more extensive
 [Color Register list](hardware/3-color-selection-registers-some-sample-color-register.md) .




            Contents of the       Resulting
            Color Register          Color
            ---------------       ---------
                 $FFF               White
                 $6FE               Sky blue
                 $DB9               Tan
                 $000               Black


        Table 3-4: Sample Color Register Contents
Some sample instructions for loading the color registers are shown below:

   LEA     CUSTOM,a0              ; Get base address of custom hardware...
   MOVE.W  #$FFF,COLOR00(a0)      ; Load white into color register 0
   MOVE.W  #$6FE,COLOR01(a0)      ; Load sky blue into color register 1


   The color registers are write-only.
   ----------------------------------
   Only by looking at the screen can you find out the contents of
   each color register.  As a standard practice, then, for these
   and certain other write-only registers, you may wish to keep a
   "back-up" or "shadow" copy in RAM.  As you write to the color
   register itself, you should update this RAM copy.  If you do so,
   you will always know the value each register contains.

