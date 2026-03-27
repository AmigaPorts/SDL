---
title: dos.library/AttemptLockDosList
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-attemptlockdoslist-2
functions: [Forbid, LockDosList, NextDosEntry, UnLockDosList]
libraries: [dos.library, exec.library]
---

# dos.library/AttemptLockDosList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AttemptLockDosList -- Attempt to lock the Dos Lists for use (V36)

   SYNOPSIS
	dlist = AttemptLockDosList(flags)
	D0			    D1

	struct [DosList](autodocs-3.5/include-dos-dosextens-h.md) *AttemptLockDosList(ULONG)

   FUNCTION
	Locks the dos device list in preparation to walk the list.  If the
	list is 'busy' then this routine will return NULL.  See [LockDosList()](autodocs-3.5/dos-library-lockdoslist-2.md)
	for more information.

   INPUTS
	flags - Flags stating which types of nodes you want to lock.

   RESULT
	dlist - Pointer to the beginning of the list or NULL.  Not a valid
		node!

   BUGS
	In V36 through V39.23 dos, this would return NULL or 0x00000001 for
	failure.  Fixed in V39.24 dos (after kickstart 39.106).

   SEE ALSO
	[LockDosList()](autodocs-3.5/dos-library-lockdoslist-2.md), [UnLockDosList()](autodocs-3.5/dos-library-unlockdoslist-2.md), [Forbid()](autodocs-3.5/exec-library-forbid-2.md), [NextDosEntry()](autodocs-3.5/dos-library-nextdosentry-2.md)

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
- [UnLockDosList — dos.library](../autodocs/dos.library.md#unlockdoslist)
