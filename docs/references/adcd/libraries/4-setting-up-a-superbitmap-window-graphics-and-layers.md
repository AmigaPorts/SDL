---
title: 4 / / Setting Up A SuperBitMap Window / Graphics and Layers Functions
manual: libraries
chapter: libraries
section: 4-setting-up-a-superbitmap-window-graphics-and-layers
functions: [CopySBitMap, ScrollLayer, SyncSBitMap]
libraries: [graphics.library, layers.library]
---

# 4 / / Setting Up A SuperBitMap Window / Graphics and Layers Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The portion of the bitmap showing within a SuperBitMap window is
controlled by the application.  Initially, the window shows the bitmap
starting from its origin (0,0) and clipped to fit within the window layer.
The visible portion of the bitmap can be scrolled around within the window
using the layers library [ScrollLayer()](libraries/30-layers-creating-and-using-new-layers.md) function:


```c
    void ScrollLayer(LONG unused, struct Layer *layer, LONG dx, LONG dy)
```
Pass this function a pointer to the window's layer in layer and the scroll
offsets in dx and dy.  (A pointer to the window's layer can be obtained
from [Window.RPort](libraries/4-intuition-windows-the-window-structure.md)->Layer.)

When rendering operations are performed in a SuperBitMap window, any
rendering that falls outside window boundaries is done in the
application's bitmap.  Rendering that falls within window bounds is done
in the screen's bitmap.  Before performing an operation such as a save on
the application bitmap, the graphics library function [SyncSBitMap()](autodocs-2.0/graphics-library-syncsbitmap.md) should
be called:


```c
    void SyncSBitMap(struct Layer *layer)
```
Pass this function a pointer to the window's layer.  [SyncSBitMap()](autodocs-2.0/graphics-library-syncsbitmap.md) copies
the window contents to the corresponding part of the application bitmap,
bringing it up to date.  (If no rendering operations have been performed
this call is not necessary.)

Similarly, after making any changes to the application bitmap such as
loading a new one, the window's layer should be locked and the
[CopySBitMap()](autodocs-2.0/graphics-library-copysbitmap.md) function should be called.


```c
    void CopySBitMap(struct Layer *)
```
This function copies the new information in the appropriate area of the
underlying bitmap to the window's layer.

For more information about bitmaps and layers, see the
"[Graphics Primitives](libraries/27-data-move-operations-scrolling-a-sub-rectangle-of-a.md)" and "[Layers Library](libraries/30-layers-creating-and-using-new-layers.md)" chapters of this manual.  Also
see the <graphics/[clip.h](autodocs-2.0/includes-graphics-clip-h.md)>, <graphics/[gfx.h](autodocs-2.0/includes-graphics-gfx-h.md)>, <graphics/[layers.h](autodocs-2.0/includes-graphics-layers-h.md)>,
[graphics library](autodocs-2.0/graphics-doc.md) and [layers library](autodocs-2.0/layers-doc.md) sections of the Amiga ROM Kernel
Reference Manual: Includes and Autodocs.

---

## See Also

- [CopySBitMap — graphics.library](../autodocs/graphics.library.md#copysbitmap)
- [ScrollLayer — layers.library](../autodocs/layers.library.md#scrolllayer)
- [SyncSBitMap — graphics.library](../autodocs/graphics.library.md#syncsbitmap)
