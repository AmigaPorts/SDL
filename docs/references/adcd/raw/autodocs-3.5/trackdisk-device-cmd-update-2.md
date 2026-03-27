# trackdisk.device/CMD_UPDATE



   NAME
	CMD_UPDATE/ETD_UPDATE -- write out the track buffer if it is dirty.

   FUNCTION
	The trackdisk device does not write data sectors unless it is
	necessary (you request that a different track be used) or until the
	user requests that an update be performed. This improves system speed
	by caching disk operations. These commands ensure that any
	buffered data is flushed out to the disk. If the track buffer has not
	been changed since the track was read in, these commands do nothing.
	ETD_UPDATE command checks for diskchange.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CMD_UPDATE or ETD_UPDATE
	io_Flags	0 or IOF_QUICK
	iotd_Count	(ETD_UPDATE only) maximum allowable change counter
			value.

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)

   SEE ALSO
	[CMD_WRITE](../Includes_and_Autodocs_3._guide/node0581.html)

