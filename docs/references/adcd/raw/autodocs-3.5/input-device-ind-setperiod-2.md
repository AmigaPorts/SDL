# input.device/IND_SETPERIOD



   NAME
	IND_SETPERIOD -- Set the key repeat period

   FUNCTION
	This command sets the period at which a repeating key repeats.

	This command always executes immediately.

   IO REQUEST - a timerequest
	tr_node.io_Message	mn_ReplyPort set if quick I/O is not possible
	tr_node.io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	tr_node.io_Unit		preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	tr_node.io_Command	IND_SETPERIOD
	tr_node.io_Flags	IOB_QUICK set if quick I/O is possible
	tr_time.tv_secs		the repeat period seconds
	tr_time.tv_micro	the repeat period microseconds

