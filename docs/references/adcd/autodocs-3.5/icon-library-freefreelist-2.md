---
title: icon.library/FreeFreeList
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-freefreelist-2
functions: []
libraries: []
---

# icon.library/FreeFreeList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeFreeList - free all memory in a free list.

   SYNOPSIS
	FreeFreeList(free)
	             A0

	void FreeFreeList(struct [FreeList](autodocs-3.5/include-workbench-workbench-h.md) *);

   FUNCTION
	This routine frees all memory in a free list, and the
	free list itself.  It is useful for easily getting
	rid of all memory in a series of structures.  There is
	a free list in a Workbench object, and this contains
	all the memory associated with that object.

	A [FreeList](autodocs-3.5/include-workbench-workbench-h.md) is a list of [MemList](autodocs-3.5/include-exec-memory-h.md) structures.  See the
	[MemList](autodocs-3.5/include-exec-memory-h.md) and [MemEntry](autodocs-3.5/include-exec-memory-h.md) documentation for more information.

	If the [FreeList](autodocs-3.5/include-workbench-workbench-h.md) itself is in the free list, it must be
	in the first [MemList](autodocs-3.5/include-exec-memory-h.md) in the [FreeList](autodocs-3.5/include-workbench-workbench-h.md).

   INPUTS
	free -- a pointer to a [FreeList](autodocs-3.5/include-workbench-workbench-h.md) structure; as of V44
	    a NULL free parameter will be ignored.

   SEE ALSO
	[exec.library/AllocEntry](autodocs-3.5/exec-library-allocentry-2.md)
	[exec.library/FreeEntry](autodocs-3.5/exec-library-freeentry-2.md)
	[icon.library/AddFreeList](autodocs-3.5/icon-library-addfreelist-2.md)
	[workbench/workbench.h](autodocs-3.5/include-workbench-workbench-h.md)

