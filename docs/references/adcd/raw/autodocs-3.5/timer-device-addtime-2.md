# timer.device/AddTime



   NAME
	AddTime -- Add one time request to another.

   SYNOPSIS
	AddTime( Dest, Source )
	         A0    A1

	void AddTime( struct [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) *, struct [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) *);

   FUNCTION
	This routine adds one [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structure to another.  The
	results are stored in the destination (Dest + Source -> Dest)

	A0 and A1 will be left unchanged

   INPUTS
	Dest, Source -- pointers to [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structures.

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	[timer.device/CmpTime()](../Includes_and_Autodocs_3._guide/node0576.html),
	[timer.device/SubTime()](../Includes_and_Autodocs_3._guide/node0579.html)

   BUGS

