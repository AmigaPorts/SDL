---
title: 28 / / Displaying the VSprites / Drawing the Graphics Elements
manual: libraries
chapter: libraries
section: 28-displaying-the-vsprites-drawing-the-graphics-elements
functions: [DrawGList]
libraries: [graphics.library]
---

# 28 / / Displaying the VSprites / Drawing the Graphics Elements

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The system function called [DrawGList()](autodocs-2.0/graphics-library-drawglist.md) looks through the list of GELS and
prepares the necessary Copper instructions and memory areas to display the
data.  This function is called as follows:


```c
    struct RastPort myRastPort = {0};
    struct ViewPort myViewPort = {0};

    DrawGList(&myRastPort, &myViewPort);
```
The myRastPort argument specifies the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) containing the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md)
list with the VSprites that you want to display.  The &myViewPort argument
is a pointer to the [ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) for which the VSprites will be created.

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
