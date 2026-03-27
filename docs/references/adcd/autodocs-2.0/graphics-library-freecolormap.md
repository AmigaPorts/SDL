---
title: graphics.library/FreeColorMap
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-freecolormap
functions: [GetColorMap, SetRGB4]
libraries: [graphics.library]
---

# graphics.library/FreeColorMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeColorMap -- Free the [ColorMap](autodocs-2.0/includes-graphics-view-h.md) structure and return memory
                                            to free memory pool.
```
SYNOPSIS

```c
    FreeColorMap( colormap )
                   a0

    void FreeColorMap(struct [ColorMap](autodocs-2.0/includes-graphics-view-h.md) *);
```
FUNCTION

```c
    Return the memory to the free memory pool that was allocated
    with [GetColorMap](autodocs-2.0/graphics-library-getcolormap.md).
```
INPUTS

```c
    colormap - pointer to [ColorMap](autodocs-2.0/includes-graphics-view-h.md) allocated with [GetColorMap](autodocs-2.0/graphics-library-getcolormap.md)
```
RESULT

    The space is made available for others to use.
BUGS

SEE ALSO

```c
    [SetRGB4()](autodocs-2.0/graphics-library-setrgb4.md) [GetColorMap()](autodocs-2.0/graphics-library-getcolormap.md) [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md)
```

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
