---
title: graphics.library/FreeCopList
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-freecoplist-2
functions: []
libraries: []
---

# graphics.library/FreeCopList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeCopList -- deallocate intermediate copper list

   SYNOPSIS
```c
       FreeCopList(coplist)
```
		      a0

	void FreeCopList( struct [CopList](autodocs-3.5/include-graphics-copper-h.md) *);

   FUNCTION
	[Deallocate](autodocs-3.5/exec-library-deallocate-2.md) all memory associated with this copper list.

   INPUTS

```c
       coplist	- pointer to structure [CopList](autodocs-3.5/include-graphics-copper-h.md)
```
   RESULTS
	memory returned to memory manager

   BUGS

   SEE ALSO
	[graphics/copper.h](autodocs-3.5/include-graphics-copper-h.md)

