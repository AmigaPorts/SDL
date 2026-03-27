---
title: graphics.library/ReadPixel
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-readpixel-2
functions: [WritePixel]
libraries: [graphics.library]
---

# graphics.library/ReadPixel

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       ReadPixel -- read the pen number value of the pixel at a
                    specified x,y location within a certain [RastPort](autodocs-3.5/include-graphics-rastport-h.md).
```
   SYNOPSIS

```c
       penno = ReadPixel( rp,    x,    y )
         d0               a1  d0:16 d1:16
```
	[LONG](autodocs-3.5/include-exec-types-h.md) ReadPixel( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [SHORT](autodocs-3.5/include-exec-types-h.md), [SHORT](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION

```c
       Combine the bits from each of the bit-planes used to describe
       a particular [RastPort](autodocs-3.5/include-graphics-rastport-h.md) into the pen number selector which that
       bit combination normally forms for the system hardware selection
       of pixel color.
```
   INPUTS

```c
       rp -  pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
       (x,y) a point in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
```
   RESULT
```c
       penno - the pen number of the pixel at (x,y) is returned.
```
		-1 is returned if the pixel cannot be read for some reason.

   BUGS

   SEE ALSO

```c
       [WritePixel()](autodocs-3.5/graphics-library-writepixel-2.md)	[graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)
```

---

## See Also

- [WritePixel — graphics.library](../autodocs/graphics.library.md#writepixel)
