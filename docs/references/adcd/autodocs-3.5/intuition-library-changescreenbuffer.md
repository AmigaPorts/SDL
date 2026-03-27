---
title: intuition.library/ChangeScreenBuffer
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-changescreenbuffer
functions: [AllocDBufInfo, AllocScreenBuffer, ChangeScreenBuffer, ChangeVPBitMap, FreeScreenBuffer]
libraries: [graphics.library, intuition.library]
---

# intuition.library/ChangeScreenBuffer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ChangeScreenBuffer -- Swap the screen's [BitMap](autodocs-3.5/include-graphics-gfx-h.md). (V39)

    SYNOPSIS
	success = ChangeScreenBuffer( [Screen](autodocs-3.5/include-intuition-screens-h.md), [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) )
	D0                            A0      A1

	ULONG ChangeScreenBuffer( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, struct [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) * );

    FUNCTION
	Performs double (or multiple) buffering on an Intuition screen
	in an Intuition-cooperative manner.  The [BitMap](autodocs-3.5/include-graphics-gfx-h.md) associated
	with the supplied [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) will be installed in the
	specified screen, if possible.  The previously-installed [BitMap](autodocs-3.5/include-graphics-gfx-h.md)
	is available for re-use upon receiving a signal from
	graphics.library.  See the graphics.library autodocs for
	[graphics.library/AllocDBufInfo()](autodocs-3.5/graphics-library-allocdbufinfo.md) and [graphics.library/ChangeVPBitMap()](autodocs-3.5/graphics-library-changevpbitmap.md)
	for details.

    INPUTS
	Screen: pointer to the screen whose bitmap is to be swapped.
	ScreenBuffer: pointer to a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) structure obtained from
	    [AllocScreenBuffer()](autodocs-3.5/intuition-library-allocscreenbuffer.md).

    RESULT
	Returns non-zero if the operation succeeded.  Returns zero
	if the operation cannot be performed.  This function will
	fail if Intuition's state cannot permit it, for example the
	user is playing with menus or gadgets.

    NOTES
	It is not required to restore the original [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md)
	before closing the screen. Simply [FreeScreenBuffer()](autodocs-3.5/intuition-library-freescreenbuffer.md) each
	buffer (including the original and the currently-installed one)
	then close the screen.	Of course, you cannot call
	ChangeScreenBuffer() after freeing the currently-installed one.

    BUGS

    SEE ALSO
	[AllocScreenBuffer()](autodocs-3.5/intuition-library-allocscreenbuffer.md), [FreeScreenBuffer()](autodocs-3.5/intuition-library-freescreenbuffer.md),
	[graphics.library/ChangeVPBitMap()](autodocs-3.5/graphics-library-changevpbitmap.md)

---

## See Also

- [AllocDBufInfo — graphics.library](../autodocs/graphics.library.md#allocdbufinfo)
- [AllocScreenBuffer — intuition.library](../autodocs/intuition.library.md#allocscreenbuffer)
- [ChangeScreenBuffer — intuition.library](../autodocs/intuition.library.md#changescreenbuffer)
- [ChangeVPBitMap — graphics.library](../autodocs/graphics.library.md#changevpbitmap)
- [FreeScreenBuffer — intuition.library](../autodocs/intuition.library.md#freescreenbuffer)
