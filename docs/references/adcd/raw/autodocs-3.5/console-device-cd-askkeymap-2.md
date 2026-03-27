# console.device/CD_ASKKEYMAP



   NAME
	CD_ASKKEYMAP -- Get the current key map structure for this console.

    FUNCTION
	Fill the io_Data buffer with the current [KeyMap](../Includes_and_Autodocs_3._guide/node0623.html#line20) structure in
	use by this console unit.

    IO REQUEST INPUT
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CD_ASKKEYMAP
	io_Flags	IOF_QUICK if quick I/O possible, else zero
	io_Length	sizeof(*keyMap)
	io_Data		struct [KeyMap](../Includes_and_Autodocs_3._guide/node0623.html#line20) *keyMap
			pointer to a structure that describes
			the raw keycode to byte stream conversion.

    IO REQUEST RESULT
	This function sets the io_Error field in the [IOStdReq](../Includes_and_Autodocs_3._guide/node0621.html#line26), and fills
	the structure the structure pointed to by io_Data with the current
	 key map.

    SEE ALSO
	[exec/io.h](../Includes_and_Autodocs_3._guide/node0621.html), [devices/keymap.h](../Includes_and_Autodocs_3._guide/node0623.html), [devices/console.h](../Includes_and_Autodocs_3._guide/node0657.html)

