# 27 / / The RastPort Structure / Initializing a BitMap Structure


Associated with the [RastPort](../Libraries_Manual_guide/node034A.html) is another data structure called a [BitMap](../Libraries_Manual_guide/node032B.html#line74)
which contains a description of the organization of the data in the
drawing area.  This tells the graphics library where in memory the drawing
area is located and how it is arranged.  Before you can set up a RastPort
for drawing you must first declare and initialize a BitMap structure,
defining the characteristics of the drawing area, as shown in the
following example. This was already shown in the "[Forming a Basic Display](../Libraries_Manual_guide/node032C.html)"
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
