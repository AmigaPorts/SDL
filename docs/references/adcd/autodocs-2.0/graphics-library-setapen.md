---
title: graphics.library/SetAPen
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-setapen
functions: [SetBPen]
libraries: [graphics.library]
---

# graphics.library/SetAPen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetAPen -- Set the primary pen for a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
SYNOPSIS

```c
    SetAPen( rp, pen )
             a1  d0

    void SetAPen( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, UBYTE );
```
FUNCTION

    Set the primary drawing pen for lines, fills, and text.
INPUTS

```c
    rp - pointer to [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure.
    pen - (0-255)
```
RESULT

```c
    Changes the minterms in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) to reflect new primary pen.
    Sets line drawer to restart pattern.
```
BUGS

SEE ALSO

```c
    [SetBPen()](autodocs-2.0/graphics-library-setbpen.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [SetBPen — graphics.library](../autodocs/graphics.library.md#setbpen)
