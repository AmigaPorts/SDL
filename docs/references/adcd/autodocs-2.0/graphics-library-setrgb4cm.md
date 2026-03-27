---
title: graphics.library/SetRGB4CM
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-setrgb4cm
functions: [GetColorMap, GetRGB4, SetRGB4]
libraries: [graphics.library]
---

# graphics.library/SetRGB4CM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetRGB4CM -- Set one color register for this [ColorMap](autodocs-2.0/includes-graphics-view-h.md).
```
SYNOPSIS

```c
    SetRGB4CM(  cm,  n,   r,    g,    b)
                a0  d0  d1:4  d2:4  d3:4

    void SetRGB4CM( struct [ColorMap](autodocs-2.0/includes-graphics-view-h.md) *, SHORT, UBYTE, UBYTE, UBYTE );
```
INPUTS

```c
    cm = colormap
    n = the number of the color register to set. Ranges from 0 to 31
         on current amiga displays.
    r = red level (0-15)
    g = green level (0-15)
    b = blue level (0-15)
```
RESULT

```c
    Store the (r,g,b) triplet at index n of the [ColorMap](autodocs-2.0/includes-graphics-view-h.md) structure.
    This function can be used to set up a [ColorMap](autodocs-2.0/includes-graphics-view-h.md) before before
    linking it into a viewport.
```
BUGS

SEE ALSO

```c
    [GetColorMap()](autodocs-2.0/graphics-library-getcolormap.md) [GetRGB4()](autodocs-2.0/graphics-library-getrgb4.md) [SetRGB4()](autodocs-2.0/graphics-library-setrgb4.md) [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md)
```

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GetRGB4 — graphics.library](../autodocs/graphics.library.md#getrgb4)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
