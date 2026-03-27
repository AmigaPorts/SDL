---
title: layers.library/UnlockLayerInfo
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-unlocklayerinfo
functions: []
libraries: []
---

# layers.library/UnlockLayerInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    UnlockLayerInfo -- Unlock the LayerInfo structure.
SYNOPSIS

```c
    UnlockLayerInfo( li )
                     a0

    void UnlockLayerInfo( struct [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) *);
```
FUNCTION

```c
    After the operation is complete that required a [LockLayerInfo](autodocs-2.0/layers-library-locklayerinfo.md),
    unlock the LayerInfo structure so that  other tasks may
    affect the layers.
```
INPUTS

```c
    li - pointer to the [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure
```
 BUGS

 SEE ALSO

```c
    [LockLayerInfo](autodocs-2.0/layers-library-locklayerinfo.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```
