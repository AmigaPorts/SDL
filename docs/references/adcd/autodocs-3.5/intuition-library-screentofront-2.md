---
title: intuition.library/ScreenToFront
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-screentofront-2
functions: [ScreenDepth, ScreenToBack]
libraries: [intuition.library]
---

# intuition.library/ScreenToFront

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ScreenToFront -- Make the specified screen the frontmost.

    SYNOPSIS
	ScreenToFront( [Screen](autodocs-3.5/include-intuition-screens-h.md) )
		       A0

	VOID ScreenToFront( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) * );

    FUNCTION
	Brings the specified [Screen](autodocs-3.5/include-intuition-screens-h.md) to the front of the display.

    INPUTS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = a pointer to a [Screen](autodocs-3.5/include-intuition-screens-h.md) structure

    RESULT
	None

    BUGS

    SEE ALSO
	[ScreenDepth()](autodocs-3.5/intuition-library-screendepth.md), [ScreenToBack()](autodocs-3.5/intuition-library-screentoback-2.md)

---

## See Also

- [ScreenDepth — intuition.library](../autodocs/intuition.library.md#screendepth)
- [ScreenToBack — intuition.library](../autodocs/intuition.library.md#screentoback)
