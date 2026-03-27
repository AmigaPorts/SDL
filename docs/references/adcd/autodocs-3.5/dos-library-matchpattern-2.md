---
title: dos.library/MatchPattern
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-matchpattern-2
functions: [IoErr, MatchFirst, MatchNext, MatchPatternNoCase, ParsePattern]
libraries: [dos.library]
---

# dos.library/MatchPattern

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MatchPattern --  Checks for a pattern match with a string (V36)

   SYNOPSIS
	match = MatchPattern(pat, str)
	D0                   D1   D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) MatchPattern(STRPTR, STRPTR)

   FUNCTION
	Checks for a pattern match with a string.  The pattern must be a
	tokenized string output by [ParsePattern()](autodocs-3.5/dos-library-parsepattern-2.md).  This routine is
	case-sensitive.

	NOTE: this routine is highly recursive.  You must have at least
	1500 free bytes of stack to call this (it will cut off it's
	recursion before going any deeper than that and return failure).
	That's _currently_ enough for about 100 levels deep of #, (, ~, etc.

   INPUTS
	pat - Special pattern string to match as returned by [ParsePattern()](autodocs-3.5/dos-library-parsepattern-2.md)
	str - String to match against given pattern

   RESULT
	match - success or failure of pattern match.  On failure,
		[IoErr()](autodocs-3.5/dos-library-ioerr-2.md) will return 0 or ERROR_TOO_MANY_LEVELS (starting
		with V37 - before that there was no stack checking).

   SEE ALSO
	[ParsePattern()](autodocs-3.5/dos-library-parsepattern-2.md), [MatchPatternNoCase()](autodocs-3.5/dos-library-matchpatternnocase-2.md), [MatchFirst()](autodocs-3.5/dos-library-matchfirst-2.md), [MatchNext()](autodocs-3.5/dos-library-matchnext-2.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [MatchFirst — dos.library](../autodocs/dos.library.md#matchfirst)
- [MatchNext — dos.library](../autodocs/dos.library.md#matchnext)
- [MatchPatternNoCase — dos.library](../autodocs/dos.library.md#matchpatternnocase)
- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
