---
title: 28 Graphics Sprites, Bobs and Animation / Function Reference
manual: libraries
chapter: libraries
section: 28-graphics-sprites-bobs-and-animation-function-reference
functions: [AddAnimOb, AddBob, AddVSprite, Animate, ChangeSprite, DoCollision, DrawGList, FreeGBuffers, FreeSprite, GetGBuffers, GetSprite, InitGMasks, InitGels, InitMasks, MoveSprite, RemBob, RemIBob, RemVSprite, SetCollision, SortGList]
libraries: [graphics.library]
---

# 28 Graphics Sprites, Bobs and Animation / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the Amiga's graphics animation
functions.  See the Amiga ROM Kernel Reference Manual: Includes and
Autodocs for details on each function call.


                 Table 28-1: Graphics Animation Functions
  ________________________________________________________________________
 |                                                                        |
 |     Animation                                                          |
 |     Function                   Description                             |
 |========================================================================|
 |     [AddAnimOb()](autodocs-2.0/graphics-library-addanimob.md)  Add an AnimOb to the linked list of AnimObs.          |
 |        [AddBob()](autodocs-2.0/graphics-library-addbob.md)  Add a Bob to the current gel list.                    |
 |    [AddVSprite()](autodocs-2.0/graphics-library-addvsprite.md)  Add a VSprite to the current gel list.                |
 |       [Animate()](autodocs-2.0/graphics-library-animate.md)  Process every AnimOb in the current animation list.   |
 |  [ChangeSprite()](autodocs-2.0/graphics-library-changesprite.md)  Change the sprite image pointer.                      |
 |   [DoCollision()](autodocs-2.0/graphics-library-docollision.md)  Test every gel in gel list for collisions.            |
 |     [DrawGList()](autodocs-2.0/graphics-library-drawglist.md)  Process the gel list, queueing VSprites, drawing Bobs.|
 |  [FreeGBuffers()](autodocs-2.0/graphics-library-freegbuffers.md)  Deallocate memory obtained by GetGBuffers().          |
 |    [FreeSprite()](autodocs-2.0/graphics-library-freesprite.md)  Return sprite for use by others and virtual sprite    |
 |                  machine.                                              |
 |   [GetGBuffers()](autodocs-2.0/graphics-library-getgbuffers.md)  Attempt to allocate all buffers of an entire AnimOb.  |
 |     [GetSprite()](autodocs-2.0/graphics-library-getsprite.md)  Attempt to get a sprite for the simple sprite manager.|
 |      [InitGels()](autodocs-2.0/graphics-library-initgels.md)  Initialize a gel list; must be called before using    |
 |                  gels.                                                 |
 |    [InitGMasks()](autodocs-2.0/graphics-library-initgmasks.md)  Initialize all of the masks of an AnimOb.             |
 |     [InitMasks()](autodocs-2.0/graphics-library-initmasks.md)  Initialize the [BorderLine](libraries/28-detecting-gel-collisions-vsprite-borderline.md) and [CollMask](libraries/28-detecting-gel-collisions-vsprite-collision-mask.md) masks of a     |
 |                  VSprite.                                              |
 |    [MoveSprite()](autodocs-2.0/graphics-library-movesprite.md)  Move sprite to a point relative to top of [ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).   |
 |        [RemBob()](autodocs-2.0/graphics-library-rembob.md)  Remove a Bob from the gel list.                       |
 |       [RemIBob()](autodocs-2.0/graphics-library-remibob.md)  Immediately remove a Bob from the gel list and the    |
 |                  [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).                                             |
 |    [RemVSprite()](autodocs-2.0/graphics-library-remvsprite.md)  Remove a VSprite from the current gel list.           |
 |  [SetCollision()](autodocs-2.0/graphics-library-setcollision.md)  Set a pointer to a user collision routine.            |
 |     [SortGList()](autodocs-2.0/graphics-library-sortglist.md)  Sort the current gel list, ordering its y,x           |
 |                  coordinates.                                          |
 |________________________________________________________________________|

---

## See Also

- [AddAnimOb — graphics.library](../autodocs/graphics.library.md#addanimob)
- [AddBob — graphics.library](../autodocs/graphics.library.md#addbob)
- [AddVSprite — graphics.library](../autodocs/graphics.library.md#addvsprite)
- [Animate — graphics.library](../autodocs/graphics.library.md#animate)
- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
- [DoCollision — graphics.library](../autodocs/graphics.library.md#docollision)
- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [FreeGBuffers — graphics.library](../autodocs/graphics.library.md#freegbuffers)
- [FreeSprite — graphics.library](../autodocs/graphics.library.md#freesprite)
- [GetGBuffers — graphics.library](../autodocs/graphics.library.md#getgbuffers)
- [GetSprite — graphics.library](../autodocs/graphics.library.md#getsprite)
- [InitGMasks — graphics.library](../autodocs/graphics.library.md#initgmasks)
- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
- [InitMasks — graphics.library](../autodocs/graphics.library.md#initmasks)
- [MoveSprite — graphics.library](../autodocs/graphics.library.md#movesprite)
- [RemBob — graphics.library](../autodocs/graphics.library.md#rembob)
- [RemIBob — graphics.library](../autodocs/graphics.library.md#remibob)
- [RemVSprite — graphics.library](../autodocs/graphics.library.md#remvsprite)
- [SetCollision — graphics.library](../autodocs/graphics.library.md#setcollision)
- [SortGList — graphics.library](../autodocs/graphics.library.md#sortglist)
