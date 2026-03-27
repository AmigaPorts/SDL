# printer.device/CMD_FLUSH



   NAME
	CMD_FLUSH -- abort all I/O requests (immediate)

   FUNCTION
	CMD_FLUSH aborts all stopped I/O at the unit.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CMD_FLUSH
	io_Flags	IOB_QUICK set if quick I/O is possible

