---
title: 28 / Using Bobs / Sorting and Displaying Bobs
manual: libraries
chapter: libraries
section: 28-using-bobs-sorting-and-displaying-bobs
functions: [DrawGList, LoadView, MrgCop, RethinkDisplay, SortGList, WaitTOF]
libraries: [graphics.library, intuition.library]
---

# 28 / Using Bobs / Sorting and Displaying Bobs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As with VSprites, the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) list must be sorted before any Bobs can be
displayed.  This is accomplished with the [SortGList()](libraries/28-using-virtual-sprites-getting-the-vsprite-list-in-order.md) function.  For Bobs,
the system uses the position information to decide inter-Bob priorities,
if not explicitly set by using the [Bob.Before](libraries/28-bob-priorities-specifying-the-drawing-order.md) and [Bob.After](libraries/28-bob-priorities-specifying-the-drawing-order.md) pointers.

Once the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) list has been sorted, the Bobs in the list can be
displayed by calling [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md).  This call should then be followed by a
call to [WaitTOF()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md) if the application wants to be sure that the Bobs are
rendered before proceeding.  Call these functions as follows:


```c
    struct RastPort myRastPort = {0};  /* Of course, these have to be */
    struct ViewPort myViewPort = {0};  /* initialized...              */

    SortGList(&myRastPort);
    DrawGList(&myRastPort, &myViewPort);/* Draw the elements (Bobs only) */
    WaitTOF();


    Warning:
    --------
    If your [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) list contains VSprites in addition to Bobs, you
    must also call [MrgCop()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md) and [LoadView()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md) to make all the GELs
    visible.  Or, under Intuition, [RethinkDisplay()](libraries/3-screen-functions-that-integrate-intuition-and-graphics.md) must be called to
    make all the GELs visible.
```

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
- [SortGList — graphics.library](../autodocs/graphics.library.md#sortglist)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
