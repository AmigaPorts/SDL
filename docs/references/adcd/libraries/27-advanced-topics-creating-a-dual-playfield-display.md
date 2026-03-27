---
title: 27 / Advanced Topics / Creating a Dual-Playfield Display
manual: libraries
chapter: libraries
section: 27-advanced-topics-creating-a-dual-playfield-display
functions: [LoadView, MakeVPort, MrgCop]
libraries: [graphics.library]
---

# 27 / Advanced Topics / Creating a Dual-Playfield Display

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In dual-playfield mode, you have two separately controllable playfields.
You specify dual-playfield mode in 1.3 by setting the [DUALPF](libraries/27-display-routines-and-structures-viewport-display-modes.md) bit in the
[ViewPort.Modes](libraries/27-display-routines-and-structures-viewport-display-modes.md) field.  In Release 2, you specify dual-playfield by using
any ModeID that includes DPF in its name as listed in <graphics/[displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md)>.

In dual-playfield mode, you always define two [RasInfo](libraries/27-display-routines-and-structures-viewport-display-memory.md) data structures.
Each of these structures defines one of the playfields. There are five
different ways you can configure a dual-playfield display, because there
are five different distributions of the bitplanes which the system
hardware allows.




        Table 27-6: Bitplane Assignment in Dual-playfield Mode


               Number of    Playfield 1    Playfield 2
               Bitplanes       Depth          Depth
               ---------       -----          -----
                   2             1              1
                   3             2              1
                   4             2              2
                   5             3              2
                   6             3              3
Under 1.3 if [PFBA](libraries/27-display-routines-and-structures-viewport-display-modes.md) is set in the [ViewPort.Modes](libraries/27-display-routines-and-structures-viewport-display-modes.md) field, or, under Release 2,
if the ModeID includes DPF2 in its name, then the playfield priorities are
swapped and playfield 2 will be displayed in front of playfield 1.  In
this way, you can get more bitplanes in the background playfield than you
have in the foreground playfield. The playfield priority affects only one
[ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) at a time.  If you have multiple ViewPorts with dual-playfields,
the playfield priority is set for each one individually.

Here's a summary of the steps you need to take to create a dual-playfield
display:

  * Allocate one [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure and one [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure.

  * Allocate two [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) structures.  Allocate two [RasInfo](libraries/27-display-routines-and-structures-viewport-display-memory.md) structures

```c
    (linked together), each pointing to a separate BitMap. The two
    RasInfo structures are linked together as follows:

        struct RasInfo playfield1, playfield2;

        playfield1.Next = &playfield2;
        playfield2.Next = NULL;
```
  * Initialize each [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure to describe one playfield, using one

    of the permissible bitplane distributions shown in the above table
    and allocate memory for the bitplanes themselves.  Note that BitMap 1
    and BitMap 2 need not be the same width and height.
  * Initialize the [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure.  In 1.3, specify dual-playfield

```c
    mode by setting the [DUALPF](libraries/27-display-routines-and-structures-viewport-display-modes.md) bit (and [PFBA](libraries/27-display-routines-and-structures-viewport-display-modes.md), if appropriate) in the
    [ViewPort.Modes](libraries/27-display-routines-and-structures-viewport-display-modes.md) field.  Under Release 2, specify dual-playfield mode
    by selecting a ModeID that includes DPF (or DPF2) in its name as
    listed in <graphics/[displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md)>.  Set the [ViewPort.RasInfo](autodocs-2.0/includes-graphics-view-h.md) field
    to the address of the playfield 1 [RasInfo](libraries/27-display-routines-and-structures-viewport-display-memory.md).
```
  * Set up the [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) information

  * Call [MakeVPort()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md), [MrgCop()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md) and [LoadView()](libraries/27-display-routines-and-structures-loading-and-displaying.md) to display the newly

```c
    created [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).
```
For display purposes, each of the two [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md)s is assigned to a separate
[ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).  To draw separately into the BitMaps, you must also assign these
BitMaps to two separate [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)s.  The section called
"[Initializing a RastPort Structure](libraries/27-the-rastport-structure-initializing-a-rastport-structure.md)" shows you how to use a RastPort data
structure to control your drawing routines.

---

## See Also

- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
