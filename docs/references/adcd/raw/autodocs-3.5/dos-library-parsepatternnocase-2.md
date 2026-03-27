# dos.library/ParsePatternNoCase



   NAME
	ParsePatternNoCase -- Create a tokenized string for
						[MatchPatternNoCase()](../Includes_and_Autodocs_3._guide/node0190.html) (V37)

   SYNOPSIS
	IsWild = ParsePatternNoCase(Source, Dest, DestLength)
	d0                            D1     D2      D3

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) ParsePatternNoCase(STRPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), LONG)

   FUNCTION
	Tokenizes a pattern, for use by [MatchPatternNoCase()](../Includes_and_Autodocs_3._guide/node0190.html).  Also indicates
	if there are any wildcards in the pattern (i.e. whether it might match
	more than one item).  Note that Dest must be at least 2 times as
	large as Source plus 2 bytes.

	For a description of the wildcards, see [ParsePattern()](../Includes_and_Autodocs_3._guide/node019B.html).

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
	In V37 this call didn't always set [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) to something useful on an
	error.  Fixed in V39.
	In V37, it didn't properly convert character-classes ([x-y]) to
	upper case.  Workaround: convert the input pattern to upper case
	using [ToUpper()](../Includes_and_Autodocs_3._guide/node05B4.html) from utility.library before calling
	ParsePatternNoCase().  Fixed in V39 dos.

   SEE ALSO
	[ParsePattern()](../Includes_and_Autodocs_3._guide/node019B.html), [MatchPatternNoCase()](../Includes_and_Autodocs_3._guide/node0190.html), [MatchFirst()](../Includes_and_Autodocs_3._guide/node018D.html), [MatchNext()](../Includes_and_Autodocs_3._guide/node018E.html),
	[utility.library/ToUpper()](../Includes_and_Autodocs_3._guide/node05B4.html)

