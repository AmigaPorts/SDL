---
title: layers.library/ScrollLayer
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-scrolllayer
functions: []
libraries: []
---

# layers.library/ScrollLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ScrollLayer -- Scroll around in a superbitmap, translate coordinates
                  in non-superbitmap layer.
SYNOPSIS

```c
    ScrollLayer( dummy, l, dx, dy )
                 a0     a1 d0  d1

    void ScrollLayer( LONG, struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *, LONG, LONG);
```
FUNCTION

```c
    For a SuperBitMap Layer:
    Update the SuperBitMap from the layer display, then copy bits
    between [Layer](autodocs-2.0/includes-graphics-clip-h.md) and SuperBitMap to reposition layer over different
    portion of SuperBitMap.
    For nonSuperBitMap layers, all (x,y) pairs are adjusted by
    the scroll(x,y) value in the layer.  To cause (0,0) to actually
    be drawn at (3,10) use ScrollLayer(-3,-10). This can be useful
    along with [InstallClipRegion](autodocs-2.0/layers-library-installclipregion.md) to simulate Intuition GZZWindows
    without the overhead of an extra layer.
```
INPUTS

    dummy - unused
    l - pointer to a layer
    dx - delta to add to current x scroll value
    dy - delta to add to current y scroll value
BUGS

```c
    May not handle (dx,dy) which attempts to move the layer ouside the
    layer's SuperBitMap bounds.
```
SEE ALSO

```c
    [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```
