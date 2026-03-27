---
title: graphics.library/GetRGB4
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getrgb4-2
functions: [DisplayBeep, FreeColorMap, GetColorMap, LoadRGB4, SetRGB4]
libraries: [graphics.library, intuition.library]
---

# graphics.library/GetRGB4

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       GetRGB4 -- Inquire value of entry in [ColorMap](autodocs-3.5/include-graphics-view-h.md).
```
   SYNOPSIS

```c
       value = GetRGB4( colormap, entry )
          d0              a0       d0
```
	ULONG GetRGB4(struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) *, LONG);

   FUNCTION
	[Read](autodocs-3.5/dos-library-read-2.md) and format a value from the [ColorMap](autodocs-3.5/include-graphics-view-h.md).

   INPUTS
	colormap - pointer to [ColorMap](autodocs-3.5/include-graphics-view-h.md) structure
	entry - index into colormap

   RESULT
	returns -1 if no valid entry
	return [UWORD](autodocs-3.5/include-exec-types-h.md) RGB value 4 bits per gun right justified

   NOTE
	Intuition's [DisplayBeep()](autodocs-3.5/intuition-library-displaybeep-2.md) changes color 0. Reading Color 0 during a
	[DisplayBeep()](autodocs-3.5/intuition-library-displaybeep-2.md) will lead to incorrect results.

   BUGS

   SEE ALSO

```c
       [SetRGB4()](autodocs-3.5/graphics-library-setrgb4-2.md) [LoadRGB4()](autodocs-3.5/graphics-library-loadrgb4-2.md) [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [FreeColorMap()](autodocs-3.5/graphics-library-freecolormap-2.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)
```

---

## See Also

- [DisplayBeep — intuition.library](../autodocs/intuition.library.md#displaybeep)
- [FreeColorMap — graphics.library](../autodocs/graphics.library.md#freecolormap)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
