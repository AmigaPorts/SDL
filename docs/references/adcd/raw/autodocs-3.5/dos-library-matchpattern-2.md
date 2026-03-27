# dos.library/MatchPattern



   NAME
	MatchPattern --  Checks for a pattern match with a string (V36)

   SYNOPSIS
	match = MatchPattern(pat, str)
	D0                   D1   D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) MatchPattern(STRPTR, STRPTR)

   FUNCTION
	Checks for a pattern match with a string.  The pattern must be a
	tokenized string output by [ParsePattern()](../Includes_and_Autodocs_3._guide/node019B.html).  This routine is
	case-sensitive.

	NOTE: this routine is highly recursive.  You must have at least
	1500 free bytes of stack to call this (it will cut off it's
	recursion before going any deeper than that and return failure).
	That's _currently_ enough for about 100 levels deep of #, (, ~, etc.

   INPUTS
	pat - Special pattern string to match as returned by [ParsePattern()](../Includes_and_Autodocs_3._guide/node019B.html)
	str - String to match against given pattern

   RESULT
	match - success or failure of pattern match.  On failure,
		[IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) will return 0 or ERROR_TOO_MANY_LEVELS (starting
		with V37 - before that there was no stack checking).

   SEE ALSO
	[ParsePattern()](../Includes_and_Autodocs_3._guide/node019B.html), [MatchPatternNoCase()](../Includes_and_Autodocs_3._guide/node0190.html), [MatchFirst()](../Includes_and_Autodocs_3._guide/node018D.html), [MatchNext()](../Includes_and_Autodocs_3._guide/node018E.html)

