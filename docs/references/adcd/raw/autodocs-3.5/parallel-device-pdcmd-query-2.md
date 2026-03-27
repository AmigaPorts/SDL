# parallel.device/PDCMD_QUERY



   NAME
	Query -- query parallel port/line status

   FUNCTION
	This command return the status of the parallel port lines and
	registers.

   IO REQUEST
	io_Message      must have mn_ReplyPort initialized
	io_Device       set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit         set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command      PDCMD_QUERY (09)

   RESULTS
	io_Status        BIT  ACTIVE  FUNCTION

	                 0     high   printer busy toggle (offline)
	                 1     high   paper out
	                 2     high   printer selected on the A1000
	                              printer selected & serial "Ring
	                              Indicator" on the A500/A2000
	                              Use care when making cables.
	                 3      -     read=0,write=1
	               4-7            reserved

   BUGS
	In a earlier version of this AutoDoc, BUSY and PSEL were reversed.
	The function has always been correct.

