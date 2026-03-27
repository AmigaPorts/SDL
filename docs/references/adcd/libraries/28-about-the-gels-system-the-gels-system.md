---
title: 28 / About the GELs System / The GELs System
manual: libraries
chapter: libraries
section: 28-about-the-gels-system-the-gels-system
functions: [SortGList]
libraries: [graphics.library]
---

# 28 / About the GELs System / The GELs System

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Before you can use the GELs system, you must set up a playfield.  The GELs
system requires access to a [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md), [ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md), and [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) structure.  These
structures may be set up through the grapics library or Intuition.  For
most examples in this chapter, the Intuition library is used for this
purpose.

All GELs have a [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure at their core.  The system keeps track
of all the GELs that it will display (the active GELs) by using a standard
Exec list structure to link the VSprites.  This list is accessed via the
GelsInfo data structure, which in turn is associated with the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).
The GelsInfo structure is defined in the file <graphics/[rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)>. When
a new GEL is introduced to the system, the new GEL is added immediately
ahead of the first existing GEL whose x, y value is greater than or equal
to that of the new GEL, always trying to keep the list sorted.

As GELs are moved about the screen, their x, y values are constantly
changing.  [SortGList()](libraries/28-using-virtual-sprites-getting-the-vsprite-list-in-order.md) re-sorts this list by the x, y values. (Although
this is a list of [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structures, bear in mind that some or all may
really be Bobs or AnimComps.)

The basic set up of the [GelsInfo](autodocs-2.0/includes-graphics-rastport-h.md) structure requires three important
fields:  [sprRsrvd](libraries/28-vsprite-advanced-topics-reserving-hardware-sprites.md),  gelHead and gelTail.  The sprRsrvd field tells the
system which hardware sprites not to use when managing true VSprites.  For
instance, Intuition uses sprite 0 for the mouse pointer so this hardware
sprite is not available for assignment to a VSprite.  The gelHead and
gelTail are [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structures that are used to manage the list of GELs.
They are never displayed.  To activate or deactivate a GEL, a system call
is made to add it to or delete it from this list.

Other fields must be set up to provide for collision detection, color
optimization, and other features.  A complete example for setting up the
[GelsInfo](autodocs-2.0/includes-graphics-rastport-h.md) structure is shown in the [animtools.c](libraries/lib-examples-animtools-c.md) lisitng at the end of this
chapter.

 [Initializing the GEL System](libraries/28-the-gels-system-initializing-the-gel-system.md) 

---

## See Also

- [SortGList — graphics.library](../autodocs/graphics.library.md#sortglist)
