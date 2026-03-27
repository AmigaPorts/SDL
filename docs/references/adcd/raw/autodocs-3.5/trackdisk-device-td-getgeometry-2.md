# trackdisk.device/TD_GETGEOMETRY



   NAME

       TD_GETGEOMETRY -- return the geometry of the drive.
   FUNCTION
	This command returns a full set of information about the
	layout of the drive. The information is returned in the
	[DriveGeometry](../Includes_and_Autodocs_3._guide/node0604.html#line134) structure pointed to by io_Data.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	TD_GETGEOMETRY
	io_Flags	0 or IOF_QUICK
	io_Data		Pointer to a [DriveGeometry](../Includes_and_Autodocs_3._guide/node0604.html#line134) structure
	io_Length	sizeof(struct DriveGeometry)

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)

   NOTE
	This information may change when a disk in inserted when
	certain hardware is present.

   SEE ALSO
	[TD_GETDRIVETYPE](../Includes_and_Autodocs_3._guide/node0587.html), [TD_GETNUMTRACKS](../Includes_and_Autodocs_3._guide/node0589.html)

