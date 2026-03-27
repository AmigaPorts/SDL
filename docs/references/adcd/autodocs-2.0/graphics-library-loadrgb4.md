---
title: graphics.library/LoadRGB4
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-loadrgb4
functions: [GetColorMap, GetRGB4, SetRGB4]
libraries: [graphics.library]
---

# graphics.library/LoadRGB4

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    LoadRGB4 -- Load RGB color values from table.
SYNOPSIS

```c
    LoadRGB4( vp, colors , count )
             a0     a1     d0:16

    void LoadRGB4( struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) *, UWORD *, WORD);
```
FUNCTION

    load the count words of the colormap from table starting at
    entry 0.
INPUTS

```c
    vp - pointer to [ViewPort](autodocs-2.0/includes-graphics-view-h.md), whose colors you wish to change
    colors - pointer to table of RGB values set up as an array
             of USHORTS
                    background--  0x0RGB
                    color1    --  0x0RGB
                    color2    --  0x0RGB
                     etc.         UWORD per value.
            The colors are interpreted as 15 = maximum intensity.
                                          0 = minimum intensity.
    count   = number of UWORDs in the table to load into the
      colormap starting at color 0(background) and proceeding
      to the next higher color number
```
RESULTS

```c
    The [ViewPort](autodocs-2.0/includes-graphics-view-h.md) should have a pointer to a valid [ColorMap](autodocs-2.0/includes-graphics-view-h.md) to store
    the colors in.
    Updates the hardware copperlist to reflect the new colors.
    Updates the intermediate copperlist with the new colors.
```
BUGS


    NOTE: With V36 and up, it is not safe to call this function
    from an interrupt, because of the semaphore locking on graphics
    copper lists.
SEE ALSO

```c
    [SetRGB4()](autodocs-2.0/graphics-library-setrgb4.md) [GetRGB4()](autodocs-2.0/graphics-library-getrgb4.md) [GetColorMap()](autodocs-2.0/graphics-library-getcolormap.md) [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md)
```

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GetRGB4 — graphics.library](../autodocs/graphics.library.md#getrgb4)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
