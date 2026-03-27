---
title: 30 / / Creating and Using New Layers / Changing a Viewpoint
manual: libraries
chapter: libraries
section: 30-creating-and-using-new-layers-changing-a-viewpoint
functions: [ScrollLayer]
libraries: [layers.library]
---

# 30 / / Creating and Using New Layers / Changing a Viewpoint

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [ScrollLayer()](autodocs-2.0/layers-library-scrolllayer.md) function changes the portion of a [super bitmap](libraries/30-types-of-layers-super-bitmap-layer.md) that is
shown by a layer:


```c
    void ScrollLayer( long dummy, struct Layer *layer, long dx, long dy );
```
This function is most useful with [super bitmap](libraries/30-types-of-layers-super-bitmap-layer.md) layers but can also
simulate the effect on other layer types by adding the scroll offset to
all future rendering.

---

## See Also

- [ScrollLayer — layers.library](../autodocs/layers.library.md#scrolllayer)
