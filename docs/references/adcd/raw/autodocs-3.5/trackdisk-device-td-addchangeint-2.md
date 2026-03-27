# trackdisk.device/TD_ADDCHANGEINT



   NAME
	TD_ADDCHANGEINT -- add a disk change software interrupt handler.

   FUNCTION
	This command lets you add a software interrupt handler to the
	disk device that gets invoked whenever a disk insertion or removal
	occurs.

	You must pass in a properly initialized Exec [Interrupt](../Includes_and_Autodocs_3._guide/node061D.html#line21) structure
	and be prepared to deal with disk insertions/removals
	immediately. From within the interrupt handler, you may only call the
	status commands that can use IOF_QUICK.

	To set up the handler, an [Interrupt](../Includes_and_Autodocs_3._guide/node061D.html#line21) structure must be initialized.
	This structure is supplied as the io_Data to the TD_ADDCHANGEINT
	command. The handler then gets linked into the handler chain and
	gets invoked whenever a disk change happens. You must eventually
	remove the handler before you exit.

	This command only returns when the handler is removed. That is,
	the device holds onto the IO request until the [TD_REMCHANGEINT](../Includes_and_Autodocs_3._guide/node058E.html) command
	is executed with that same IO request. Hence, you must use [SendIO()](../Includes_and_Autodocs_3._guide/node0236.html)
	with this command.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	TD_ADDCHANGEINT
	io_Flags	0
	io_Length	sizeof(struct Interrupt)
	io_Data		pointer to [Interrupt](../Includes_and_Autodocs_3._guide/node061D.html#line21) structure

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)

   SEE ALSO
	[TD_REMCHANGEINT](../Includes_and_Autodocs_3._guide/node058E.html), [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html), [<exec/interrupts.h>](../Includes_and_Autodocs_3._guide/node061D.html),
	[exec.library/Cause()](../Includes_and_Autodocs_3._guide/node01F4.html)

