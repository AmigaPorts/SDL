---
title: 10 / / Custom Pointer / The Sprite Data Structure
manual: libraries
chapter: libraries
section: 10-custom-pointer-the-sprite-data-structure
functions: [AllocMem, SetRGB4]
libraries: [exec.library, graphics.library]
---

# 10 / / Custom Pointer / The Sprite Data Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To define the pointer, set up a sprite data structure (sprites are one of
the general purpose Amiga graphics structures). The sprite image data must
be located in Chip memory, which is memory that can be accessed by the
special Amiga hardware chips. Expansion, or Fast memory cannot be
addressed by the custom chips. Ensure that data is in Chip memory by using
the [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) function with the [MEMF_CHIP](libraries/17-introduction-to-exec-dynamic-memory-allocation.md) flag, and copying the data to
the allocated space. Alternately, use the tools or flags provided by each
compiler for this purpose. See the "[Exec Memory Allocation](libraries/20-exec-memory-allocation-memory-functions.md)" chapter for
more information.

A sprite data structure is made up of words of data. In a pointer sprite,
the first two words and the last two words are reserved for the system and
should be set to zero. All other words contain the sprite image data.

The pointer in the example, a standard busy pointer, is sixteen lines high
and sixteen pixels wide.  Currently, all sprites are two bit planes deep,
with one word of data for each line of each plane.  The example sprite
image consists of 36 words (2 planes x 18 lines = 36 words).  Add to this
the four reserved words of control information for a total of 40 words of
data.  See the [example](libraries/lib-examples-custompointer-c.md) below for the complete data definition.

The sprite data words are combined to determine which color will appear at
each pixel position of each row of the sprite.  The first two words of
image data, 0x0400 and 0x07C0, represent the top line of the sprite.  The
numbers must be viewed as binary numbers and combined in a bit-wise
fashion.  The highest bit from each word are combined to form a two bit
number representing the color register for the leftmost pixel.  The next
two bits represent the next pixel in the row, and so on, until the low
order bits from each word represent the rightmost pixel in the row.

For example:


```c
                  Hex                  Binary
                  ---                  ------

    Second word  0x07C0  0 0 0 0 0  1  1 1 1 1  0 0 0 0 0 0
    First word   0x0400  0 0 0 0 0  1  0 0 0 0  0 0 0 0 0 0

                         \________/\_/\_______/\___________/
                             |      |     |          |
                             |      |     |          |
                             |      |     |          `-- 00 = color 0
                             |      |     |
                             |      |     `-- 10 = color 2
                             |      |
                             |      `-- 11 = color 3
                             |
                             `-- 00 = color 0


    Pointer Color Ordering.
    -----------------------
    The first word in a line gives the least significant bit of the
    color register and the second word gives the most significant bit.
```
Sprites get their color information from the color registers much like
screens do.  See the Amiga [Hardware](hardware/4-forming-a-sprite-sprite-color.md) Reference Manual for more information
on the assignment of color registers to sprites.  Note that the color
number given above is added to a base number to determine the actual
hardware color register.

The colors of the Intuition pointer may be changed.  The Intuition pointer
is always sprite 0.  To change the colors of sprite 0, call the graphics
library routine [SetRGB4()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md).

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
