---
title: graphics.library/Draw
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-draw-2
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
```
	void Draw( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [SHORT](autodocs-3.5/include-exec-types-h.md), SHORT);

   FUNCTION

```c
       Draw a line from the current pen position to (x,y).
```
   INPUTS

	rp - pointer to the destination [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	x,y - coordinates of where in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to end the line.

   BUGS

   SEE ALSO
	[Move()](autodocs-3.5/graphics-library-move-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [Move — graphics.library](../autodocs/graphics.library.md#move)
