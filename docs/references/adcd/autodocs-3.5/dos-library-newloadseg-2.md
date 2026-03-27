---
title: dos.library/NewLoadSeg
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-newloadseg-2
functions: [LoadSeg, UnLoadSeg]
libraries: [dos.library]
---

# dos.library/NewLoadSeg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	NewLoadSeg -- Improved version of [LoadSeg](autodocs-3.5/dos-library-loadseg-2.md) for stacksizes (V36)

   SYNOPSIS
	seglist = NewLoadSeg(file, tags)
	D0		      D1    D2

	[BPTR](autodocs-3.5/include-dos-dos-h.md) NewLoadSeg(STRPTR, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)

	seglist = NewLoadSegTagList(file, tags)
	D0			     D1    D2

	[BPTR](autodocs-3.5/include-dos-dos-h.md) NewLoadSegTagList(STRPTR, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)

	seglist = NewLoadSegTags(file, ...)

	[BPTR](autodocs-3.5/include-dos-dos-h.md) NewLoadSegTags(STRPTR, ...)

   FUNCTION
	Does a [LoadSeg](autodocs-3.5/dos-library-loadseg-2.md) on a file, and takes additional actions based on the
	tags supplied.

	Clears unused portions of Code and Data hunks (as well as BSS hunks).
	(This also applies to [InternalLoadSeg()](autodocs-3.5/dos-library-internalloadseg-2.md) and [LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md)).

	NOTE to overlay users: NewLoadSeg() does NOT return seglist in
	both D0 and D1, as [LoadSeg](autodocs-3.5/dos-library-loadseg-2.md) does.  The current ovs.asm uses [LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md),
	and assumes returns are in D1.  We will support this for [LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md)
	ONLY.

   INPUTS
	file - Filename of file to load
	tags - pointer to tagitem array

   RESULT
	seglist - Seglist loaded, or NULL

   BUGS
	No tags are currently defined.

   SEE ALSO
	[LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md), [UnLoadSeg()](autodocs-3.5/dos-library-unloadseg-2.md), [InternalLoadSeg()](autodocs-3.5/dos-library-internalloadseg-2.md), [InternalUnLoadSeg()](autodocs-3.5/dos-library-internalunloadseg-2.md)

---

## See Also

- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [UnLoadSeg — dos.library](../autodocs/dos.library.md#unloadseg)
