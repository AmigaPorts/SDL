---
title: graphics.library/PolyDraw
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-polydraw
functions: [Draw, Move]
libraries: [graphics.library]
---

# graphics.library/PolyDraw

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    PolyDraw -- Draw lines from table of (x,y) values.
```
SYNOPSIS

```c
    PolyDraw( rp, count , array )
              a1   d0      a0

    void PolyDraw( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, WORD, WORD * );
```
FUNCTION

    starting with the first pair in the array, draw connected lines to
    it and every successive pair.
INPUTS

```c
    rp - pointer to [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    count -  number of (x,y) pairs in the array
    array - pointer to first (x,y) pair
```
BUGS

SEE ALSO

```c
    [Draw()](autodocs-2.0/graphics-library-draw.md) [Move()](autodocs-2.0/graphics-library-move.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [Draw — graphics.library](../autodocs/graphics.library.md#draw)
- [Move — graphics.library](../autodocs/graphics.library.md#move)
