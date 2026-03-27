---
title: 28 / Animation with GELs / Moving the Objects
manual: libraries
chapter: libraries
section: 28-animation-with-gels-moving-the-objects
functions: [Animate, DoCollision, DrawGList, SortGList]
libraries: [graphics.library]
---

# 28 / Animation with GELs / Moving the Objects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When you have defined all of the structures and have established all of
the links, you can call the [Animate()](autodocs-2.0/graphics-library-animate.md) routine to move the objects.
Animate() adjusts the positions of the objects as described above, and
calls the various subroutines ([AnimCRoutines](libraries/28-animation-with-gels-your-own-animation-routine-calls.md) and [AnimORoutines](libraries/28-animation-with-gels-your-own-animation-routine-calls.md)) that you
have specified.

After the system has completed the [Animate()](autodocs-2.0/graphics-library-animate.md) routine, some GELs may have
been moved, so the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) list order may possibly be incorrect.
Therefore, the list must be re-sorted with [SortGList()](libraries/28-using-virtual-sprites-getting-the-vsprite-list-in-order.md) before passing it
to a system routine.

If you are using collision detection, you then perform [DoCollision()](libraries/28-graphics-sprites-bobs-and-animation-function-reference.md).
Your collision routines may also have an effect on the relative position
of the GELs.  Therefore, you should again call [SortGList()](libraries/28-using-virtual-sprites-getting-the-vsprite-list-in-order.md) to assure that
the system correctly orders the objects before you call [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md). When
you call DrawGList(), the system renders all the GELs it finds in the
[GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) list and any changes caused by the previous call to [Animate()](autodocs-2.0/graphics-library-animate.md) can
then be seen.

This is illustrated in the following typical call sequence:


```c
    struct AnimOb **myAnimKey;
    struct RastPort *rp;
    struct ViewPort *vp;

    /* ... setup of graphics elements and objects */

    Animate(myAnimKey, rp);       /* "move" objects per instructions */
    SortGList(rp);                /*  put them in order */
    DoCollision(rp);              /*  software collision detect/action */
    SortGList(rp);                /*  put them back into right order */
    DrawGList(vp, rp);            /*  draw into current RastPort */
```

---

## See Also

- [Animate — graphics.library](../autodocs/graphics.library.md#animate)
- [DoCollision — graphics.library](../autodocs/graphics.library.md#docollision)
- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [SortGList — graphics.library](../autodocs/graphics.library.md#sortglist)
