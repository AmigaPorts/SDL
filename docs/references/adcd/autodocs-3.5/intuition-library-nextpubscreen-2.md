---
title: intuition.library/NextPubScreen
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-nextpubscreen-2
functions: [LockPubScreen, OpenScreen, PubScreenStatus]
libraries: [intuition.library]
---

# intuition.library/NextPubScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	NextPubScreen -- Identify next public screen in the cycle. (V36)

    SYNOPSIS
	Buff = NextPubScreen( [Screen](autodocs-3.5/include-intuition-screens-h.md), NameBuff )
	D0                    A0      A1

	[UBYTE](autodocs-3.5/include-exec-types-h.md) *NextPubScreen( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) * );

    FUNCTION
	Returns name of next public screen in system rotation, to
	allow visitor windows to provide function to "jump" among
	public-screens in a cycle.

    INPUTS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = pointer to the screen your window is currently open in,
	  or NULL, if you don't have a pointer to a public screen.
	NameBuff = pointer to a buffer of MAXPUBSCREENNAME+1 characters,
	  for Intuition to fill in with the name of the next public
	  screen in rotation.

    RESULT
	Returns NULL if there are no public screens, otherwise a
	pointer to your NameBuff.

    NOTES
	There is no guarantee that the public screen whose name
	was returned by this function will exist or be in "public" state
	by the time you call [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md), etc.  You must handle
	cases where [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md), etc. will fail.

	Note that this function may return the name of a public screen
	which is open but in "private mode" (see [PubScreenStatus()](autodocs-3.5/intuition-library-pubscreenstatus-2.md) and
	PSNF_PRIVATE).

    BUGS
	Due to a bug, your buffer needs to be (MAXPUBSCREENNAME + 1)
	characters big, which is one more than originally documented.

	The starting screen and cycle order of the public screens isn't
	defined, so do not draw conclusions about the order you
	see in the current version of Intuition.  We reserve the
	right to add meaning to the ordering at a future time.

    SEE ALSO
	[OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md), Intuition V36 update documentation

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [PubScreenStatus — intuition.library](../autodocs/intuition.library.md#pubscreenstatus)
