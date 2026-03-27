---
title: intuition.library/FreeScreenDrawInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-freescreendrawinfo-2
functions: [FreeScreenDrawInfo, GetScreenDrawInfo]
libraries: [intuition.library]
---

# intuition.library/FreeScreenDrawInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME	
 	FreeScreenDrawInfo -- Finish using a [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) structure. (V36)

   SYNOPSIS
	FreeScreenDrawInfo( [Screen](autodocs-3.5/include-intuition-screens-h.md), DrInfo )
			    A0      A1

	VOID FreeScreenDrawInfo( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, struct [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) * );

   FUNCTION
	Declares that you are finished with the [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) structure
	returned by [GetScreenDrawInfo()](autodocs-3.5/intuition-library-getscreendrawinfo-2.md).

   INPUTS
 	[Screen](autodocs-3.5/include-intuition-screens-h.md) - pointer to screen passed to [GetScreenDrawInfo()](autodocs-3.5/intuition-library-getscreendrawinfo-2.md).
	DrInfo - pointer to [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) returned by [GetScreenDrawInfo()](autodocs-3.5/intuition-library-getscreendrawinfo-2.md).
	    A NULL [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) pointer is a valid parameter, signifying
	    "do nothing".

   RESULT
 	None

   NOTES
	This function, and [GetScreenDrawInfo()](autodocs-3.5/intuition-library-getscreendrawinfo-2.md), don't really do much, but
	they provide an upward compatibility path.  That means that
	if you misuse them today, they probably won't cause a problem,
	although they may someday later.  So, please be very careful
	only to use the [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) structure between calls to
	[GetScreenDrawInfo()](autodocs-3.5/intuition-library-getscreendrawinfo-2.md) and FreeScreenDrawInfo(), and be sure
	that you don't forget FreeScreenDrawInfo().

   BUGS

   SEE ALSO
	[GetScreenDrawInfo()](autodocs-3.5/intuition-library-getscreendrawinfo-2.md)

---

## See Also

- [FreeScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#freescreendrawinfo)
- [GetScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#getscreendrawinfo)
