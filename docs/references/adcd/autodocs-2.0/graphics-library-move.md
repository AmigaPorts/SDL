---
title: graphics.library/Move
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-move
functions: [Draw, Text]
libraries: [graphics.library]
---

# graphics.library/Move

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Move -- Move graphics pen position.
SYNOPSIS

```c
    Move( rp,   x,    y)
          a1  d0:16 d1:16

    void Move( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, SHORT, SHORT );
```
FUNCTION

```c
    Move graphics pen position to (x,y) relative to upper left (0,0)
    of [RastPort](autodocs-2.0/includes-graphics-rastport-h.md). This sets the starting point for subsequent [Draw()](autodocs-2.0/graphics-library-draw.md)
    and [Text()](autodocs-2.0/graphics-library-text.md) calls.
```
INPUTS

```c
    rp - pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    x,y - point in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
```
RESULTS

BUGS

SEE ALSO

```c
    Draw [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [Draw — graphics.library](../autodocs/graphics.library.md#draw)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
