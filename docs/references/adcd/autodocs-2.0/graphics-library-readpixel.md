---
title: graphics.library/ReadPixel
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-readpixel
functions: [WritePixel]
libraries: [graphics.library]
---

# graphics.library/ReadPixel

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ReadPixel -- read the pen number value of the pixel at a
                 specified x,y location within a certain [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
SYNOPSIS

```c
    penno = ReadPixel( rp,    x,    y )
      d0               a1  d0:16 d1:16

    LONG ReadPixel( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, SHORT, SHORT );
```
FUNCTION

```c
    Combine the bits from each of the bit-planes used to describe
    a particular [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) into the pen number selector which that
    bit combination normally forms for the system hardware selection
    of pixel color.
```
INPUTS

```c
    rp -  pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    (x,y) a point in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
```
RESULT

```c
    penno - the pen number of the pixel at (x,y) is returned.
            -1 is returned if the pixel cannot be read for some reason.
```
BUGS

SEE ALSO

```c
    [WritePixel()](autodocs-2.0/graphics-library-writepixel.md)    [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [WritePixel — graphics.library](../autodocs/graphics.library.md#writepixel)
