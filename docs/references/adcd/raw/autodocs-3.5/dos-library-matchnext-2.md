# dos.library/MatchNext



   NAME
	MatchNext - Finds the next file or directory that matches pattern (V36)

   SYNOPSIS
	error = MatchNext(AnchorPath)
	D0                    D1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) MatchNext(struct [AnchorPath](../Includes_and_Autodocs_3._guide/node05D0.html#line51) *)

   FUNCTION
	Locates the next file or directory that matches a given pattern.
	See [<dos/dosasl.h>](../Includes_and_Autodocs_3._guide/node05D0.html) for more information.  Various bits in the flags
	allow the application to control the operation of MatchNext().

	See [MatchFirst()](../Includes_and_Autodocs_3._guide/node018D.html) for other notes.

   INPUTS
	[AnchorPath](../Includes_and_Autodocs_3._guide/node05D0.html#line51) - Place holder for search.  MUST be longword aligned!

   RESULT
	error - 0 for success or error code.  (Opposite of most Dos calls)

   BUGS
	See [MatchFirst()](../Includes_and_Autodocs_3._guide/node018D.html).

   SEE ALSO
	[MatchFirst()](../Includes_and_Autodocs_3._guide/node018D.html), [ParsePattern()](../Includes_and_Autodocs_3._guide/node019B.html), [Examine()](../Includes_and_Autodocs_3._guide/node015C.html), [CurrentDir()](../Includes_and_Autodocs_3._guide/node014E.html), [Examine()](../Includes_and_Autodocs_3._guide/node015C.html),
	[MatchEnd()](../Includes_and_Autodocs_3._guide/node018C.html), [ExNext()](../Includes_and_Autodocs_3._guide/node0160.html), [<dos/dosasl.h>](../Includes_and_Autodocs_3._guide/node05D0.html)

