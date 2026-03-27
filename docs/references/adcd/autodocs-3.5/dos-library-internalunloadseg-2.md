---
title: dos.library/InternalUnLoadSeg
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-internalunloadseg-2
functions: [Close, LoadSeg, UnLoadSeg]
libraries: [dos.library]
---

# dos.library/InternalUnLoadSeg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InternalUnLoadSeg -- Unloads a seglist loaded with [InternalLoadSeg()](autodocs-3.5/dos-library-internalloadseg-2.md) (V36)

   SYNOPSIS
	success = InternalUnLoadSeg(seglist,FreeFunc)
	  D0			      D1       A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) InternalUnLoadSeg(BPTR,void (*)(STRPTR,ULONG))

   FUNCTION
	Unloads a seglist using freefunc to free segments.  Freefunc is called
	as for [InternalLoadSeg](autodocs-3.5/dos-library-internalloadseg-2.md).  NOTE: will call [Close()](autodocs-3.5/dos-library-close-2.md) for overlaid
	seglists.

   INPUTS
	seglist  - Seglist to be unloaded
	FreeFunc - Function called to free memory

   RESULT
	success - returns whether everything went OK (since this may close
		  files).  Also returns FALSE if seglist was NULL.

   BUGS
	Really should use tags

   SEE ALSO
	[LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md), [UnLoadSeg()](autodocs-3.5/dos-library-unloadseg-2.md), [InternalLoadSeg()](autodocs-3.5/dos-library-internalloadseg-2.md), NewUnLoadSeg(), [Close()](autodocs-3.5/dos-library-close-2.md)

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [UnLoadSeg — dos.library](../autodocs/dos.library.md#unloadseg)
