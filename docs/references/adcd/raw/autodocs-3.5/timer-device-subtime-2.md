# timer.device/SubTime



   NAME
	SubTime -- Subtract one time request from another.

   SYNOPSIS
	SubTime( Dest, Source )
	         A0    A1

	void SubTime( struct [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) *, struct [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) *);

   FUNCTION
	This routine subtracts one [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structure from another.  The
	results are stored in the destination (Dest - Source -> Dest)

	A0 and A1 will be left unchanged

   INPUTS
	Dest, Source -- pointers to [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structures.

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	[timer.device/AddTime()](../Includes_and_Autodocs_3._guide/node0575.html),
	[timer.device/CmpTime()](../Includes_and_Autodocs_3._guide/node0576.html)

   BUGS

