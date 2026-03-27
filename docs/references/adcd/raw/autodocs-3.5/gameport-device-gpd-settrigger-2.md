# gameport.device/GPD_SETTRIGGER



   NAME
	GPD_SETTRIGGER -- Set the conditions for a game port report

   FUNCTION
	This command sets what conditions must be met by a game
	port unit before a pending [Read](../Includes_and_Autodocs_3._guide/node01A0.html) request will be satisfied.
	These conditions, called triggers, are independent -- that
	any one occurs is sufficient to queue a game port report to
	the [Read](../Includes_and_Autodocs_3._guide/node01A0.html) queue.	 These conditions are inquired with
	AskTrigger.

	This command always executes immediately.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	GPD_SETTRIGGER
	io_Flags	IOB_QUICK set if quick I/O is possible
	io_Length	sizeof(gamePortTrigger)
	io_Data		a structure of type [GamePortTrigger](../Includes_and_Autodocs_3._guide/node060F.html#line35), which
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

