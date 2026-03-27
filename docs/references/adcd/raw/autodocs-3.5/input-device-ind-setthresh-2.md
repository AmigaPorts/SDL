# input.device/IND_SETTHRESH



   NAME
	IND_SETTHRESH -- Set the key repeat threshold

   FUNCTION
	This command sets the time that a key must be held down before
	it can repeat.  The repeatability of a key may be restricted
	(as, for example, are the shift keys).

	This command always executes immediately.

   IO REQUEST - a timerequest
	tr_node.io_Message	mn_ReplyPort set if quick I/O is not possible
	tr_node.io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	tr_node.io_Unit		preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	tr_node.io_Command	IND_SETTHRESH
	tr_node.io_Flags	IOB_QUICK set if quick I/O is possible
	tr_time.tv_secs		the threshold seconds
	tr_time.tv_micro	the threshold microseconds

