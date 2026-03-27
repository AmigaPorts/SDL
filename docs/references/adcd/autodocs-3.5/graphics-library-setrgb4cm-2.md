---
title: graphics.library/SetRGB4CM
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setrgb4cm-2
functions: [GetColorMap, GetRGB4, SetRGB4]
libraries: [graphics.library]
---

# graphics.library/SetRGB4CM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       SetRGB4CM -- Set one color register for this [ColorMap](autodocs-3.5/include-graphics-view-h.md).
```
   SYNOPSIS

```c
       SetRGB4CM(  cm,  n,   r,    g,    b)
                   a0  d0  d1:4  d2:4  d3:4

       void SetRGB4CM( struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) *, [SHORT](autodocs-3.5/include-exec-types-h.md), [UBYTE](autodocs-3.5/include-exec-types-h.md), [UBYTE](autodocs-3.5/include-exec-types-h.md), [UBYTE](autodocs-3.5/include-exec-types-h.md) );
```
   INPUTS
	cm = colormap
```c
       n = the number of the color register to set. Ranges from 0 to 31
```
	    on current Amiga displays.

```c
       r = red level (0-15)
       g = green level (0-15)
       b = blue level (0-15)
```
   RESULT
	Store the (r,g,b) triplet at index n of the [ColorMap](autodocs-3.5/include-graphics-view-h.md) structure.
```c
       This function can be used to set up a [ColorMap](autodocs-3.5/include-graphics-view-h.md) before before
```
	linking it into a viewport.

   BUGS

   SEE ALSO

```c
       [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [GetRGB4()](autodocs-3.5/graphics-library-getrgb4-2.md) [SetRGB4()](autodocs-3.5/graphics-library-setrgb4-2.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)
```

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GetRGB4 — graphics.library](../autodocs/graphics.library.md#getrgb4)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
