---
title: 28 / / / Parameters To Your Boundary Collision Routine
manual: libraries
chapter: libraries
section: 28-parameters-to-your-boundary-collision-routine
functions: [DoCollision]
libraries: [graphics.library]
---

# 28 / / / Parameters To Your Boundary Collision Routine

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

During the operation of the [DoCollision()](libraries/28-graphics-sprites-bobs-and-animation-function-reference.md) routine, if you have enabled
boundary collisions for a GEL (by setting the least significant bit of its
[HitMask](libraries/28-detecting-gel-collisions-using-hitmask-and-memask.md)) and it has crossed a boundary, the system calls the boundary
routine you have defined.  The system will call the routine once for every
GEL that has hit, or gone outside of the boundary.  The system will call
your routine with the following two arguments:

  * A pointer to the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure of the GEL that hit the boundary

  * A flag word containing one to four bits set, representing top,

    bottom, left and right boundaries, telling you which of the
    boundaries it has hit or exceeded. To test these bits, compare to the
    constants TOPHIT, BOTTOMHIT, LEFTHIT, and RIGHTHIT.
See the [VSprite example](libraries/lib-examples-vsprite-c.md) given earlier for an example of using boundary
collision.

---

## See Also

- [DoCollision — graphics.library](../autodocs/graphics.library.md#docollision)
