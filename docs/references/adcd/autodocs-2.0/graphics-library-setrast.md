---
title: graphics.library/SetRast
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-setrast
functions: [RectFill]
libraries: [graphics.library]
---

# graphics.library/SetRast

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetRast - Set an entire drawing area to a specified color.
SYNOPSIS

```c
    SetRast( rp, pen )
             a1  d0

    void SetRast( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, UBYTE );
```
FUNCTION

```c
    Set the entire contents of the specified [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) to the
    specified pen.
```
INPUTS

```c
    rp - pointer to [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    pen - the pen number (0-255) to jam into bitmap
```
RESULT

    All pixels within the drawing area are set to the
    selected pen number.
BUGS

SEE ALSO

```c
    [RectFill()](autodocs-2.0/graphics-library-rectfill.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [RectFill — graphics.library](../autodocs/graphics.library.md#rectfill)
