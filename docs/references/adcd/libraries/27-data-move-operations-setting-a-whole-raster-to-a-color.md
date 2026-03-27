---
title: 27 / / Data Move Operations / Setting a Whole Raster to a Color
manual: libraries
chapter: libraries
section: 27-data-move-operations-setting-a-whole-raster-to-a-color
functions: [SetRast]
libraries: [graphics.library]
---

# 27 / / Data Move Operations / Setting a Whole Raster to a Color

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can preset a whole raster to a single color by using the function
[SetRast()](autodocs-2.0/graphics-library-setrast.md). A call to this function takes the following form:


```c
    SetRast(&rastPort, pen);
```
As always, the &rastPort is a pointer to the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) you wish to use.
Set the pen argument to the color register you want to fill the RastPort
with.

---

## See Also

- [SetRast — graphics.library](../autodocs/graphics.library.md#setrast)
