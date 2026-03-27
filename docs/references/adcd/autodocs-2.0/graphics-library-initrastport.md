---
title: graphics.library/InitRastPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-initrastport
functions: []
libraries: []
---

# graphics.library/InitRastPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    InitRastPort -- Initialize raster port structure
SYNOPSIS


```c
    InitRastPort( rp )
                  a1

    void InitRastPort(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION
   Initialize a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure to standard values.

INPUTS

```c
    rp = pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure.
```
RESULT

```c
    all entries in [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) get zeroed out, with the following exceptions:

        Mask, FgPen, AOLPen, and LinePtrn are set to -1.
        The DrawMode is set to JAM2
        The font is set to the standard system font
```
NOTES

```c
    The struct Rastport describes a control structure
    for a write-able raster. The [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    describes how a complete single playfield display
    will be written into. A [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure is
    referenced whenever any drawing or filling
    operations are to be performed on a section of
    memory.

    The section of memory which is being used in this
    way may or may not be presently a part of the
    current actual onscreen display memory. The name
    of the actual memory section which is linked to
    the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) is referred to here as a "raster" or
    as a bitmap.

    NOTE: Calling the routine InitRastPort only
    establishes various defaults. It does NOT
    establish where, in memory, the rasters are
    located. To do graphics with this [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) the user
    must set up the [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) pointer in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
BUGS

SEE ALSO

```c
    [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```
