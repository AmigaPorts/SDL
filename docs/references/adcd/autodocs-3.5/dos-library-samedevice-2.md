---
title: dos.library/SameDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-samedevice-2
functions: [SameDevice]
libraries: [dos.library]
---

# dos.library/SameDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SameDevice -- Are two locks are on partitions of the device? (V37)

   SYNOPSIS
	same = SameDevice(lock1, lock2)
	D0		   D1     D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) SameDevice( [BPTR](autodocs-3.5/include-dos-dos-h.md), [BPTR](autodocs-3.5/include-dos-dos-h.md) )

   FUNCTION
	SameDevice() returns whether two locks refer to partitions that
	are on the same physical device (if it can figure it out).  This
	may be useful in writing copy routines to take advantage of
	asynchronous multi-device copies.

	Entry existed in V36 and always returned 0.

   INPUTS
	lock1,lock2 - locks

   RESULT
	same - whether they're on the same device as far as Dos can determine.

---

## See Also

- [SameDevice — dos.library](../autodocs/dos.library.md#samedevice)
