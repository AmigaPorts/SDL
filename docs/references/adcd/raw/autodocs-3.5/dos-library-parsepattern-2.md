# dos.library/ParsePattern



   NAME
	ParsePattern -- Create a tokenized string for [MatchPattern()](../Includes_and_Autodocs_3._guide/node018F.html) (V36)

   SYNOPSIS
	IsWild = ParsePattern(Source, Dest, DestLength)
	d0                      D1     D2      D3

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) ParsePattern(STRPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), LONG)

   FUNCTION
	Tokenizes a pattern, for use by [MatchPattern()](../Includes_and_Autodocs_3._guide/node018F.html).  Also indicates if
	there are any wildcards in the pattern (i.e. whether it might match
	more than one item).  Note that Dest must be at least 2 times as
	large as Source plus bytes to be (almost) 100% certain of no
	buffer overflow.  This is because each input character can currently
	expand to 2 tokens (with one exception that can expand to 3, but
	only once per string).  Note: this implementation may change in
	the future, so you should handle error returns in all cases, but
	the size above should still be a reasonable upper bound for a buffer
	allocation.

	The patterns are fairly extensive, and approximate some of the ability
	of Unix/grep "regular expression" patterns.  Here are the available
	tokens:

	?	Matches a single character.
	#	Matches the following expression 0 or more times.
	(ab|cd)	Matches any one of the items seperated by '|'.
	~	Negates the following expression.  It matches all strings
		that do not match the expression (aka ~(foo) matches all
		strings that are not exactly "foo").
	[abc]	Character class: matches any of the characters in the class.
	[~bc]	Character class: matches any of the characters not in the
		class.
	a-z	Character range (only within character classes).
	%	Matches 0 characters always (useful in "(foo|bar|%)").
	*	Synonym for "#?", not available by default in 2.0.  Available
		as an option that can be turned on.

	"Expression" in the above table means either a single character
	(ex: "#?"), or an alternation (ex: "#(ab|cd|ef)"), or a character
	class (ex: "#[a-zA-Z]").

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

   SEE ALSO
	[ParsePatternNoCase()](../Includes_and_Autodocs_3._guide/node019C.html), [MatchPattern()](../Includes_and_Autodocs_3._guide/node018F.html), [MatchFirst()](../Includes_and_Autodocs_3._guide/node018D.html), [MatchNext()](../Includes_and_Autodocs_3._guide/node018E.html)

