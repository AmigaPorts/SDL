---
title: graphics.library/SetDrMd
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-setdrmd
functions: [SetAPen, SetBPen]
libraries: [graphics.library]
---

# graphics.library/SetDrMd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetDrMd -- Set drawing mode for a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
```
SYNOPSIS

```c
    SetDrMd( rp, mode )
             a1  d0:8

    void SetDrMd( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, UBYTE );
```
FUNCTION

    Set the drawing mode for lines, fills and text.
    Get the bit definitions from rastport.h
INPUTS

```c
    rp - pointer to [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure.
    mode - 0-255, some combinations may not make much sense.
```
RESULT

    The mode set is dependant on the bits selected.
    Changes minterms to reflect new drawing mode.
    Sets line drawer to restart pattern.
BUGS

SEE ALSO

```c
    [SetAPen()](autodocs-2.0/graphics-library-setapen.md) [SetBPen()](autodocs-2.0/graphics-library-setbpen.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [SetAPen — graphics.library](../autodocs/graphics.library.md#setapen)
- [SetBPen — graphics.library](../autodocs/graphics.library.md#setbpen)
