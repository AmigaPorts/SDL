---
title: Graphics
manual: amiga-mail
chapter: amiga-mail
section: graphics
functions: [Flood, GetColorMap, LoadRGB4, MrgCop, Text, WaitBlit]
libraries: [graphics.library]
---

# Graphics

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* Do not rely on the order of Copper list instructions.  For example,
  2.0's MrgCop() builds different Copper lists to that of 1.3, by
  including new registers in the list (e.g. MOVE xxxx,DIWHIGH).  This
  changes the positions of  the  other  instructions.   We  know  of one
  game that 'assumes' the BPLxPTRs  would be at a certain offset in the
  Copper list, and that is now broken on machines running 2.0 with the new
  Denise chip.

* Graphics and layers functions which use the blitter generally return
  after STARTING the final blit.  If you are mixing graphics rendering
  calls and processor access of the same memory, you must WaitBlit()
  before touching (or deallocating) the source or destination memory with
  the processor.  For example, the Text() function was sped up for 2.0,
  causing some programs to trash partial lines of text.

* ColorMap structure is bigger.  Programs must use GetColorMap() to
  create one.

* Blitter rtns decide ascend/descend on 1st plane only.

* Changing the display mode of an existing screen or viewport while it
  is open is still not a supported operation.

* GfxBase DisplayFlags and row/cols may not match Workbench screen.

* Do not hardcode modulo values - use BitMap->BytesPerRow.

* If the graphics Autodocs say that you need a TmpRas of a certain size
  for some functions, then you must make that the minimum size.  In some
  cases, before 2.0, you may have gotten away with using a smaller TmpRas
  with some functions (for example Flood() ).  To be more robust, Graphics
  now checks the TmpRas size and will fail the function call if the TmpRas
  is too small.

* ECS chips under 2.0 use a different method of generating displays.
  The display window registers now control DMA.

* LoadRGB4() used to poke colors into the active copperlist with no
  protection against deallocation of that copperlist while it was being
  poked. Under 2.0, semaphore protection of the copperlist was added to
  LoadRGB4(). This semaphore protection makes it totally incorrect and
  extremely dangerous to call LoadRGB4() during an interrupt.  The general
  symptom of this problem is that a system deadlock can be caused by
  dragging one screen up and down while another is cycling.  Color cycling
  should be performed from within a task, not an interrupt.  Note that in
  general, the only functions which may be safely called from within an
  interrupt are the small list of Exec functions documented in the ``Exec:
  Interrupts'' chapter of ROM Kernel Manual: Libraries and Devices.

---

## See Also

- [Flood — graphics.library](../autodocs/graphics.library.md#flood)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
