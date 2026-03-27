---
title: Layers
manual: amiga-mail
chapter: amiga-mail
section: layers
functions: [NewLayerInfo]
libraries: [layers.library]
---

# Layers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* Use NewLayerInfo() to create, not FattenLayerInfo(), ThinLayerInfo(),
  InitLayers().

* Simple-refresh preserves all of the pixels it can.  Sizing a
  SIMPLE_REFRESH window no longer clears the whole window.

* Speed of layer operations is different.  Don't depend on layer
  operations to finish before or after other asynchronous actions.

---

## See Also

- [NewLayerInfo — layers.library](../autodocs/layers.library.md#newlayerinfo)
