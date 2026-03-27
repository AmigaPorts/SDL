---
title: 30 / / Creating and Using New Layers / Moving and Sizing Layers
manual: libraries
chapter: libraries
section: 30-creating-and-using-new-layers-moving-and-sizing-layers
functions: [MoveLayer, MoveSizeLayer, SizeLayer]
libraries: [layers.library]
---

# 30 / / Creating and Using New Layers / Moving and Sizing Layers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The layers library includes three functions for moving and sizing layers:


```c
    LONG MoveLayer( long dummy, struct Layer *layer, long dx, long dy );
    LONG SizeLayer( long dummy, struct Layer *layer, long dx, long dy );
    LONG MoveSizeLayer( struct Layer *layer, long dx, long dy, long dw,
                        long dh);
```
[MoveLayer()](autodocs-2.0/layers-library-movelayer.md) moves a layer to a new position relative to its current
position.  [SizeLayer()](autodocs-2.0/layers-library-sizelayer.md) changes the size of a layer by modifying the
coordinates of the lower right corner of the layer.  [MoveSizeLayer()](autodocs-2.0/layers-library-movesizelayer.md)
changes both the size and position of a layer in a single call.

---

## See Also

- [MoveLayer — layers.library](../autodocs/layers.library.md#movelayer)
- [MoveSizeLayer — layers.library](../autodocs/layers.library.md#movesizelayer)
- [SizeLayer — layers.library](../autodocs/layers.library.md#sizelayer)
