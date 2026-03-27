# dos.library/RemSegment



   NAME
	RemSegment - Removes a resident segment from the resident list (V36)

   SYNOPSIS
	success = RemSegment(segment)
	D0		        D1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) RemSegment(struct [Segment](../Includes_and_Autodocs_3._guide/node05D9.html#line298) *)

   FUNCTION
	Removes a resident segment from the Dos resident segment list,
	unloads it, and does any other cleanup required.  Will only succeed
	if the seg_UC (usecount) is 0.

   INPUTS
	segment - the segment to be removed

   RESULT
	success - success or failure.

   SEE ALSO
	[FindSegment()](../Includes_and_Autodocs_3._guide/node0168.html), [AddSegment()](../Includes_and_Autodocs_3._guide/node013D.html)

