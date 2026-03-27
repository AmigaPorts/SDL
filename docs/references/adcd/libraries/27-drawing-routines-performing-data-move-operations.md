---
title: 27 / Drawing Routines / Performing Data Move Operations
manual: libraries
chapter: libraries
section: 27-drawing-routines-performing-data-move-operations
functions: [WaitBlit]
libraries: [graphics.library]
---

# 27 / Drawing Routines / Performing Data Move Operations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The graphics library includes several routines that use the hardware
blitter to handle the rectangularly organized data that you work with when
doing raster-based graphics.  These blitter routines do the following:


      * Clear an entire segment of memory

      * Set a raster to a specific color

      * Scroll a subrectangle of a raster

      * Draw a pattern "through a stencil"

      * Extract a pattern from a bit-packed array and draw it into a
        raster

      * Copy rectangular regions from one bitmap to another

      * Control and utilize the hardware-based data mover, the blitter
The following sections cover these routines in detail.


```c
    WARNING:
    --------
    The graphics library rendering and data movement routines generally
    wait to get access to the blitter, start their blit, and then exit
    without waiting for the blit to finish.  Therefore, you must
    [WaitBlit()](libraries/27-performing-data-move-operations-when-to-wait-for-the.md) after a graphics rendering or data movement call if you
    intend to immediately deallocate, examine, or perform order-dependent
    processor operations on the memory used in the call.
```
 [Clearing a Memory Area](libraries/27-performing-data-move-operations-clearing-a-memory-area.md) 
 [Setting a Whole Raster to a Color](libraries/27-data-move-operations-setting-a-whole-raster-to-a-color.md) 
 [Scrolling a Sub-rectangle of a Raster](libraries/27-data-move-operations-scrolling-a-sub-rectangle-of-a.md) 
 [Drawing through a Stencil](libraries/27-performing-data-move-operations-drawing-through-a-stencil.md) 
 [Extracting from a Bit-packed Array](libraries/27-data-move-operations-extracting-from-a-bit-packed-array.md) 
 [Copying Rectangular Areas](libraries/27-performing-data-move-operations-copying-rectangular-areas.md) 
 [Scaling Rectangular Areas](libraries/27-performing-data-move-operations-scaling-rectangular-areas.md) 
 [When to Wait for the Blitter](libraries/27-performing-data-move-operations-when-to-wait-for-the.md) 
 [Accessing the Blitter Directly](libraries/27-performing-data-move-operations-accessing-blitter.md) 

---

## See Also

- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
