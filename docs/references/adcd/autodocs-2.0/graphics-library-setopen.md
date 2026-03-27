---
title: graphics.library/SetOPen
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-setopen
functions: [AreaEnd]
libraries: [graphics.library]
---

# graphics.library/SetOPen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetOPen -- Change the Area OutLine pen and turn on Outline
                    mode for areafills.
SYNOPSIS

```c
    SetOPen(rp, pen)

    void SetOPen( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, UBYTE );
```
FUNCTION

```c
    This is implemented as a c-macro.
    Pen is the pen number that will be used to draw a border
    around an areafill during [AreaEnd()](autodocs-2.0/graphics-library-areaend.md).
```
INPUTS

```c
    rp = pointer to [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    pen = number  between 0-255
```
BUGS

SEE ALSO

```c
    [AreaEnd()](autodocs-2.0/graphics-library-areaend.md) [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
