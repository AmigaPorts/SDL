# input.device/IND_SETMTRIG



   NAME
	IND_SETMTRIG -- Set the conditions for a mouse port report

   FUNCTION
	This command sets what conditions must be met by a mouse
	before a pending [Read](../Includes_and_Autodocs_3._guide/node01A0.html) request will be satisfied.  The trigger
	specification is that used by the gameport device.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	IND_SETMTRIG
	io_Flags	IOB_QUICK set if quick I/O is possible
	io_Length	sizeof(gameportTrigger)
	io_Data		a structure of type GameportTrigger, which
			has the following elements
	    gpt_Keys -
		    GPTB_DOWNKEYS set if button down transitions
		    trigger a report, and GPTB_UPKEYS set if button up
		    transitions trigger a report
	    gpt_Timeout	-
		    a time which, if exceeded, triggers a report;
		    measured in vertical blank units (60/sec)
	    gpt_XDelta	-
		    a distance in x which, if exceeded, triggers a
		    report
	    gpt_YDelta	-
		    a distance in x which, if exceeded, triggers a
		    report

