---
title: layers.library/UnlockLayers
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-unlocklayers
functions: []
libraries: []
---

# layers.library/UnlockLayers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    UnlockLayers -- Unlock all layers from graphics output.
                    Restart graphics output to layers that have been
                    waiting
SYNOPSIS

```c
    UnlockLayers( li )
                  a0

    void UnlockLayers( struct [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) *);
```
FUNCTION

```c
    Make all layers in this layer list unlocked.
    Then call [UnlockLayerInfo](autodocs-2.0/layers-library-unlocklayerinfo.md)
```
INPUTS

```c
    li - pointer to the [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure
```
BUGS

SEE ALSO

```c
    [LockLayers](autodocs-2.0/layers-library-locklayers.md), [UnlockLayer](autodocs-2.0/layers-library-unlocklayer.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```
