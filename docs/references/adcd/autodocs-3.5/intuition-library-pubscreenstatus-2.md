---
title: intuition.library/PubScreenStatus
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-pubscreenstatus-2
functions: [OpenScreen]
libraries: [intuition.library]
---

# intuition.library/PubScreenStatus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	PubScreenStatus -- Change status flags for a public screen. (V36)

    SYNOPSIS
	ResultFlags = PubScreenStatus( [Screen](autodocs-3.5/include-intuition-screens-h.md), StatusFlags )
	D0		   	       A0      D0

	[UWORD](autodocs-3.5/include-exec-types-h.md) PubScreenStatus( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	Changes status flags for a given public screen.  The only
	flag bit currently defined is PSNF_PRIVATE.  Thus,
	PubScreenStatus( screen, PSNF_PRIVATE ) makes a screen
	private, while PubScreenStatus( screen, 0 ) makes it public.

	Do not apply this function to a screen if your program
	isn't the screen's "owner", in particular, don't call
	this function for the Workbench screen.

    INPUTS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = pointer to public screen
	StatusFlags = Any of the PSNF_ flags (only PSNF_PRIVATE is
	    currently defined).

    RESULT
	Returns 0 in the lowest order bit of the return value
	if the screen wasn't public, or because it can not be taken
	private because visitors are open in it.

	All other bits in the return code are reserved for future
	enhancement.

    BUGS

    SEE ALSO
	[OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md), Intuition V36 update documentation

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
