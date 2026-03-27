---
title: 27 / / Loading and Displaying the View / Exiting Gracefully
manual: libraries
chapter: libraries
section: 27-loading-and-displaying-the-view-exiting-gracefully
functions: [AllocRaster, FreeColorMap, FreeCprList, FreeRaster, FreeVPortCopLists, GetColorMap, LoadView, MakeVPort, MrgCop, WaitBOVP, WaitTOF]
libraries: [graphics.library]
---

# 27 / / Loading and Displaying the View / Exiting Gracefully

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The preceding sample program provides a way of exiting gracefully with the
cleanup() subroutine.  This function returns to the memory manager all
dynamically-allocated memory chunks.  Notice the calls to [FreeRaster()](autodocs-2.0/graphics-library-freeraster.md) and
[FreeColorMap()](autodocs-2.0/graphics-library-freecolormap.md). These calls correspond directly to the allocation calls
[AllocRaster()](libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md) and [GetColorMap()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md) located in the body of the program. Now
look at the calls within cleanup() to [FreeVPortCopLists()](autodocs-2.0/graphics-library-freevportcoplists.md) and
[FreeCprList()](autodocs-2.0/graphics-library-freecprlist.md). When you call [MakeVPort()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md), the graphics system dynamically
allocates some space to hold intermediate instructions from which a final
Copper instruction list is created. When you call [MrgCop()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md), these
intermediate Copper lists are merged together into the final Copper list,
which is then given to the hardware for interpretation. It is this list
that provides the stable display on the screen, split into separate
[ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)s with their own colors and resolutions and so on.

When your program completes, you must see that it returns all of the
memory resources that it used so that those memory areas are again
available to the system for reassignment to other tasks.  Therefore, if
you use the routines [MakeVPort()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md) or [MrgCop()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md), you must also arrange to use
[FreeCprList()](autodocs-2.0/graphics-library-freecprlist.md) (pointing to each of those lists in the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure) and
[FreeVPortCopLists()](autodocs-2.0/graphics-library-freevportcoplists.md) (pointing to the [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) that is about to be
deallocated).  If your View is interlaced, you will also have to call
FreeCprList(&view.SHFCprList) because an interlaced view has a separate
Copper list for each of the two fields displayed. Do not confuse
FreeVPortCopLists() with FreeCprList(). The former works on intermediate
Copper lists for a specific ViewPort, the latter directly on a hardware
Copper list from the View.

As a final caveat, notice that when you do free everything, the memory
manager or other programs may immediately change the contents of the freed
memory.  Therefore, if the Copper is still executing an instruction stream
(as a result of a previous [LoadView()](libraries/27-display-routines-and-structures-loading-and-displaying.md)) when you free that memory, the
display will malfunction. Once another [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) has been installed via
LoadView(), do a [WaitTOF()](libraries/28-displaying-the-vsprites-synchronizing-with-the-display.md) for the new View to begin displaying, and then
you can begin freeing up your resources.  WaitTOF() waits for the vertical
blanking period to begin and all vertical blank interrupts to complete
before returning to the caller. The routine [WaitBOVP()](autodocs-2.0/graphics-library-waitbovp.md) (for
"WaitBottomOfViewPort") busy waits until the vertical beam reaches the
bottom of the specified [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) before returning to the caller.  This
means no other tasks run until this function returns.

---

## See Also

- [AllocRaster — graphics.library](../autodocs/graphics.library.md#allocraster)
- [FreeColorMap — graphics.library](../autodocs/graphics.library.md#freecolormap)
- [FreeCprList — graphics.library](../autodocs/graphics.library.md#freecprlist)
- [FreeRaster — graphics.library](../autodocs/graphics.library.md#freeraster)
- [FreeVPortCopLists — graphics.library](../autodocs/graphics.library.md#freevportcoplists)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [WaitBOVP — graphics.library](../autodocs/graphics.library.md#waitbovp)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
