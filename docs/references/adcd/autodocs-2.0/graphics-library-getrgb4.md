---
title: graphics.library/GetRGB4
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-getrgb4
functions: [DisplayBeep, FreeColorMap, GetColorMap, LoadRGB4, SetRGB4]
libraries: [graphics.library, intuition.library]
---

# graphics.library/GetRGB4

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetRGB4 -- Inquire value of entry in [ColorMap](autodocs-2.0/includes-graphics-view-h.md).
```
SYNOPSIS

```c
    value = GetRGB4( colormap, entry )
      d0              a0       d0

    ULONG GetRGB4(struct [ColorMap](autodocs-2.0/includes-graphics-view-h.md) *, LONG);
```
FUNCTION

```c
    Read and format a value from the [ColorMap](autodocs-2.0/includes-graphics-view-h.md).
```
INPUTS

```c
    colormap - pointer to [ColorMap](autodocs-2.0/includes-graphics-view-h.md) structure
    entry - index into colormap
```
RESULT

    returns -1 if no valid entry
    return UWORD RGB value 4 bits per gun right justified
NOTE

```c
    Intuition's [DisplayBeep()](autodocs-2.0/intuition-library-displaybeep.md) changes color 0. Reading Color 0 during a
    [DisplayBeep()](autodocs-2.0/intuition-library-displaybeep.md) will lead to incorrect results.
```
BUGS

SEE ALSO

```c
    [SetRGB4()](autodocs-2.0/graphics-library-setrgb4.md) [LoadRGB4()](autodocs-2.0/graphics-library-loadrgb4.md) [GetColorMap()](autodocs-2.0/graphics-library-getcolormap.md) [FreeColorMap()](autodocs-2.0/graphics-library-freecolormap.md) [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md)
```

---

## See Also

- [DisplayBeep — intuition.library](../autodocs/intuition.library.md#displaybeep)
- [FreeColorMap — graphics.library](../autodocs/graphics.library.md#freecolormap)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
