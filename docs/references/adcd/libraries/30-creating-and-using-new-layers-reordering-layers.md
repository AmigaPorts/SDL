---
title: 30 / / Creating and Using New Layers / Reordering Layers
manual: libraries
chapter: libraries
section: 30-creating-and-using-new-layers-reordering-layers
functions: [BeginUpdate, BehindLayer, EndUpdate, InstallClipRegion, MoveLayerInFrontOf, UpfrontLayer]
libraries: [layers.library]
---

# 30 / / Creating and Using New Layers / Reordering Layers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The layers library provides three function calls for reordering layers:


```c
    LONG BehindLayer ( long dummy, struct Layer *layer );
    LONG UpfrontLayer( long dummy, struct Layer *layer );
    LONG MoveLayerInFrontOf( struct Layer *layer_to_move,
                             struct Layer *other_layer );
```
[BehindLayer()](autodocs-2.0/layers-library-behindlayer.md) moves a layer behind all other layers.  This function
considers any [backdrop](libraries/30-types-of-layers-backdrop-layer.md) layers, moving a current layer behind all others
except backdrop layers.  [UpfrontLayer()](autodocs-2.0/layers-library-upfrontlayer.md) moves a layer in front of all
other layers.  [MoveLayerInFrontOf()](autodocs-2.0/layers-library-movelayerinfrontof.md) is used to place a layer at a specific
depth, just in front of a given layer.

As areas of [simple refresh](libraries/30-types-of-layers-simple-refresh-layer.md) layers become exposed, due to layer movement or
sizing for example, the newly exposed areas have not been drawn into, and
need refreshing.  The system keeps track of these areas by using a
[DamageList](libraries/30-layers-the-layer-structure.md).  To update only those areas that need it, the [BeginUpdate()](autodocs-2.0/layers-library-beginupdate.md)
[EndUpdate()](autodocs-2.0/layers-library-endupdate.md) functions are called.


```c
    LONG BeginUpdate( struct Layer *l );
    void EndUpdate  ( struct Layer *layer, unsigned long flag );
```
[BeginUpdate()](autodocs-2.0/layers-library-beginupdate.md) saves the pointer to the current clipping rectangles and
installs a pointer to a set of [ClipRect](libraries/30-layers-the-layer-structure.md)s generated from the [DamageList](libraries/30-layers-the-layer-structure.md) in
the layer structure.  To repair the layer, use the graphics rendering
routines as if to redraw the entire layer, and the routines will
automatically use the new clipping rectangle list.  So, only the damaged
areas are actually rendered into, saving time.


```c
    Never Modify the DamageList.
    ----------------------------
    The system generates and maintains the [DamageList](libraries/30-layers-the-layer-structure.md) region.  All
    application clipping should be done through the [InstallClipRegion()](libraries/30-layers-library-regions.md)
    function.
```
To complete the update process call [EndUpdate()](autodocs-2.0/layers-library-endupdate.md) which will restore the
original [ClipRect](libraries/30-layers-the-layer-structure.md) list.

---

## See Also

- [BeginUpdate — layers.library](../autodocs/layers.library.md#beginupdate)
- [BehindLayer — layers.library](../autodocs/layers.library.md#behindlayer)
- [EndUpdate — layers.library](../autodocs/layers.library.md#endupdate)
- [InstallClipRegion — layers.library](../autodocs/layers.library.md#installclipregion)
- [MoveLayerInFrontOf — layers.library](../autodocs/layers.library.md#movelayerinfrontof)
- [UpfrontLayer — layers.library](../autodocs/layers.library.md#upfrontlayer)
