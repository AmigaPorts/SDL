---
title: 30 / / Creating and Using Layers / Allocating and Deallocating Layers
manual: libraries
chapter: libraries
section: 30-creating-and-using-layers-allocating-and-deallocating
functions: [CreateBehindLayer, CreateUpfrontLayer, DeleteLayer]
libraries: [layers.library]
---

# 30 / / Creating and Using Layers / Allocating and Deallocating Layers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Layers are created using the routines [CreateUpfrontLayer()](autodocs-2.0/layers-library-createupfrontlayer.md)
and [CreateBehindLayer()](autodocs-2.0/layers-library-createbehindlayer.md).  CreateUpfrontLayer()
creates a layer that will appear in front of any existing layers.


```c
    struct Layer *CreateUpfrontLayer( struct Layer_Info *li,
                                      struct BitMap *bm,
                                      long x0, long y0, long x1, long y1,
                                      long flags, struct BitMap *bm2 );
```
[CreateBehindLayer()](autodocs-2.0/layers-library-createbehindlayer.md) creates a layer that appears behind existing layers,
but in front of [backdrop](libraries/30-types-of-layers-backdrop-layer.md) layers.


```c
    struct Layer *CreateBehindLayer( struct Layer_Info *li,
                                     struct BitMap *bm,
                                     long x0, long y0, long x1, long y1,
                                     long flags, struct BitMap *bm2 );
```
Both of these routines return a pointer to a [Layer](libraries/30-layers-the-layer-structure.md) data structure (as
defined in the include file <graphics/[layers.h](autodocs-2.0/includes-graphics-layers-h.md)>), or NULL if the operation
was unsuccessful.


```c
    A New Layer Also Gets a RastPort.
    ---------------------------------
    When a layer is created, the routine automatically creates a
    [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) to go along with it.  If the layer's RastPort is passed
    to the drawing routines, drawing will be restricted to the layer.
    See "[The Layer's RastPort](libraries/30-layers-the-layer-s-rastport.md)" section above.
```
Use the [DeleteLayer()](autodocs-2.0/layers-library-deletelayer.md) call to remove a layer:


```c
    LONG DeleteLayer( long dummy, struct Layer *layer );
```
[DeleteLayer()](autodocs-2.0/layers-library-deletelayer.md) removes a layer from the layer list and frees the memory
allocated by the layer creation calls listed above.

---

## See Also

- [CreateBehindLayer — layers.library](../autodocs/layers.library.md#createbehindlayer)
- [CreateUpfrontLayer — layers.library](../autodocs/layers.library.md#createupfrontlayer)
- [DeleteLayer — layers.library](../autodocs/layers.library.md#deletelayer)
