# exec.library/AllocSignal



   NAME
	AllocSignal -- allocate a signal bit

   SYNOPSIS
	signalNum = AllocSignal(signalNum)
	D0			D0

	[BYTE](../Includes_and_Autodocs_3._guide/node0654.html#line48) AllocSignal(BYTE);

   FUNCTION
	[Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) a signal bit from the current tasks' pool.  Either a
	particular bit, or the next free bit may be allocated.	The signal
	associated with the bit will be properly initialized (cleared).  At
	least 16 user signals are available per task.  Signals should be
	deallocated before the task exits.

	If the signal is already in use (or no free signals are available)
	a -1 is returned.

	Allocated signals are only valid for use with the task that
	allocated them.


   WARNING
	Signals may not be allocated or freed from exception handling code.

   INPUTS
	signalNum - the desired signal number {of 0..31} or -1 for no
		    preference.

   RESULTS
	signalNum - the signal bit number allocated {0..31}. If no signals
		    are available, this function returns -1.

   SEE ALSO
	[FreeSignal()](../Includes_and_Autodocs_3._guide/node0210.html)

