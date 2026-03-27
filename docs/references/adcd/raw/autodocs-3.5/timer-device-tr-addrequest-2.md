# timer.device/TR_ADDREQUEST



   NAME
	TR_ADDREQUEST -- Submit a request to wait a period of time.

   FUNCTION
	Ask the timer to wait a specified amount of time before
	replying the [timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39).

	The message may be forced to finish early with an
	[AbortIO()/WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html) pair.

   TIMER REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       preset by timer in [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit         preset by timer in [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command      TR_ADDREQUEST
	io_Flags        IOF_QUICK permitted (but ignored)
	tr_time         a [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structure specifying how long the
	                    device will wait before replying

   RESULTS
	tr_time         will be zeroed

   NOTES
	This function may be called from interrupts.

	Previous to 2.0, the tr_time field was documented as containing
	junk when the [timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39) was returned.

   SEE ALSO
	[timer.device/AbortIO()](../Includes_and_Autodocs_3._guide/node0574.html),
	[timer.device/TimeDelay()](../Includes_and_Autodocs_3._guide/node004F.html),

   BUGS

