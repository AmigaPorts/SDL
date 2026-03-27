# exec.library/AddDevice



   NAME
	AddDevice -- add a device to the system

   SYNOPSIS
	AddDevice(device)
		  A1

	void AddDevice(struct [Device](../Includes_and_Autodocs_3._guide/node05FB.html#line23) *);

   FUNCTION
	This function adds a new device to the system device list, making
	it available to other programs.  The device must be ready to be
	opened at this time.

   INPUTS
	device - pointer to a properly initialized device node

   SEE ALSO
	[RemDevice()](../Includes_and_Autodocs_3._guide/node022A.html), [OpenDevice()](../Includes_and_Autodocs_3._guide/node0221.html), [CloseDevice()](../Includes_and_Autodocs_3._guide/node01F6.html), [MakeLibrary()](../Includes_and_Autodocs_3._guide/node021B.html)

