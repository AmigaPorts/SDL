---
title: 28 / VSprite Advanced Topics / Reserving Hardware Sprites
manual: libraries
chapter: libraries
section: 28-vsprite-advanced-topics-reserving-hardware-sprites
functions: []
libraries: []
---

# 28 / VSprite Advanced Topics / Reserving Hardware Sprites

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To prevent the VSprite system from using specific hardware sprites, set
the [sprRsrvd](autodocs-2.0/includes-graphics-rastport-h.md) member of the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) structure. The pointer to the GelsInfo
structure is contained in the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) structure. If all of the bits of
this 8-bit value are ones (0xFF), then all of the hardware sprites may be
used by the VSprite system. If any of the bits is a 0, the sprite
corresponding to that bit will not be utilized by VSprites.


```c
    Reserving Can Cause Problems.
    -----------------------------
    Reserving sprites increases the likelihood of the system not being
    able to display a VSprite ([VSOVERFLOW](libraries/28-using-virtual-sprites-using-vsprite-flags.md)). See the next section,
    "[How VSprites are Assigned](libraries/28-vsprite-advanced-topics-how-vsprites-are-assigned.md)," for further details on this topic.
```
You reserve a sprite by setting its corresponding bit in sprRsrvd.  For
instance, to reserve sprite zero only, set sprRsrvd to 0x01.  To reserve
sprite three only, set sprRsrvd to 0x08.

If a hardware sprite is reserved, the system will not consider it when it
makes VSprite assignments.  Remember, hardware sprite pairs share color
register sets.  If a hardware sprite is reserved, its mate should probably
be reserved too, otherwise the reserved sprite's colors will change as the
unreserved mate is assigned different VSprites.  For example, it is common
practice to reserve Sprites 0 and 1, so that the Intuition pointer (Sprite
0) is left alone.  This could be accomplished with the following
statements:


```c
    struct RastPort myRastPort = {0};  /* the View structure is defined */

    myRastPort.GelsInfo->sprRsrvd = 0x03;  /* reserve 0 and 1 */
```
The [GfxBase](autodocs-2.0/includes-graphics-gfxbase-h.md) structure may be examined to find which sprites are already in
use.  This may, at your option, impact what sprites you reserve.  If
Intuition is running, sprite 0 will already be in use as its pointer.

The reserved sprite status is accessible as


```c
    currentreserved = GfxBase->SpriteReserved;
```
The [next section](libraries/28-vsprite-advanced-topics-how-vsprites-are-assigned.md) presents a few trouble-shooting techniques for VSprite
assignment.

