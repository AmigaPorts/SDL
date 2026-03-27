---
title: 28 / / The GELs System / Initializing the GEL System
manual: libraries
chapter: libraries
section: 28-the-gels-system-initializing-the-gel-system
functions: [InitGels]
libraries: [graphics.library]
---

# 28 / / The GELs System / Initializing the GEL System

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To initialize the animation system, call the system function [InitGels()](autodocs-2.0/graphics-library-initgels.md).
It takes the form:


```c
    struct VSprite  *vsHead;
    struct VSprite  *vsTail;
    struct GelsInfo *gInfo;

    InitGels(vsHead, vsTail, gInfo);
```
The vsHead argument is a pointer to the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure to be used as
the GEL list head.  (You must allocate an actual VSprite structure for
vsHead to point to.)  The vsTail argument is a pointer to the VSprite
structure to be used as the GEL list tail.  (You must allocate an actual
VSprite structure for vsTail to point to.)  The gInfo argument is a
pointer to the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) structure to be initialized.

[InitGels()](autodocs-2.0/graphics-library-initgels.md) forms these structures into a linked list of GELs that is empty
except for these two dummy elements (the head and tail).  It gives the
head [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) the maximum negative x and y positions and the tail VSprite
the maximum positive x and y positions.  This is to aid the system in
keeping the list sorted by x, y values, so GELs that are closer to the top
and left of the display are nearer the head of the list.  The memory space
that the VSprites and [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) structures take up must already have been
allocated.  This can be done either by declaring them statically or
explicitly allocating memory for them.

Once the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) structure has been allocated and initialized, GELs can
be added to the system.  Refer to the [setupGelSys()](libraries/lib-examples-animtools-c.md) and [cleanupGelSys()](libraries/lib-examples-animtools-c.md)
functions in the [animtools.c](libraries/lib-examples-animtools-c.md) lisitng at the end of the chapter for
examples of allocating, initializing and freeing a GelsInfo structure.

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
