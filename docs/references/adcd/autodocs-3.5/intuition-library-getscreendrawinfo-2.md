---
title: intuition.library/GetScreenDrawInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-getscreendrawinfo-2
functions: [FreeScreenDrawInfo, GetScreenDrawInfo, LockPubScreen]
libraries: [intuition.library]
---

# intuition.library/GetScreenDrawInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME	
	GetScreenDrawInfo -- Get pointer to rendering information. (V36)

   SYNOPSIS
	DrInfo = GetScreenDrawInfo( [Screen](autodocs-3.5/include-intuition-screens-h.md) )
	D0	  		    A0

	struct [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) *GetScreenDrawInfo( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) * );

   FUNCTION
	Returns a pointer to a [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) structure derived from the
	screen passed.  This data structure is READ ONLY.  The field
	dri_Version identifies which version of struct [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) you
	are given a pointer to.

   INPUTS
 	[Screen](autodocs-3.5/include-intuition-screens-h.md)        - pointer to a valid, open screen.

   RESULT
 	DrInfo - pointer to a system-allocated [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) structure,
	as defined in [intuition/screens.h](autodocs-3.5/include-intuition-screens-h.md).

   NOTES
	Some information in the [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) structure may in the future
	be calculated the first time this function is called for a
	particular screen.

	You must call [FreeScreenDrawInfo()](autodocs-3.5/intuition-library-freescreendrawinfo-2.md) when you are done using the
	returned pointer.

	This function does not prevent a screen from closing.  Apply it
	only to the screens you opened yourself, or apply a protocol
	such as [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md).

	WARNING: Until further notice, the pointer returned does not
	remain valid after the screen is closed.

	This function and [FreeScreenDrawInfo()](autodocs-3.5/intuition-library-freescreendrawinfo-2.md) don't really do much now,
	but they provide an upward compatibility path.  That means that
	if you misuse them today, they probably won't cause a problem,
	although they may someday later.  So, please be very careful
	only to use the [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) structure between calls to
	GetScreenDrawInfo() and [FreeScreenDrawInfo()](autodocs-3.5/intuition-library-freescreendrawinfo-2.md), and be sure
	that you don't forget [FreeScreenDrawInfo()](autodocs-3.5/intuition-library-freescreendrawinfo-2.md).

   BUGS
	Does not reflect to changes in screen modes, depth, or pens.

   SEE ALSO
	[FreeScreenDrawInfo()](autodocs-3.5/intuition-library-freescreendrawinfo-2.md), [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md), [intuition/screens.h](autodocs-3.5/include-intuition-screens-h.md)

---

## See Also

- [FreeScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#freescreendrawinfo)
- [GetScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#getscreendrawinfo)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
