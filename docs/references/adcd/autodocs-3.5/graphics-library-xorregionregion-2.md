---
title: graphics.library/XorRegionRegion
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-xorregionregion-2
functions: []
libraries: []
---

# graphics.library/XorRegionRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME 

       XorRegionRegion -- Perform 2d XOR operation of one region
                       with second region, leaving result in second region
   SYNOPSIS 

```c
       status = XorRegionRegion(region1,region2)
         d0                        a0      a1
```
	[BOOL](autodocs-3.5/include-exec-types-h.md) XorRegionRegion( struct [Region](autodocs-3.5/include-graphics-regions-h.md) *, struct [Region](autodocs-3.5/include-graphics-regions-h.md) * );

   FUNCTION 
	Join the regions together. If any part of region1 overlaps
	region2 then remove that from the new region.

   INPUTS 

```c
       region1      = pointer to [Region](autodocs-3.5/include-graphics-regions-h.md) structure
       region2      = pointer to [Region](autodocs-3.5/include-graphics-regions-h.md) structure
```
   RESULTS
	status - return TRUE if successful operation
		 return FALSE if ran out of memory

   BUGS 

