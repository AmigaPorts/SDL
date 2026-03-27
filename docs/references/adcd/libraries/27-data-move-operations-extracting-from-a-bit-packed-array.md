---
title: 27 / / Data Move Operations / Extracting from a Bit-packed Array
manual: libraries
chapter: libraries
section: 27-data-move-operations-extracting-from-a-bit-packed-array
functions: [BltPattern, BltTemplate]
libraries: [graphics.library]
---

# 27 / / Data Move Operations / Extracting from a Bit-packed Array

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You use the routine [BltTemplate()](autodocs-2.0/graphics-library-blttemplate.md) to extract a rectangular area from a
source area and place it into a destination area. The following figure
shows an example.


     Array Start -->· · · · · · · · · · * * * · · ·<-- Line 1 end
  Line 1 end + 1 -->· · · · · · · · · · · * · · · ·


                    · · · · · · · · · · · * · · · ·
                    · · · · · · · · · · · * · · · ·
                    · · · · · · · · · · · * · · · ·
                    · · · · · · · · · · · * · · · ·
                    · · · · · · · · · · * * * · · ·

                    ------------------->
                Character starts 10-bits
               in from starting point on
              the left edge of the array.


    Figure 27-18: Example of Extracting from a Bit-Packed Array
For a rectangular bit array to be extracted from within a larger,
rectangular bit array, the system must know how the larger array is
organized.  For this extraction to occur properly, you also need to tell
the system the modulo for the inner rectangle. The modulo is the value
that must be added to the address pointer so that it points to the correct
word in the next line in this rectangularly organized array.

The following figure represents a single bitplane and the smaller
rectangle to be extracted. The modulo in this instance is 4, because at
the end of each line, you must add 4 to the address pointer to make it
point to the first word in the smaller rectangle.

   ________________________________________________
  |                                                |
  |  20    21    22    23    24    25    26    27  |<-- Larger source
  |                                                |    bit-plane image
  |  28    29    30    31    32    33    34    35  |
  |             ----------------------             |
  |  36    37  | 38    39    40    41 |  42    43  |
  |            |                      |<-----------|--- Smaller rectangle
  |  44    45  | 46    47    48    49 |  50    51  |    to be extracted
  |            |                      |            |
  |  52    53  | 54    55    56    57 |  58    59  |
  |             ----------------------             |
  |  60    61    62    63    64    65    66    67  |
  |________________________________________________|




                Figure 27-19: Modulo


    Warning:
    --------
    The modulo value must be an even number of bytes.
[BltTemplate()](autodocs-2.0/graphics-library-blttemplate.md) takes the following arguments:


```c
    BltTemplate(source, srcX, srcMod, &destRastPort, destX, destY,
                sizeX, sizeY);
```
The source argument specifies the rectangular bit array to use as the
source template.  Set this to the address of the nearest word (rounded
down) that contains the first line of the source rectangle.  The srcX
argument gives the exact bit position (0-15) within the source address at
which the rectangular bit array begins.  The srcMod argument sets the
source modulo so the next line of the rectangular bit array can be found.

The data from the source rectangle is copied into the destination [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)
specified by destRastPort. The destX and destY arguments indicate where
the data from the source rectangle should be positioned within the
destination RastPort.  The sizeX and sizeY arguments indicate the
dimensions of the data to be moved.

[BltTemplate()](autodocs-2.0/graphics-library-blttemplate.md) uses [FgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md), [BgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md), [DrawMode](libraries/27-the-rastport-structure-rastport-drawing-modes.md) and [Mask](libraries/27-the-rastport-structure-rastport-write-mask.md) to place the template
into the destination area. This routine differs from [BltPattern()](libraries/27-performing-data-move-operations-drawing-through-a-stencil.md) in that
only a solid color is deposited in the destination drawing area, with or
without a second solid color as the background (as in the case of text).
Also, the template can be arbitrarily bit-aligned and sized in x.

---

## See Also

- [BltPattern — graphics.library](../autodocs/graphics.library.md#bltpattern)
- [BltTemplate — graphics.library](../autodocs/graphics.library.md#blttemplate)
