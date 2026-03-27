---
title: 30 / Layers / The Layer Structure
manual: libraries
chapter: libraries
section: 30-layers-the-layer-structure
functions: []
libraries: []
---

# 30 / Layers / The Layer Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The internal representation of layers is essentially a set of clipping
rectangles.  Each layer is represented by an instance of the Layer
structure.  All the layers in a display are linked together through the
[Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure.  Any display shared by multiple layers (such as an
Intuition screen) requires one Layer_Info data structure to handle
interactions between the various layers. Here is a partial listing of the
Layer structure from <graphics/[clip.h](autodocs-2.0/includes-graphics-clip-h.md)>.  (For a complete listing refer to
the Amiga ROM Kernel Reference Manual: Includes and Autodocs.)


```c
    struct Layer
    {
        struct  Layer *front,*back;
        struct  ClipRect   *ClipRect; /* read ROMs to find 1st cliprect */
        struct  RastPort   *rp;
        struct  Rectangle  bounds;
          ...

        UWORD   Flags;                /* obscured ?, Virtual BitMap? */
        struct  BitMap  *SuperBitMap;
          ...

        struct  Region  *DamageList;  /* list of rectangles to refresh */
                                      /* through */
    };


    The Layer Structure is Read-Only.
    ---------------------------------
    Applications should never directly modify any of the elements of the
    Layer structure. In addition, applications should only read the
    front, back, rp, bounds, Flags, SuperBitMap and DamageList elements
    of the Layer structure. (Some of these elements are subject to
    dynamic change by the system so proper layer locking procedures must
    be followed when relying on what the application has read.)
```
