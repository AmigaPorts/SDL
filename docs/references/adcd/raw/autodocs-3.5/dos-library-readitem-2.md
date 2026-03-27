# dos.library/ReadItem



   NAME
	ReadItem - reads a single argument/name from command line (V36)

   SYNOPSIS
	value = ReadItem(buffer, maxchars, input)
	D0                D1        D2      D3

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) ReadItem(STRPTR, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), struct [CSource](../Includes_and_Autodocs_3._guide/node05F5.html#line60) *)

   FUNCTION
	Reads a "word" from either [Input()](../Includes_and_Autodocs_3._guide/node017F.html) (buffered), or via [CSource](../Includes_and_Autodocs_3._guide/node05F5.html#line60), if it
	is non-NULL (see [<dos/rdargs.h>](../Includes_and_Autodocs_3._guide/node05F5.html) for more information).  Handles
	quoting and some '*' substitutions (*e and *n) inside quotes (only).
	See [dos/dos.h](../Includes_and_Autodocs_3._guide/node05F8.html) for a listing of values returned by ReadItem()
	(ITEM_XXXX).  A "word" is delimited by whitespace, quotes, '=', or
	an EOF.

	ReadItem always unreads the last thing read (UnGetC(fh,-1)) so the
	caller can find out what the terminator was.

   INPUTS
	buffer   - buffer to store word in.
	maxchars - size of the buffer
	input    - [CSource](../Includes_and_Autodocs_3._guide/node05F5.html#line60) input or NULL (uses FGetC(Input()))

   RESULT
	value - See [<dos/dos.h>](../Includes_and_Autodocs_3._guide/node05F8.html) for return values.

   BUGS
	Doesn't actually unread the terminator.

   SEE ALSO
	[ReadArgs()](../Includes_and_Autodocs_3._guide/node01A1.html), [FindArg()](../Includes_and_Autodocs_3._guide/node0165.html), [UnGetC()](../Includes_and_Autodocs_3._guide/node01C6.html), [FGetC()](../Includes_and_Autodocs_3._guide/node0162.html), [Input()](../Includes_and_Autodocs_3._guide/node017F.html), [<dos/dos.h>](../Includes_and_Autodocs_3._guide/node05F8.html),
	[<dos/rdargs.h>](../Includes_and_Autodocs_3._guide/node05F5.html), [FreeArgs()](../Includes_and_Autodocs_3._guide/node016F.html)

