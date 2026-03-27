# dos.library/FindArg



   NAME
	FindArg - find a keyword in a template (V36)

   SYNOPSIS
	index = FindArg(template, keyword)
	D0                D1        D2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) FindArg(STRPTR, STRPTR)

   FUNCTION
	Returns the argument number of the keyword, or -1 if it is not a
	keyword for the template.  Abbreviations are handled.

   INPUTS
	keyword  - keyword to search for in template
	template - template string to search

   RESULT
	index - number of entry in template, or -1 if not found

   BUGS
	In earlier published versions of the autodoc, keyword and template
	were backwards.

   SEE ALSO
	[ReadArgs()](../Includes_and_Autodocs_3._guide/node01A1.html), [ReadItem()](../Includes_and_Autodocs_3._guide/node01A2.html), [FreeArgs()](../Includes_and_Autodocs_3._guide/node016F.html)

