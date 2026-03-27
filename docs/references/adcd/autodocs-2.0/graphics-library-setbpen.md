---
title: graphics.library/SetBPen
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-setbpen
functions: [SetAPen]
libraries: [graphics.library]
---

# graphics.library/SetBPen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetBPen -- Set secondary pen for a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
```
SYNOPSIS

```c
    SetBPen( rp, pen )
             a1  d0

    void SetBPen( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, UBYTE );
```
FUNCTION

    Set the secondary drawing pen for lines, fills, and text.
INPUTS

```c
    rp - pointer to [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure.
    pen - (0-255)
```
RESULT

```c
    Changes the minterms in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) to reflect new secondary pen.
    Sets line drawer to restart pattern.
```
BUGS

SEE ALSO

```c
    [SetAPen()](autodocs-2.0/graphics-library-setapen.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [SetAPen — graphics.library](../autodocs/graphics.library.md#setapen)
