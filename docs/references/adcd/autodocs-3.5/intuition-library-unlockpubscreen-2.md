---
title: intuition.library/UnlockPubScreen
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-unlockpubscreen-2
functions: [LockPubScreen, UnlockPubScreen]
libraries: [intuition.library]
---

# intuition.library/UnlockPubScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	UnlockPubScreen -- Release lock on a public screen. (V36)

    SYNOPSIS
	UnlockPubScreen( Name, [Screen] )
			 A0    A1

	VOID UnlockPubScreen( [UBYTE](autodocs-3.5/include-exec-types-h.md) *, struct [Screen](autodocs-3.5/include-intuition-screens-h.md) * );

    FUNCTION
	Releases lock gotten by [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md).
	It is best to identify the locked public screen by
	the pointer returned from [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md).  To do this,
	supply a NULL 'Name' pointer and the screen pointer.

	In rare circumstances where it would be more convenient to pass
	a non-NULL pointer to the public screen name string, the
	'Screen' parameter is ignored.

    INPUTS
	Name = pointer to name of public screen.  If Name is NULL,
	    then argument 'Screen' is used as a direct pointer to
	    a public screen.
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = pointer to a public screen.  Used only if Name
	    is NULL.  This pointer MUST have been returned
	    by [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md).
	    It is safe to call UnlockPubScreen() with NULL Name
	    and [Screen](autodocs-3.5/include-intuition-screens-h.md) (the function will have no effect).

    RESULT

    BUGS

    SEE ALSO
	[LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md)

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
