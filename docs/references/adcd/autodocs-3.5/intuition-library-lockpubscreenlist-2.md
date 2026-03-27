---
title: intuition.library/LockPubScreenList
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-lockpubscreenlist-2
functions: [LockIBase, LockPubScreenList, OpenScreen, UnlockPubScreenList]
libraries: [intuition.library]
---

# intuition.library/LockPubScreenList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	LockPubScreenList -- Prevent changes to the system list. (V36)

    SYNOPSIS
	[List](autodocs-3.5/include-exec-lists-h.md) = LockPubScreenList()
	D0

	struct [List](autodocs-3.5/include-exec-lists-h.md) *LockPubScreenList( VOID );

    FUNCTION
	Arbitrates access to public screen list	while you quickly
	make a copy of it for display to the user.

	Note that this is intended only for the Public [Screen](autodocs-3.5/include-intuition-screens-h.md) Manager
	program.

    NOTES
	The nodes on the list are [PubScreenNode](autodocs-3.5/include-intuition-screens-h.md) structures.
	Act quickly while holding this lock.  The restrictions
	on [LockIBase()](autodocs-3.5/intuition-library-lockibase-2.md) apply here as well.

    INPUTS
	None.

    RESULT
	A pointer to the public screen list.

    BUGS

    SEE ALSO
	[UnlockPubScreenList()](autodocs-3.5/intuition-library-unlockpubscreenlist-2.md), [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md), Intuition V36 update documentation

---

## See Also

- [LockIBase — intuition.library](../autodocs/intuition.library.md#lockibase)
- [LockPubScreenList — intuition.library](../autodocs/intuition.library.md#lockpubscreenlist)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [UnlockPubScreenList — intuition.library](../autodocs/intuition.library.md#unlockpubscreenlist)
