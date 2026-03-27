---
title: 28 / Using Virtual Sprites / Displaying the VSprites
manual: libraries
chapter: libraries
section: 28-using-virtual-sprites-displaying-the-vsprites
functions: [DrawGList, LoadView, MrgCop, WaitTOF]
libraries: [graphics.library]
---

# 28 / Using Virtual Sprites / Displaying the VSprites

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The next few sections explain how to display the VSprites. The following
system functions are used:


```c
    [DrawGList()](libraries/28-displaying-the-vsprites-drawing-the-graphics-elements.md)  [Draws](libraries/28-displaying-the-vsprites-merging-vsprite-instructions.md) the VSprites into the current [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).
       [MrgCop()](libraries/28-displaying-the-vsprites-merging-vsprite-instructions.md)  Installs the VSprites into the display.
     [LoadView()](libraries/28-displaying-the-vsprites-loading-the-new-view.md)  Asks the system to display the new [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).
      [WaitTOF()](libraries/28-displaying-the-vsprites-synchronizing-with-the-display.md)  Synchronizes the functions with the display.
```
 [Drawing the Graphics Elements](libraries/28-displaying-the-vsprites-drawing-the-graphics-elements.md)    [Loading the New View](libraries/28-displaying-the-vsprites-loading-the-new-view.md) 
 [Merging VSprite Instructions](libraries/28-displaying-the-vsprites-merging-vsprite-instructions.md)     [Synchronizing with the Display](libraries/28-displaying-the-vsprites-synchronizing-with-the-display.md) 

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
