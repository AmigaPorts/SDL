---
title: 30 / / Types of Layers / Simple Refresh Layer
manual: libraries
chapter: libraries
section: 30-types-of-layers-simple-refresh-layer
functions: []
libraries: []
---

# 30 / / Types of Layers / Simple Refresh Layer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When an application draws into the layer, any portion of the layer that is
visible (not obscured) will be rendered into the common [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) of the
viewing area.  All graphics rendering routines are "clipped", so that only
exposed sections of the layer are drawn into.  No back-up of obscured
areas is provided.

If another layer operation is performed that causes an obscured part of a
simple refresh layer to be exposed, the application must determine if the
section need be refreshed, re-drawing the newly exposed part of the layer
as required.

The basic advantage of simple refresh is that it does not require back-up
area to save drawing sections that cannot be seen, saving memory. However,
the application needs to monitor the layer to see if it needs refreshing.
This is typically performed with statements like:


```c
    if (layer->Flags & LAYERREFRESH)
        refresh(layer);
```
