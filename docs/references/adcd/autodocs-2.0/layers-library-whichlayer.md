---
title: layers.library/WhichLayer
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-whichlayer
functions: []
libraries: []
---

# layers.library/WhichLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    WhichLayer -- Which [Layer](autodocs-2.0/includes-graphics-clip-h.md) is this point in?
```
SYNOPSIS

```c
    layer = WhichLayer( li, x, y )
    d0                  a0  d0 d1

    struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *WhichLayer(struct Layer_Info*, WORD, WORD);
```
FUNCTION

```c
    Starting at the topmost layer check to see if this point (x,y)
        occurs in this layer.  If it does return the pointer to this
        layer. Return NULL if there is no layer at this point.
```
INPUTS

```c
    li  = pointer to LayerInfo structure
    (x,y) = coordinate in the [BitMap](autodocs-2.0/includes-graphics-gfx-h.md)
```
RESULTS

    layer - pointer to the topmost layer that this point is in
            NULL if this point is not in a layer
SEE ALSO

```c
    [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```
