# timer.device/AbortIO



   NAME
	AbortIO -- [Remove](../Includes_and_Autodocs_3._guide/node022F.html) an existing timer request.

   SYNOPSIS
	error = AbortIO( [timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39) )
	D0               A1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) AbortIO( struct [timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39) * );

   FUNCTION
	This is an exec.library call.

	This routine removes a timerquest from the timer.  It runs in
	the context of the caller.

   INPUTS
	[timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39) - the timer request to be aborted

   RETURNS
	0  if the request was aborted, io_Error will also be set to
	    IOERR_ABORTED.
	-1 otherwise

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	exec.library/AbortIO()

   BUGS

