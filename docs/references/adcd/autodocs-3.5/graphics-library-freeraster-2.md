---
title: graphics.library/FreeRaster
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-freeraster-2
functions: [AllocRaster]
libraries: [graphics.library]
---

# graphics.library/FreeRaster

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
       FreeRaster -- Release an allocated area to the system free memory pool
.


   SYNOPSIS
```c
       FreeRaster( p, width, height)
```
		   a0   d0:16  d1:16

	void FreeRaster( [PLANEPTR](autodocs-3.5/include-graphics-gfx-h.md), USHORT, USHORT);

   FUNCTION
	Return the memory associated with this [PLANEPTR](autodocs-3.5/include-graphics-gfx-h.md) of size
	width and height to the MEMF_CHIP memory pool.

   INPUTS

```c
       p  =  a pointer to a memory space  returned  as  a
             result of a call to [AllocRaster](autodocs-3.5/graphics-library-allocraster-2.md).
```
	width - the width in bits of the bitplane.
	height - number of rows in bitplane.

   BUGS

   NOTES

```c
       Width and height should be the same values with which you
       called [AllocRaster](autodocs-3.5/graphics-library-allocraster-2.md) in the first place.
```
   SEE ALSO
	[AllocRaster()](autodocs-3.5/graphics-library-allocraster-2.md) [graphics/gfx.h](autodocs-3.5/include-graphics-gfx-h.md)

---

## See Also

- [AllocRaster — graphics.library](../autodocs/graphics.library.md#allocraster)
