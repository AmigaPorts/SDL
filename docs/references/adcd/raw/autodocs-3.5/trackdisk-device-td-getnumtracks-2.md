# trackdisk.device/TD_GETNUMTRACKS



   NAME
	TD_GETNUMTRACKS -- return the number of tracks for the type of disk
			   drive for the unit that was opened.

   FUNCTION
	This command returns the number of tracks that are available
	on the disk unit.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	TD_GETNUMTRACKS
	io_Flags	0 or IOF_QUICK

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)
	io_Actual - if io_Error is 0 this contains the drive type connected to
		    this unit.

   SEE ALSO
	[TD_GETDRIVETYPE](../Includes_and_Autodocs_3._guide/node0587.html)

