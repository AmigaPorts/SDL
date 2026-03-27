---
title: intuition.library/FreeScreenBuffer
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-freescreenbuffer
functions: [AllocScreenBuffer, ChangeScreenBuffer, ChangeVPBitMap, CloseScreen, FreeScreenBuffer, WaitBlit]
libraries: [graphics.library, intuition.library]
---

# intuition.library/FreeScreenBuffer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	FreeScreenBuffer -- Free a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) structure. (V39)

    SYNOPSIS
	FreeScreenBuffer( [Screen](autodocs-3.5/include-intuition-screens-h.md), [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) )
	                  A0      A1

	VOID FreeScreenBuffer( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, struct [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) * );

    FUNCTION
	Frees a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) structure you got from [AllocScreenBuffer()](autodocs-3.5/intuition-library-allocscreenbuffer.md),
	and releases associated resources.  You must call FreeScreenBuffer()
	before you close your screen.

    INPUTS
	Screen: pointer to the screen this [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) is associated with.
	ScreenBuffer: pointer to a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) structure obtained from
	    [AllocScreenBuffer()](autodocs-3.5/intuition-library-allocscreenbuffer.md).  It is safe to call this function with
	    a NULL argument.  It will have no effect.

    RESULT
	None.

    NOTES
	Originally, FreeScreenBuffer() did not [WaitBlit()](autodocs-3.5/graphics-library-waitblit-2.md) before freeing
	a [BitMap](autodocs-3.5/include-graphics-gfx-h.md).  The intent was that the application should do this.
	However, as this sort of thing is easily forgotten, [WaitBlit()](autodocs-3.5/graphics-library-waitblit-2.md)
	was added in V40.  Application writers should ensure that freeing
	the buffer is safe by calling [WaitBlit()](autodocs-3.5/graphics-library-waitblit-2.md) themselves.

	The SB_SCREEN_BITMAP flag instructs [AllocScreenBuffer()](autodocs-3.5/intuition-library-allocscreenbuffer.md) to provide
	a [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) referring to the screen's actual bitmap.  When
	you are done changing screen buffers, you must FreeScreenBuffer()
	the currently-installed [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md) before you close the screen.
	Intuition will recognize when FreeScreenBuffer() is called for
	the currently-installed [ScreenBuffer](autodocs-3.5/include-intuition-screens-h.md), and will know to free the
	supporting structures but not the [BitMap](autodocs-3.5/include-graphics-gfx-h.md).  [CloseScreen()](autodocs-3.5/intuition-library-closescreen-2.md) will
	take care of that.

    BUGS

    SEE ALSO
	[AllocScreenBuffer()](autodocs-3.5/intuition-library-allocscreenbuffer.md), [ChangeScreenBuffer()](autodocs-3.5/intuition-library-changescreenbuffer.md),
	[graphics.library/ChangeVPBitMap()](autodocs-3.5/graphics-library-changevpbitmap.md)

---

## See Also

- [AllocScreenBuffer — intuition.library](../autodocs/intuition.library.md#allocscreenbuffer)
- [ChangeScreenBuffer — intuition.library](../autodocs/intuition.library.md#changescreenbuffer)
- [ChangeVPBitMap — graphics.library](../autodocs/graphics.library.md#changevpbitmap)
- [CloseScreen — intuition.library](../autodocs/intuition.library.md#closescreen)
- [FreeScreenBuffer — intuition.library](../autodocs/intuition.library.md#freescreenbuffer)
- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
