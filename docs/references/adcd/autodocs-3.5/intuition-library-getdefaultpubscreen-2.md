---
title: intuition.library/GetDefaultPubScreen
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-getdefaultpubscreen-2
functions: [LockPubScreen, OpenWindow, SetDefaultPubScreen]
libraries: [intuition.library]
---

# intuition.library/GetDefaultPubScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	GetDefaultPubScreen -- Get name of default public screen. (V36)

    SYNOPSIS
	GetDefaultPubScreen( Namebuff )
			     A0

	VOID GetDefaultPubScreen( [UBYTE](autodocs-3.5/include-exec-types-h.md) * );

    FUNCTION
	Provides the name of the current default public screen.
	Only anticipated use is for Public [Screen](autodocs-3.5/include-intuition-screens-h.md) Manager utilities,
	since it is easy to open a visitor window on the default
	public screen without specifying the name.

    INPUTS
	Namebuff = a buffer of MAXPUBSCREENNAME.  This can be NULL.

    RESULT
	None.  Will provide the string "Workbench" in Namebuff if there
	is no current default public screen.

    NOTES
	This function actually "returns" in register D0 a pointer
	to the public screen.  Unfortunately, the lifespan of
	this pointer is not ensured; the screen could be closed
	at any time.  The *ONLY* legitimate use we can see for
	this return value is to compare for identity with the pointer
	to a public screen you either have a window open in, or
	a lock on using [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md), to determine if that
	screen is in fact the default screen.

	Also note that if there no default public screen has been set,
	the return value of this function will be zero, and not a pointer
	to the Workbench screen.

    BUGS
	The function prototype does not reflect the return value.

    SEE ALSO
	[SetDefaultPubScreen()](autodocs-3.5/intuition-library-setdefaultpubscreen-2.md), [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md)

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [SetDefaultPubScreen — intuition.library](../autodocs/intuition.library.md#setdefaultpubscreen)
