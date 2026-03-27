---
title: graphics.library/NewRegion
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-newregion-2
functions: [NewRegion]
libraries: [graphics.library]
---

# graphics.library/NewRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME 

       NewRegion -- Get an empty region.
   SYNOPSIS 
```c
       region = NewRegion()
```
	d0

	struct [Region](autodocs-3.5/include-graphics-regions-h.md) *NewRegion();

   FUNCTION 
	Create a [Region](autodocs-3.5/include-graphics-regions-h.md) structure, initialize it to empty, and return
	a pointer it.

   RESULTS
	region - pointer to initialized region. If it could not allocate
		required memory region = NULL.

   INPUTS 
	none

   BUGS 

   SEE ALSO
	[graphics/regions.h](autodocs-3.5/include-graphics-regions-h.md)

---

## See Also

- [NewRegion — graphics.library](../autodocs/graphics.library.md#newregion)
