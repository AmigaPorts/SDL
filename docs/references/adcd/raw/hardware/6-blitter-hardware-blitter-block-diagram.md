# 6 Blitter Hardware / Blitter Block Diagram


Figure 6-13 shows the basic building blocks for a single bit of a 16-bit
wide operation of the blitter.  It does not cover the line-drawing
hardware.


```c
     [Figure 6-13: Blitter Block Diagram](../Hardware_Manual_guide/node02DD.html) 
```
*  The upper left corner shows how the first-- and last-- word  [masks](../Hardware_Manual_guide/node011F.html#line42)  are
   applied to the incoming A-source data.  When the blit shrinks to one
   word wide, both  [masks](../Hardware_Manual_guide/node011F.html#line42)  are applied.

*  The shifter (upper right and center left) drawing illustrates how 16
   bits of data is taken from a specified position within a 32-bit
   register, based on the A  [shift](../Hardware_Manual_guide/node011F.html)  or B  [shift](../Hardware_Manual_guide/node011F.html)  values shown in  [BLTCON0](../Hardware_Manual_guide/node001A.html) 
   and  [BLTCON1](../Hardware_Manual_guide/node001A.html) .

*  The  [minterm](../Hardware_Manual_guide/node011D.html)  generator (center right) illustrates how the  [minterm](../Hardware_Manual_guide/node011D.html) 
   select bits either allow or inhibit the use of a specific  [minterm](../Hardware_Manual_guide/node011D.html) .

*  The drawing shows how the fill operation works on the data generated
   by the  [minterm](../Hardware_Manual_guide/node011D.html)  combinations.  Fill operations can be performed
   simultaneously with other complex logic operations.

*  At the bottom, the drawing shows that data generated for the
   destination can be prevented from being written to a destination by
   using one of the blitter control bits.

*  Not shown on this diagram is the logic for zero detection, which
   looks at every bit generated for the destination.  If there are any
   1-bits generated, this logic indicates that the area of the blit
   contained at least one 1-bit (zero detect is false.)

