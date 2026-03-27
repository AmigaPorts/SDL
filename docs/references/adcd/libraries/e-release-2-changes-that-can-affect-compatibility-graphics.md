---
title: E / Release 2 Changes That Can Affect Compatibility / Graphics
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-graphics
functions: [Flood, GetColorMap, LoadRGB4, MrgCop, Text, WaitBlit]
libraries: [graphics.library]
---

# E / Release 2 Changes That Can Affect Compatibility / Graphics

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * Do not rely on the order of Copper list instructions.  The Release 2

```c
    [MrgCop()](libraries/28-displaying-the-vsprites-merging-vsprite-instructions.md) function builds different Copper lists to that of 1.3, by
    including new registers in the list (e.g., MOVE xxxx,DIWHIGH).  This
    changes the positions of  the  other  instructions.  We  know  of one
    game that 'assumes' the BPLxPTRs  would be at a certain offset in the
    Copper list, and that is now broken on machines running 2.0 with the
    new Denise chip.
```
  * Graphics and layers functions which use the blitter generally return

```c
    after starting the final blit.  If you are mixing graphics rendering
    calls and processor access of the same memory, you must [WaitBlit()](libraries/27-performing-data-move-operations-when-to-wait-for-the.md)
    before touching (or deallocating) the source or destination memory
    with the processor.  For example, the [Text()](libraries/29-graphics-library-and-text-the-text-function.md) function is faster in
    Release 2, causing some programs to trash partial lines of text.
```
  * [ColorMap](libraries/3-screens-and-graphics-lib-limitations-of-the-graphics.md) structure is bigger.  Programs must use [GetColorMap()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md) to

    create one.
  * Blitter rtns decide ascend/descend on 1st plane only.

  * Changing the display mode of an existing screen or viewport while

    open is still not a supported operation.
  * [GfxBase DisplayFlags](autodocs-2.0/includes-graphics-gfxbase-h.md) and row/cols may not match Workbench screen.

  * Do not hardcode modulo values - use [BitMap->BytesPerRow](autodocs-2.0/includes-graphics-gfx-h.md).

  * If the graphics Autodocs say that you need a [TmpRas](libraries/27-the-rastport-structure-rastport-area-fill-information.md) of a certain size

```c
    for some functions, then you must make that the minimum size.  In
    some cases, before 2.0, you may have gotten away with using a smaller
    TmpRas with some functions (for example [Flood()](libraries/27-using-the-graphics-drawing-routines-flood-fill-operations.md)).  To be more robust,
    graphics now checks the TmpRas size and will fail the function call
    if the TmpRas is too small.
```
  * ECS chips under 2.0 generate displays differently. The display window

    registers now control DMA.
  * [LoadRGB4()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md) used to poke colors into the active copperlist with no

```c
    protection against deallocation of that copperlist while it was being
    poked.  Under 2.0, semaphore protection of the copperlist was added
    to LoadRGB4() which makes it totally incorrect and extremely
    dangerous to call LoadRGB4() during an interrupt.  The general
    symptom of this problem is that a system deadlock can be caused by
    dragging one screen up and down while another is cycling.  Color
    cycling should be performed from within a task, not an interrupt.  In
    general, the only functions which may be safely called from within an
    interrupt are the small list of Exec functions documented in the
    "[Exec Interrupts](libraries/26-exec-interrupts-function-reference.md)" chapter.
```

---

## See Also

- [Flood — graphics.library](../autodocs/graphics.library.md#flood)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
