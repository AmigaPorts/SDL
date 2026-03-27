---
title: 27 / / The RastPort Structure / RastPort Area-fill Information
manual: libraries
chapter: libraries
section: 27-the-rastport-structure-rastport-area-fill-information
functions: [AreaDraw, AreaEnd, AreaMove, FreeRaster, InitArea, InitTmpRas]
libraries: [graphics.library]
---

# 27 / / The RastPort Structure / RastPort Area-fill Information

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Two structures in the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) -- [AreaInfo](autodocs-2.0/includes-graphics-rastport-h.md) and [TmpRas](autodocs-2.0/includes-graphics-rastport-h.md) -- define certain
information for area filling operations.  The AreaInfo pointer is
initialized by a call to the routine [InitArea()](autodocs-2.0/graphics-library-initarea.md).


```c
    #define AREA_SIZE 200

    register USHORT i;
    WORD areaBuffer[AREA_SIZE];
    struct AreaInfo areaInfo = {0};

    /*  Clear areaBuffer before calling InitArea().  */
    for (i=0; i<AREA_SIZE; i++)
        areaBuffer[i] = 0;

    InitArea(&areaInfo, areaBuffer, (AREA_SIZE*2)/5);
```
The area buffer must start on a word boundary.  That is why the sample
declaration shows areaBuffer as composed of unsigned words (200), rather
than unsigned bytes (400).  It still reserves the same amount of space,
but aligns the data space correctly.

To use area fill, you must first provide a work space in memory for the
system to store the list of points that define your area. You must allow a
storage space of 5 bytes per vertex.  To create the areas in the work
space, you use the functions [AreaMove()](libraries/27-using-the-graphics-drawing-routines-area-fill-operations.md), [AreaDraw()](libraries/27-using-the-graphics-drawing-routines-area-fill-operations.md), and [AreaEnd()](libraries/27-using-the-graphics-drawing-routines-area-fill-operations.md).

Typically, you prepare the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) for area-filling by following the
steps in the code fragment above and then linking your [AreaInfo](autodocs-2.0/includes-graphics-rastport-h.md) into the
RastPort like so:


```c
    rastPort->AreaInfo = &areaInfo;
```
In addition to the [AreaInfo](autodocs-2.0/includes-graphics-rastport-h.md) structure in the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md), you must also
provide the system with some work space to build the object whose vertices
you are going to define.  This requires that you initialize a [TmpRas](autodocs-2.0/includes-graphics-rastport-h.md)
structure, then point to that structure for your RastPort to use. First
the TmpRas structure is initialized (via [InitTmpRas()](autodocs-2.0/graphics-library-inittmpras.md)) then it is linked
into the RastPort structure.


```c
    Allocate Enough Space.
    ----------------------
    The area to which [TmpRas.RasPtr](autodocs-2.0/includes-graphics-rastport-h.md) points must be at least as large
    as the area (width times height) of the largest rectangular region
    you plan to fill. Typically, you allocate a space as large as a
    single bitplane (usually 320 by 200 bits for Lores mode, 640 by 200
    for Hires, and 1280 by 200 for SuperHires).
```
When you use functions that dynamically allocate memory from the system,
you must remember to return these memory blocks to the system before your
program exits.  See the description of [FreeRaster()](autodocs-2.0/graphics-library-freeraster.md) in the Amiga ROM
Kernel Reference Manual: Includes and Autodocs.

---

## See Also

- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
- [FreeRaster — graphics.library](../autodocs/graphics.library.md#freeraster)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
- [InitTmpRas — graphics.library](../autodocs/graphics.library.md#inittmpras)
