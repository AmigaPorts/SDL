---
title: exec.library/RemSemaphore
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-remsemaphore-2
functions: [AddSemaphore, FindSemaphore]
libraries: [exec.library]
---

# exec.library/RemSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemSemaphore -- remove a signal semaphore from the system

   SYNOPSIS
	RemSemaphore(signalSemaphore)
		     A1

	void RemSemaphore(struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *);

   FUNCTION
	This function removes a signal semaphore structure from the
	system's signal semaphore list.  Subsequent attempts to
	rendezvous by name with this semaphore will fail.

   INPUTS

       signalSemaphore -- an initialized signal semaphore structure
   SEE ALSO
	[AddSemaphore()](autodocs-3.5/exec-library-addsemaphore-2.md), [FindSemaphore()](autodocs-3.5/exec-library-findsemaphore-2.md)

---

## See Also

- [AddSemaphore — exec.library](../autodocs/exec.library.md#addsemaphore)
- [FindSemaphore — exec.library](../autodocs/exec.library.md#findsemaphore)
