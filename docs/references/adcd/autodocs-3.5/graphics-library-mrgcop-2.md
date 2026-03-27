---
title: graphics.library/MrgCop
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-mrgcop-2
functions: [InitVPort, LoadView, MakeVPort, MrgCop, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# graphics.library/MrgCop

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       MrgCop -- Merge together coprocessor instructions.
   SYNOPSIS

```c
       error = MrgCop( [View](autodocs-3.5/include-graphics-view-h.md) )
       d0              A1
```
	ULONG MrgCop( struct [View](autodocs-3.5/include-graphics-view-h.md) * );

   FUNCTION

```c
       Merge together the display, color, sprite and user coprocessor
       instructions into a single coprocessor instruction stream.  This
       essentially creates a per-display-frame program for the coprocessor.
       This function MrgCop is used, for example, by the graphics animation
       routines which effectively add information into an essentially
       static background display.  This changes some of the user
       or sprite instructions, but not those which have formed the
       basic display in the first place.  When all forms of coprocessor
       instructions are merged together, you will have a complete per-
       frame instruction list for the coprocessor.

       Restrictions:  Each of the coprocessor instruction lists MUST be
       internally sorted in min to max Y-X order.  The merge routines
       depend on this! Each list must be terminated using CEND(copperlist).
```
   INPUTS

```c
       [View](autodocs-3.5/include-graphics-view-h.md) - a pointer to the view structure whose coprocessor
              instructions are to be merged.
```
   RESULT

```c
       The view structure will now contain a complete, sorted/merged
       list of instructions for the coprocessor, ready to be used by
       the display processor.  The display processor is told to use
       this new instruction stream through the instruction [LoadView()](autodocs-3.5/graphics-library-loadview-2.md).
```
	From V39, MrgCop() can return a ULONG error value (previous versions
	returned void), to indicate that either there was insufficient memory
	to build the system copper lists, or that MrgCop() had no work to do
	if, for example, there were no ViewPorts in the list.

	You should check for these error values - they are defined in
	[<graphics/view.h>](autodocs-3.5/include-graphics-view-h.md).

   BUGS

   SEE ALSO
```c
       [InitVPort()](autodocs-3.5/graphics-library-initvport-2.md) [MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md) [LoadView()](autodocs-3.5/graphics-library-loadview-2.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)
```
	[intuition.library/RethinkDisplay()](autodocs-3.5/intuition-library-rethinkdisplay-2.md)

---

## See Also

- [InitVPort — graphics.library](../autodocs/graphics.library.md#initvport)
- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
