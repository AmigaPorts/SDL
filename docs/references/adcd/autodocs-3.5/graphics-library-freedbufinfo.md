---
title: graphics.library/FreeDBufInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-freedbufinfo
functions: [AllocDBufInfo, ChangeVPBitMap]
libraries: [graphics.library]
---

# graphics.library/FreeDBufInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       FreeDBufInfo -- free information for multi-buffered animation (V39)
```
   SYNOPSIS
```c
       FreeDBufInfo(db)
```
	             a1

	void FreeDBufInfo(struct [DBufInfo](autodocs-3.5/include-graphics-view-h.md) *)

   FUNCTION
	Frees a structure obtained from [AllocDBufInfo](autodocs-3.5/graphics-library-allocdbufinfo.md)

   INPUTS

```c
       db  =  A pointer to a [DBufInfo](autodocs-3.5/include-graphics-view-h.md).
```
   BUGS

   NOTES
	FreeDBufInfo(NULL) is a no-op.

   SEE ALSO
	[AllocDBufInfo()](autodocs-3.5/graphics-library-allocdbufinfo.md) [ChangeVPBitMap()](autodocs-3.5/graphics-library-changevpbitmap.md)

---

## See Also

- [AllocDBufInfo — graphics.library](../autodocs/graphics.library.md#allocdbufinfo)
- [ChangeVPBitMap — graphics.library](../autodocs/graphics.library.md#changevpbitmap)
