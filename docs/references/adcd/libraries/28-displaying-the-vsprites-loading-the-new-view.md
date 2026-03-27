---
title: 28 / / Displaying the VSprites / Loading the New View
manual: libraries
chapter: libraries
section: 28-displaying-the-vsprites-loading-the-new-view
functions: [LoadView]
libraries: [graphics.library]
---

# 28 / / Displaying the VSprites / Loading the New View

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Now that the display instructions include the definition of the VSprites,
the system can display this newly configured [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) with the [LoadView()](autodocs-2.0/graphics-library-loadview.md)
function:


```c
    struct View *view;

    LoadView(view);
```
Again, view is a pointer to the [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) that contains the the new Copper
instruction list (if you are using GELs in an Intuition Screen, do not
call [LoadView()](autodocs-2.0/graphics-library-loadview.md).)

The Copper instruction lists are double-buffered, so this instruction does
not actually take effect until the next display field occurs. This avoids
the possibility of some function trying to update the Copper instruction
list while the Copper is trying to use it to create the display.

---

## See Also

- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
