---
title: dos.library/MatchNext
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-matchnext-2
functions: [MatchEnd, MatchFirst, MatchNext, ParsePattern]
libraries: [dos.library]
---

# dos.library/MatchNext

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MatchNext - Finds the next file or directory that matches pattern (V36)

   SYNOPSIS
	error = MatchNext(AnchorPath)
	D0                    D1

	[LONG](autodocs-3.5/include-exec-types-h.md) MatchNext(struct [AnchorPath](autodocs-3.5/include-dos-dosasl-h.md) *)

   FUNCTION
	Locates the next file or directory that matches a given pattern.
	See [<dos/dosasl.h>](autodocs-3.5/include-dos-dosasl-h.md) for more information.  Various bits in the flags
	allow the application to control the operation of MatchNext().

	See [MatchFirst()](autodocs-3.5/dos-library-matchfirst-2.md) for other notes.

   INPUTS
	[AnchorPath](autodocs-3.5/include-dos-dosasl-h.md) - Place holder for search.  MUST be longword aligned!

   RESULT
	error - 0 for success or error code.  (Opposite of most Dos calls)

   BUGS
	See [MatchFirst()](autodocs-3.5/dos-library-matchfirst-2.md).

   SEE ALSO
	[MatchFirst()](autodocs-3.5/dos-library-matchfirst-2.md), [ParsePattern()](autodocs-3.5/dos-library-parsepattern-2.md), [Examine()](autodocs-3.5/dos-library-examine-2.md), [CurrentDir()](autodocs-3.5/dos-library-currentdir-2.md), [Examine()](autodocs-3.5/dos-library-examine-2.md),
	[MatchEnd()](autodocs-3.5/dos-library-matchend-2.md), [ExNext()](autodocs-3.5/dos-library-exnext-2.md), [<dos/dosasl.h>](autodocs-3.5/include-dos-dosasl-h.md)

---

## See Also

- [MatchEnd — dos.library](../autodocs/dos.library.md#matchend)
- [MatchFirst — dos.library](../autodocs/dos.library.md#matchfirst)
- [MatchNext — dos.library](../autodocs/dos.library.md#matchnext)
- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
