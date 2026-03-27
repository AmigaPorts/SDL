---
title: dos.library/NextDosEntry
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-nextdosentry-2
functions: [AddDosEntry, FindDosEntry, LockDosList, RemDosEntry]
libraries: [dos.library]
---

# dos.library/NextDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	NextDosEntry -- Get the next Dos [List](autodocs-3.5/include-exec-lists-h.md) entry (V36)

   SYNOPSIS
	newdlist = NextDosEntry(dlist,flags)
	D0                       D1    D2

	struct [DosList](autodocs-3.5/include-dos-dosextens-h.md) *NextDosEntry(struct [DosList](autodocs-3.5/include-dos-dosextens-h.md) *,ULONG)

   FUNCTION
	Find the next Dos [List](autodocs-3.5/include-exec-lists-h.md) entry of the right type.  You MUST have locked
	the types you're looking for.  Returns NULL if there are no more of
	that type in the list.

   INPUTS
	dlist    - The current device entry.
	flags	 - What type of entries to look for.

   RESULT
	newdlist - The next device entry of the right type or NULL.

   SEE ALSO
	[AddDosEntry()](autodocs-3.5/dos-library-adddosentry-2.md), [RemDosEntry()](autodocs-3.5/dos-library-remdosentry-2.md), [FindDosEntry()](autodocs-3.5/dos-library-finddosentry-2.md), [LockDosList()](autodocs-3.5/dos-library-lockdoslist-2.md),
	[MakeDosEntry()](autodocs-3.5/dos-library-makedosentry-2.md), [FreeDosEntry()](autodocs-3.5/dos-library-freedosentry-2.md)

---

## See Also

- [AddDosEntry — dos.library](../autodocs/dos.library.md#adddosentry)
- [FindDosEntry — dos.library](../autodocs/dos.library.md#finddosentry)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [RemDosEntry — dos.library](../autodocs/dos.library.md#remdosentry)
