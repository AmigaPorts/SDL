---
title: dos.library/UnLoadSeg
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-unloadseg-2
functions: [LoadSeg]
libraries: [dos.library]
---

# dos.library/UnLoadSeg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	UnLoadSeg -- Unload a seglist previously loaded by [LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md)

    SYNOPSIS
	success = UnLoadSeg( seglist )
	D0		       D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) UnLoadSeg(BPTR)

    FUNCTION
	Unload a seglist loaded by [LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md).  'seglist' may be zero.
	Overlaid segments will have all needed cleanup done, including
	closing files.

    INPUTS
	seglist - BCPL pointer to a segment identifier

    RESULTS
	success - returns 0 if a NULL seglist was passed or if it failed
		  to close an overlay file.  NOTE: this function returned
		  a random value before V36!

    SEE ALSO
	[LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md), [InternalLoadSeg()](autodocs-3.5/dos-library-internalloadseg-2.md), [InternalUnLoadSeg()](autodocs-3.5/dos-library-internalunloadseg-2.md)

---

## See Also

- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
