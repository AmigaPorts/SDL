---
title: graphics.library/Draw
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-draw
functions: [Move]
libraries: [graphics.library]
---

# graphics.library/Draw

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Draw -- Draw a line between the current pen position
                   and the new x,y position.
SYNOPSIS

```c
    Draw( rp,   x,     y)
         a1  d0:16  d1:16

    void Draw( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, SHORT, SHORT);
```
FUNCTION

```c
    Draw a line from the current pen position to (x,y).
```
INPUTS


```c
    rp - pointer to the destination [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
    x,y - coordinates of where in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) to end the line.
```
BUGS

SEE ALSO

```c
    [Move()](autodocs-2.0/graphics-library-move.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [Move — graphics.library](../autodocs/graphics.library.md#move)
