---
title: dos.library/CreateDir
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-createdir-2
functions: [Lock, UnLock]
libraries: [dos.library]
---

# dos.library/CreateDir

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CreateDir -- Create a new directory

    SYNOPSIS
	lock = CreateDir( name )
	D0		  D1

	[BPTR](autodocs-3.5/include-dos-dos-h.md) CreateDir(STRPTR)

    FUNCTION
	CreateDir creates a new directory with the specified name. An error
	is returned if it fails.  Directories can only be created on
	devices which support them, e.g. disks.  CreateDir returns an
	exclusive lock on the new directory if it succeeds.

    INPUTS
	name - pointer to a null-terminated string

    RESULTS
	lock - BCPL pointer to a lock or NULL for failure.

    SEE ALSO
	[Lock()](autodocs-3.5/dos-library-lock-2.md), [UnLock()](autodocs-3.5/dos-library-unlock-2.md)

---

## See Also

- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
