---
title: layers.library/CreateUpfrontHookLayer
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-createupfronthooklayer
functions: []
libraries: []
---

# layers.library/CreateUpfrontHookLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME                                                              (V36)

    CreateUpfrontHookLayer -- Create a new layer on top of existing layers,
                              using supplied callback BackFill hook.
SYNOPSIS

```c
    result = CreateUpfrontHookLayer(li,bm,x0,y0,x1,y1,flags,hook,[,bm2])
    d0                              a0 a1 d0 d1 d2 d3   d4  a3   [ a2 ]

    struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *CreateUpfrontHookLayer(struct [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) *,
                  struct [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) *, LONG, LONG, LONG,
                  LONG, LONG, struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) *, ... );
```
FUNCTION

```c
    Create a new [Layer](autodocs-2.0/includes-graphics-clip-h.md) of position and size (x0,y0)->(x1,y1)
    and place it on top of all other layers.
    Make this layer of type found in flags
    Install Layer->BackFill callback hook.
    if SuperBitMap, use bm2 as pointer to real SuperBitMap.
    and copy contents of Superbitmap into display layer.

    Note: when using SUPERBITMAP, you should also set LAYERSMART flag.
```
INPUTS

```c
    li - pointer to LayerInfo structure
    bm - pointer to common [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) used by all Layers
    x0,y0 - upper left hand corner of layer
    x1,y1 - lower right hand corner of layer
    flags - various types of layers supported as bit sets.
    hook -  Layer->BackFill callback [Hook](autodocs-2.0/includes-utility-hooks-h.md) which will be called
            with object == (struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *) result->RastPort
            and message == [ (Layer *) layer, (struct Rectangle) bounds,
                           (WORD) offsetx, (WORD) offsety ]
    bm2 - pointer to optional Super [BitMap](autodocs-2.0/includes-graphics-gfx-h.md)
```
RESULTS

```c
    result - pointer to [Layer](autodocs-2.0/includes-graphics-clip-h.md) structure if successful
             NULL if not successful
```
BUGS

SEE ALSO
   [DeleteLayer](autodocs-2.0/layers-library-deletelayer.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md), [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md), [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md)

```c
    [utility/hooks.h](autodocs-2.0/includes-utility-hooks-h.md)
```
