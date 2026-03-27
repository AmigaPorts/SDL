---
title: dos.library/MatchEnd
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-matchend-2
functions: [MatchFirst, MatchNext, ParsePattern]
libraries: [dos.library]
---

# dos.library/MatchEnd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MatchEnd -- Free storage allocated for [MatchFirst()/MatchNext()](autodocs-3.5/dos-library-matchnext-2.md) (V36)

   SYNOPSIS
	MatchEnd(AnchorPath)
	             D1

	VOID MatchEnd(struct [AnchorPath](autodocs-3.5/include-dos-dosasl-h.md) *)

   FUNCTION
	Return all storage associated with a given search.

   INPUTS
	[AnchorPath](autodocs-3.5/include-dos-dosasl-h.md) - Anchor used for [MatchFirst()/MatchNext()](autodocs-3.5/dos-library-matchnext-2.md)
		     MUST be longword aligned!

   SEE ALSO
	[MatchFirst()](autodocs-3.5/dos-library-matchfirst-2.md), [ParsePattern()](autodocs-3.5/dos-library-parsepattern-2.md), [Examine()](autodocs-3.5/dos-library-examine-2.md), [CurrentDir()](autodocs-3.5/dos-library-currentdir-2.md), [Examine()](autodocs-3.5/dos-library-examine-2.md),
	[MatchNext()](autodocs-3.5/dos-library-matchnext-2.md), [ExNext()](autodocs-3.5/dos-library-exnext-2.md), [<dos/dosasl.h>](autodocs-3.5/include-dos-dosasl-h.md)

---

## See Also

- [MatchFirst — dos.library](../autodocs/dos.library.md#matchfirst)
- [MatchNext — dos.library](../autodocs/dos.library.md#matchnext)
- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
