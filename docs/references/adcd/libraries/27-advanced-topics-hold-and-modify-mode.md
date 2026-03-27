---
title: 27 / Advanced Topics / Hold-And-Modify Mode
manual: libraries
chapter: libraries
section: 27-advanced-topics-hold-and-modify-mode
functions: []
libraries: []
---

# 27 / Advanced Topics / Hold-And-Modify Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In hold-and-modify mode you can create a single-playfield, low-resolution
display in which 4,096 different colors can be displayed simultaneously.
This requires your [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) to be defined with six bitplanes.  Under 1.3,
you specify HAM mode by setting the [HAM](libraries/27-display-routines-and-structures-viewport-display-modes.md) flag in the [ViewPort.Modes](libraries/27-display-routines-and-structures-viewport-display-modes.md) field.
Under Release 2, you specify HAM by selecting any ModeID which includes
HAM in its name as defined in <graphics/[displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md)>.

When you draw into the [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) associated with this [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md), you can
choose colors in one of four different ways.  If you draw using color
numbers 0 to 15, the pixel you draw will appear in the color specified in
that particular system color register.  If you draw with any other color
value (16 to 63) the color displayed depends on the color of the pixel
that is to the immediate left of this pixel on the screen.  To see how
this works, consider how the bitplanes are used in HAM.

Hold-and-modify mode requires six bitplanes.  Planes 5 and 6 are used to
modify the way bits from planes 1 through 4 are treated, as follows:

  * If the bit combination from planes 6 and 5 for any given pixel is 00,

```c
    normal color selection procedure is followed.  Thus, the bit
    combinations from planes 4 to 1, in that order of significance, are
    used to choose one of 16 color registers (registers 0 through 15).
```
  * If the bit combination in planes 6 and 5 is 01, the color of the

```c
    pixel immediately to the left of this pixel is duplicated and then
    modified.  The bit combinations from planes 4 through 1 are used to
    replace the four bits representing the blue value of the preceding
    pixel color. (No color registers are changed.)
```
  * If the bit combination in planes 6 and 5 is 10, then the color of the

    pixel immediately to the left of this pixel is duplicated and
    modified.  The bit combinations from planes 4 through 1 are used to
    replace the four bits representing the red value of the preceding
    pixel color.
  * If the bit combination in planes 6 and 5 is 11, then the color of the

    pixel immediately to the left of this pixel is duplicated and
    modified.  The bit combinations from planes 4 through 1 are used to
    replace the four bits representing the green value of the preceding
    pixel color.
You can use just five bitplanes in HAM mode.  In that case, the data for
the sixth plane is automatically assumed to be 0.  Note that for the first
pixel in each line, hold-and-modify begins with the background color.  The
color choice does not carry over from the preceding line.


```c
    Note:
    -----
    Since a typical hold-and-modify pixel only changes one of the three
    RGB color values at a time, color selection is limited.  HAM mode
    does allow for the display of 4,096 colors simultaneously, but there
    are only 64 color options for any given pixel (not 4,096).  The color
    of a pixel depends on the color of the preceding pixel.
```
