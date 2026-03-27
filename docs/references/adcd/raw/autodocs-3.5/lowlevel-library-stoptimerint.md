# lowlevel.library/StopTimerInt



   NAME
	StopTimerInt -- stop the timer associated with the timer interrupt.
			(V40)

   SYNOPSIS
	StopTimerInt(intHandle);
	             A1

	VOID StopTimerInt(APTR);

   FUNCTION
	Stops the timer associated with the timer interrupt handle passed.
	This is used to stop a continuous timer started by
	[StartTimerInt()](../Includes_and_Autodocs_3._guide/node046D.html).

   INPUTS
	intHandle - handle obtained from [AddTimerInt()](../Includes_and_Autodocs_3._guide/node0462.html).

   SEE ALSO
	[AddTimerInt()](../Includes_and_Autodocs_3._guide/node0462.html), [RemTimerInt()](../Includes_and_Autodocs_3._guide/node046A.html), [StartTimerInt()](../Includes_and_Autodocs_3._guide/node046D.html)

