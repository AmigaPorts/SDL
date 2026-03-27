---
title: graphics.library/ClearEOL
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-cleareol
functions: [ClearScreen, SetRast, Text]
libraries: [graphics.library]
---

# graphics.library/ClearEOL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ClearEOL -- Clear from current position to end of line.
SYNOPSIS

```c
    ClearEOL(rp)
             A1

    void ClearEOL(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

    Clear a rectangular swath from the current position to the
    right edge of the rastPort.  The height of the swath is taken
    from that of the current text font, and the vertical
    positioning of the swath is adjusted by the text baseline,
    such that text output at this position would lie wholly on
    this newly cleared area.
    Clearing consists of setting the color of the swath to zero,
    or, if the DrawMode is 2, to the BgPen.
INPUTS

```c
    rp - pointer to [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
```
RESULT

NOTES

    o   This function may use the blitter.
SEE ALSO

```c
    [Text()](autodocs-2.0/graphics-library-text.md)  [ClearScreen()](autodocs-2.0/graphics-library-clearscreen.md)  [SetRast()](autodocs-2.0/graphics-library-setrast.md)
    [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [ClearScreen — graphics.library](../autodocs/graphics.library.md#clearscreen)
- [SetRast — graphics.library](../autodocs/graphics.library.md#setrast)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
