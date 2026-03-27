# lowlevel.library/RemTimerInt



   NAME
	RemTimerInt -- remove a previously installed timer interrupt. (V40)

   SYNOPSIS
	RemTimerInt(intHandle);
	            A1

	VOID RemTimerInt(APTR);

   FUNCTION
	Removes a timer interrupt routine previously installed with
	[AddTimerInt](../Includes_and_Autodocs_3._guide/node0462.html).

   INPUTS
	intHandle - handle obtained from [AddTimerInt()](../Includes_and_Autodocs_3._guide/node0462.html). This may be NULL,
		    in which case this function does nothing.

   SEE ALSO
	[AddTimerInt()](../Includes_and_Autodocs_3._guide/node0462.html), [StopTimerInt()](../Includes_and_Autodocs_3._guide/node046E.html), [StartTimerInt()](../Includes_and_Autodocs_3._guide/node046D.html)

