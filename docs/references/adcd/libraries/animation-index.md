---
title: Animation Index
manual: libraries
chapter: libraries
section: animation-index
functions: [AddBob, Animate, DoCollision, DrawGList, InitMasks, RemBob, RemIBob, SetCollision, SortGList]
libraries: [graphics.library]
---

# Animation Index

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Animation
  AddBob(), [641](libraries/28-using-bobs-adding-a-bob.md)
  Animate(), [660](libraries/28-animation-with-gels-moving-the-objects.md)
  AnimComp
```c
    animation concepts, [652](libraries/28-animation-with-gels-your-own-animation-routine-calls.md)
    AnimComp flags, [659](libraries/28-using-sequenced-drawing-and-motion-control.md)
    custom animation routine, [660](libraries/28-animation-with-gels-your-own-animation-routine-calls.md)
    ring motion control, [654](libraries/28-animation-types-ring-motion-control.md)
    sequenced drawing, [654](libraries/28-animation-types-sequenced-drawing.md)
    sequencing components, [656](libraries/28-specifying-animation-components-component-ordering.md)
    sequencing within components, [655](libraries/28-specifying-animation-components-sequencing-animcomps.md)
    setting animation timing, [655](libraries/28-animation-components-specifying-time-for-each-image.md)
    setting component position, [655](libraries/28-specifying-animation-components-position-of-an-animcomp.md)
    setting up ring motion control, [659](libraries/28-specifying-animation-object-setting-up-ring-motion.md)
    setting up simple motion control, [658](libraries/28-specifying-animation-object-setting-up-simple-motion.md)
    simple motion control, [654](libraries/28-animation-types-simple-motion-control.md)
    specifying components, [655](libraries/28-animation-with-gels-specifying-animation-components.md)
```
  AnimOb, [656](libraries/28-animation-with-gels-specifying-the-animation-object.md)
```c
    adding an AnimOb, [659](libraries/28-animation-with-gels-adding-animation-objects.md)
    custom animation routine, [660](libraries/28-animation-with-gels-your-own-animation-routine-calls.md)
    moving the objects, [660](libraries/28-animation-with-gels-moving-the-objects.md)
    setting AnimOb position, [658](libraries/28-specifying-the-animation-object-position-of-an-animob.md)
    special numbering system, [661](libraries/28-animation-with-gels-animations-special-numbering-system.md)
    the AnimKey, [659](libraries/28-animation-with-gels-the-animkey.md)
    typical function call sequence, [660](libraries/28-animation-with-gels-moving-the-objects.md)
```
  Bob
```c
    attaching a Bob to a VSprite, [635](libraries/28-the-bob-structure-linking-bob-and-vsprite-structures.md)
    behavior for unselected bitplanes, [639](libraries/28-other-items-influencing-bob-colors-planeonoff.md)
    Bob flags, [636](libraries/28-using-bobs-using-bob-flags.md)
    changing a Bob, [642](libraries/28-using-bobs-changing-bobs.md)
    double-buffering, [645](libraries/28-using-bobs-double-buffering.md)
    ImageShadow, [635](libraries/28-using-bobs-vsprite-flags-and-bobs.md)
    setting bitplanes, [639](libraries/28-other-items-influencing-bob-colors-planepick.md)
    setting collision detection, [639](libraries/28-other-items-influencing-bob-colors-planeonoff.md)
    setting color, [638](libraries/28-using-bobs-specifying-the-colors-of-a-bob.md)
    setting depth, [638](libraries/28-using-bobs-specifying-the-colors-of-a-bob.md)
    setting image, [637](libraries/28-using-bobs-specifying-the-shape-of-a-bob.md)
    setting rendering priority, [640](libraries/28-using-bobs-bob-priorities.md)
    setting rendering restrictions, [640](libraries/28-bob-priorities-specifying-the-drawing-order.md)
    setting shadow mask, [638](libraries/28-other-items-influencing-bob-colors-imageshadow.md)
    setting shape, [637](libraries/28-using-bobs-specifying-the-shape-of-a-bob.md)
    setting size, [637](libraries/28-using-bobs-specifying-the-size-of-a-bob.md)
    struct VSprite differences for Bobs, [634](libraries/28-using-bobs-the-vsprite-structure-and-bobs.md)
    system selected rendering priorities, [640](libraries/28-bob-priorities-letting-the-system-decide-priorities.md)
    using Bobs, [634](libraries/28-graphics-sprites-bobs-and-animation-using-bobs.md)
    VSprite flags for Bobs, [634](libraries/28-using-bobs-vsprite-flags-and-bobs.md)
```
  collision detection, [646](libraries/28-collisions-and-gel-structure-extensions-detecting-gel.md)
```c
    adding user-defined data to GELs, [651](libraries/28-adding-user-extensions-to-gel-data-structures.md)
    AUserStuff, [651](libraries/28-adding-user-extensions-to-gel-data-structures.md)
    BorderLine for faster detection, [648](libraries/28-detecting-gel-collisions-vsprite-borderline.md)
    boundary collision flags, [650](libraries/28-parameters-to-your-boundary-collision-routine.md)
    building the collision handler table, [646](libraries/28-detecting-collisions-building-a-table-of-collision.md)
    BUserStuff, [651](libraries/28-adding-user-extensions-to-gel-data-structures.md)
    initializing collision detection, [646](libraries/28-detecting-gel-collisions-preparing-for-collision.md)
    parameters to user-defined routines, [650](libraries/28-parameters-to-your-boundary-collision-routine.md), [650](libraries/28-parameters-to-your-inter-gel-collision-routines.md)
    processing of multiple collisions, [650](libraries/28-set-up-for-boundary-collisions-handling-multiple.md)
    selective collision detection, [649](libraries/28-detecting-gel-collisions-using-hitmask-and-memask.md)
    sensitive areas, [647](libraries/28-detecting-gel-collisions-vsprite-collision-mask.md)
    setting the collision mask, [647](libraries/28-detecting-gel-collisions-vsprite-collision-mask.md)
    specifying collision boundaries, [650](libraries/28-setting-up-for-boundary-collisions.md)
    UserExt, [651](libraries/28-adding-user-extensions-to-gel-data-structures.md)
    VUserStuff, [651](libraries/28-adding-user-extensions-to-gel-data-structures.md)
```
  DoCollision(), [646](libraries/28-collisions-and-gel-structure-extensions-detecting-gel.md)
  DrawGList(), [642](libraries/28-using-bobs-sorting-and-displaying-bobs.md)
  Examples - complete bobs example, [642](libraries/lib-examples-bob-c.md)
  InitMasks(), [648](libraries/28-detecting-gel-collisions-vsprite-borderline.md)
  introduction, [613](libraries/28-graphics-sprites-bobs-and-animation.md)
  RemBob(), [641](libraries/28-using-bobs-removing-a-bob.md)
  RemIBob(), [641](libraries/28-using-bobs-removing-a-bob.md)
  SetCollision(), [647](libraries/28-detecting-collisions-building-a-table-of-collision.md)
  SortGList(), [642](libraries/28-using-bobs-sorting-and-displaying-bobs.md)
  struct Bob, [635](libraries/28-using-bobs-the-bob-structure.md)
  struct CollTable, [646](libraries/28-detecting-collisions-building-a-table-of-collision.md)
  struct DBufPacket, [645](libraries/28-double-buffering-dbufpacket-and-double-buffering.md)

---

## See Also

- [AddBob — graphics.library](../autodocs/graphics.library.md#addbob)
- [Animate — graphics.library](../autodocs/graphics.library.md#animate)
- [DoCollision — graphics.library](../autodocs/graphics.library.md#docollision)
- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [InitMasks — graphics.library](../autodocs/graphics.library.md#initmasks)
- [RemBob — graphics.library](../autodocs/graphics.library.md#rembob)
- [RemIBob — graphics.library](../autodocs/graphics.library.md#remibob)
- [SetCollision — graphics.library](../autodocs/graphics.library.md#setcollision)
- [SortGList — graphics.library](../autodocs/graphics.library.md#sortglist)
