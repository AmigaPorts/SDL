---
title: intuition.library/AllocScreenBuffer
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-allocscreenbuffer
functions: [AllocDBufInfo, AllocScreenBuffer, ChangeScreenBuffer, ChangeVPBitMap, FreeScreenBuffer, OpenScreen]
libraries: [graphics.library, intuition.library]
---

# intuition.library/AllocScreenBuffer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	AllocScreenBuffer -- Get a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) for double-buffering. (V39)

    SYNOPSIS
	sbuffer = AllocScreenBuffer( [Screen](autodocs-3.5/include-intuition-screens-h.md), [BitMap](autodocs-3.5/include-graphics-gfx-h.md), flags )
	D0                           A0      A1      D0

	struct [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) *AllocScreenBuffer( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *,
	    struct [BitMap](autodocs-3.5/include-graphics-gfx-h.md) *, ULONG );

    FUNCTION
	Allocates a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) structure and usually a [BitMap](autodocs-3.5/include-graphics-gfx-h.md).  This
	structure can be used for double (or multiple) buffering in
	Intuition screens.  You may use this call to obtain a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md)
	structure for the screen's initial [BitMap](autodocs-3.5/include-graphics-gfx-h.md), or for other BitMaps
	you intend to swap in.

	AllocScreenBuffer() also allocates a graphics.library [DBufInfo](autodocs-3.5/include-graphics-view-h.md)
	structure.  The [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) structure this call returns contains
	a pointer to that [DBufInfo](autodocs-3.5/include-graphics-view-h.md) structure, which is free for your use.
	See [graphics.library/AllocDBufInfo()](autodocs-3.5/graphics-library-allocdbufinfo.md) for full details on using
	this structure to achieve notification of when it is safe to
	render into an old buffer and when it is right to switch again.

    INPUTS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = pointer to the screen to double-buffer
	[BitMap](autodocs-3.5/include-graphics-gfx-h.md) = For CUSTOMBITMAP screens, you may pre-allocate
		a [BitMap](autodocs-3.5/include-graphics-gfx-h.md) matching the screen's BitMap's properties, and
		pass that in, to get a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) referring to that
		[BitMap](autodocs-3.5/include-graphics-gfx-h.md).  Set this parameter to NULL if you'd prefer
		that Intuition allocate the alternate buffer.  This parameter
		must be NULL for non-CUSTOMBITMAP screens.
	Flags = Set a combination of these flags:
	    For non-CUSTOMBITMAP screens, set SB_SCREEN_BITMAP in order to
		get a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) referring to the screen's actual [BitMap](autodocs-3.5/include-graphics-gfx-h.md).
		(For CUSTOMBITMAP screens, just set the [BitMap](autodocs-3.5/include-graphics-gfx-h.md) parameter
		to the [BitMap](autodocs-3.5/include-graphics-gfx-h.md) you passed to [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md)).
	    Set SB_COPY_BITMAP if you would like the screen's [BitMap](autodocs-3.5/include-graphics-gfx-h.md)
		copied into this ScreenBuffer's [BitMap](autodocs-3.5/include-graphics-gfx-h.md).  This is required
		to get any menu-bar or gadget imagery into each
		ScreenBuffer's [BitMap](autodocs-3.5/include-graphics-gfx-h.md).  If the screen has no Intuition
		rendering, you may omit this flag.  Also, when allocating
		a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) for the screen's initial [BitMap](autodocs-3.5/include-graphics-gfx-h.md), this flag
		should not be set.

    RESULT
	Pointer to a valid [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) structure, or NULL if failure.
	You may render into the resulting [BitMap](autodocs-3.5/include-graphics-gfx-h.md) as appropriate.
	You may use the sb_DBufInfo field to access graphics.library
	ViewPort-buffering features such as learning when it is safe
	to reuse the previous [BitMap](autodocs-3.5/include-graphics-gfx-h.md).  If not, you risk writing into
	the on-screen [BitMap](autodocs-3.5/include-graphics-gfx-h.md), which can damage menu or gadget rendering!


    NOTES
	The role of SB_SCREEN_BITMAP is to wrap a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) around
	the actual current [BitMap](autodocs-3.5/include-graphics-gfx-h.md) used by the non-CUSTOMBITMAP screen.
	The words actual or current are used instead of initial, since
	an application could do some double-buffering, leave the
	non-initial buffer installed into the screen, free up the
	others, then re-allocate [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) structures to do more
	double-buffering.  In that case, the actual screen [BitMap](autodocs-3.5/include-graphics-gfx-h.md) is
	not necessarily the initial one.

	The role of SB_COPY_BITMAP is to say "please put whatever
	imagery is currently on-screen into this new [BitMap](autodocs-3.5/include-graphics-gfx-h.md) too".
	That's how the screen titlebar and other imagery get copied
	over into each buffer.

    BUGS

    SEE ALSO
	[FreeScreenBuffer()](autodocs-3.5/intuition-library-freescreenbuffer.md), [ChangeScreenBuffer()](autodocs-3.5/intuition-library-changescreenbuffer.md),
	[graphics.library/AllocDBufInfo()](autodocs-3.5/graphics-library-allocdbufinfo.md), [graphics.library/ChangeVPBitMap()](autodocs-3.5/graphics-library-changevpbitmap.md)

---

## See Also

- [AllocDBufInfo — graphics.library](../autodocs/graphics.library.md#allocdbufinfo)
- [AllocScreenBuffer — intuition.library](../autodocs/intuition.library.md#allocscreenbuffer)
- [ChangeScreenBuffer — intuition.library](../autodocs/intuition.library.md#changescreenbuffer)
- [ChangeVPBitMap — graphics.library](../autodocs/graphics.library.md#changevpbitmap)
- [FreeScreenBuffer — intuition.library](../autodocs/intuition.library.md#freescreenbuffer)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
