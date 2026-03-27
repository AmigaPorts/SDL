---
title: layers.library/FattenLayerInfo
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-fattenlayerinfo
functions: []
libraries: []
---

# layers.library/FattenLayerInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FattenLayerInfo -- convert 1.0 LayerInfo to 1.1 LayerInfo
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
SYNOPSIS

```c
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
    FattenLayerInfo( li )
                     a0

    LONG FattenLayerInfo( struct [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) *);
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
```
FUNCTION

```c
    V1.1 software and any later releases need to have more info in the
    [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure. To do this in a 1.0 supportable manner requires
    allocation and deallocation of the memory whenever most
    layer library functions are called.  To prevent unnecessary
    allocation/deallocation FattenLayerInfo will preallocate the
    necessary data structures and fake out the layer library into
    thinking it has a LayerInfo gotten from [NewLayerInfo](autodocs-2.0/layers-library-newlayerinfo.md).
    [NewLayerInfo](autodocs-2.0/layers-library-newlayerinfo.md) is the approved method for getting this structure.
    When a program needs to give up the LayerInfo structure it
    must call [ThinLayerInfo](autodocs-2.0/layers-library-thinlayerinfo.md) before freeing the memory. [ThinLayerInfo](autodocs-2.0/layers-library-thinlayerinfo.md)
    is not necessary if [New/DisposeLayerInfo](autodocs-2.0/layers-library-disposelayerinfo.md) are used however.
```
INPUTS

    li - pointer to LayerInfo structure
BUGS

SEE ALSO


```c
    [NewLayerInfo](autodocs-2.0/layers-library-newlayerinfo.md), [ThinLayerInfo](autodocs-2.0/layers-library-thinlayerinfo.md), [DisposeLayerInfo](autodocs-2.0/layers-library-disposelayerinfo.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```
