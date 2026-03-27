---
title: 27 / / Using the Graphics Drawing Routines / Area-fill Operations
manual: libraries
chapter: libraries
section: 27-using-the-graphics-drawing-routines-area-fill-operations
functions: [AreaDraw, AreaEnd, AreaMove]
libraries: [graphics.library]
---

# 27 / / Using the Graphics Drawing Routines / Area-fill Operations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Assuming that you have properly initialized your [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) structure to
include a properly initialized [AreaInfo](libraries/27-the-rastport-structure-rastport-area-fill-information.md), you can perform area fill by
using the functions described in this section.

[AreaMove()](autodocs-2.0/graphics-library-areamove.md) tells the system to begin a new polygon, closing off any other
polygon that may already be in process by connecting the end-point of the
previous polygon to its starting point. AreaMove() is executed with the
statement:


```c
    LONG result;
    result = AreaMove(&rastPort, x, y);
```
[AreaMove()](autodocs-2.0/graphics-library-areamove.md) returns 0 if successful, -1 if there was no more space left in
the vector list. [AreaDraw()](autodocs-2.0/graphics-library-areadraw.md) tells the system to add a new vertex to a list
that it is building.  No drawing takes place until [AreaEnd()](autodocs-2.0/graphics-library-areaend.md) is executed.
AreaDraw is executed with the statement:


```c
    LONG result;
    result = AreaDraw(&rastPort, x, y);
```
[AreaDraw()](autodocs-2.0/graphics-library-areadraw.md) returns 0 if successful, -1 if there was no more space left in
the vector list. [AreaEnd()](autodocs-2.0/graphics-library-areaend.md) tells the system to draw all of the defined
shapes and fill them.  When this function is executed, it obeys the
drawing mode and uses the line pattern and area pattern specified in your
[RastPort](libraries/27-drawing-routines-the-rastport-structure.md) to render the objects you have defined.

To fill an area, you do not have to [AreaDraw()](autodocs-2.0/graphics-library-areadraw.md) back to the first point
before calling [AreaEnd()](autodocs-2.0/graphics-library-areaend.md).  AreaEnd() automatically closes the polygon.
AreaEnd() is executed with the following statement:


```c
    LONG result;
    result = AreaEnd(&rastPort);
```
[AreaEnd()](autodocs-2.0/graphics-library-areaend.md) returns 0 if successful, -1 if there was an error. To turn off
the outline function, you have to set the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) [Flags](libraries/27-drawing-routines-the-rastport-structure.md) variable back to
0 with [BNDRYOFF()](autodocs-2.0/includes-graphics-gfxmacros-h.md):


```c
    #include "graphics/gfxmacros.h"

    BNDRYOFF(&rastPort);
```
Otherwise, every subsequent area-fill or rectangle-fill operation will
outline their rendering with the outline pen ([AOlPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md)).

---

## See Also

- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
