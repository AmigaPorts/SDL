---
title: 27 / Advanced Topics / Creating a Double-Buffered Display
manual: libraries
chapter: libraries
section: 27-advanced-topics-creating-a-double-buffered-display
functions: [FreeCprList, LoadView, MakeVPort, MrgCop, WaitTOF]
libraries: [graphics.library]
---

# 27 / Advanced Topics / Creating a Double-Buffered Display

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To produce smooth animation or similar effects, it is occasionally
necessary to double-buffer your display.  To prevent the user from seeing
your graphics rendering while it is in progress, you will want to draw
into one memory area while actually displaying a different area.

There are two methods of creating and displaying a double-buffered
display.  The simplest method is to create two complete Views and switch
back and forth between them with [LoadView()](libraries/27-display-routines-and-structures-loading-and-displaying.md) and [WaitTOF()](libraries/28-displaying-the-vsprites-synchronizing-with-the-display.md).

The second method consists of creating two separate display areas and two
sets of pointers to those areas for a single [View](libraries/27-display-routines-and-structures-viewport-display-memory.md).  This is more
complicated but takes less memory.

  * Allocate one [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure and one [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure.

  * Allocate two [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) structures and one [RasInfo](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure. Initialize

```c
    each BitMap structure to describe one drawing area and allocate
    memory for the bitplanes themselves. Initialize the RasInfo
    structure, setting the [RasInfo.BitMap](autodocs-2.0/includes-graphics-view-h.md) field to the address of one of
    the two BitMaps you created.
```
  * Call [MakeVPort()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md), [MrgCop()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md) and [LoadView()](libraries/27-display-routines-and-structures-loading-and-displaying.md). When you call MrgCop(),

```c
    the system uses the information you have provided to create a Copper
    instruction list for the Copper to execute.  The system allocates
    memory for a long-frame (LOF) Copper list and, if this is an
    interlaced display, a short-frame (SHF) Copper list as well.  The
    system places a pointer to the long-frame Copper list in
    [View.LOFCprList](autodocs-2.0/includes-graphics-view-h.md) and a pointer to a short-frame Copper list (if this
    is an interlaced display) in [View.SHFCprList](autodocs-2.0/includes-graphics-view-h.md).  The Copper instruction
    stream referenced by these pointers applies to the first [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md).
```
  * Save the values in [View.LOFCprList](autodocs-2.0/includes-graphics-view-h.md) and [View.SHFCprlist](autodocs-2.0/includes-graphics-view-h.md) and reset

```c
    these fields to zero.  Place a pointer to the second [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure
    in the [RasInfo.BitMap](autodocs-2.0/includes-graphics-view-h.md) field.  Next call [MakeVPort()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md) and [MrgCop()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md).
```
  * When you perform [MrgCop()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md) with the Copper instruction list fields of

```c
    the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) set to zero, the system automatically allocates and fills in
    a new list of instructions for the Copper.  Now you have created two
    sets of instruction streams for the Copper, one that works with data
    in the first [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) and the other that works with data in the second
    BitMap.
```
  * You can save pointers to the second list of Copper instructions as

```c
    well.  Then, to perform the double-buffering, alternate between the
    two Copper lists.  The code for the double-buffering loop would be as
    follows: call [WaitTOF()](libraries/28-displaying-the-vsprites-synchronizing-with-the-display.md), change the Copper instruction list pointers
    in the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md), call [LoadView()](libraries/27-display-routines-and-structures-loading-and-displaying.md) to show one of the [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md)s while drawing
    into the other BitMap, and repeat.
```
Remember that you will have to call [FreeCprList()](libraries/27-loading-and-displaying-the-view-exiting-gracefully.md) on both sets of Copper
lists when you have finished.

---

## See Also

- [FreeCprList — graphics.library](../autodocs/graphics.library.md#freecprlist)
- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
