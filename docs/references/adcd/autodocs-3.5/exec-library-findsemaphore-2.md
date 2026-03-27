---
title: exec.library/FindSemaphore
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-findsemaphore-2
functions: [Forbid, Permit]
libraries: [exec.library]
---

# exec.library/FindSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindSemaphore -- find a given system signal semaphore

   SYNOPSIS
	signalSemaphore = FindSemaphore(name)
	D0		                A1

	struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *FindSemaphore(STRPTR);

   FUNCTION
	This function will search the system signal semaphore list for a
	semaphore with the given name.	The first semaphore matching this
	name will be returned.

	This function does not arbitrate for access to the semaphore list,
	surround the call with a [Forbid()/Permit()](autodocs-3.5/exec-library-permit-2.md) pair.

   INPUT
	name - name of the semaphore to find

   RESULT
	semaphore - a pointer to the signal semaphore, or zero if not
		    found.

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
