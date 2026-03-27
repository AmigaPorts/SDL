---
title: layers.library/InitLayers
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-initlayers
functions: []
libraries: []
---

# layers.library/InitLayers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InitLayers -- Initialize [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
```
SYNOPSIS

```c
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
    InitLayers( li )
                a0

    void InitLayers( struct [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) *);
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
```
FUNCTION

```c
    Initialize [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure in preparation to use
    other layer operations on this list of layers.
    Make the Layers unlocked (open), available to layer operations.
```
INPUTS

    li - pointer to LayerInfo structure
BUGS

SEE ALSO

```c
    [NewLayerInfo](autodocs-2.0/layers-library-newlayerinfo.md), [DisposeLayerInfo](autodocs-2.0/layers-library-disposelayerinfo.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```
