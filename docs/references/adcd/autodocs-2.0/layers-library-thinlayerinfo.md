---
title: layers.library/ThinLayerInfo
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-thinlayerinfo
functions: []
libraries: []
---

# layers.library/ThinLayerInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ThinLayerInfo -- convert 1.1 LayerInfo to 1.0 LayerInfo.
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
SYNOPSIS

```c
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
    ThinLayerInfo( li )
                   a0

    void ThinLayerInfo( struct [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) *);
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
```
FUNCTION

```c
    return the extra memory needed that was allocated with
    [FattenLayerInfo](autodocs-2.0/layers-library-fattenlayerinfo.md). This is must be done prior to freeing
    the [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure itself. V1.1 software should be
    using [DisposeLayerInfo](autodocs-2.0/layers-library-disposelayerinfo.md).
```
INPUTS

    li - pointer to LayerInfo structure
BUGS

SEE ALSO

```c
    [DisposeLayerInfo](autodocs-2.0/layers-library-disposelayerinfo.md), [FattenLayerInfo](autodocs-2.0/layers-library-fattenlayerinfo.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```
