---
title: 28 / Using Virtual Sprites / Using VSprite Flags
manual: libraries
chapter: libraries
section: 28-using-virtual-sprites-using-vsprite-flags
functions: [RemBob, RemVSprite]
libraries: [graphics.library]
---

# 28 / Using Virtual Sprites / Using VSprite Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [Flags](autodocs-2.0/includes-graphics-gels-h.md) member of the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure is both read and written by the
system.  Some bits are used by the application to inform the system;
others are used by the system to indicate things to the application.

The only [Flags](autodocs-2.0/includes-graphics-gels-h.md) bits that are used by true VSprites are:

[VSPRITE](autodocs-2.0/includes-graphics-gels-h.md)

    This may be set to indicate to the system that it should treat the
    structure as a true VSprite, not part of a Bob.  This affects the
    interpretation of the data layout and the use of various system
    variables.
[VSOVERFLOW](autodocs-2.0/includes-graphics-gels-h.md)

    The system sets this bit in the true VSprites that it is unable to
    display.  This happens when there are too many in the same scan line,
    and the system has run out of Simple Sprites to assign.  It indicates
    that this VSprite has not been displayed.  If no sprites are
    reserved, this means that more than eight sprites touch one scan
    line.  This bit will not be set for Bobs and should not be changed by
    the application.
[GELGONE](autodocs-2.0/includes-graphics-gels-h.md)

```c
    If the system has set GELGONE bit in the [Flags](autodocs-2.0/includes-graphics-gels-h.md) member, then the GEL
    associated with this VSprite is not on the display at all, it is
    entirely outside the GEL boundaries.  This area is defined by the
    [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) members [topmost, bottommost, leftmost and rightmost](libraries/28-setting-up-for-boundary-collisions.md) (see
    <graphics/[rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)>). On the basis of that information, the
    application may decide that the object need no longer be part of the
    GEL list and may decide to remove it to speed up the consideration of
    other objects. Use [RemVSprite()](libraries/28-using-virtual-sprites-adding-and-removing-vsprites.md) (or [RemBob()](libraries/28-using-bobs-removing-a-bob.md), if it's a Bob) to do
    this. This bit should not be changed by the application.
```
The [VSprite.Flags](autodocs-2.0/includes-graphics-gels-h.md) value should be initialized like this for a VSprite
GEL:


```c
    myVSprite.Flags = VSPRITE;
```

---

## See Also

- [RemBob — graphics.library](../autodocs/graphics.library.md#rembob)
- [RemVSprite — graphics.library](../autodocs/graphics.library.md#remvsprite)
