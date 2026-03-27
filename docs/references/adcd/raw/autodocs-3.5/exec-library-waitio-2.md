# exec.library/WaitIO



   NAME
	WaitIO -- wait for completion of an I/O request

   SYNOPSIS
	error = WaitIO(iORequest)
	D0	       A1

	[BYTE](../Includes_and_Autodocs_3._guide/node0654.html#line48) WaitIO(struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *);

   FUNCTION
	This function waits for the specified I/O request to complete, then
	removes it from the replyport.	If the I/O has already completed,
	this function will return immediately.

	This function should be used with care, as it does not return until
	the I/O request completes; if the I/O never completes, this
	function will never return, and your task will hang.  If this
	situation is a possibility, it is safer to use the [Wait()](../Includes_and_Autodocs_3._guide/node0246.html) function.
	[Wait()](../Includes_and_Autodocs_3._guide/node0246.html) will return return when any of a specified set of signal is
	received.  This is how I/O timeouts can be properly handled.

   WARNING
	If this [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) was "Quick" or otherwise finished BEFORE this
	call, this function drops though immediately, with no call to
	[Wait()](../Includes_and_Autodocs_3._guide/node0246.html).  A side effect is that the signal bit related the port may
	remain set.  Expect this.

	When removing a known complete [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) from a port, WaitIO() is the
	preferred method.  A simple [Remove()](../Includes_and_Autodocs_3._guide/node022F.html) would require a [Disable/Enable](../Includes_and_Autodocs_3._guide/node0205.html)
	pair!

   INPUTS
	iORequest - pointer to an I/O request block

   RESULTS
	error - zero if successful, else an error is returned
		(a sign extended copy of io_Error).

   SEE ALSO
	[DoIO()](../Includes_and_Autodocs_3._guide/node0204.html), [SendIO()](../Includes_and_Autodocs_3._guide/node0236.html), [CheckIO()](../Includes_and_Autodocs_3._guide/node01F5.html), [AbortIO()](../Includes_and_Autodocs_3._guide/node01D7.html)

