---
title: dos.library/RemSegment
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-remsegment-2
functions: [AddSegment, FindSegment]
libraries: [dos.library]
---

# dos.library/RemSegment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemSegment - Removes a resident segment from the resident list (V36)

   SYNOPSIS
	success = RemSegment(segment)
	D0		        D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) RemSegment(struct [Segment](autodocs-3.5/include-dos-dosextens-h.md) *)

   FUNCTION
	Removes a resident segment from the Dos resident segment list,
	unloads it, and does any other cleanup required.  Will only succeed
	if the seg_UC (usecount) is 0.

   INPUTS
	segment - the segment to be removed

   RESULT
	success - success or failure.

   SEE ALSO
	[FindSegment()](autodocs-3.5/dos-library-findsegment-2.md), [AddSegment()](autodocs-3.5/dos-library-addsegment-2.md)

---

## See Also

- [AddSegment — dos.library](../autodocs/dos.library.md#addsegment)
- [FindSegment — dos.library](../autodocs/dos.library.md#findsegment)
