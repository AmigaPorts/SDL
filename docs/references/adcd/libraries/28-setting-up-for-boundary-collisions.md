---
title: 28 / / Setting Up For Boundary Collisions
manual: libraries
chapter: libraries
section: 28-setting-up-for-boundary-collisions
functions: [DoCollision]
libraries: [graphics.library]
---

# 28 / / Setting Up For Boundary Collisions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To specify the region in the playfield that the system will use to define
the outermost limits of the GEL boundaries, you use these [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md)
members: [topmost, bottommost, leftmost, and rightmost](autodocs-2.0/includes-graphics-rastport-h.md). The [DoCollision()](libraries/28-graphics-sprites-bobs-and-animation-function-reference.md)
routine tests these boundaries when determining boundary collisions within
this [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).  They have nothing whatsoever to do with graphical
clipping.  Graphical clipping makes use of the RastPort's clipping
rectangle.

Here is a typical program segment that assigns the members correctly (for
boundaries 50, 100, 80, 240).  It assumes that you already have a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)
structure pointer named myRastPort.


```c
    myRastPort->GelsInfo->topmost    = 50;
    myRastPort->GelsInfo->bottommost = 100;
    myRastPort->GelsInfo->leftmost   = 80;
    myRastPort->GelsInfo->rightmost  = 240;
```
 [Parameters To Your Boundary Collision Routine](libraries/28-parameters-to-your-boundary-collision-routine.md) 
 [Parameters To Your Inter-GEL Collision Routines](libraries/28-parameters-to-your-inter-gel-collision-routines.md) 
 [Handling Multiple Collisions](libraries/28-set-up-for-boundary-collisions-handling-multiple.md) 

---

## See Also

- [DoCollision — graphics.library](../autodocs/graphics.library.md#docollision)
