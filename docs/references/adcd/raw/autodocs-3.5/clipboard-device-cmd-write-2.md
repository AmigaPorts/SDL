# clipboard.device/CMD_WRITE



   NAME
	CMD_WRITE -- [Write](../Includes_and_Autodocs_3._guide/node01D1.html) to a clip on the clipboard.

   FUNCTION
	This command writes data to the clipboard.  This data can be
	provided sequentially by clearing io_Offset for the initial
	write, and using the incremented value unaltered for
	subsequent writes.  If io_Offset is ever beyond the current
	clip size, the clip is padded with zeros.

	If this write is in response to a [SatisfyMsg](../Includes_and_Autodocs_3._guide/node05E9.html#line56) for a pending
	post, then the io_ClipID returned by the [CBD_POST](../Includes_and_Autodocs_3._guide/node00D7.html) command must
	be used.  Otherwise, a new ID is obtained by clearing the
	io_ClipID for the first write.  Subsequent writes must not
	alter the io_ClipID.

   IO REQUEST
	io_Message	mn_ReplyPort set up
	io_Device	preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CMD_WRITE
	io_Length	number of bytes from io_Data to write
	io_Data		pointer to block of data to write
	io_Offset	usually zero if this is the initial write
	io_ClipID	zero if this is the initial write, ClipID of
			the Post if this is to satisfy a post

   RESULTS
	io_Error	non-zero if an error occurred
	io_Actual	filled with the actual number of bytes written
	io_Offset	updated to next write position
	io_ClipID	the clip ID assigned to this write: do not
			alter for subsequent writes

