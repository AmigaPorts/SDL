---
title: graphics.library/SetRGB4
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setrgb4-2
functions: [GetRGB4, LoadRGB4]
libraries: [graphics.library]
---

# graphics.library/SetRGB4

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
       SetRGB4 -- Set one color register for this viewport.

    SYNOPSIS
       SetRGB4(  vp, n,   r,    g,    b)
                 a0  d0  d1:4  d2:4  d3:4
```
	void SetRGB4( struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *, [SHORT](autodocs-3.5/include-exec-types-h.md), [UBYTE](autodocs-3.5/include-exec-types-h.md), [UBYTE](autodocs-3.5/include-exec-types-h.md), [UBYTE](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	Change the color look up table so that this viewport displays
	the color (r,g,b) for pen number n.

    INPUTS
	vp - pointer to  viewport structure
```c
       n - the color number (range from 0 to 31)
       r - red level (0-15)
       g - green level (0-15)
       b - blue level (0-15)

    RESULT
```
	If there is a [ColorMap](autodocs-3.5/include-graphics-view-h.md) for this viewport, then the value will
	be stored in the [ColorMap](autodocs-3.5/include-graphics-view-h.md).
       The selected color register is changed to match your specs.
	If the color value is unused then nothing will happen.


    BUGS
	NOTE: Under V36 and up, it is not safe to call this function
	from an interrupt, due to semaphore protection of graphics
	copper lists.


```c
    SEE ALSO
       [LoadRGB4()](autodocs-3.5/graphics-library-loadrgb4-2.md) [GetRGB4()](autodocs-3.5/graphics-library-getrgb4-2.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)
```

---

## See Also

- [GetRGB4 — graphics.library](../autodocs/graphics.library.md#getrgb4)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
