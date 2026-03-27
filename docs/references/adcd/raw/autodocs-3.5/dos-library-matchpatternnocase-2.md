# dos.library/MatchPatternNoCase



   NAME
	MatchPatternNoCase --  Checks for a pattern match with a string (V37)

   SYNOPSIS
	match = MatchPatternNoCase(pat, str)
	D0                         D1   D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) MatchPatternNoCase(STRPTR, STRPTR)

   FUNCTION
	Checks for a pattern match with a string.  The pattern must be a
	tokenized string output by [ParsePatternNoCase()](../Includes_and_Autodocs_3._guide/node019C.html).  This routine is
	case-insensitive.

	NOTE: this routine is highly recursive.  You must have at least
	1500 free bytes of stack to call this (it will cut off it's
	recursion before going any deeper than that and return failure).
	That's _currently_ enough for about 100 levels deep of #, (, ~, etc.

   INPUTS
	pat - Special pattern string to match as returned by [ParsePatternNoCase()](../Includes_and_Autodocs_3._guide/node019C.html)
	str - String to match against given pattern

   RESULT
	match - success or failure of pattern match.  On failure,
		[IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) will return 0 or ERROR_TOO_MANY_LEVELS (starting
		with V37 - before that there was no stack checking).

   BUGS
	See [ParsePatternNoCase()](../Includes_and_Autodocs_3._guide/node019C.html).

   SEE ALSO
	[ParsePatternNoCase()](../Includes_and_Autodocs_3._guide/node019C.html), [MatchPattern()](../Includes_and_Autodocs_3._guide/node018F.html), [MatchFirst()](../Includes_and_Autodocs_3._guide/node018D.html), [MatchNext()](../Includes_and_Autodocs_3._guide/node018E.html)

