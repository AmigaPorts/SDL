# printer.device/PRD_WRITEPREFS



   NAME
	PRD_WRITEPREFS - write the current driver prefs from a buffer (V44)

   FUNCTION
	This is a non standard write command that writes the driver
	preferences.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Command	PRD_WRITEPREFS
	io_Flags	IOB_QUICK set if quick I/O is possible
	io_Length	the length of the buffer
	io_Data		a buffer
	io_Actual	the number of bytes copied to the driver prefs.

	The printer driver checks the buffer before copying it to its
	preferences. So you don't have to worry about changing the printer
	driver between [PRD_READPREFS](../Includes_and_Autodocs_3._guide/node0512.html) and PRD_WRITEPREFS.

