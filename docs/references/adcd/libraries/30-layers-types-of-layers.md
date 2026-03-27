---
title: 30 / Layers / Types of Layers
manual: libraries
chapter: libraries
section: 30-layers-types-of-layers
functions: []
libraries: []
---

# 30 / Layers / Types of Layers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The layers library supports three types of layers: simple refresh, smart
refresh and super bitmap.  The type of the layer, specified by the Flags
field in the [Layer](libraries/30-layers-the-layer-structure.md)s structure, determines what facilities the layer
provides.


```c
    Use Only One Layer Type Flag
    ----------------------------
    The three layer-type Flags are mutually exclusive.  That is, only one
    layer-type flag (LAYERSIMPLE, LAYERSMART and LAYERSUPER) should be
    specified.
```
 [Simple Refresh Layer](libraries/30-types-of-layers-simple-refresh-layer.md)    [Super Bitmap Layer](libraries/30-types-of-layers-super-bitmap-layer.md) 
 [Smart Refresh Layer](libraries/30-types-of-layers-smart-refresh-layer.md)     [Backdrop Layer](libraries/30-types-of-layers-backdrop-layer.md) 

