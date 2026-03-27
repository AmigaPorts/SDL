# trackdisk.device/CMD_CLEAR



   NAME
	CMD_CLEAR/ETD_CLEAR -- mark the track buffer as containing invalid
			       data.

   FUNCTION
	These commands mark the track buffer as invalid, forcing a
	reread of the disk on the next operation. ETD_UPDATE or [CMD_UPDATE](../Includes_and_Autodocs_3._guide/node0580.html)
	would be used to force data out to the disk before turning the motor
	off. ETD_CLEAR or CMD_CLEAR are usually used after having locked out
	the trackdisk.device via the use of the disk resource, when you
	wish to prevent the track from being updated, or when you wish to
	force the track to be re-read. ETD_CLEAR or CMD_CLEAR will not do an
	update, nor will an update command do a clear.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CMD_CLEAR or ETD_CLEAR
	io_Flags	0 or IOF_QUICK
	iotd_Count	(ETD_CLEAR only) maximum allowable change counter
			value.

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)

   SEE ALSO
	[CMD_WRITE](../Includes_and_Autodocs_3._guide/node0581.html), [CMD_UPDATE](../Includes_and_Autodocs_3._guide/node0580.html)

