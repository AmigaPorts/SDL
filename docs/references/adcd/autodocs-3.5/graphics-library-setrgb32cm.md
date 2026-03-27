---
title: graphics.library/SetRGB32CM
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setrgb32cm
functions: [GetColorMap, GetRGB32, SetRGB32, SetRGB4CM]
libraries: [graphics.library]
---

# graphics.library/SetRGB32CM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       SetRGB32CM -- Set one color register for this [ColorMap](autodocs-3.5/include-graphics-view-h.md). (V39)
```
   SYNOPSIS

```c
       SetRGB32CM(  cm,  n,   r,    g,    b)
                    a0  d0   d1    d2    d3

       void SetRGB4CM( struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) *, ULONG, ULONG, ULONG , ULONG);
```
   INPUTS
	cm = colormap
```c
       n = the number of the color register to set. Must not exceed the numbe
```
r of colors
	    allocated for the colormap.

```c
       r = red level (32 bit unsigned left justified fraction)
       g = green level
       b = blue level
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
       [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [GetRGB32()](autodocs-3.5/graphics-library-getrgb32.md) [SetRGB32()](autodocs-3.5/graphics-library-setrgb32.md) [SetRGB4CM()](autodocs-3.5/graphics-library-setrgb4cm-2.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)
```

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GetRGB32 — graphics.library](../autodocs/graphics.library.md#getrgb32)
- [SetRGB32 — graphics.library](../autodocs/graphics.library.md#setrgb32)
- [SetRGB4CM — graphics.library](../autodocs/graphics.library.md#setrgb4cm)
