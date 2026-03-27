# printer.device/CMD_INVALID



   NAME
	CMD_INVALID -- invalid command

   FUNCTION
	CMD_INVALID is always an invalid command, and sets the device
	error appropriately.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Command	CMD_INVALID
	io_Flags	IOB_QUICK set if quick I/O is possible

