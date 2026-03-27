---
title: graphics.library/ClearRegion
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-clearregion-2
functions: [NewRegion]
libraries: [graphics.library]
---

# graphics.library/ClearRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME 

```c
       ClearRegion -- [Remove](autodocs-3.5/exec-library-remove-2.md) all rectangles from region.
```
   SYNOPSIS 

```c
       ClearRegion(region)
                     a0
```
	viod ClearRegion( struct [Region](autodocs-3.5/include-graphics-regions-h.md) * );

   FUNCTION 

       Clip away all rectangles in the region leaving nothing.
   INPUTS 

```c
       region - pointer to [Region](autodocs-3.5/include-graphics-regions-h.md) structure
```
   BUGS 

   SEE ALSO
	[NewRegion()](autodocs-3.5/graphics-library-newregion-2.md) [graphics/regions.h](autodocs-3.5/include-graphics-regions-h.md)

---

## See Also

- [NewRegion — graphics.library](../autodocs/graphics.library.md#newregion)
