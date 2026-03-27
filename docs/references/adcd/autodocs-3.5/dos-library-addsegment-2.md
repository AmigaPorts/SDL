---
title: dos.library/AddSegment
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-addsegment-2
functions: [FindSegment, LoadSeg, RemSegment]
libraries: [dos.library]
---

# dos.library/AddSegment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddSegment - Adds a resident segment to the resident list (V36)

   SYNOPSIS
	success = AddSegment(name, seglist, type)
	D0		      D1     D2      D3

	[BOOL](autodocs-3.5/include-exec-types-h.md) AddSegment(STRPTR, [BPTR](autodocs-3.5/include-dos-dos-h.md), LONG)

   FUNCTION
	Adds a segment to the Dos resident list, with the specified Seglist
	and type (stored in seg_UC - normally 0).  NOTE: currently unused
	types may cause it to interpret other registers (d4-?) as additional
	parameters in the future.

	Do NOT build [Segment](autodocs-3.5/include-dos-dosextens-h.md) structures yourself!

   INPUTS
	name    - name for the segment
	seglist - Dos seglist of code for segment
	type    - initial usecount, normally 0

   RESULT
	success - success or failure

   SEE ALSO
	[FindSegment()](autodocs-3.5/dos-library-findsegment-2.md), [RemSegment()](autodocs-3.5/dos-library-remsegment-2.md), [LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md)

---

## See Also

- [FindSegment — dos.library](../autodocs/dos.library.md#findsegment)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [RemSegment — dos.library](../autodocs/dos.library.md#remsegment)
