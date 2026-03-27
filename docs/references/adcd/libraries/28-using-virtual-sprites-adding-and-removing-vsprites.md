---
title: 28 / Using Virtual Sprites / Adding and Removing VSprites
manual: libraries
chapter: libraries
section: 28-using-virtual-sprites-adding-and-removing-vsprites
functions: [AddVSprite, RemVSprite]
libraries: [graphics.library]
---

# 28 / Using Virtual Sprites / Adding and Removing VSprites

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once a true VSprite has been set up and initialized, the obvious next step
is to give it to the system by adding it to the GEL list. The VSprite may
then be manipulated as needed.  Before the program ends, the VSprite
should be removed from the GELs list by calling [RemVSprite()](autodocs-2.0/graphics-library-remvsprite.md). A typical
calling sequence could be performed like so:


```c
    struct VSprite  myVSprite = {0};
    struct RastPort myRastPort = {0};

    AddVSprite(&myVSprite, &myRastPort);

    /* Manipulate the VSprite as needed here */

    RemVSprite(&myVSprite);
```
The &myVSprite argument is a fully initialized [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure and
&myRastPort is the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) with which this VSprite is to be associated.
Note that you will probably not like the results if you try to
[RemVSprite()](autodocs-2.0/graphics-library-remvsprite.md) a VSprite that has not been added to the system with
[AddVSprite()](autodocs-2.0/graphics-library-addvsprite.md).  See the Amiga ROM Kernel Reference Manual: Includes and
Autodocs for additional information on these functions.

---

## See Also

- [AddVSprite — graphics.library](../autodocs/graphics.library.md#addvsprite)
- [RemVSprite — graphics.library](../autodocs/graphics.library.md#remvsprite)
