---
title: graphics.library/NextDisplayInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-nextdisplayinfo-2
functions: [FindDisplayInfo, GetDisplayInfoData]
libraries: [graphics.library]
---

# graphics.library/NextDisplayInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	NextDisplayInfo -- iterate current displayinfo identifiers (V36)

   SYNOPSIS
	next_ID = NextDisplayInfo(last_ID)
	D0                        D0

	ULONG NextDisplayInfo(ULONG);

   FUNCTION
	The basic iteration function with which to find all records in the
	graphics database.  Using each ID in succession, you can then call
	[FindDisplayInfo()](autodocs-3.5/graphics-library-finddisplayinfo-2.md) to obtain the handle associated with each ID.
	Each ID is a 32-bit Key which uniquely identifies one record.
	The INVALID_ID is special, and indicates the end-of-list.

   INPUTS
	last_ID - previous displayinfo identifier
	          or INVALID_ID if beginning iteration.

   RESULT
	next_ID - subsequent displayinfo identifier
	          or INVALID_ID if no more records.

   BUGS

   SEE ALSO
	[FindDisplayInfo()](autodocs-3.5/graphics-library-finddisplayinfo-2.md), [GetDisplayInfoData()](autodocs-3.5/graphics-library-getdisplayinfodata-2.md)
	[graphics/displayinfo.h](autodocs-3.5/include-graphics-displayinfo-h.md)

---

## See Also

- [FindDisplayInfo — graphics.library](../autodocs/graphics.library.md#finddisplayinfo)
- [GetDisplayInfoData — graphics.library](../autodocs/graphics.library.md#getdisplayinfodata)
