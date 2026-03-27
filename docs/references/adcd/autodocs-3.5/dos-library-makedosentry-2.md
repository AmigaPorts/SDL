---
title: dos.library/MakeDosEntry
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-makedosentry-2
functions: [AddDosEntry, AllocDosObject, FindDosEntry, LockDosList, NextDosEntry, RemDosEntry]
libraries: [dos.library]
---

# dos.library/MakeDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MakeDosEntry -- Creates a [DosList](autodocs-3.5/include-dos-dosextens-h.md) structure (V36)

   SYNOPSIS
	newdlist = MakeDosEntry(name, type)
	D0                       D1    D2

	struct [DosList](autodocs-3.5/include-dos-dosextens-h.md) *MakeDosEntry(STRPTR, LONG)

   FUNCTION
	Create a [DosList](autodocs-3.5/include-dos-dosextens-h.md) structure, including allocating a name and correctly
	null-terminating the BSTR.  It also sets the dol_Type field, and sets
	all other fields to 0.  This routine should be eliminated and replaced
	by a value passed to AllocDosObject()!

   INPUTS
	name - name for the device/volume/assign node.
	type - type of node.

   RESULT
	newdlist - The new device entry or NULL.

   SEE ALSO
	[AddDosEntry()](autodocs-3.5/dos-library-adddosentry-2.md), [RemDosEntry()](autodocs-3.5/dos-library-remdosentry-2.md), [FindDosEntry()](autodocs-3.5/dos-library-finddosentry-2.md), [LockDosList()](autodocs-3.5/dos-library-lockdoslist-2.md),
	[NextDosEntry()](autodocs-3.5/dos-library-nextdosentry-2.md), [FreeDosEntry()](autodocs-3.5/dos-library-freedosentry-2.md)

---

## See Also

- [AddDosEntry — dos.library](../autodocs/dos.library.md#adddosentry)
- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [FindDosEntry — dos.library](../autodocs/dos.library.md#finddosentry)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
- [RemDosEntry — dos.library](../autodocs/dos.library.md#remdosentry)
