---
title: 30 / / Creating and Using New Layers / Creating the Layers
manual: libraries
chapter: libraries
section: 30-creating-and-using-new-layers-creating-the-layers
functions: [CreateBehindLayer, CreateUpfrontLayer, NewLayerInfo]
libraries: [layers.library]
---

# 30 / / Creating and Using New Layers / Creating the Layers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The application must first allocate and initialize a [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) data
structure which the system uses to keep track of layers that are created,
use statements like:


```c
    struct Layer_Info *theLayerInfo;

    if (NULL != (theLayerInfo = NewLayerInfo()))
        {
        /* use Layer_Info */

        DisposeLayerInfo(theLayerInfo);
        }
```
Layers may be created in the common bit map by calling
[CreateUpfrontLayer()](libraries/30-layers-creating-and-using-new-layers.md) or [CreateBehindLayer()](libraries/30-layers-creating-and-using-new-layers.md), with a sequence such as the
following:


```c
    struct Layer      *layer;
    struct Layer_Info *theLayerInfo;
    struct BitMap     *theBitMap;

    /* requests construction of a smart refresh layer. */
    if (NULL == (layer = CreateUpfrontLayer(theLayerInfo, theBitMap,
              20, 20, 100, 80, LAYERSMART, NULL)))
        error("CreateUpfrontLayer() failed.");
    else
        {
        ; /* layer successfully created here. */
        }
```

---

## See Also

- [CreateBehindLayer — layers.library](../autodocs/layers.library.md#createbehindlayer)
- [CreateUpfrontLayer — layers.library](../autodocs/layers.library.md#createupfrontlayer)
- [NewLayerInfo — layers.library](../autodocs/layers.library.md#newlayerinfo)
