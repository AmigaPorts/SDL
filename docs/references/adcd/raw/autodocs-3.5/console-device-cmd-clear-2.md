# console.device/CMD_CLEAR



    NAME
	CMD_CLEAR -- Clear console input buffer.

    FUNCTION
	[Remove](../Includes_and_Autodocs_3._guide/node022F.html) from the console input buffer any reports waiting to
	satisfy read requests.

    IO REQUEST INPUT
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CMD_CLEAR
	io_Flags	IOB_QUICK set if quick I/O is possible, else 0

    SEE ALSO
	[exec/io.h](../Includes_and_Autodocs_3._guide/node0621.html), [devices/console.h](../Includes_and_Autodocs_3._guide/node0657.html)

