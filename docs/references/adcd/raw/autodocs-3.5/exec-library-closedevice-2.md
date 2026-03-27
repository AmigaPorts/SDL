# exec.library/CloseDevice



   NAME
	CloseDevice -- conclude access to a device

   SYNOPSIS
	CloseDevice(iORequest)
		    A1

	void CloseDevice(struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *);

   FUNCTION
	This function informs the device that access to a device/unit
	previously opened has been concluded.  The device may perform
	certain house-cleaning operations.

	The user must ensure that all outstanding IORequests have been
	returned before closing the device.  The [AbortIO](../Includes_and_Autodocs_3._guide/node0574.html) function can kill
	any stragglers.

	After a close, the I/O request structure is free to be reused.
	Starting with V36 exec it is safe to CloseDevice() with an
	[IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) that is either cleared to zeros, or failed to
	open.

   INPUTS
	iORequest - pointer to an I/O request structure

   SEE ALSO
	[OpenDevice()](../Includes_and_Autodocs_3._guide/node0221.html)

