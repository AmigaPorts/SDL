# console.device/CMD_READ



   NAME
	CMD_READ -- return the next input from the keyboard

   FUNCTION
	[Read](../Includes_and_Autodocs_3._guide/node01A0.html) the next input, generally from the keyboard.  The form of
	this input is as an ANSI byte stream: i.e. either ASCII text
	or control sequences.  Raw input events received by the
	console device can be selectively filtered via the aSRE and aRRE
	control sequences (see the write command).  Keys are converted
	via the keymap associated with the unit, which is modified
	with AskKeyMap and SetKeyMap

	If, for example, raw keycodes had been enabled by writing
	<CSI>1{ to the console (where <CSI> is $9B or Esc[), keys
	would return raw keycode reports with the information from
	the input event itself, in the form:
	<CSI>1;0;<keycode>;<qualifiers>;0;0;<seconds>;<microseconds>q

	If there is no pending input, this command will not be
	satisfied, but if there is some input, but not as much as can
	fill io_Length, the request will be satisfied with the input
	currently available.

    IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CMD_READ
	io_Flags	IOF_QUICK if quick I/O possible, else zero
	io_Length	sizeof(*buffer)
	io_Data		char buffer[]
			a pointer to the destination for the characters to read
			from the keyboard.

   RESULTS
	This function sets the error field in the [IOStdReq](../Includes_and_Autodocs_3._guide/node0621.html#line26), and fills
	    in the io_Data area with the next input, and io_Actual with
	    the number of bytes read.

    BUGS

    SEE ALSO
	[exec/io.h](../Includes_and_Autodocs_3._guide/node0621.html), [devices/console.h](../Includes_and_Autodocs_3._guide/node0657.html)

