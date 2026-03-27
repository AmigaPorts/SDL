# narrator.device/AbortIO



   NAME
	AbortIO - Abort an IO request


   SYNOPSIS
	AbortIO(IORequest)
		   A1


   FUNCTION
	Exec library call to abort a specified READ or WRITE request.
	The [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) may be in the queue or currently active.  If
	currently active, the request is immediately stopped and then
	removed.


   INPUTS
	Pointer to the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block to be aborted.


   RESULTS
	io_Error field in the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block set to #IOERR_ABORTED.


   SEE ALSO

