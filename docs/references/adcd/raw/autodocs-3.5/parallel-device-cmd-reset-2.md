# parallel.device/CMD_RESET



   NAME
	Reset -- reinitializes the parallel device

   FUNCTION
	This command resets the parallel device to its freshly initialized
	condition. It aborts all I/O requests both queued and current and
	sets the devices's flags and parameters to their boot-up time
	default values. At boot-up time the PTermArray is random, and it
	will be so also here.

   IO REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit         set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command      CMD_RESET (01)

   RESULTS
	Error -- if the Reset succeded, then io_Error will be null.
	         if the Reset failed, then the io_Error will be non-zero.

