# exec.library/SendIO



   NAME
	SendIO -- initiate an I/O command

   SYNOPSIS
	SendIO(iORequest)
	       A1

	void SendIO(struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *);

   FUNCTION
	This function requests the device driver start processing the given
	I/O request.  The device will return control without waiting for
	the I/O to complete.

	The io_Flags field of the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) will be set to zero before the
	request is sent.  See [BeginIO()](../Includes_and_Autodocs_3._guide/node0557.html) for more details.

   INPUTS
	iORequest - pointer to an I/O request, or a device specific
		    extended [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17).

   SEE ALSO
	[DoIO()](../Includes_and_Autodocs_3._guide/node0204.html), [CheckIO()](../Includes_and_Autodocs_3._guide/node01F5.html), [WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html), [AbortIO()](../Includes_and_Autodocs_3._guide/node01D7.html)

