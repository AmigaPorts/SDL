---
title: graphics.library/GetColorMap
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-getcolormap
functions: [FreeColorMap, GetRGB4, SetRGB4]
libraries: [graphics.library]
---

# graphics.library/GetColorMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME


    GetColorMap -- allocate and initialize Colormap
SYNOPSIS

```c
    cm = GetColorMap( entries )
          d0                   d0

    struct [ColorMap](autodocs-2.0/includes-graphics-view-h.md) *GetColorMap( ULONG);
```
FUNCTION

```c
    Allocates, initializes and returns a pointer to a [ColorMap](autodocs-2.0/includes-graphics-view-h.md)
    data structure, later enabling calls to [SetRGB4](autodocs-2.0/graphics-library-setrgb4.md)
    and [LoadRGB4](autodocs-2.0/graphics-library-loadrgb4.md) to load colors for a view port. The ColorTable
    pointer in the [ColorMap](autodocs-2.0/includes-graphics-view-h.md) structure points to a hardware
    specific colormap data structure. You should not count on
    it being anything you can understand. Use [GetRGB4()](autodocs-2.0/graphics-library-getrgb4.md) to
    query it or [SetRGB4CM](autodocs-2.0/graphics-library-setrgb4cm.md) to set it directly.
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
    [SetRGB4()](autodocs-2.0/graphics-library-setrgb4.md) [FreeColorMap()](autodocs-2.0/graphics-library-freecolormap.md)
```

---

## See Also

- [FreeColorMap — graphics.library](../autodocs/graphics.library.md#freecolormap)
- [GetRGB4 — graphics.library](../autodocs/graphics.library.md#getrgb4)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
