---
title: intuition.library/ScreenToBack
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-screentoback-2
functions: [ScreenDepth, ScreenToFront]
libraries: [intuition.library]
---

# intuition.library/ScreenToBack

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ScreenToBack -- Send the specified screen to the back of the display.

    SYNOPSIS
	ScreenToBack( [Screen](autodocs-3.5/include-intuition-screens-h.md) )
		      A0

	VOID ScreenToBack( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) * );

    FUNCTION
	Sends the specified screen to the back of the display.

    INPUTS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = pointer to a [Screen](autodocs-3.5/include-intuition-screens-h.md) structure

    RESULT
	None

    BUGS

    SEE ALSO
	[ScreenDepth()](autodocs-3.5/intuition-library-screendepth.md), [ScreenToFront()](autodocs-3.5/intuition-library-screentofront-2.md)

---

## See Also

- [ScreenDepth — intuition.library](../autodocs/intuition.library.md#screendepth)
- [ScreenToFront — intuition.library](../autodocs/intuition.library.md#screentofront)
