---
title: graphics.library/GetColorMap
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getcolormap-2
functions: [FreeColorMap, GetRGB32, GetRGB4, SetRGB4]
libraries: [graphics.library]
---

# graphics.library/GetColorMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME


       GetColorMap -- allocate and initialize Colormap
   SYNOPSIS

```c
       cm = GetColorMap( entries )
       d0		    d0
```
	struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) *GetColorMap( ULONG);

   FUNCTION

```c
       Allocates, initializes and returns a pointer to a [ColorMap](autodocs-3.5/include-graphics-view-h.md)
       data structure, later enabling calls to [SetRGB4/SetRGB32](autodocs-3.5/graphics-library-setrgb32.md)
       and [LoadRGB4/LoadRGB32](autodocs-3.5/graphics-library-loadrgb32.md) to load colors for a view port. The
       ColorTable pointer in the [ColorMap](autodocs-3.5/include-graphics-view-h.md) structure points to a
       hardware specific colormap data structure. You should not
       count on it being anything you can understand. Use
       [GetRGB4()/GetRGB32()](autodocs-3.5/graphics-library-getrgb32.md) to query it or [SetRGB4CM/SetRGB32CM](autodocs-3.5/graphics-library-setrgb32cm.md)
       to set it directly.
```
   INPUTS
	entries - number of entries for this colormap

    RESULT
	The pointer value returned by this routine, if nonzero,

       may be stored into the ViewPort.ColorMap pointer.
       If a value of 0 is returned, the system was unable
       to allocate enough memory space for the required
       data structures.
   BUGS

   SEE ALSO

```c
       [SetRGB4()](autodocs-3.5/graphics-library-setrgb4-2.md) [FreeColorMap()](autodocs-3.5/graphics-library-freecolormap-2.md)
```

---

## See Also

- [FreeColorMap — graphics.library](../autodocs/graphics.library.md#freecolormap)
- [GetRGB32 — graphics.library](../autodocs/graphics.library.md#getrgb32)
- [GetRGB4 — graphics.library](../autodocs/graphics.library.md#getrgb4)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
