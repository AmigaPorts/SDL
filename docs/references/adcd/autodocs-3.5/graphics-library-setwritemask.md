---
title: graphics.library/SetWriteMask
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setwritemask
functions: []
libraries: []
---

# graphics.library/SetWriteMask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME


```c
       SetWriteMask -- Set the pixel write mask value for a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) (V39).
```
   SYNOPSIS
```c
       success=SetWriteMask ( rp, msk )
```
	  d0	               a0   d0

	ULONG SetWriteMask(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *,ULONG)

   FUNCTION
	Set the current value of the bit write mask for the rastport.
	bits of the pixel with zeros in their mask will not be modified by
	subsequent drawing operations.

   INPUTS
```c
       rp  =  a pointer to a valid [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
```
	msk =  a longword mask value.

	Graphics devices which do not support per-bit masking will
	return 0 (failure).
   BUGS

   NOTES

   SEE ALSO
	[graphics/gfxmacros.h](autodocs-3.5/include-graphics-gfxmacros-h.md)

