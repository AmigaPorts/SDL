---
title: layers.library/CreateBehindLayer
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-createbehindlayer
functions: []
libraries: []
---

# layers.library/CreateBehindLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CreateBehindLayer -- Create a new layer behind all existing layers.
SYNOPSIS

```c
    result = CreateBehindLayer(li,bm,x0,y0,x1,y1,flags [,bm2])
    d0                         a0 a1 d0 d1 d2 d3   d4  [ a2 ]

    struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *CreateBehindLayer(struct [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) *, struct [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) *,
        LONG, LONG, LONG, LONG, LONG, ... );
```
FUNCTION

```c
    Create a new [Layer](autodocs-2.0/includes-graphics-clip-h.md) of position and size (x0,y0)->(x1,y1)
    Make this layer of type found in flags.
    If SuperBitMap, use bm2 as pointer to real SuperBitMap,
    and copy contents of Superbitmap into display layer.
    If this layer is a backdrop layer then place it behind all
    other layers including other backdrop layers. If this is
    not a backdrop layer then place it behind all nonbackdrop
    layers.

    Note: when using SUPERBITMAP, you should also set LAYERSMART flag.
```
INPUTS

```c
    li - pointer to LayerInfo structure
    bm - pointer to common [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) used by all Layers
    x0,y0 - upper left hand corner of layer
    x1,y1 - lower right hand corner of layer
    flags - various types of layers supported as bit sets.
            (for bit definitions, see [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md) )
    bm2 - pointer to optional Super [BitMap](autodocs-2.0/includes-graphics-gfx-h.md)
```
RESULTS

```c
    result - pointer to [Layer](autodocs-2.0/includes-graphics-clip-h.md) structure if successful
             NULL if not successful
```
BUGS

SEE ALSO

```c
    [DeleteLayer](autodocs-2.0/layers-library-deletelayer.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md), [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md), [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md)
```
