---
title: 4 / Preserving the Window Display / Setting Up A SuperBitMap Window
manual: libraries
chapter: libraries
section: 4-preserving-the-window-display-setting-up-a-superbitmap
functions: [AllocMem, AllocRaster, InitBitMap, OpenWindowTagList]
libraries: [exec.library, graphics.library, intuition.library]
---

# 4 / Preserving the Window Display / Setting Up A SuperBitMap Window

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

SuperBitMap windows are created by setting the WFLG_SUPER_BITMAP flag, or
by specifying the [WA_SuperBitMap](libraries/4-window-attributes-boolean-window-attribute-tags.md) tag in the [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) call.  A
pointer to an allocated and initialized [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure must be provided.

A SuperBitMap window requires the application to allocate and initialize
its own bitmap.  This entails allocating a [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure, initializing
the structure and allocating memory for the bit planes.

Allocate a [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure with the Exec [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) function.  Then use
the graphics function [InitBitMap()](libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md) to initialize the BitMap structure:


```c
    void InitBitMap( struct BitMap *bitMap, long depth,
                     long width, long height );
```
[InitBitMap()](libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md) fills in fields in the [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure describing how a
linear memory area is organized as a series of one or more rectangular
bit-planes.

Once you have allocated and initialized the [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure, use the
graphics library function [AllocRaster()](libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md) to allocate the memory space for
all the bit planes.


```c
    PLANEPTR AllocRaster( unsigned long width, unsigned long height );
```
The [example](libraries/lib-examples-lines-c.md) listed in the next section shows how to allocate a [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md)
structure, initialize it with [InitBitMap()](libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md) and use [AllocRaster()](libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md) function
to set up memory for the bitplanes.

 [Graphics and Layers Functions for SuperBitMap Windows](libraries/4-setting-up-a-superbitmap-window-graphics-and-layers.md) 
 [SuperBitMap Window Example](libraries/lib-examples-lines-c.md) 

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [AllocRaster — graphics.library](../autodocs/graphics.library.md#allocraster)
- [InitBitMap — graphics.library](../autodocs/graphics.library.md#initbitmap)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
