# 28 / VSprite Advanced Topics / Reserving Hardware Sprites


To prevent the VSprite system from using specific hardware sprites, set
the [sprRsrvd](../Includes_and_Autodocs_2._guide/node00AF.html#line39) member of the [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) structure. The pointer to the GelsInfo
structure is contained in the [RastPort](../Libraries_Manual_guide/node034A.html) structure. If all of the bits of
this 8-bit value are ones (0xFF), then all of the hardware sprites may be
used by the VSprite system. If any of the bits is a 0, the sprite
corresponding to that bit will not be utilized by VSprites.


```c
    Reserving Can Cause Problems.
    -----------------------------
    Reserving sprites increases the likelihood of the system not being
    able to display a VSprite ([VSOVERFLOW](../Libraries_Manual_guide/node0383.html#line12)). See the next section,
    "[How VSprites are Assigned](../Libraries_Manual_guide/node0393.html)," for further details on this topic.
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
The [GfxBase](../Includes_and_Autodocs_2._guide/node00AE.html#line24) structure may be examined to find which sprites are already in
use.  This may, at your option, impact what sprites you reserve.  If
Intuition is running, sprite 0 will already be in use as its pointer.

The reserved sprite status is accessible as


```c
    currentreserved = GfxBase->SpriteReserved;
```
The [next section](../Libraries_Manual_guide/node0393.html) presents a few trouble-shooting techniques for VSprite
assignment.

