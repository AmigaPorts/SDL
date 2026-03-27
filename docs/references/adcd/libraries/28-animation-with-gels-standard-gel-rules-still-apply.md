---
title: 28 / Animation with GELs / Standard Gel Rules Still Apply
manual: libraries
chapter: libraries
section: 28-animation-with-gels-standard-gel-rules-still-apply
functions: [Animate, DrawGList, InitGels]
libraries: [graphics.library]
---

# 28 / Animation with GELs / Standard Gel Rules Still Apply

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Before you use the animation system, you must have called the routine
[InitGels()](libraries/28-the-gels-system-initializing-the-gel-system.md).  The section called "[Bob Priorities](libraries/28-using-bobs-bob-priorities.md)" describes how the system
maintains the list of GELs to draw on the screen according to their
various data fields.  The animation system selectively adds GELs to and
removes GELs from this list of screen objects during the [Animate()](libraries/28-animation-with-gels-moving-the-objects.md)
routine.  On the next call to [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md), the system will draw the GELs
in the list into the selected [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).

---

## See Also

- [Animate — graphics.library](../autodocs/graphics.library.md#animate)
- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
