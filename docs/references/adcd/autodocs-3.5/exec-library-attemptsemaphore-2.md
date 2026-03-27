---
title: exec.library/AttemptSemaphore
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-attemptsemaphore-2
functions: [ObtainSemaphore, ObtainSemaphoreShared, ReleaseSemaphore]
libraries: [exec.library]
---

# exec.library/AttemptSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AttemptSemaphore -- try to obtain without blocking

   SYNOPSIS
	success = AttemptSemaphore(signalSemaphore)
	D0			   A0

	[LONG](autodocs-3.5/include-exec-types-h.md) AttemptSemaphore(struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *);

   FUNCTION
	This call is similar to [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md), except that it will not
	block if the semaphore could not be locked.

   INPUT

       signalSemaphore -- an initialized signal semaphore structure
   RESULT
	success -- TRUE if the semaphore was locked, false if some
	    other task already possessed the semaphore.

    NOTE
	This call does NOT preserve registers.

   SEE ALSO
	[ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md) [ObtainSemaphoreShared()](autodocs-3.5/exec-library-obtainsemaphoreshared-2.md), [ReleaseSemaphore()](autodocs-3.5/exec-library-releasesemaphore-2.md),
	[exec/semaphores.h](autodocs-3.5/include-exec-semaphores-h.md)

---

## See Also

- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)
