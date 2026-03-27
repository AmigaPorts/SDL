---
title: graphics.library/LoadView
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-loadview-2
functions: [InitVPort, MakeVPort, MrgCop, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# graphics.library/LoadView

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       LoadView -- Use a (possibly freshly created) coprocessor instruction
                   list to create the current display.
```
   SYNOPSIS

```c
       LoadView( [View](autodocs-3.5/include-graphics-view-h.md) )
                  A1
```
	void LoadView( struct [View](autodocs-3.5/include-graphics-view-h.md) * );

   FUNCTION
	Install a new view to be displayed during the next display
	refresh pass.

```c
       Coprocessor instruction list has been created by
       [InitVPort()](autodocs-3.5/graphics-library-initvport-2.md), [MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md), and [MrgCop()](autodocs-3.5/graphics-library-mrgcop-2.md).
```
   INPUTS

```c
       [View](autodocs-3.5/include-graphics-view-h.md) - a pointer to the [View](autodocs-3.5/include-graphics-view-h.md) structure which contains the
       pointer to the constructed coprocessor instructions list, or NULL.
```
   RESULT
	If the [View](autodocs-3.5/include-graphics-view-h.md) pointer is non-NULL, the new [View](autodocs-3.5/include-graphics-view-h.md) is displayed,
	according to your instructions.  The vertical blank routine
	will pick this pointer up and direct the copper to start
	displaying this [View](autodocs-3.5/include-graphics-view-h.md).

	If the [View](autodocs-3.5/include-graphics-view-h.md) pointer is NULL, no [View](autodocs-3.5/include-graphics-view-h.md) is displayed.

   NOTE
	Even though a LoadView(NULL) is performed, display DMA will still be
	active.  Sprites will continue to be displayed after a LoadView(NULL)
	unless an OFF_SPRITE is subsequently performed.

   BUGS

   SEE ALSO
```c
       [InitVPort()](autodocs-3.5/graphics-library-initvport-2.md) [MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md) [MrgCop()](autodocs-3.5/graphics-library-mrgcop-2.md) [intuition/RethinkDisplay()](autodocs-3.5/intuition-library-rethinkdisplay-2.md)
```
	[graphics/view.h](autodocs-3.5/include-graphics-view-h.md)

---

## See Also

- [InitVPort — graphics.library](../autodocs/graphics.library.md#initvport)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
