# printer.device/CMD_RESET



   NAME
	CMD_RESET -- reset the printer

   FUNCTION
	CMD_RESET resets the printer device without destroying handles
	to the open device.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CMD_RESET
	io_Flags	IOB_QUICK set if quick I/O is possible

