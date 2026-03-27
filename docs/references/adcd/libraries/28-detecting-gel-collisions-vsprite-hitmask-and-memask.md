---
title: 28 / / Detecting Gel Collisions / VSprite HitMask and MeMask
manual: libraries
chapter: libraries
section: 28-detecting-gel-collisions-vsprite-hitmask-and-memask
functions: [DoCollision]
libraries: [graphics.library]
---

# 28 / / Detecting Gel Collisions / VSprite HitMask and MeMask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Software collision detection is independently enabled and disabled for
each GEL. Further, you can specify which of 16 possible collision routines
you wish to have automatically executed.  [DoCollision()](libraries/28-graphics-sprites-bobs-and-animation-function-reference.md), in addition to
sensing an overlap between objects, uses these masks to determine which
routine (if any) the system will call when a collision occurs.

When the system determines a collision, it performs a logical-AND of the
[HitMask](libraries/28-detecting-gel-collisions-using-hitmask-and-memask.md) of the upper-leftmost object in the colliding pair with the [MeMask](libraries/28-detecting-gel-collisions-using-hitmask-and-memask.md)
of the lower-rightmost object of the pair.  The bits that are 1s after the
logical-AND operation choose which one of the 16 possible collision
routines to perform.

  * If the collision is with the boundary, bit 0 is always a 1 and the

```c
    system calls the collision handling routine number 0.  Always assign
    the routine that handles boundary collisions to vector 0 in the
    collision handling table. The system uses the flag called BORDERHIT
    to indicate that an object has landed on or moved beyond the
    outermost bounds of the drawing area (the edge of the clipping
    region).  The [VSprite example](libraries/lib-examples-vsprite-c.md) earlier in this chapter uses collision
    detection to check for border hits.
```
  * If any one of the other bits (1 to 15) is set, then the system calls

    your collision handling routine corresponding to the bit set.
  * If more than one bit is set in both masks, the system calls the

```c
    vector corresponding to the rightmost (the least significant) bit
    only.
```

---

## See Also

- [DoCollision — graphics.library](../autodocs/graphics.library.md#docollision)
