# trackdisk.device/CMD_WRITE



   NAME
	CMD_WRITE/ETD_WRITE -- write sectors of data to a disk.

   FUNCTION
	These commands transfer data from a supplied buffer to the track
	buffer. If the track that contains this sector is already in the track
	buffer, no disk activity is initiated. If the desired sector is not in
	the buffer, the track containing that sector is automatically read in.
	If the data in the current track buffer has been modified, it is
	written out to the disk before the new track is read in for
	modification. ETD_WRITE will write the sector label area if
	iotd_SecLabel is non-NULL.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CMD_WRITE or ETD_WRITE
	io_Flags	0 or IOF_QUICK
	io_Data		pointer to the buffer where the data should be put
	io_Length	number of bytes to write, must be a multiple of
			TD_SECTOR.
	io_Offset	byte offset from the start of the disk describing
			where to write data to, must be a multiple of
			TD_SECTOR.
	iotd_Count	(ETD_WRITE only) maximum allowable change counter
			value.
	iotd_SecLabel	(ETD_WRITE only) NULL or sector label buffer pointer.
			If provided, the buffer must be a multiple of
			TD_LABELSIZE.

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)

   NOTES
	Under versions of Kickstart earlier than V36, the io_Data had to
	point to a buffer in chip memory. This restriction is no longer
	present as of Kickstart V36 and beyond.

   SEE ALSO
	[CMD_READ](../Includes_and_Autodocs_3._guide/node057F.html), [TD_FORMAT](../Includes_and_Autodocs_3._guide/node0586.html)

