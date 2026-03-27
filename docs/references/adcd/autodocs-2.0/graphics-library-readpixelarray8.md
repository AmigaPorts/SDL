---
title: graphics.library/ReadPixelArray8
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-readpixelarray8
functions: [ReadPixel, ReadPixelLine8]
libraries: [graphics.library]
---

# graphics.library/ReadPixelArray8

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ReadPixelArray8 -- read the pen number value of a rectangular array
    of pixels starting at a specified x,y location and continuing
    through to another x,y location within a certain [RastPort](autodocs-2.0/includes-graphics-rastport-h.md). (V36)
```
SYNOPSIS

```c
    count = ReadPixelArray8(rp,xstart,ystart,xstop,ystop,array,temprp)
    D0                      A0 D0:16  D1:16  D2:16 D3:16 A2    A1
```
 LONG ReadPixelArray8(struct  [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, UWORD, UWORD, UWORD, UWORD,

```c
       UBYTE *, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

```c
    For each pixel in a rectangular region, combine the bits from each
    of the bit-planes used to describe a particular [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) into the pen
    number selector which that bit combination normally forms for the
    system hardware selection of pixel color.
```
INPUTS

```c
    rp    -  pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    (xstart,ystart) - starting point in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
    (xstop,ystop)   - stopping point in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
    array -  pointer to an array of ubytes from which to fetch the pixel
             data allocate at least ((((width+15)>>4)<<4)*(ystop-ystart+1))
             bytes.
    temprp - temporary rastport (copy of rp with [Layer](autodocs-2.0/includes-graphics-clip-h.md) set == NULL,
             temporary memory allocated for
             temprp->BitMap with Rows set == 1,
             temprp->BytesPerRow == (((width+15)>>4)<<1),
             and temporary memory allocated for
             temprp->BitMap->Planes[])
```
RESULT

```c
    For each pixel in the array:
        Pen - (0..255) number at that position is returned
      count - the number of pixels read.
```
NOTE

```c
    xstop must be >= xstart
    ystop must be >= ystart
```
BUGS

SEE ALSO

```c
    [ReadPixel()](autodocs-2.0/graphics-library-readpixel.md)  [ReadPixelLine8()](autodocs-2.0/graphics-library-readpixelline8.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [ReadPixel — graphics.library](../autodocs/graphics.library.md#readpixel)
- [ReadPixelLine8 — graphics.library](../autodocs/graphics.library.md#readpixelline8)
