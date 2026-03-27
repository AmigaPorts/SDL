---
title: 30 / / Types of Layers / Super Bitmap Layer
manual: libraries
chapter: libraries
section: 30-types-of-layers-super-bitmap-layer
functions: [CopySBitMap, ScrollLayer, SizeLayer, SyncSBitMap]
libraries: [graphics.library, layers.library]
---

# 30 / / Types of Layers / Super Bitmap Layer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A super bitmap layer is similar to a [smart refresh](libraries/30-types-of-layers-smart-refresh-layer.md) layer.  It too has a
back-up area for rendering graphics for currently obscured parts of the
display.  Whenever an obscured area is made visible, the corresponding
part of the backup area is copied to the display automatically.

However, it differs from [smart refresh](libraries/30-types-of-layers-smart-refresh-layer.md) in that:

  * The back-up [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) is user-supplied, rather than being allocated

    dynamically by the system.
  * The back-up [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) may be as large or larger than the the current

    size of the layer. It may also be larger than the maximum size of the
    layer.
To see a larger portion of a super bitmap on-display, use [SizeLayer()](libraries/30-layers-creating-and-using-new-layers.md).  To
see a different portion of the super bitmap in the layer, use
[ScrollLayer()](libraries/30-layers-creating-and-using-new-layers.md).

When the graphics routines perform drawing commands, part of the drawing
appears in the common [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) (the on-display portion). Any drawing outside
the displayed portion itself is rendered into the super bitmap. When the
layer is scrolled or sized, the layer contents are copied into the super
bitmap, the scroll or size positioning is modified, and the appropriate
portions are then copied back into the layer. (Refer to the graphics
library functions [SyncSBitMap()](libraries/4-setting-up-a-superbitmap-window-graphics-and-layers.md) and [CopySBitMap()](libraries/4-setting-up-a-superbitmap-window-graphics-and-layers.md).

---

## See Also

- [CopySBitMap — graphics.library](../autodocs/graphics.library.md#copysbitmap)
- [ScrollLayer — layers.library](../autodocs/layers.library.md#scrolllayer)
- [SizeLayer — layers.library](../autodocs/layers.library.md#sizelayer)
- [SyncSBitMap — graphics.library](../autodocs/graphics.library.md#syncsbitmap)
