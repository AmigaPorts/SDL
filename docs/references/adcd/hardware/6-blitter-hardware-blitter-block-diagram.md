---
title: 6 Blitter Hardware / Blitter Block Diagram
manual: hardware
chapter: hardware
section: 6-blitter-hardware-blitter-block-diagram
functions: []
libraries: []
---

# 6 Blitter Hardware / Blitter Block Diagram

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Figure 6-13 shows the basic building blocks for a single bit of a 16-bit
wide operation of the blitter.  It does not cover the line-drawing
hardware.


```c
     [Figure 6-13: Blitter Block Diagram](hardware/hard-pics-6-13-pic.md) 
```
*  The upper left corner shows how the first-- and last-- word  [masks](hardware/6-blitter-hardware-shifts-and-masks.md)  are
   applied to the incoming A-source data.  When the blit shrinks to one
   word wide, both  [masks](hardware/6-blitter-hardware-shifts-and-masks.md)  are applied.

*  The shifter (upper right and center left) drawing illustrates how 16
   bits of data is taken from a specified position within a 32-bit
   register, based on the A  [shift](hardware/6-blitter-hardware-shifts-and-masks.md)  or B  [shift](hardware/6-blitter-hardware-shifts-and-masks.md)  values shown in  [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md) 
   and  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md) .

*  The  [minterm](hardware/6-function-generator-designing-the-lf-control-byte-with.md)  generator (center right) illustrates how the  [minterm](hardware/6-function-generator-designing-the-lf-control-byte-with.md) 
   select bits either allow or inhibit the use of a specific  [minterm](hardware/6-function-generator-designing-the-lf-control-byte-with.md) .

*  The drawing shows how the fill operation works on the data generated
   by the  [minterm](hardware/6-function-generator-designing-the-lf-control-byte-with.md)  combinations.  Fill operations can be performed
   simultaneously with other complex logic operations.

*  At the bottom, the drawing shows that data generated for the
   destination can be prevented from being written to a destination by
   using one of the blitter control bits.

*  Not shown on this diagram is the logic for zero detection, which
   looks at every bit generated for the destination.  If there are any
   1-bits generated, this logic indicates that the area of the blit
   contained at least one 1-bit (zero detect is false.)

