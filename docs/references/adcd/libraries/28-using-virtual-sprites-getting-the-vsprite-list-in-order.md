---
title: 28 / Using Virtual Sprites / Getting the VSprite List In Order
manual: libraries
chapter: libraries
section: 28-using-virtual-sprites-getting-the-vsprite-list-in-order
functions: [DrawGList, SortGList]
libraries: [graphics.library]
---

# 28 / Using Virtual Sprites / Getting the VSprite List In Order

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the system has displayed the last line of a VSprite, it is able to
reassign the hardware sprite to another VSprite located at a lower
position on the screen.  The system allocates hardware sprites in the
order in which it encounters the VSprites in the list.  Therefore, the
list of VSprites must be sorted before the system can assign the use of
the hardware Sprites correctly.

The function [SortGList()](autodocs-2.0/graphics-library-sortglist.md) must be used to get the GELs in the correct order
before the system is asked to display them.  This sorting step is
essential!  It should be done before calling [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md), whenever a GEL
has changed position.  This function is called as follows:


```c
    struct RastPort myRastPort = {0};

    SortGList(&myRastPort);
```
The only argument is a pointer to the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) structure containing the
[GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md).

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [SortGList — graphics.library](../autodocs/graphics.library.md#sortglist)
