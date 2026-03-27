---
title: layers.library/DisposeLayerInfo
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-disposelayerinfo
functions: [DeleteLayer, DisposeLayerInfo]
libraries: [layers.library]
---

# layers.library/DisposeLayerInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    DisposeLayerInfo -- Return all memory for LayerInfo to memory pool
SYNOPSIS

```c
    DisposeLayerInfo( li )
                      a0

    void DisposeLayerInfo( struct [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) *);
```
FUNCTION

```c
    return LayerInfo and any other memory attached to this LayerInfo
    to memory allocator.

    Note: if you wish to delete the layers associated with this [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md)
        structure, remember to call [DeleteLayer()](autodocs-2.0/layers-library-deletelayer.md) for each of the layers
        before calling DisposeLayerInfo().
```
INPUTS

    li - pointer to LayerInfo structure
EXAMPLE



```c
    --delete the layers associated this [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure--

    DeleteLayer(li,simple_layer);
    DeleteLayer(li,smart_layer);

    --see documentation on [DeleteLayer](autodocs-2.0/layers-library-deletelayer.md) about deleting SuperBitMap layers--
    my_super_bitmap_ptr = super_layer->SuperBitMap;
    DeleteLayer(li,super_layer);

    --now dispose of the [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure itself--
    DisposeLayerInfo(li);
```
BUGS

SEE ALSO

```c
    [DeleteLayer](autodocs-2.0/layers-library-deletelayer.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```

---

## See Also

- [DeleteLayer — layers.library](../autodocs/layers.library.md#deletelayer)
- [DisposeLayerInfo — layers.library](../autodocs/layers.library.md#disposelayerinfo)
