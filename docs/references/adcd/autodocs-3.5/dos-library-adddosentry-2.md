---
title: dos.library/AddDosEntry
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-adddosentry-2
functions: [AttemptLockDosList, FindDosEntry, LockDosList, NextDosEntry, RemDosEntry]
libraries: [dos.library]
---

# dos.library/AddDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddDosEntry -- Add a Dos [List](autodocs-3.5/include-exec-lists-h.md) entry to the lists (V36)

   SYNOPSIS
	success = AddDosEntry(dlist)
	D0                     D1

	[LONG](autodocs-3.5/include-exec-types-h.md) AddDosEntry(struct [DosList](autodocs-3.5/include-dos-dosextens-h.md) *)

   FUNCTION
	Adds a device, volume or assign to the dos devicelist.  Can fail if it
	conflicts with an existing entry (such as another assign to the same
	name or another device of the same name).  Volume nodes with different
	dates and the same name CAN be added, or with names that conflict with
	devices or assigns.  Note: the dos list does NOT have to be locked to
	call this.  Do not access dlist after adding unless you have locked the
	Dos [Device](autodocs-3.5/include-exec-devices-h.md) list.

	An additional note concerning calling this from within a handler:
	in order to avoid deadlocks, your handler must either be multi-
	threaded, or it must attempt to lock the list before calling this
	function.  The code would look something like this:

	if (AttemptLockDosList(LDF_xxx|LDF_WRITE))
	{
		rc = AddDosEntry(...);
		UnLockDosList(LDF_xxx|LDF_WRITE);
	}

	If [AttemptLockDosList()](autodocs-3.5/dos-library-attemptlockdoslist-2.md) fails (i.e. it's locked already), check for
	messages at your filesystem port (don't wait!) and try the
	[AttemptLockDosList()](autodocs-3.5/dos-library-attemptlockdoslist-2.md) again.

   INPUTS
	dlist   - [Device](autodocs-3.5/include-exec-devices-h.md) list entry to be added.

   RESULT
	success - Success/Failure indicator

   SEE ALSO
	[RemDosEntry()](autodocs-3.5/dos-library-remdosentry-2.md), [FindDosEntry()](autodocs-3.5/dos-library-finddosentry-2.md), [NextDosEntry()](autodocs-3.5/dos-library-nextdosentry-2.md), [LockDosList()](autodocs-3.5/dos-library-lockdoslist-2.md),
	[MakeDosEntry()](autodocs-3.5/dos-library-makedosentry-2.md), [FreeDosEntry()](autodocs-3.5/dos-library-freedosentry-2.md), [AttemptLockDosList()](autodocs-3.5/dos-library-attemptlockdoslist-2.md)

---

## See Also

- [AttemptLockDosList — dos.library](../autodocs/dos.library.md#attemptlockdoslist)
- [FindDosEntry — dos.library](../autodocs/dos.library.md#finddosentry)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
- [RemDosEntry — dos.library](../autodocs/dos.library.md#remdosentry)
