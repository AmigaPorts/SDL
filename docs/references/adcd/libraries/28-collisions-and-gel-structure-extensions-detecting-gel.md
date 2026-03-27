---
title: 28 / Collisions and GEL Structure Extensions / Detecting Gel Collisions
manual: libraries
chapter: libraries
section: 28-collisions-and-gel-structure-extensions-detecting-gel
functions: [DoCollision]
libraries: [graphics.library]
---

# 28 / Collisions and GEL Structure Extensions / Detecting Gel Collisions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All GELs, including VSprites, can participate in the software collision
detection features of the graphics library.  Simple Sprites must use
hardware collision detection.  See the Amiga [Hardware](hardware/7-system-control-hardware-collision-detection.md) Reference Manual for
information about hardware collision detection.

Two kinds of collisions are handled by the system routines:
GEL-to-boundary hits and GEL-to-GEL hits.  You can set up as many as 16
different routines to handle different collision combinations; one routine
to handle the boundary hits, and up to fifteen more to handle different
inter-GEL hits.

You supply the actual collision handling routines, and provide their
addresses to the system so that it can call them as needed (when the hits
are detected).  These addresses are kept in a collision handler table
pointed to by the [CollHandler](libraries/28-detecting-collisions-building-a-table-of-collision.md) field of the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) list.  Which routine
is called depends on the 16-bit [MeMask](autodocs-2.0/includes-graphics-gels-h.md) and [HitMask](autodocs-2.0/includes-graphics-gels-h.md) members of the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md)
structures involved in the collision.

When you call [DoCollision()](libraries/28-graphics-sprites-bobs-and-animation-function-reference.md), the system goes through the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) list
which, is constantly kept sorted by x, y position.  If a GEL intersects
the display boundaries and the GELs [HitMask](autodocs-2.0/includes-graphics-gels-h.md) indicates it is appropriate,
the boundary collision routine is called.  When DoCollision() finds that
two GELs overlap, it compares the [MeMask](autodocs-2.0/includes-graphics-gels-h.md) of one with the HitMask of the
other.  If corresponding bits are set in both, it calls the appropriate
inter-GEL collision routine at the table position corresponding to the
bits in the HitMask and MeMask, as outlined below.

 [Preparing for Collision Detection](libraries/28-detecting-gel-collisions-preparing-for-collision.md)         [VSprite BorderLine](libraries/28-detecting-gel-collisions-vsprite-borderline.md) 
 [Building a Table of Collision Routines](libraries/28-detecting-collisions-building-a-table-of-collision.md)    [VSprite HitMask and MeMask](libraries/28-detecting-gel-collisions-vsprite-hitmask-and-memask.md) 
 [VSprite Collision Mask](libraries/28-detecting-gel-collisions-vsprite-collision-mask.md)                    [Using HitMask and MeMask](libraries/28-detecting-gel-collisions-using-hitmask-and-memask.md) 

---

## See Also

- [DoCollision — graphics.library](../autodocs/graphics.library.md#docollision)
