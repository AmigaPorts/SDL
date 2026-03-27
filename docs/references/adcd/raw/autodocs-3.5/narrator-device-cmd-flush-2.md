# narrator.device/CMD_FLUSH



   NAME
	CMD_FLUSH - Aborts all inprogress and queued requests


   SYNOPSIS
	Standard device command.


   FUNCTION
	Aborts all inprogress and queued speech requests.


   INPUTS
	Valid [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block with the io_Command field set to CMD_FLUSH.
	A valid [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block is one with its io_Message structure, and
	io_Device and io_Unit fields properly initialized.  The easiest
	way to insure proper initialization is to make a copy of the
	[IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block after a successful [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html) call.


   RESULTS
	io_Error in [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block set to 0


   SEE ALSO
  	Exec input/output documentation.

