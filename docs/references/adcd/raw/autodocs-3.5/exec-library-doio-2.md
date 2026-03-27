# exec.library/DoIO



   NAME
	DoIO -- perform an I/O command and wait for completion

   SYNOPSIS
	error = DoIO(iORequest)
	D0	     A1

	[BYTE](../Includes_and_Autodocs_3._guide/node0654.html#line48) DoIO(struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *);

   FUNCTION
	This function requests a device driver to perform the I/O command
	specified in the I/O request.  This function will always wait until
	the I/O request is fully complete.

	DoIO() handles all the details, including Quick I/O, waiting for
	the request, and removing the reply message, etc..

   IMPLEMENTATION
	This function first tries to complete the IO via the "Quick I/O"
	mechanism.  The io_Flags field is always set to IOF_QUICK (0x01)
	before the internal device call.

	The LN_TYPE field is used internally to flag completion.  Active
	requests have type NT_MESSAGE.  Requests that have been replied
	have type NT_REPLYMSG.  It is illegal to start IO using a
	still active [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17), or a request with type NT_REPLYMSG.

   INPUTS
	iORequest - pointer to an [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) initialized by [OpenDevice()](../Includes_and_Autodocs_3._guide/node0221.html)

   RESULTS
	error - a sign-extended copy of the io_Error field of the
		[IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17).  Most device commands require that the error
		return be checked.

   SEE ALSO
	[SendIO()](../Includes_and_Autodocs_3._guide/node0236.html), [CheckIO()](../Includes_and_Autodocs_3._guide/node01F5.html), [WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html), [AbortIO()](../Includes_and_Autodocs_3._guide/node01D7.html), [amiga.lib/BeginIO](../Includes_and_Autodocs_3._guide/node0557.html)

