# amiga.lib/BeginIO



   NAME
	BeginIO -- initiate asynchronous device I/O

   SYNOPSIS
	BeginIO(ioReq)

	VOID BeginIO(struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *);

   FUNCTION
	This function takes an [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17), and passes it directly to the
	"BeginIO" vector of the proper device.  This is equivalent to
	[SendIO()](../Includes_and_Autodocs_3._guide/node0236.html), except that io_Flags is not cleared. A good understanding
	of Exec device I/O is required to properly use this function.

	This function does not wait for the I/O to complete.

   INPUTS
	ioReq - an initialized and opened [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) structure with the
	        io_Flags field set to a reasonable value (set to 0 if you do
		not require io_Flags).

   SEE ALSO
	[exec.library/DoIO()](../Includes_and_Autodocs_3._guide/node0204.html), [exec.library/SendIO()](../Includes_and_Autodocs_3._guide/node0236.html), [exec.library/WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html)

