# trackdisk.device/TD_GETDRIVETYPE



   NAME
	TD_GETDRIVETYPE -- return the type of disk drive for the unit that was
			   opened.

   FUNCTION
	This command returns the type of the disk drive to the user.
	This number will be a small integer and will come from the set of
	DRIVEXXX constants defined in [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html).

	The only way you can actually use this command is if the trackdisk
	device understands the drive type of the hardware that is plugged in.
	This is because the [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html) call will fail if the trackdisk device
	does not understand the drive type. To find raw drive identifiers see
	the disk.resource's DR_GETUNITID entry point.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	TD_GETDRIVETYPE
	io_Flags	0 or IOF_QUICK

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)
	io_Actual - if io_Error is 0 this contains the drive type connected to
		    this unit.

   SEE ALSO
	[TD_GETNUMTRACKS](../Includes_and_Autodocs_3._guide/node0589.html), [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)

