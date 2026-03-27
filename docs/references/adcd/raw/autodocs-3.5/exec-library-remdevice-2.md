# exec.library/RemDevice



   NAME
	RemDevice -- remove a device from the system

   SYNOPSIS
	RemDevice(device)
	          A1

	void RemDevice(struct [Device](../Includes_and_Autodocs_3._guide/node05FB.html#line23) *);

   FUNCTION
	This function calls the device's EXPUNGE vector, which requests
	that a device delete itself.  The device may refuse to do this if
	it is busy or currently open. This is not typically called by user
	code.

	There are certain, limited circumstances where it may be
	appropriate to attempt to specifically flush a certain device.
	Example:

	 /* Attempts to flush the named device out of memory. */
	 #include [<exec/types.h>](../Includes_and_Autodocs_3._guide/node0654.html)
	 #include [<exec/execbase.h>](../Includes_and_Autodocs_3._guide/node0609.html)

	 void FlushDevice(name)
	 [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) name;
	 {
	 struct [Device](../Includes_and_Autodocs_3._guide/node05FB.html#line23) *result;

	    Forbid();
	    if(result=(struct [Device](../Includes_and_Autodocs_3._guide/node05FB.html#line23) *)FindName(&SysBase->DeviceList,name))
		RemDevice(result);
	    Permit();
	 }

   INPUTS
	device - pointer to a device node

   SEE ALSO
	[AddLibrary()](../Includes_and_Autodocs_3._guide/node01DB.html)

