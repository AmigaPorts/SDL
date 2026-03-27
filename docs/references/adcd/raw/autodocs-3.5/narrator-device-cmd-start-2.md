# narrator.device/CMD_START




   NAME
	CMD_START - Restarts the device after a [CMD_STOP](../Includes_and_Autodocs_3._guide/node04D7.html) command


   SYNOPSIS
	Standard device command.


   FUNCTION
	CMD_START restarts the currently active speech (if any)	and
	allows queued requests to start.


   INPUTS
	Valid [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block with the io_Command field set to CMD_START
	A valid [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block is one with its io_Message structure, and
	io_Device and io_Unit fields properly initialized.  The easiest
	way to insure proper initialization is to make a copy of the
	[IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block after a successful [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html) call.


   RESULTS
	io_Error set to 0.


   SEE ALSO
	Exec input/output documentation.

