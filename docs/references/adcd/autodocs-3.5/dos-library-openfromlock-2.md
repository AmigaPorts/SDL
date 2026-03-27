---
title: dos.library/OpenFromLock
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-openfromlock-2
functions: [Close, Lock, Open, UnLock]
libraries: [dos.library]
---

# dos.library/OpenFromLock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	OpenFromLock -- Opens a file you have a lock on (V36)

   SYNOPSIS
	fh = OpenFromLock(lock)
	D0                 D1

	[BPTR](autodocs-3.5/include-dos-dos-h.md) OpenFromLock(BPTR)

   FUNCTION
	Given a lock, this routine performs an open on that lock.  If the open
	succeeds, the lock is (effectively) relinquished, and should not be
	UnLock()ed or used.  If the open fails, the lock is still usable.
	The lock associated with the file internally is of the same access
	mode as the lock you gave up - shared is similar to MODE_OLDFILE,
	exclusive is similar to MODE_NEWFILE.

   INPUTS
	lock - [Lock](autodocs-3.5/dos-library-lock-2.md) on object to be opened.

   RESULT
	fh   - Newly opened file handle or NULL for failure

   BUGS
	In the original V36 autodocs, this was shown (incorrectly) as
	taking a Mode parameter as well.  The prototypes and pragmas were
	also wrong.

   SEE ALSO
	[Open()](autodocs-3.5/dos-library-open-2.md), [Close()](autodocs-3.5/dos-library-close-2.md), [Lock()](autodocs-3.5/dos-library-lock-2.md), [UnLock()](autodocs-3.5/dos-library-unlock-2.md)

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
