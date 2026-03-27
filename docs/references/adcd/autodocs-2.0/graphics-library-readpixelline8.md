---
title: graphics.library/ReadPixelLine8
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-readpixelline8
functions: [ReadPixel]
libraries: [graphics.library]
---

# graphics.library/ReadPixelLine8

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ReadPixelLine8 -- read the pen number value of a horizontal line
    of pixels starting at a specified x,y location and continuing
    right for count pixels. (V36)
```
SYNOPSIS

```c
    count = ReadPixelLine8(rp,xstart,ystart,width,array,temprp)
    D0                     A0 D0:16  D1:16  D2    A2    A1

    LONG ReadPixelLine8(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, UWORD, UWORD, UWORD,
         UBYTE *, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) * );
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
    rp     - pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    (x,y)  - a point in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
    width  - count of horizontal pixels to read
    array -  pointer to an array of UBYTEs from which to fetch the pixel
             data allocate at least (((width+15)>>4)<<4) bytes.
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
    count   - the number of pixels read.
```
NOTE

    width must be non negative
BUGS

SEE ALSO

```c
    [ReadPixel()](autodocs-2.0/graphics-library-readpixel.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [ReadPixel — graphics.library](../autodocs/graphics.library.md#readpixel)
