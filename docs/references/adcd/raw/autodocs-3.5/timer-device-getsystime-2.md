# timer.device/GetSysTime



   NAME
	GetSysTime -- Get the system time. (V36)

   SYNOPSIS
	GetSysTime( Dest )
	            A0

	void GetSysTime( struct [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) * );

   FUNCTION
	Ask the system what time it is.  The system time starts off at
	zero at power on, but may be initialized via the [TR_SETSYSTIME](../Includes_and_Autodocs_3._guide/node057C.html)
	timer.device command.

	System time is monotonocally increasing and guarenteed to be
	unique (except when the system time is set back).

	A0 will be left unchanged.

	This function is less expensive to use than the [TR_GETSYSTIME](../Includes_and_Autodocs_3._guide/node057B.html)
	[IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17).

   INPUTS
	Dest -- pointer to a [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structure to hold the system time.

   RESULTS
	Dest -- the [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structure will contain the system time.

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	[timer.device/TR_GETSYSTIME](../Includes_and_Autodocs_3._guide/node057B.html),
	[timer.device/TR_SETSYSTIME](../Includes_and_Autodocs_3._guide/node057C.html),

   BUGS

