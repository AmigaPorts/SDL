---
title: D / Errors / Disk Icon Won't Go Away
manual: libraries
chapter: libraries
section: d-errors-disk-icon-won-t-go-away
functions: [Lock, UnLock]
libraries: [dos.library]
---

# D / Errors / Disk Icon Won't Go Away

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This occurs when a program leaves a [Lock()](autodocs-2.0/dos-library-lock.md) on one or more of a disk's
files or directories.  A memory loss of exactly 24 bytes is usually Lock()
which has not been [UnLock()](autodocs-2.0/dos-library-unlock.md)ed.

---

## See Also

- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
