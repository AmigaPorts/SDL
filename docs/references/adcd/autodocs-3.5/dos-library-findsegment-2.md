---
title: dos.library/FindSegment
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-findsegment-2
functions: [AddSegment, Forbid, RemSegment]
libraries: [dos.library, exec.library]
---

# dos.library/FindSegment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindSegment - Finds a segment on the resident list (V36)

   SYNOPSIS
	segment = FindSegment(name, start, system)
	D0		       D1     D2     D3

	struct [Segment](autodocs-3.5/include-dos-dosextens-h.md) *FindSegment(STRPTR, struct [Segment](autodocs-3.5/include-dos-dosextens-h.md) *, LONG)

   FUNCTION
	Finds a segment on the Dos resident list by name and type, starting
	at the segment AFTER 'start', or at the beginning if start is NULL.
	If system is zero, it will only return nodes with a seg_UC of 0
	or more.  It does NOT increment the seg_UC, and it does NOT do any
	locking of the list.  You must [Forbid()](autodocs-3.5/exec-library-forbid-2.md) lock the list to use this
	call.

	To use an entry you have found, you must: if the seg_UC is 0 or more,
	increment it, and decrement it (under Forbid()!) when you're done
	the the seglist.

	The other values for seg_UC are:
		-1   - system module, such as a filesystem or shell
		-2   - resident shell command
		-999 - disabled internal command, ignore
	Negative values should never be modified.  All other negative
	values between 0 and -32767 are reserved to AmigaDos and should not
	be used.

   INPUTS
	name   - name of segment to find
	start  - segment to start the search after
	system - true for system segment, false for normal segments

   RESULT
	segment - the segment found or NULL

   SEE ALSO
	[AddSegment()](autodocs-3.5/dos-library-addsegment-2.md), [RemSegment()](autodocs-3.5/dos-library-remsegment-2.md), [Forbid()](autodocs-3.5/exec-library-forbid-2.md)

---

## See Also

- [AddSegment — dos.library](../autodocs/dos.library.md#addsegment)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [RemSegment — dos.library](../autodocs/dos.library.md#remsegment)
