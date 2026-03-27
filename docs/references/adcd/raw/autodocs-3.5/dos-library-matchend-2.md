# dos.library/MatchEnd



   NAME
	MatchEnd -- Free storage allocated for [MatchFirst()/MatchNext()](../Includes_and_Autodocs_3._guide/node018E.html) (V36)

   SYNOPSIS
	MatchEnd(AnchorPath)
	             D1

	VOID MatchEnd(struct [AnchorPath](../Includes_and_Autodocs_3._guide/node05D0.html#line51) *)

   FUNCTION
	Return all storage associated with a given search.

   INPUTS
	[AnchorPath](../Includes_and_Autodocs_3._guide/node05D0.html#line51) - Anchor used for [MatchFirst()/MatchNext()](../Includes_and_Autodocs_3._guide/node018E.html)
		     MUST be longword aligned!

   SEE ALSO
	[MatchFirst()](../Includes_and_Autodocs_3._guide/node018D.html), [ParsePattern()](../Includes_and_Autodocs_3._guide/node019B.html), [Examine()](../Includes_and_Autodocs_3._guide/node015C.html), [CurrentDir()](../Includes_and_Autodocs_3._guide/node014E.html), [Examine()](../Includes_and_Autodocs_3._guide/node015C.html),
	[MatchNext()](../Includes_and_Autodocs_3._guide/node018E.html), [ExNext()](../Includes_and_Autodocs_3._guide/node0160.html), [<dos/dosasl.h>](../Includes_and_Autodocs_3._guide/node05D0.html)

