---
title: graphics.library/ClearScreen
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-clearscreen
functions: [ClearEOL, SetRast, Text]
libraries: [graphics.library]
---

# graphics.library/ClearScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ClearScreen -- Clear from current position to end of [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
SYNOPSIS

```c
    ClearScreen(rp)
                A1

    void ClearScreen(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

```c
    Clear a rectangular swath from the current position to the
    right edge of the rastPort with [ClearEOL](autodocs-2.0/graphics-library-cleareol.md), then clear the rest
    of the screen from just beneath the swath to the bottom of
    the rastPort.
    Clearing consists of setting the color of the swath to zero,
    or, if the DrawMode is 2, to the BgPen.
```
INPUTS

```c
    rp - pointer to [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
```
NOTES

    o   This function may use the blitter.
SEE ALSO

```c
    [ClearEOL()](autodocs-2.0/graphics-library-cleareol.md)  [Text()](autodocs-2.0/graphics-library-text.md)  [SetRast()](autodocs-2.0/graphics-library-setrast.md)
    [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [ClearEOL — graphics.library](../autodocs/graphics.library.md#cleareol)
- [SetRast — graphics.library](../autodocs/graphics.library.md#setrast)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
