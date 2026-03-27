---
title: E / Release 2 Changes That Can Affect Compatibility / Layers
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-layers
functions: [NewLayerInfo]
libraries: [layers.library]
---

# E / Release 2 Changes That Can Affect Compatibility / Layers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * Use [NewLayerInfo()](libraries/30-allocating-and-deallocating-layer-info.md) to create, not [FattenLayerInfo()](autodocs-2.0/layers-library-fattenlayerinfo.md), [ThinLayerInfo()](autodocs-2.0/layers-library-thinlayerinfo.md),

```c
    [InitLayers()](autodocs-2.0/layers-library-initlayers.md).
```
  * Simple-refresh preserves all of the pixels it can.  Sizing a

```c
    [SIMPLE_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) window no longer clears the whole window.
```
  * Speed of layer operations is different.  Don't depend on layer

    operations to finish before or after other asynchronous actions.

---

## See Also

- [NewLayerInfo — layers.library](../autodocs/layers.library.md#newlayerinfo)
