---
title: dos.library/RemDosEntry
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-remdosentry-2
functions: [AddDosEntry, FindDosEntry, LockDosList, NextDosEntry]
libraries: [dos.library]
---

# dos.library/RemDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemDosEntry -- Removes a Dos [List](autodocs-3.5/include-exec-lists-h.md) entry from it's list (V36)

   SYNOPSIS
	success = RemDosEntry(dlist)
	D0                     D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) RemDosEntry(struct [DosList](autodocs-3.5/include-dos-dosextens-h.md) *)

   FUNCTION
	This removes an entry from the Dos [Device](autodocs-3.5/include-exec-devices-h.md) list.  The memory associated
	with the entry is NOT freed.  NOTE: you must have locked the Dos [List](autodocs-3.5/include-exec-lists-h.md)
	with the appropriate flags before calling this routine.  Handler
	writers should see the [AddDosEntry()](autodocs-3.5/dos-library-adddosentry-2.md) caveats about locking and use
	a similar workaround to avoid deadlocks.

   INPUTS
	dlist   - [Device](autodocs-3.5/include-exec-devices-h.md) list entry to be removed.

   RESULT
	success - Success/failure indicator

   SEE ALSO
	[AddDosEntry()](autodocs-3.5/dos-library-adddosentry-2.md), [FindDosEntry()](autodocs-3.5/dos-library-finddosentry-2.md), [NextDosEntry()](autodocs-3.5/dos-library-nextdosentry-2.md), [LockDosList()](autodocs-3.5/dos-library-lockdoslist-2.md),
	[MakeDosEntry()](autodocs-3.5/dos-library-makedosentry-2.md), [FreeDosEntry()](autodocs-3.5/dos-library-freedosentry-2.md)

---

## See Also

- [AddDosEntry — dos.library](../autodocs/dos.library.md#adddosentry)
- [FindDosEntry — dos.library](../autodocs/dos.library.md#finddosentry)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
