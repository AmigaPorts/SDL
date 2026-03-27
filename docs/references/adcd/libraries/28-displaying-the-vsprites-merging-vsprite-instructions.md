---
title: 28 / / Displaying the VSprites / Merging VSprite Instructions
manual: libraries
chapter: libraries
section: 28-displaying-the-vsprites-merging-vsprite-instructions
functions: [DrawGList, MrgCop]
libraries: [graphics.library]
---

# 28 / / Displaying the VSprites / Merging VSprite Instructions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md) has prepared the necessary instructions and memory areas
to display the data, the VSprites are installed into the display with
[MrgCop()](autodocs-2.0/graphics-library-mrgcop.md).  (DrawGList() does not actually draw the VSprites, it only
prepares the Copper instructions.)


```c
    struct View *view;

    MrgCop(view);
```
The view is a pointer to the [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure whose Copper instructions are
to be merged.

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
