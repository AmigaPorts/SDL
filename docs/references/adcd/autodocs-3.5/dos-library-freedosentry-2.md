---
title: dos.library/FreeDosEntry
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-freedosentry-2
functions: [AddDosEntry, FindDosEntry, FreeDosObject, LockDosList, NextDosEntry, RemDosEntry]
libraries: [dos.library]
---

# dos.library/FreeDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeDosEntry -- Frees an entry created by [MakeDosEntry](autodocs-3.5/dos-library-makedosentry-2.md) (V36)

   SYNOPSIS
	FreeDosEntry(dlist)
	               D1

	void FreeDosEntry(struct [DosList](autodocs-3.5/include-dos-dosextens-h.md) *)

   FUNCTION
	Frees an entry created by [MakeDosEntry()](autodocs-3.5/dos-library-makedosentry-2.md).  This routine should be
	eliminated and replaced by a value passed to FreeDosObject()!

   INPUTS
	dlist - [DosList](autodocs-3.5/include-dos-dosextens-h.md) to free.

   SEE ALSO
	[AddDosEntry()](autodocs-3.5/dos-library-adddosentry-2.md), [RemDosEntry()](autodocs-3.5/dos-library-remdosentry-2.md), [FindDosEntry()](autodocs-3.5/dos-library-finddosentry-2.md), [LockDosList()](autodocs-3.5/dos-library-lockdoslist-2.md),
	[NextDosEntry()](autodocs-3.5/dos-library-nextdosentry-2.md), [MakeDosEntry()](autodocs-3.5/dos-library-makedosentry-2.md)

---

## See Also

- [AddDosEntry — dos.library](../autodocs/dos.library.md#adddosentry)
- [FindDosEntry — dos.library](../autodocs/dos.library.md#finddosentry)
- [FreeDosObject — dos.library](../autodocs/dos.library.md#freedosobject)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
- [RemDosEntry — dos.library](../autodocs/dos.library.md#remdosentry)
