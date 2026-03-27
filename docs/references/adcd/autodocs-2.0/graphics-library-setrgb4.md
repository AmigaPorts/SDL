---
title: graphics.library/SetRGB4
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-setrgb4
functions: [GetRGB4, LoadRGB4]
libraries: [graphics.library]
---

# graphics.library/SetRGB4

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetRGB4 -- Set one color register for this viewport.
SYNOPSIS

```c
    SetRGB4(  vp, n,   r,    g,    b)
              a0  d0  d1:4  d2:4  d3:4

    void SetRGB4( struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) *, SHORT, UBYTE, UBYTE, UBYTE );
```
FUNCTION

```c
    Change the color look up table so that this viewport displays
    the color (r,g,b) for pen number n.
```
INPUTS

```c
    vp - pointer to  viewport structure
    n - the color number (range from 0 to 31)
    r - red level (0-15)
    g - green level (0-15)
    b - blue level (0-15)
```
RESULT

```c
    If there is a [ColorMap](autodocs-2.0/includes-graphics-view-h.md) for this viewport, then the value will
    be stored in the [ColorMap](autodocs-2.0/includes-graphics-view-h.md).
    The selected color register is changed to match your specs.
    If the color value is unused then nothing will happen.
```
BUGS

    NOTE: Under V36 and up, it is not safe to call this function
    from an interrupt, due to semaphore protection of graphics
    copper lists.
SEE ALSO

```c
    [LoadRGB4()](autodocs-2.0/graphics-library-loadrgb4.md) [GetRGB4()](autodocs-2.0/graphics-library-getrgb4.md) [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md)
```

---

## See Also

- [GetRGB4 — graphics.library](../autodocs/graphics.library.md#getrgb4)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
