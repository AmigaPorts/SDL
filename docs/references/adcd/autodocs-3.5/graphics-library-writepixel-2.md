---
title: graphics.library/WritePixel
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-writepixel-2
functions: [ReadPixel]
libraries: [graphics.library]
---

# graphics.library/WritePixel

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       WritePixel -- Change the pen num of one specific pixel in a
                     specified [RastPort](autodocs-3.5/include-graphics-rastport-h.md).
```
   SYNOPSIS

```c
       error = WritePixel(  rp, x,  y)
         d0                 a1 D0  D1
```
	[LONG](autodocs-3.5/include-exec-types-h.md) WritePixel( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [SHORT](autodocs-3.5/include-exec-types-h.md), [SHORT](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION

```c
       Changes the pen number of the selected pixel in the specified
       [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to that currently specified by PenA, the primary
       drawing pen. Obeys minterms in [RastPort](autodocs-3.5/include-graphics-rastport-h.md).
```
   INPUTS

```c
       rp - a pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
       (x,y) - point within the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) at which the selected
           pixel is located.
```
   RESULT
```c
       error = 0 if pixel succesfully changed
```
	      = -1 if (x,y) is outside the [RastPort](autodocs-3.5/include-graphics-rastport-h.md)

   BUGS

   SEE ALSO

```c
       [ReadPixel()](autodocs-3.5/graphics-library-readpixel-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)
```

---

## See Also

- [ReadPixel — graphics.library](../autodocs/graphics.library.md#readpixel)
