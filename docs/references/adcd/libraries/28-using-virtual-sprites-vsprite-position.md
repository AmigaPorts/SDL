---
title: 28 / Using Virtual Sprites / VSprite Position
manual: libraries
chapter: libraries
section: 28-using-virtual-sprites-vsprite-position
functions: []
libraries: []
---

# 28 / Using Virtual Sprites / VSprite Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To control the position of a VSprite, the x and y variables in the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md)
structure are used.  These specify where the upper left corner of the
VSprite will be, relative to the upper left corner of the playfield area
it appears over.  So if VSprites are used under Intuition and within a
screen, they will be positioned relative to the upper left-hand corner of
the screen.

In a 320 by 200 screen, a y value of 0 puts the VSprite at the top of that
display, a y value of (200 - VSprite height) puts the VSprite at the
bottom.  And an x value of 0 puts the VSprite at the left edge of that
display, while an x value of (320 - VSprite width) puts the VSprite at the
far right.  Values of less than (0,0) or greater than (320, 200) may be
used to move the VSprite partially or entirely off the screen, if desired.

See the "[Graphics Primitives](libraries/27-display-routines-and-structures-viewport-display-memory.md)" chapter for more information on display
coordinates and display size.  See the Amiga [Hardware](hardware/amiga-hardware-reference-manual-4-sprite-hardware.md) Reference Manual for
more information on hardware sprites.


    Position VSprites Properly.
    ---------------------------
    It is important that the starting position of true VSprites is not
    less than -20 in the y direction, which is the start of the active
    display area for sprites.  Also, if they are moved too far to the
    left, true VSprites may not have enough DMA time to be displayed.
The x, y values may be set like this to put the VSprite in the upper-left:


```c
    myVSprite.Y = 0;
    myVSprite.X = 0;
```
