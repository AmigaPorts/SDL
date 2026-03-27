---
title: graphics.library/QBSBlit
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-qbsblit-2
functions: [OwnBlitter, QBSBlit, QBlit]
libraries: [graphics.library]
---

# graphics.library/QBSBlit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

	QBSBlit -- Synchronize the blitter request with the video beam.

   SYNOPSIS

	QBSBlit( bsp )
		 a1

	void QBSBlit( struct [bltnode](autodocs-3.5/include-hardware-blit-h.md) * );

   FUNCTION
	Call a user routine for use of the blitter, enqueued separately from

```c
       the [QBlit](autodocs-3.5/graphics-library-qblit-2.md) queue.  Calls the user routine contained in the blit
       structure when the video beam is located at a specified position
       onscreen.   Useful when you are trying to blit into a visible part
       of the screen and wish to perform the data move while the beam is
       not trying to display that same area.  (prevents showing part of
       an old display and part of a new display simultaneously).  Blitter
       requests on the QBSBlit queue take precedence over those on the
       regular blitter queue. The beam position is specified in the blitnode.
```
   INPUTS
	bsp - pointer to a blit structure.  See description in the

             Graphics Support section of the manual for more info.
   RESULT

       User routine is called when the QBSBlit queue reaches this
       request AND the video beam is in the specified position.
       If there are lots of blits going on and the video beam
       has wrapped around back to the top it will call all the
       remaining bltnodes as fast as it can to try and catch up.
   NOTES

```c
       [QBlit()](autodocs-3.5/graphics-library-qblit-2.md), and QBSBlit() have been rewritten for V39.  Queued
       blits are now handled in FIFO order.  Tasks trying to
       [OwnBlitter()](autodocs-3.5/graphics-library-ownblitter-2.md) are now given a fair share of the total
       blitter time available.  QBSBlit() is no longer queued
       separately from nodes added by [QBlit()](autodocs-3.5/graphics-library-qblit-2.md).  This fixes the
       ordering dependencies listed under BUGS in prior autodoc
       notes.
```
   BUGS

   SEE ALSO
	[QBlit()](autodocs-3.5/graphics-library-qblit-2.md) [hardware/blit.h](autodocs-3.5/include-hardware-blit-h.md)

---

## See Also

- [OwnBlitter — graphics.library](../autodocs/graphics.library.md#ownblitter)
- [QBSBlit — graphics.library](../autodocs/graphics.library.md#qbsblit)
- [QBlit — graphics.library](../autodocs/graphics.library.md#qblit)
