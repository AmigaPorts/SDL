# parallel.device/CMD_WRITE



   NAME
	[Write](../Includes_and_Autodocs_3._guide/node01D1.html) -- send output to parallel port

   FUNCTION
	This command causes a stream of characters to be written to the
	parallel output register. The number of characters is specified in
	io_Length, unless -1 is used, in which case output is sent until
	a zero byte occurs in the data. This is independent of, and may be
	used simultaneously with setting the EOFMODE in io_ParFlags and using
	the PTermArray to terminate the read or write.

   IO REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit         set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command      CMD_WRITE (03)
	io_Flags        If IOF_QUICK is set, driver will attempt Quick IO
	io_Length       number of characters to transmit, or if set
	                to -1 send until zero byte encountered
	io_Data         pointer to block of data to transmit

   RESULTS
	io_Error -- If the [Write](../Includes_and_Autodocs_3._guide/node01D1.html) succeded, then io_Error will be null.
	     If the [Write](../Includes_and_Autodocs_3._guide/node01D1.html) failed, then io_Error will contain an error code.

   SEE ALSO
	[parallel.device/PDCMD_SETPARAMS](../Includes_and_Autodocs_3._guide/node04F6.html)

