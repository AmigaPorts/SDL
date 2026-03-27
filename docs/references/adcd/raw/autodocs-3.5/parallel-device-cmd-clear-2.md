# parallel.device/CMD_CLEAR



   NAME
	Clear -- clear the parallel port buffer

   FUNCTION
	This command just RTS's (no buffer to clear)

   IO REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit         set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command      CMD_CLEAR (05)

