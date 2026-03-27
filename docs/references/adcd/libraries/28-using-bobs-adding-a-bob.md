---
title: 28 / Using Bobs / Adding a Bob
manual: libraries
chapter: libraries
section: 28-using-bobs-adding-a-bob
functions: [AddBob]
libraries: [graphics.library]
---

# 28 / Using Bobs / Adding a Bob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To add a Bob to the system GEL list, use the [AddBob()](autodocs-2.0/graphics-library-addbob.md) routine.  The [Bob](libraries/28-using-bobs-the-bob-structure.md)
and [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structures must be correct and cohesive when this call is
made.  See the [makeBob()](libraries/lib-examples-animtools-c.md) and [makeVSprite()](libraries/lib-examples-animtools-c.md) routines in the [animtools.c](libraries/lib-examples-animtools-c.md)
file listed at the end of this chapter for a detailed example of setting
up Bobs and VSprites.  See the [setupGelSys()](libraries/lib-examples-animtools-c.md) function for a more complete
example of the initialization of the GELs system.

For example:


```c
    struct GelsInfo myGelsInfo = {0};
    struct VSprite dummySpriteA = {0}, dummySpriteB = {0};
    struct Bob myBob = {0};
    struct RastPort rastport = {0};

    /* Done ONCE, for this GelsInfo.  See setupGelSys() at the end of this
    ** chapter for a more complete initialization of the Gel system
    */
    InitGels(&dummySpriteA, &dummySpriteB, &myGelsInfo);

    /* Initialize the Bob members here, then AddBob() */
    AddBob(&myBob, &rastport);
```

---

## See Also

- [AddBob — graphics.library](../autodocs/graphics.library.md#addbob)
