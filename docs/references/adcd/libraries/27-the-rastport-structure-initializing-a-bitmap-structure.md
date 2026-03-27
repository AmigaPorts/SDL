---
title: 27 / / The RastPort Structure / Initializing a BitMap Structure
manual: libraries
chapter: libraries
section: 27-the-rastport-structure-initializing-a-bitmap-structure
functions: []
libraries: []
---

# 27 / / The RastPort Structure / Initializing a BitMap Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Associated with the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) is another data structure called a [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md)
which contains a description of the organization of the data in the
drawing area.  This tells the graphics library where in memory the drawing
area is located and how it is arranged.  Before you can set up a RastPort
for drawing you must first declare and initialize a BitMap structure,
defining the characteristics of the drawing area, as shown in the
following example. This was already shown in the "[Forming a Basic Display](libraries/27-display-routines-and-structures-forming-a-basic-display.md)"
section, but it is repeated here because it relates to drawing as well as
to display routines. (You need not necessarily use the same BitMap for
both the drawing and the display, e.g., double-buffered displays.)


```c
    #define DEPTH 2       /* Two planes deep. */
    #define WIDTH 320     /* Width in pixels. */
    #define HEIGHT 200    /* Height in scanlines. */

    struct BitMap bitMap;

    /* Initialize the BitMap. */
    InitBitMap(&bitMap, DEPTH, WIDTH, HEIGHT);
```
