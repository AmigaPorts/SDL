---
title: dos.library/InternalLoadSeg
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-internalloadseg-2
functions: [LoadSeg, UnLoadSeg]
libraries: [dos.library]
---

# dos.library/InternalLoadSeg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InternalLoadSeg -- Low-level load routine (V36)

   SYNOPSIS
	seglist = InternalLoadSeg(fh,table,functionarray,stack)
	D0			  D0  A0        A1	  A2

	[BPTR](autodocs-3.5/include-dos-dos-h.md) InternalLoadSeg(BPTR,[BPTR](autodocs-3.5/include-dos-dos-h.md),[LONG](autodocs-3.5/include-exec-types-h.md) *,[LONG](autodocs-3.5/include-exec-types-h.md) *)

   FUNCTION
	Loads from fh.  Table is used when loading an overlay, otherwise
	should be NULL.  Functionarray is a pointer to an array of functions.
	Note that the current [Seek](autodocs-3.5/dos-library-seek-2.md) position after loading may be at any point
	after the last hunk loaded.  The filehandle will not be closed.  If a
	stacksize is encoded in the file, the size will be stuffed in the
	[LONG](autodocs-3.5/include-exec-types-h.md) pointed to by stack.  This [LONG](autodocs-3.5/include-exec-types-h.md) should be initialized to your
	default value: InternalLoadSeg() will not change it if no stacksize
	is found. Clears unused portions of Code and Data hunks (as well as
	BSS hunks).  (This also applies to [LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md) and [NewLoadSeg()](autodocs-3.5/dos-library-newloadseg-2.md)).

	If the file being loaded is an overlaid file, this will return
	-(seglist).  All other results will be positive.

	NOTE to overlay users: InternalLoadSeg() does NOT return seglist in
	both D0 and D1, as [LoadSeg](autodocs-3.5/dos-library-loadseg-2.md) does.  The current ovs.asm uses [LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md),
	and assumes returns are in D1.  We will support this for [LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md)
	ONLY.

   INPUTS
	fh	      - Filehandle to load from.
	table	      - When loading an overlay, otherwise ignored.
	functionarray - Array of function to be used for read, alloc, and free.
	   FuncTable[0] ->  Actual = ReadFunc(readhandle,buffer,length),DOSBase
		            D0                D1         D2     D3      A6
	   FuncTable[1] ->  Memory = AllocFunc(size,flags), Execbase
		            D0                 D0   D1      a6
	   FuncTable[2] ->  FreeFunc(memory,size), Execbase
		                     A1     D0     A6
	stack         - Pointer to storage (ULONG) for stacksize.

   RESULT
	seglist	      - Seglist loaded or NULL.  NOT returned in D1!

   BUGS
	Really should use tags.

   SEE ALSO
	[LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md), [UnLoadSeg()](autodocs-3.5/dos-library-unloadseg-2.md), [NewLoadSeg()](autodocs-3.5/dos-library-newloadseg-2.md), [InternalUnLoadSeg()](autodocs-3.5/dos-library-internalunloadseg-2.md)

---

## See Also

- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [UnLoadSeg — dos.library](../autodocs/dos.library.md#unloadseg)
