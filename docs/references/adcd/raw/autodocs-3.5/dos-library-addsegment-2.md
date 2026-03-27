# dos.library/AddSegment



   NAME
	AddSegment - Adds a resident segment to the resident list (V36)

   SYNOPSIS
	success = AddSegment(name, seglist, type)
	D0		      D1     D2      D3

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) AddSegment(STRPTR, [BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129), LONG)

   FUNCTION
	Adds a segment to the Dos resident list, with the specified Seglist
	and type (stored in seg_UC - normally 0).  NOTE: currently unused
	types may cause it to interpret other registers (d4-?) as additional
	parameters in the future.

	Do NOT build [Segment](../Includes_and_Autodocs_3._guide/node05D9.html#line298) structures yourself!

   INPUTS
	name    - name for the segment
	seglist - Dos seglist of code for segment
	type    - initial usecount, normally 0

   RESULT
	success - success or failure

   SEE ALSO
	[FindSegment()](../Includes_and_Autodocs_3._guide/node0168.html), [RemSegment()](../Includes_and_Autodocs_3._guide/node01A7.html), [LoadSeg()](../Includes_and_Autodocs_3._guide/node0185.html)

