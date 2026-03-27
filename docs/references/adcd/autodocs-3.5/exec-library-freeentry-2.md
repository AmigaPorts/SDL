---
title: exec.library/FreeEntry
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-freeentry-2
functions: []
libraries: []
---

# exec.library/FreeEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeEntry -- free many regions of memory

   SYNOPSIS
	FreeEntry(memList)
		  A0
	void FreeEntry(struct [MemList](autodocs-3.5/include-exec-memory-h.md) *);

   FUNCTION
	This function takes a memList structure (as returned by AllocEntry)
	and frees all the entries.

   INPUTS
	memList -- pointer to structure filled in with [MemEntry](autodocs-3.5/include-exec-memory-h.md)
		   structures

   SEE ALSO
	[AllocEntry()](autodocs-3.5/exec-library-allocentry-2.md)

