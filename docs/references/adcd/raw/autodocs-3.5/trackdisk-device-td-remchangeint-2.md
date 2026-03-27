# trackdisk.device/TD_REMCHANGEINT



   NAME
	TD_REMCHANGEINT -- remove a disk change software interrupt handler.

   FUNCTION
	This command removes a disk change software interrupt added
	by a previous use of [TD_ADDCHANGEINT](../Includes_and_Autodocs_3._guide/node0582.html).

   IO REQUEST INPUT
	The same IO request used for [TD_ADDCHANGEINT](../Includes_and_Autodocs_3._guide/node0582.html).

	io_Device	preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	TD_REMCHANGEINT
	io_Flags	0
	io_Length	sizeof(struct Interrupt)
	io_Data		pointer to [Interrupt](../Includes_and_Autodocs_3._guide/node061D.html#line21) structure

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)

   BUGS
	This command did not function properly under versions of Kickstart
	earlier than V36. A valid workaround under these older versions of
	Kickstart is:

		Forbid();
		Remove(ioRequest);
		Permit();

	Do not use this workaround in versions of Kickstart >= V36, use
	TD_REMCHANGEINT instead (for future compatibility with V38+).

   SEE ALSO
	[TD_ADDCHANGEINT](../Includes_and_Autodocs_3._guide/node0582.html), [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)

