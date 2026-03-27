---
title: dos.library/ParsePatternNoCase
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-parsepatternnocase-2
functions: [IoErr, MatchFirst, MatchNext, MatchPatternNoCase, ParsePattern, ParsePatternNoCase, ToUpper]
libraries: [dos.library, utility.library]
---

# dos.library/ParsePatternNoCase

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ParsePatternNoCase -- Create a tokenized string for
						[MatchPatternNoCase()](autodocs-3.5/dos-library-matchpatternnocase-2.md) (V37)

   SYNOPSIS
	IsWild = ParsePatternNoCase(Source, Dest, DestLength)
	d0                            D1     D2      D3

	[LONG](autodocs-3.5/include-exec-types-h.md) ParsePatternNoCase(STRPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), LONG)

   FUNCTION
	Tokenizes a pattern, for use by [MatchPatternNoCase()](autodocs-3.5/dos-library-matchpatternnocase-2.md).  Also indicates
	if there are any wildcards in the pattern (i.e. whether it might match
	more than one item).  Note that Dest must be at least 2 times as
	large as Source plus 2 bytes.

	For a description of the wildcards, see [ParsePattern()](autodocs-3.5/dos-library-parsepattern-2.md).

   INPUTS
	source     - unparsed wildcard string to search for.
       dest       - output string, gets tokenized version of input.
	DestLength - length available in destination (should be at least as
		     twice as large as source + 2 bytes).

   RESULT
	IsWild - 1 means there were wildcards in the pattern,
		 0 means there were no wildcards in the pattern,
		-1 means there was a buffer overflow or other error

   BUGS
	In V37 this call didn't always set [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) to something useful on an
	error.  Fixed in V39.
	In V37, it didn't properly convert character-classes ([x-y]) to
	upper case.  Workaround: convert the input pattern to upper case
	using [ToUpper()](autodocs-3.5/utility-library-toupper-2.md) from utility.library before calling
	ParsePatternNoCase().  Fixed in V39 dos.

   SEE ALSO
	[ParsePattern()](autodocs-3.5/dos-library-parsepattern-2.md), [MatchPatternNoCase()](autodocs-3.5/dos-library-matchpatternnocase-2.md), [MatchFirst()](autodocs-3.5/dos-library-matchfirst-2.md), [MatchNext()](autodocs-3.5/dos-library-matchnext-2.md),
	[utility.library/ToUpper()](autodocs-3.5/utility-library-toupper-2.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [MatchFirst — dos.library](../autodocs/dos.library.md#matchfirst)
- [MatchNext — dos.library](../autodocs/dos.library.md#matchnext)
- [MatchPatternNoCase — dos.library](../autodocs/dos.library.md#matchpatternnocase)
- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
- [ParsePatternNoCase — dos.library](../autodocs/dos.library.md#parsepatternnocase)
- [ToUpper — utility.library](../autodocs/utility.library.md#toupper)
