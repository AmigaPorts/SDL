---
title: 30 / / / Allocating and Deallocating Layer_Info
manual: libraries
chapter: libraries
section: 30-allocating-and-deallocating-layer-info
functions: [DisposeLayerInfo, NewLayerInfo]
libraries: [layers.library]
---

# 30 / / / Allocating and Deallocating Layer_Info

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Use [NewLayerInfo()](autodocs-2.0/layers-library-newlayerinfo.md) to allocate and initialize a [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure and
associated sub-structures.


```c
    struct Layer_Info *NewLayerInfo( void );
```
You must call this function before attempting to use any of the other
layers functions described below.  When you have finished with a
[Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure, use [DisposeLayerInfo()](autodocs-2.0/layers-library-disposelayerinfo.md) to deallocate it.


```c
    void DisposeLayerInfo( struct Layer_Info *li );
```
This function deallocates a [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) and associated structures
previously allocated with [NewLayerInfo()](autodocs-2.0/layers-library-newlayerinfo.md).

---

## See Also

- [DisposeLayerInfo — layers.library](../autodocs/layers.library.md#disposelayerinfo)
- [NewLayerInfo — layers.library](../autodocs/layers.library.md#newlayerinfo)
