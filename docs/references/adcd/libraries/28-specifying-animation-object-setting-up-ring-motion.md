---
title: 28 / / Specifying Animation Object / Setting Up Ring Motion Control
manual: libraries
chapter: libraries
section: 28-specifying-animation-object-setting-up-ring-motion
functions: [DrawGList]
libraries: [graphics.library]
---

# 28 / / Specifying Animation Object / Setting Up Ring Motion Control

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To make a given component trigger a move of the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) you set the
[RINGTRIGGER](autodocs-2.0/includes-graphics-gels-h.md) bit of that [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md)'s [Flags](libraries/28-animation-with-gels-animation-data-structures.md) field. When the system software
encounters this flag, it adds the values of [RingXTrans](libraries/28-animation-with-gels-animation-data-structures.md) and [RingYTrans](libraries/28-animation-with-gels-animation-data-structures.md) to
the [AnX and AnY](libraries/28-specifying-the-animation-object-position-of-an-animob.md) values of the controlling AnimOb.  The next time you
execute [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md), the drawing sequence will use the new position.

You usually set [RINGTRIGGER](autodocs-2.0/includes-graphics-gels-h.md) in only one of the animation components in a
sequence (the last one); however, you can use this flag and the
translation variables any way you wish.

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
