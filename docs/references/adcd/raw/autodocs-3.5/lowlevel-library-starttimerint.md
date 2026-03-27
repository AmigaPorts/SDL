# lowlevel.library/StartTimerInt



   NAME
	StartTimerInt -- start the timer associated with the timer interrupt.
			 (V40)

   SYNOPSIS
	StartTimerInt(intHandle, timeInterval, continuous);
	              A1         D0            D1

	VOID StartTimerInt(APTR, ULONG, BOOL);

   FUNCTION
	This routine starts a stopped timer that is assocatied with a
	timer interrupt created by [AddTimerInt()](../Includes_and_Autodocs_3._guide/node0462.html).

   INPUTS
	intHandle - handle obtained from [AddTimerInt()](../Includes_and_Autodocs_3._guide/node0462.html).
	timeInterval - number of micoseconds between interrupts. The
	               maximum value allowed is 90,000. If higher values
	               are passed there will be unexpected results.
	continuous - FALSE for a one shot interrupt. TRUE for multiple
	             interrupts.

   SEE ALSO
	[AddTimerInt()](../Includes_and_Autodocs_3._guide/node0462.html), [RemTimerInt()](../Includes_and_Autodocs_3._guide/node046A.html), [StopTimerInt()](../Includes_and_Autodocs_3._guide/node046E.html)

