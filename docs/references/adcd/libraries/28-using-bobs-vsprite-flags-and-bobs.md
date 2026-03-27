---
title: 28 / Using Bobs / VSprite Flags and Bobs
manual: libraries
chapter: libraries
section: 28-using-bobs-vsprite-flags-and-bobs
functions: [AllocRaster]
libraries: [graphics.library]
---

# 28 / Using Bobs / VSprite Flags and Bobs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The bits in the [VSprite.Flags](autodocs-2.0/includes-graphics-gels-h.md) field that apply to a Bob are the [VSPRITE](libraries/28-using-virtual-sprites-using-vsprite-flags.md)
flag, the [SAVEBACK](autodocs-2.0/includes-graphics-gels-h.md) flag and the [OVERLAY](autodocs-2.0/includes-graphics-gels-h.md) flag.  When a [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure is
used to define a Bob, the VSPRITE flag in the VSprite.Flags field must be
set to zero.  This tells the system that this GEL is a Bob type.

To have the GEL routines save the background before the Bob is drawn and
restore the background after the Bob is removed, specify the [SAVEBACK](autodocs-2.0/includes-graphics-gels-h.md) flag
(stands for "save the background") in the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure [Flags](autodocs-2.0/includes-graphics-gels-h.md) field.
If this flag is set, the [SaveBuffer](libraries/28-using-bobs-the-bob-structure.md) must have been allocated, which is
where the system puts this saved background area.  The buffer must be
large enough to save all the background bitplanes, regardless of how many
planes the Bob has.  The size in words can be calculated as follows:


```c
    /* Note that Bob.Width is in units of words. */
    size = Bob.Width * Bob.Height * RastPort.BitMap.Depth;
```
To allocate this space, the graphics function [AllocRaster()](libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md) can be used.
AllocRaster() takes the width in bits, so it is a convenient way to
allocate the space needed.  The [makeBob()](libraries/lib-examples-animtools-c.md) routine below shows another way
to correctly allocate this buffer. For example:


```c
    /* space for 16 bits times 5 lines times 5 bitplanes */
    myBob.SaveBuffer = AllocRaster( (UWORD) 16, (UWORD) (5 * 5) );


    Warning:
    --------
    The [SaveBuffer](libraries/28-using-bobs-the-bob-structure.md) must be allocated from Chip memory and contain an
    even number of word-aligned bytes.  The [AllocRaster()](libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md) function
    does this for you.  The AllocRaster() function rounds the width
    value up to the next integer multiple of 16 bits which is greater
    than or equal to the current value an it obtains memory from the Chip
    memory pool.
```
[OVERLAY](autodocs-2.0/includes-graphics-gels-h.md) is the other [VSprite.Flags](autodocs-2.0/includes-graphics-gels-h.md) item that applies to Bobs. If this flag
is set, it means that the background's original pixels show through in any
area where there are 0 bits in the Bob's shadow mask ([ImageShadow](libraries/28-other-items-influencing-bob-colors-imageshadow.md),
explained later).  The space for the ImageShadow shadow mask must have
been allocated and initialized.  The ImageShadow mask must be allocated
from Chip memory.

If the [OVERLAY](autodocs-2.0/includes-graphics-gels-h.md) bit is cleared, the system uses the entire rectangle of
words that define the Bob image to replace the playfield area at the
specified x,y coordinates.  See the paragraphs below called "[ImageShadow](libraries/28-other-items-influencing-bob-colors-imageshadow.md)".

---

## See Also

- [AllocRaster — graphics.library](../autodocs/graphics.library.md#allocraster)
