---
title: 27 / / Forming a Basic Display / Preparing the RasInfo Structure
manual: libraries
chapter: libraries
section: 27-forming-a-basic-display-preparing-the-rasinfo-structure
functions: [ScrollVPort]
libraries: [graphics.library]
---

# 27 / / Forming a Basic Display / Preparing the RasInfo Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [RasInfo](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure provides information to the system about the
location of the [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) as well as the positioning of the display area as a
window against a larger drawing area. Use the following steps to prepare
the RasInfo structure:


```c
    /* Initialize the RasInfos. */
    rasInfo.BitMap = &bitMap;  /* Attach the corresponding BitMap.       */
    rasInfo.RxOffset = 0;      /* Align upper left corners of display    */
    rasInfo.RyOffset = 0;      /* with upper left corner of drawing area.*/
    rasInfo.Next = NULL;       /* for a single playfield display, there
                                * is only one RasInfo structure present  */
```
The system may be made to reinterpret the [RxOffset](autodocs-2.0/includes-graphics-view-h.md) and [RyOffset](autodocs-2.0/includes-graphics-view-h.md) values in
a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)'s [RasInfo](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure by calling [ScrollVPort()](autodocs-2.0/graphics-library-scrollvport.md) with the address
of the ViewPort. Changing one or both offsets and calling ScrollVPort()
has the effect of scrolling the ViewPort.

---

## See Also

- [ScrollVPort — graphics.library](../autodocs/graphics.library.md#scrollvport)
