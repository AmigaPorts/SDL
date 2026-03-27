---
title: 27 / / RastPort Structure / RastPort Line and Area Drawing Patterns
manual: libraries
chapter: libraries
section: 27-rastport-structure-rastport-line-and-area-drawing
functions: []
libraries: []
---

# 27 / / RastPort Structure / RastPort Line and Area Drawing Patterns

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) data structure provides two different pattern variables that
it uses during the various drawing functions: a line pattern and an area
pattern. The line pattern is 16 bits wide and is applied to all lines.
When you initialize a RastPort, this line pattern value is set to all 1s
(hex FFFF), so that solid lines are drawn. You can also set this pattern
to other values to draw dotted lines if you wish. For example, you can
establish a dotted line pattern with the graphics macro [SetDrPt()](autodocs-2.0/includes-graphics-gfxmacros-h.md):


```c
    SetDrPt(&rastPort, 0xCCCC);
```
The second argument is a bit-pattern, 1100110011001100, to be applied to
all lines drawn. If you draw multiple, connected lines, the pattern
cleanly connects all the points.

The area pattern is also 16 bits wide and its height is some power of two.
This means that you can define patterns in heights of 1, 2, 4, 8, 16, and
so on.  To tell the system how large a pattern you are providing, use the
graphics macro [SetAfPt()](autodocs-2.0/includes-graphics-gfxmacros-h.md):


```c
    SetAfPt(&rastPort, &areaPattern, power_of_two);
```
The &areaPattern argument is the address of the first word of the area
pattern and power_of_two specifies how many words are in the pattern. For
example:


```c
    USHORT ditherData[] =
    {
        0x5555, 0xAAAA
    };

    SetAfPt(&rastPort, ditherData, 1);
```
This example produces a small cross-hatch pattern, useful for shading.
Because power_of_two is set to 1, the pattern height is 2 to the 1st, or 2
rows high.

To clear the area fill pattern, use:


```c
    SetAfPt(&rastPort, NULL, 0);


    Pattern Positioning.
    --------------------
    The pattern is always positioned with respect to the upper left
    corner of the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) drawing area (the 0,0 coordinate).  If you
    draw two rectangles whose edges are adjacent, the pattern will be
    continuous across the rectangle boundaries.
```
The last example given produces a two-color pattern with one color where
there are 1s and the other color where there are 0s in the pattern.  A
special mode allows you to develop a pattern having up to 256 colors.  To
create this effect, specify power_of_two as a negative value instead of a
positive value.  For instance, the following initialization establishes an
8-color checkerboard pattern where each square in the checkerboard has a
different color.


```c
    USHORT areaPattern[3][8] =
    {
    /* plane 0 pattern */
        {
               0x0000, 0x0000,
               0xffff, 0xffff,
               0x0000, 0x0000,
               0xffff, 0xffff
        },
    /* plane 1 pattern */
        {
               0x0000, 0x0000,
               0x0000, 0x0000,
               0xffff, 0xffff,
               0xffff, 0xffff
        },
    /* plane 2 pattern */
        {
               0xff00, 0xff00,
               0xff00, 0xff00,
               0xff00, 0xff00,
               0xff00, 0xff00
        }
    };

    SetAfPt(&rastPort, &areaPattern, -3);

    /* when doing this, it is best to set */
    /* three other parameters as follows: */
    SetAPen(&rastPort, -1);
    SetBPen(&rastPort, 0);
    SetDrMd(&rastPort, JAM2);
```
If you use this multicolored pattern mode, you must provide as many planes
of pattern data as there are planes in your [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md).

