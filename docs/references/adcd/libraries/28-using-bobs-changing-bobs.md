---
title: 28 / Using Bobs / Changing Bobs
manual: libraries
chapter: libraries
section: 28-using-bobs-changing-bobs
functions: [DrawGList, InitMasks, SortGList]
libraries: [graphics.library]
---

# 28 / Using Bobs / Changing Bobs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following characteristics of Bobs can be changed dynamically between
calls to [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md):

  * To change the location of the Bob in the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) drawing area,

```c
    adjust the X and Y values in the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure associated with
    this Bob.
```
  * To change a Bob's appearance, the pointer to the [ImageData](libraries/28-using-bobs-specifying-the-shape-of-a-bob.md) in the

```c
    associated [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure may be changed.  Note that a change in
    the ImageData also requires a change or recalculation of the
    [ImageShadow](libraries/28-other-items-influencing-bob-colors-imageshadow.md), using [InitMasks()](libraries/28-graphics-sprites-bobs-and-animation-function-reference.md).
```
  * To change a Bob's colors modify the [PlanePick](libraries/28-other-items-influencing-bob-colors-planepick.md), [PlaneOnOff](libraries/28-other-items-influencing-bob-colors-planeonoff.md) or [Depth](libraries/28-using-bobs-specifying-the-colors-of-a-bob.md)

```c
    parameters in the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure associated with this Bob.
```
  * To change a Bob's display priorities, alter the [Before](libraries/28-bob-priorities-specifying-the-drawing-order.md) and [After](libraries/28-bob-priorities-specifying-the-drawing-order.md)

```c
    pointers in the [Bob](libraries/28-using-bobs-the-bob-structure.md) structure.
```
  * To change the Bob into a paintbrush, specify the [SAVEBOB](libraries/28-using-bobs-using-bob-flags.md) flag in the

```c
    [Bob.Flags](libraries/28-using-bobs-using-bob-flags.md) field.

    Changes Are Not Immediately Seen.
    ---------------------------------
    Neither these nor other changes are evident until [SortGList()](libraries/28-using-virtual-sprites-getting-the-vsprite-list-in-order.md) and
    then [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md) are called.
```

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [InitMasks — graphics.library](../autodocs/graphics.library.md#initmasks)
- [SortGList — graphics.library](../autodocs/graphics.library.md#sortglist)
