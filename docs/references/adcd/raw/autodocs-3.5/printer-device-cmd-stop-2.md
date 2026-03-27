# printer.device/CMD_STOP



   NAME
	CMD_STOP -- pause current and queued I/O requests (immediate)

   FUNCTION
	CMD_STOP pauses all queued requests for the unit, and tries to
	pause the current I/O request.  The only commands that will
	be subsequently allowed to be performed are immediate I/O
	requests, which include those to start, flush, and finish the
	I/O after the stop command.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CMD_STOP
	io_Flags	IOB_QUICK set if quick I/O is possible

