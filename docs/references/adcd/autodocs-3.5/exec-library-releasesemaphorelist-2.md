---
title: exec.library/ReleaseSemaphoreList
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-releasesemaphorelist-2
functions: [ObtainSemaphoreList, ReleaseSemaphoreList]
libraries: [exec.library]
---

# exec.library/ReleaseSemaphoreList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReleaseSemaphoreList -- make a list of semaphores available

   SYNOPSIS
	ReleaseSemaphoreList(list)
			     A0

	void ReleaseSemaphoreList(struct [List](autodocs-3.5/include-exec-lists-h.md) *);

   FUNCTION
	ReleaseSemaphoreList() is the inverse of [ObtainSemaphoreList()](autodocs-3.5/exec-library-obtainsemaphorelist-2.md). It
	releases each element in the semaphore list.

	Needless to say, havoc breaks out if the task releases more times
	than it has obtained.

   INPUT

       list -- a list of signal semaphores
   SEE ALSO
	[ObtainSemaphoreList()](autodocs-3.5/exec-library-obtainsemaphorelist-2.md)

---

## See Also

- [ObtainSemaphoreList — exec.library](../autodocs/exec.library.md#obtainsemaphorelist)
- [ReleaseSemaphoreList — exec.library](../autodocs/exec.library.md#releasesemaphorelist)
