# exec.library/CheckIO



   NAME
	CheckIO -- get the status of an [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17)

   SYNOPSIS
	result = CheckIO(IORequest)
	D0		 A1

	struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *CheckIO(struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *);

   FUNCTION
	This function determines the current state of an I/O request and
	returns FALSE if the I/O has not yet completed.  This function
	effectively hides the internals of the I/O completion mechanism.

	CheckIO() will NOT remove the returned [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) from the reply port.
	This is best performed with [WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html). If the request has already
	completed, [WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html) will return quickly. Use of the [Remove()](../Includes_and_Autodocs_3._guide/node022F.html)
	function is dangerous, since other tasks may still be adding things
	to your message port; a [Disable()](../Includes_and_Autodocs_3._guide/node0203.html) would be required.

	This function should NOT be used to busy loop (looping until IO is
	complete).  [WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html) is provided for that purpose.

   INPUTS
	iORequest - pointer to an I/O request block

   RESULTS
	result - NULL if I/O is still in progress.  Otherwise
		 D0 points to the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block.

   NOTE
	CheckIO can hang if called on an [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) that has never been used.
	This occurs if LN_TYPE of the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) is set to "NT_MESSAGE".
	Instead simply set LN_TYPE to 0.

   SEE ALSO
	[DoIO()](../Includes_and_Autodocs_3._guide/node0204.html), [SendIO()](../Includes_and_Autodocs_3._guide/node0236.html), [WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html), [AbortIO()](../Includes_and_Autodocs_3._guide/node01D7.html)

