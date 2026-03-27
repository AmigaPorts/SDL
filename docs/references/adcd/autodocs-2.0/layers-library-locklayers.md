---
title: layers.library/LockLayers
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-locklayers
functions: [LockLayerInfo]
libraries: [layers.library]
---

# layers.library/LockLayers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    LockLayers -- lock all layers from graphics output.
SYNOPSIS

```c
    LockLayers( li )
                a0

    void LockLayers( struct [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) *);
```
FUNCTION

```c
    First calls [LockLayerInfo()](autodocs-2.0/layers-library-locklayerinfo.md)
    Make all layers in this layer list locked.
```
INPUTS

```c
    li - pointer to [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure
```
BUGS

SEE ALSO

```c
    [LockLayer](autodocs-2.0/layers-library-locklayer.md), [LockLayerInfo](autodocs-2.0/layers-library-locklayerinfo.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```

---

## See Also

- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
