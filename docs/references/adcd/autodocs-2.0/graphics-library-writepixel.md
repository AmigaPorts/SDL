---
title: graphics.library/WritePixel
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-writepixel
functions: [ReadPixel]
libraries: [graphics.library]
---

# graphics.library/WritePixel

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    WritePixel -- Change the pen num of one specific pixel in a
                 specified [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
SYNOPSIS

```c
    error = WritePixel(  rp, x,  y)
     d0                 a1 D0  D1

    LONG WritePixel( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, SHORT, SHORT );
```
FUNCTION

```c
    Changes the pen number of the selected pixel in the specified
    [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) to that currently specified by PenA, the primary
    drawing pen. Obeys minterms in [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
INPUTS

```c
    rp    - a pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    (x,y) - point within the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) at which the selected
            pixel is located.
```
RESULT

```c
    error = 0 if pixel succesfully changed
          = -1 if (x,y) is outside the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
```
BUGS

SEE ALSO

```c
    [ReadPixel()](autodocs-2.0/graphics-library-readpixel.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [ReadPixel — graphics.library](../autodocs/graphics.library.md#readpixel)
