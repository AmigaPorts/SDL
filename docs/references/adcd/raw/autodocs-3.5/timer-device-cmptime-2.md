# timer.device/CmpTime



   NAME
	CmpTime -- Compare two [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structures.

   SYNOPSIS
	result = CmpTime( Dest, Source )
	D0                A0    A1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) CmpTime( struct [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) *, struct [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) *);

   FUNCTION
	This routine compares [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structures

	A0 and A1 will be left unchanged

   INPUTS
	Dest, Source -- pointers to [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structures.

   RESULTS
	result will be   0 if Dest has same time as source
	                -1 if Dest has more time than source
	                +1 if Dest has less time than source

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	[timer.device/AddTime()](../Includes_and_Autodocs_3._guide/node0575.html),
	[timer.device/SubTime()](../Includes_and_Autodocs_3._guide/node0579.html)

   BUGS
	Older version of this document had the sense of the return
	codes wrong; the code hasn't changed but the document has.

