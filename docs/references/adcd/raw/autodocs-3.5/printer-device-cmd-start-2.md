# printer.device/CMD_START



   NAME
	CMD_START -- restart after stop (immediate)

   FUNCTION
	CMD_START restarts the unit after a stop command.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CMD_START
	io_Flags	IOB_QUICK set if quick I/O is possible

