# parallel.device/CMD_STOP



   NAME
	Stop -- pause current activity on the parallel device

   FUNCTION
	This command halts the current I/O activity on the parallel
	device by discontinuing the handshaking sequence. The stop and
	start commands may not be nested.

   IO REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit         set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command      CMD_STOP (06)

   SEE ALSO
	[parallel.device/CMD_START](../Includes_and_Autodocs_3._guide/node04F1.html)

