---
title: graphics.library/WaitBlit
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-waitblit-2
functions: [DisownBlitter, OwnBlitter, WaitBlit]
libraries: [graphics.library]
---

# graphics.library/WaitBlit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       WaitBlit -- [Wait](autodocs-3.5/exec-library-wait-2.md) for the blitter to be finished before proceeding
                   with anything else.
```
   SYNOPSIS

```c
       WaitBlit()
```
	void WaitBlit( void );

   FUNCTION
	WaitBlit returns when the blitter is idle. This function should
	normally only be used when dealing with the blitter in a
	synchronous manner, such as when using [OwnBlitter](autodocs-3.5/graphics-library-ownblitter-2.md) and [DisownBlitter](autodocs-3.5/graphics-library-disownblitter-2.md).
	WaitBlit does not wait for all blits queued up using [QBlit](autodocs-3.5/graphics-library-qblit-2.md) or
	[QBSBlit](autodocs-3.5/graphics-library-qbsblit-2.md). You should call WaitBlit if you are just about to modify or
	free some memory that the blitter may be using.

   INPUTS

       none
   RESULT
       Your program waits until the blitter is finished.
	This routine does not use any the CPU registers.
	do/d1/a0/a1 are preserved by this routine.
	It may change the condition codes though.

   BUGS
	When examining bits with the CPU right after a blit, or when freeing
	temporary memory used by the blitter, a WaitBlit() may be required.

	Note that many graphics calls fire up the blitter, and let it run.
	The CPU does not need to wait for the blitter to finish before
	returning.

	Because of a bug in Agnus (prior to all revisions of fat Agnus)
 	this code may return too soon when the blitter has, in fact, not
	started the blit yet, even though BltSize has been written.

	This most often occurs in a heavily loaded system with extended memory,
	HIRES, and 4 bitplanes.

	WaitBlit currently tries to avoid this Agnus problem by testing
	the BUSY bit multiple times to make sure the blitter has started.
	If the blitter is BUSY at first check, this function busy waits.

	This initial hardware bug was fixed as of the first "Fat Agnus" chip,
	as used in all A500 and A2000 computers.

	Because of a different bug in Agnus (currently all revisions thru ECS)
 	this code may return too soon when the blitter has, in fact, not
	stopped the blit yet, even though blitter busy has been cleared.

	This most often occurs in a heavily loaded system with extended memory,
	in PRODUCTIVITY mode, and 2 bitplanes.

	WaitBlit currently tries to avoid this Agnus problem by testing
	the BUSY bit multiple times to make sure the blitter has really
	written its final word of destination data.

   SEE ALSO
	[OwnBlitter()](autodocs-3.5/graphics-library-ownblitter-2.md) [DisownBlitter()](autodocs-3.5/graphics-library-disownblitter-2.md) [hardware/blit.h](autodocs-3.5/include-hardware-blit-h.md)

---

## See Also

- [DisownBlitter — graphics.library](../autodocs/graphics.library.md#disownblitter)
- [OwnBlitter — graphics.library](../autodocs/graphics.library.md#ownblitter)
- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
