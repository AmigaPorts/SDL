---
title: 28 / / Specifying the Animation Object / Position of an AnimOb
manual: libraries
chapter: libraries
section: 28-specifying-the-animation-object-position-of-an-animob
functions: [DrawGList]
libraries: [graphics.library]
---

# 28 / / Specifying the Animation Object / Position of an AnimOb

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To position the object and its component parts, use the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) structure
members [AnX and AnY](libraries/28-animation-with-gels-animation-data-structures.md).  The following figure illustrates how each component
has its own offset from the AnimOb's common reference point.


```c
     [Figure 28-7: Specifying an AnimOb Position](libraries/lib-pics-28-7-pic.md) 
```
When you change the animation object's [AnX and AnY](libraries/28-animation-with-gels-animation-data-structures.md), all of the component
parts will be redrawn relative to it the next time [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md) is called.

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
