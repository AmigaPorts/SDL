---
title: graphics.library/BltPattern
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-bltpattern-2
functions: [AreaEnd]
libraries: [graphics.library]
---

# graphics.library/BltPattern

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	BltPattern --  Using standard drawing rules for areafill,
					 blit through a mask.

   SYNOPSIS

```c
       BltPattern(rp, mask, xl, yl, maxx, maxy, bytecnt)
                  a1,  a0   d0  d1   d2   d3     d4
```
	void BltPattern
	   (struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, void *, [SHORT](autodocs-3.5/include-exec-types-h.md), [SHORT](autodocs-3.5/include-exec-types-h.md), [SHORT](autodocs-3.5/include-exec-types-h.md), [SHORT](autodocs-3.5/include-exec-types-h.md), SHORT);

   FUNCTION

```c
       Blit using drawmode,areafill pattern, and mask
       at position rectangle (xl,yl) (maxx,maxy).
```
   INPUTS

```c
       rp    -  points to the destination [RastPort](autodocs-3.5/include-graphics-rastport-h.md) for the blit.
       mask  -  points to 2 dimensional mask if needed
                if mask == NULL then use a rectangle.
       xl,yl -  coordinates of upper left of rectangular region in [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
       maxx,maxy - points to lower right of rectangular region in [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
       bytecnt - BytesPerRow for mask
```
   RESULT

   SEE ALSO
	[AreaEnd()](autodocs-3.5/graphics-library-areaend-2.md)

---

## See Also

- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
