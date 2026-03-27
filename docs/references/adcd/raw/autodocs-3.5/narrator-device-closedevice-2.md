# narrator.device/CloseDevice



   NAME
	CloseDevice - terminates access to the narrator device


   SYNOPSIS
	CloseDevice(IORequest)
		       A1

   FUNCTION
	[Close](../Includes_and_Autodocs_3._guide/node0149.html) invalidates the IO_UNIT and IO_DEVICE fields in the
	[IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block, preventing subsequent IO until another
	[OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html).  CloseDevice also reduces the open count.  If
	the count goes to 0 and the expunge bit is set, the device
	is expunged.  If the open count goes to zero and the delayed
	expunge bit is not set, CloseDevice sets the expunge bit.


   INPUTS
	A valid [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block with its io_Message structure, and
	io_Device and io_Unit fields properly initialized.  These
	fields are initialized by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html).


   RESULTS
	CloseDevice invalidates the unit and device pointers in the
	[IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block.


   SEE ALSO

