---
title: 6 / Blitter Done Flag / Multitasking and the Blitter
manual: hardware
chapter: hardware
section: 6-blitter-done-flag-multitasking-and-the-blitter
functions: [DisownBlitter, OwnBlitter, WaitBlit]
libraries: [graphics.library]
---

# 6 / Blitter Done Flag / Multitasking and the Blitter

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When a blit is in progress, none of the blitter registers should be
written.  For details on arbitration of blitter access in the system,
please refer to the ROM Kernel Manual.  In particular, read the discussion
about the OwnBlitter() and DisownBlitter() functions.  Even after the
blitter has been "owned", a blit may still be finishing up, so the blitter
 [done flag](hardware/6-blitter-hardware-blitter-done-flag.md)  should be checked before using it even the first time.  Use of
the ROM kernel function WaitBlit() is recommended.

You should also check the blitter  [done flag](hardware/6-blitter-hardware-blitter-done-flag.md)  before using results of a
blit.  The blit may not be finished, so the data may not be ready yet.
This can lead to difficult to find bugs, because a 68000 may be slow
enough for a blit to finish without checking the  [done flag](hardware/6-blitter-hardware-blitter-done-flag.md) , while a
68020, perhaps running out of its cache, may be able to get at the data
before the blitter has finished writing it.

Let us say that we have a subroutine that displays a text box on top of
other imagery temporarily.  This subroutine might allocate a chunk of
memory to hold the original screen image while we are displaying our text
box, then draw the text box.  On exit, the subroutine might blit the
original imagery back and then free the allocated memory.  If the memory
is freed before the blitter  [done flag](hardware/6-blitter-hardware-blitter-done-flag.md)  is checked, some other process
might allocate that memory and store new data into it before the blit is
finished, trashing the blitter source and, thus, the screen imagery being
restored.

---

## See Also

- [DisownBlitter — graphics.library](../autodocs/graphics.library.md#disownblitter)
- [OwnBlitter — graphics.library](../autodocs/graphics.library.md#ownblitter)
- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
