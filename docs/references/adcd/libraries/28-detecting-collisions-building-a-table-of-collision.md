---
title: 28 / / Detecting Collisions / Building a Table of Collision Routines
manual: libraries
chapter: libraries
section: 28-detecting-collisions-building-a-table-of-collision
functions: [SetCollision]
libraries: [graphics.library]
---

# 28 / / Detecting Collisions / Building a Table of Collision Routines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The collision handler table is a structure, CollTable, defined in
<graphics/[gels.h](autodocs-2.0/includes-graphics-gels-h.md)>.  It is accessed as the CollHandler member of the
[GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) structure.  The table only needs to be as large as the number of
bits for which you wish to provide collision processing.  It is safest,
though, to allocate space for all 16 entries, considering the small amount
of space required.

Call the routine [SetCollision()](autodocs-2.0/graphics-library-setcollision.md) to initialize the table entries that
correspond to the [HitMask](libraries/28-detecting-gel-collisions-using-hitmask-and-memask.md) and [MeMask](libraries/28-detecting-gel-collisions-using-hitmask-and-memask.md) bits that you plan to use.  Do not
set any of the table entries directly, instead give the address to
SetCollision() routine and let it handle the set up of the
[GelsInfo.CollTable](autodocs-2.0/includes-graphics-rastport-h.md) field.

For example, [SetCollision()](autodocs-2.0/graphics-library-setcollision.md) could be called as follows:


```c
    ULONG            num;
    VOID           (*routine)();
    struct GelsInfo *GInfo;

    VOID myCollisionRoutine(GELA, GELB)   /* sample collision routine */
    struct VSprite *GELA;
    struct VSprite *GELB;
    {
        /* process gels here - GELA and GELB point to the base VSprites */
        /* of the gels, you can use the user extensions to identify what */
        /* hit (if you need the info). */
    }

    /* GelsInfo must be allocated and initialized */

    routine = myCollisionRoutine;

    SetCollision(num, routine, GInfo)
```
The num argument is the collision table vector number (0-15).  The
(*routine)() argument is a pointer to your collision routine.  And the
GInfo argument is a pointer to the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) structure.

---

## See Also

- [SetCollision — graphics.library](../autodocs/graphics.library.md#setcollision)
