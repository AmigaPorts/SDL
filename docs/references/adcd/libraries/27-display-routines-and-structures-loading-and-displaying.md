---
title: 27 / Display Routines and Structures / Loading and Displaying the View
manual: libraries
chapter: libraries
section: 27-display-routines-and-structures-loading-and-displaying
functions: [LoadView]
libraries: [graphics.library]
---

# 27 / Display Routines and Structures / Loading and Displaying the View

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To display the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md), you need to load it using [LoadView()](autodocs-2.0/graphics-library-loadview.md) and turn on the
direct memory access (DMA). A typical call is shown below.


```c
    LoadView(&view);
```
The &view argument is the address of the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure defined in the
[example above](libraries/27-display-routines-and-structures-forming-a-basic-display.md).

There are two macros, defined in <graphics/[gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md)>, that control
display DMA: ON_DISPLAY and OFF_DISPLAY. They simply turn the display DMA
control bit in the DMA control register on or off.

If you are drawing to the display area and do not want the user to see
intermediate steps in the drawing, you can turn off the display.  Because
OFF_DISPLAY shuts down the display DMA and possibly speeds up other system
operations, it can be used to provide additional memory cycles to the
blitter or the 68000.  The distribution of system DMA, however, allows
four-channel sound, disk read/write, and a sixteen-color, low-resolution
display (or four-color, high-resolution display) to operate at the same
time with no slowdown (7.1 megahertz effective rate) in the operation of
the 68000.  Using OFF_DISPLAY in a multitasking environment may, however,
be an unfriendly thing to do to the other running processes.  Use
OFF_DISPLAY with discretion.

 [A Custom ViewPort Example](libraries/lib-examples-rgbboxes-c.md)    [Exiting Gracefully](libraries/27-loading-and-displaying-the-view-exiting-gracefully.md) 

---

## See Also

- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
