---
title: 28 / Using Bobs / Using Bob Flags
manual: libraries
chapter: libraries
section: 28-using-bobs-using-bob-flags
functions: [DrawGList, RemBob]
libraries: [graphics.library]
---

# 28 / Using Bobs / Using Bob Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following paragraphs describe how to set the [Flags](libraries/28-using-bobs-the-bob-structure.md) field in the [Bob](libraries/28-using-bobs-the-bob-structure.md)
structure (note that these flags do not apply to the Flags field of the
[VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure).

[SAVEBOB](autodocs-2.0/includes-graphics-gels-h.md)

```c
    To tell the system not to erase the old image of the Bob when the Bob
    is moved, specify the SAVEBOB flag in the [Bob](libraries/28-using-bobs-the-bob-structure.md) structure [Flags](libraries/28-using-bobs-the-bob-structure.md) field.
    This makes the Bob behave like a paintbrush.  It has the opposite
    effect of [SAVEBACK](libraries/28-using-bobs-vsprite-flags-and-bobs.md).

    It's Faster To Draw A New Bob.
    ------------------------------
    It takes longer to preserve and restore the raster image than simply
    to draw a new Bob image wherever required.
```
[BOBISCOMP](autodocs-2.0/includes-graphics-gels-h.md)

```c
    If this Bob is part of an [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md), set the BOBISCOMP flag in the [Bob](libraries/28-using-bobs-the-bob-structure.md)
    structure to 1.  If the flag is a 1, the pointer named [BobComp](libraries/28-using-bobs-the-bob-structure.md) must
    have been initialized.  Otherwise, the system ignores the pointer,
    and it may be left alone (though it's good practice to initialize it
    to NULL).  See "[Animation Data Structures](libraries/28-animation-with-gels-animation-data-structures.md)" for a discussion
    of AnimComps.
```
[BWAITING](autodocs-2.0/includes-graphics-gels-h.md)

```c
    This flag is used solely by the system, and should be left alone.
    When a Bob is waiting to be drawn, the system sets the BWAITING flag
    in the [Bob](libraries/28-using-bobs-the-bob-structure.md) structure to 1.  This occurs only if the system has found
    a [Before](libraries/28-bob-priorities-specifying-the-drawing-order.md) pointer in this Bob's structure that points to another Bob.
    Thus, the system flag BWAITING provides current draw-status to the
    system.  Currently, the system clears this flag on return from each
    call to [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md).
```
[BDRAWN](autodocs-2.0/includes-graphics-gels-h.md)

```c
    This is a system status flag that indicates to the system whether or
    not this Bob has already been drawn.  Therefore, in the process of
    examining the various [Before](libraries/28-bob-priorities-specifying-the-drawing-order.md) and [After](libraries/28-bob-priorities-specifying-the-drawing-order.md) flags, the drawing routines
    can determine the drawing sequence.  The system clears this flag on
    return from each call to [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md).
```
[BOBSAWAY](autodocs-2.0/includes-graphics-gels-h.md)

```c
    To initiate the removal of a Bob during the next call to [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md),
    set BOBSAWAY to 1.  Either the application or the system may set this
    [Bob](libraries/28-using-bobs-the-bob-structure.md) structure system flag.  The system restores the background where
    it has last drawn the Bob.  The system will unlink the Bob from the
    system GEL list the next time DrawGList() is called, unless the
    application is using double-buffering.  In that case, the Bob will
    not be unlinked and completely removed until two calls to DrawGList()
    have occurred and the Bob has been removed from both buffers.  The
    [RemBob()](libraries/28-using-bobs-removing-a-bob.md) macro sets the BOBSAWAY flag.
```
[BOBNIX](autodocs-2.0/includes-graphics-gels-h.md)

```c
    When a Bob has been completely removed, the system sets the BOBNIX
    flag to 1 on return from [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md).  In other words, when the
    background area has been fully restored and the Bob has been removed
    from the GEL list, this flag in is set to a 1.  BOBNIX is especially
    significant when double-buffering because when an application asks
    for a Bob to be removed, the system must remove it from both the
    drawing buffer and from the display buffer.  Once BOBNIX has been
    set, it means the Bob has been removed from both buffers and the
    application is free to reuse or deallocate the Bob.
```
[SAVEPRESERVE](autodocs-2.0/includes-graphics-gels-h.md)

```c
    The SAVEPRESERVE flag is a double-buffer version of the [SAVEBACK](libraries/28-using-bobs-vsprite-flags-and-bobs.md)
    flag.  If using double-buffering and wishing to save and restore the
    background, set SAVEBACK to 1.  SAVEPRESERVE is used by the system to
    indicate whether the Bob in the "other" buffer has been restored; it
    is for system use only.
```

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [RemBob — graphics.library](../autodocs/graphics.library.md#rembob)
