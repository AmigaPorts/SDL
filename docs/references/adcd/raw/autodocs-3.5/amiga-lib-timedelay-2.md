# amiga.lib/TimeDelay



   NAME
	TimeDelay -- Return after a period of time has elapsed.

   SYNOPSIS
	Error = TimeDelay( [Unit](../Includes_and_Autodocs_3._guide/node05FB.html#line30), Seconds, MicroSeconds )
	D0                 D0    D1       D2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) TimeDelay( [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), ULONG, ULONG );

   FUNCTION
	Waits for the period of time specified before returning to the
	the caller.

   INPUTS
	[Unit](../Includes_and_Autodocs_3._guide/node05FB.html#line30) -- timer.device unit to open for this command.
	Seconds -- The seconds field of a [timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39) is filled with
	    this value. Check the documentation for what a particular
	    timer.device unit expects there.
	MicroSeconds -- The microseconds field of a [timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39) is
	    filled with this value. Check the documentation for what
	    a particular timer.device units expects there.

   RESULTS
	Error -- will be zero if all went well; otherwise, non-zero.

   NOTES
	Two likely reasons for failures are invalid unit numbers or
	no more free signal bits for this task.

	While this function first appears in V37 amiga.lib, it works
	on Kickstart V33 and higher.

   SEE ALSO
	[timer.device/TR_ADDREQUEST](../Includes_and_Autodocs_3._guide/node057A.html),
	timer.device/TR_WAITUNTIL,
	timer.device/WaitUnitl()

   BUGS

