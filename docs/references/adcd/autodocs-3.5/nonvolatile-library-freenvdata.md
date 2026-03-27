---
title: nonvolatile.library/FreeNVData
manual: autodocs-3.5
chapter: autodocs-3.5
section: nonvolatile-library-freenvdata
functions: []
libraries: []
---

# nonvolatile.library/FreeNVData

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeNVData -- release the memory allocated by a function of this
		      library. (V40)

   SYNOPSIS
	FreeNVData(data);
		   A0

	VOID FreeNVData(APTR);

   FUNCTION
	Frees a block of memory that was allocated by any of the following:
	[GetCopyNV()](autodocs-3.5/nonvolatile-library-getcopynv.md), [GetNVInfo()](autodocs-3.5/nonvolatile-library-getnvinfo.md), [GetNVList()](autodocs-3.5/nonvolatile-library-getnvlist.md).

   INPUTS
	data - pointer to the memory block to be freed. If passed NULL,
	       this function does nothing.

   SEE ALSO
	[GetCopyNV()](autodocs-3.5/nonvolatile-library-getcopynv.md), [GetNVInfo()](autodocs-3.5/nonvolatile-library-getnvinfo.md), [GetNVList()](autodocs-3.5/nonvolatile-library-getnvlist.md)

