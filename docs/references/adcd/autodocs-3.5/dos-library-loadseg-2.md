---
title: dos.library/LoadSeg
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-loadseg-2
functions: [CreateNewProc, LoadSeg, UnLoadSeg]
libraries: [dos.library]
---

# dos.library/LoadSeg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	LoadSeg -- Scatterload a loadable file into memory

    SYNOPSIS
	seglist = LoadSeg( name )
	D0		   D1

	[BPTR](autodocs-3.5/include-dos-dos-h.md) LoadSeg(STRPTR)

    FUNCTION
	The file 'name' should be a load module produced by the linker.
	LoadSeg() scatterloads the CODE, DATA and BSS segments into memory,
	chaining together the segments with BPTR's on their first words.
	The end of the chain is indicated by a zero.  There can be any number
	of segments in a file.  All necessary relocation is handled by
	LoadSeg().

	In the event of an error any blocks loaded will be unloaded and a
	NULL result returned.

	If the module is correctly loaded then the output will be a pointer
	at the beginning of the list of blocks. Loaded code is unloaded via
	a call to [UnLoadSeg()](autodocs-3.5/dos-library-unloadseg-2.md).

    INPUTS
	name - pointer to a null-terminated string

    RESULTS
	seglist - BCPL pointer to a seglist

    SEE ALSO
	[UnLoadSeg()](autodocs-3.5/dos-library-unloadseg-2.md), [InternalLoadSeg()](autodocs-3.5/dos-library-internalloadseg-2.md), [InternalUnLoadSeg()](autodocs-3.5/dos-library-internalunloadseg-2.md), [CreateProc()](autodocs-3.5/dos-library-createproc-2.md),
	[CreateNewProc()](autodocs-3.5/dos-library-createnewproc-2.md), [NewLoadSeg()](autodocs-3.5/dos-library-newloadseg-2.md).

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [UnLoadSeg — dos.library](../autodocs/dos.library.md#unloadseg)
