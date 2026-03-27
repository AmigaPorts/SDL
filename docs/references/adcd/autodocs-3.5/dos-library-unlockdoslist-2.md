---
title: dos.library/UnLockDosList
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-unlockdoslist-2
functions: [AttemptLockDosList, LockDosList, Permit]
libraries: [dos.library, exec.library]
---

# dos.library/UnLockDosList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	UnLockDosList -- Unlocks the Dos [List](autodocs-3.5/include-exec-lists-h.md) (V36)

   SYNOPSIS
	UnLockDosList(flags)
			D1

	void UnLockDosList(ULONG)

   FUNCTION
	Unlocks the access on the Dos [Device](autodocs-3.5/include-exec-devices-h.md) [List](autodocs-3.5/include-exec-lists-h.md).  You MUST pass the same
	flags you used to lock the list.

   INPUTS
	flags - MUST be the same flags passed to (Attempt)LockDosList()

   SEE ALSO
	[AttemptLockDosList()](autodocs-3.5/dos-library-attemptlockdoslist-2.md), [LockDosList()](autodocs-3.5/dos-library-lockdoslist-2.md), [Permit()](autodocs-3.5/exec-library-permit-2.md)

---

## See Also

- [AttemptLockDosList — dos.library](../autodocs/dos.library.md#attemptlockdoslist)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
