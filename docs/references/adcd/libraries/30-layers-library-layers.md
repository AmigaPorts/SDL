---
title: 30 Layers Library / Layers
manual: libraries
chapter: libraries
section: 30-layers-library-layers
functions: []
libraries: []
---

# 30 Layers Library / Layers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The concept of a layer is closely tied to Intuition windows.  A layer is a
rectangular drawing area.  A layer can overlap other layers and has a
display priority that determines whether it will appear in front or behind
other layers.  Every Intuition window has an associated [Layer](libraries/30-layers-the-layer-structure.md) structure.
Layers allow Intuition and application programs to :


```c
    * Share a display's [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) among various tasks in an orderly way
      by creating layers, separate drawing rectangles, within the
      BitMap.

    * Move, size or depth-arrange a layer while automatically keeping
      track of which portions of other layers are hidden or revealed
      by the operation.

    * Manage the remapping of coordinates, so the application need not
      track the layer's offset into the [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).

    * Maintain each layer as a separate entity, which may optionally
      have its own [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).

    * Automatically update same newly visible portions.
```
The layers library takes care of housekeeping: the low level, repetitive
tasks which are required to keep track of where to place bits.  The layers
library also provides a locking mechanism which coordinates display
updating when multiple tasks are drawing graphics to layers.  The
windowing environment provided by the Intuition library is largely based
on layers.


```c
    WARNING:
    --------
    Layers may not be created or used directly with Intuition screens.
    Intuition windows are the only supported method of adding layers to
    Intuition screens.  Only the layer locking and unlocking functions
    are safe to use with Intuition.  An application must create and
    manage its own [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) if it will be creating layers directly on the
    display.
```
 [The Layer Structure](libraries/30-layers-the-layer-structure.md)           [Working With Existing Layers](libraries/30-layers-working-with-existing-layers.md) 
 [The Layer's RastPort](libraries/30-layers-the-layer-s-rastport.md)          [Creating and Using New Layers](libraries/30-layers-creating-and-using-new-layers.md) 
 [Types of Layers](libraries/30-layers-types-of-layers.md)               [Layers Example](libraries/lib-examples-layers-c.md) 
 [Opening the Layers Library](libraries/30-layers-opening-the-layers-library.md) 

