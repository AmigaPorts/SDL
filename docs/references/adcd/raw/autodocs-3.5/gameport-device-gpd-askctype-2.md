# gameport.device/GPD_ASKCTYPE



   NAME
	GPD_ASKCTYPE -- Acquire the current game port controller type

   FUNCTION
	This command identifies the type of controller at the game
	port, so that the signals at the port may be properly
	interpreted.  The controller type has been set by a previous
	SetCType.

	This command always executes immediately.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	GPD_ASKCTYPE
	io_Flags	IOB_QUICK set if quick I/O is possible
	io_Length	at least 1
	io_Data		the address of the byte variable for the
			result

