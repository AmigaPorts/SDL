---
title: dos.library/FindDosEntry
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-finddosentry-2
functions: [AddDosEntry, LockDosList, NextDosEntry, RemDosEntry]
libraries: [dos.library]
---

# dos.library/FindDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindDosEntry -- Finds a specific Dos [List](autodocs-3.5/include-exec-lists-h.md) entry (V36)

   SYNOPSIS
	newdlist = FindDosEntry(dlist,name,flags)
	D0                       D1    D2   D3

	struct [DosList](autodocs-3.5/include-dos-dosextens-h.md) *FindDosEntry(struct [DosList](autodocs-3.5/include-dos-dosextens-h.md) *,[STRPTR](autodocs-3.5/include-exec-types-h.md),ULONG)

   FUNCTION
	Locates an entry on the device list.  Starts with the entry dlist.
	NOTE: must be called with the device list locked, no references may be
	made to dlist after unlocking.

   INPUTS
	dlist    - The device entry to start with.
	name     - Name of device entry (without ':') to locate.
	flags    - Search control flags.  Use the flags you passed to
		   [LockDosList](autodocs-3.5/dos-library-lockdoslist-2.md), or a subset of them.  LDF_READ/LDF_WRITE are
		   not required for this call.

   RESULT
	newdlist - The device entry or NULL

   SEE ALSO
	[AddDosEntry()](autodocs-3.5/dos-library-adddosentry-2.md), [RemDosEntry()](autodocs-3.5/dos-library-remdosentry-2.md), [NextDosEntry()](autodocs-3.5/dos-library-nextdosentry-2.md), [LockDosList()](autodocs-3.5/dos-library-lockdoslist-2.md),
	[MakeDosEntry()](autodocs-3.5/dos-library-makedosentry-2.md), [FreeDosEntry()](autodocs-3.5/dos-library-freedosentry-2.md)

---

## See Also

- [AddDosEntry — dos.library](../autodocs/dos.library.md#adddosentry)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
- [RemDosEntry — dos.library](../autodocs/dos.library.md#remdosentry)
