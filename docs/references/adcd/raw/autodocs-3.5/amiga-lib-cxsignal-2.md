# amiga.lib/CxSignal



   NAME
	CxSignal -- create a commodity signaller object. (V36)

   SYNOPSIS
	signalerObj = CxSignal(task,signal);

	[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *CxSignal(struct [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) *,LONG);

   FUNCTION
	This function creates a Commodities signal object. The action
	of this object on receiving a Commodities message is to
	send the 'signal' to the 'task'. The caller is responsible
	for allocating the signal and determining the proper task ID.

	Note that 'signal' is the signal value as returned by [AllocSignal()](../Includes_and_Autodocs_3._guide/node01E9.html),
	not the mask made from that value.

	This function is a C-language macro for [CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), defined
	in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html).

   INPUTS
	task - the task for the signaller to signal
	signal - the signal bit number for the signaller to send

   RESULTS
	signallerObj - a pointer to the signaller object, or NULL if it could
		       not be created.

   SEE ALSO
	[commodities.library/CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), [exec.library/FindTask()](../Includes_and_Autodocs_3._guide/node020B.html)
	[exec.library/Signal()](../Includes_and_Autodocs_3._guide/node023D.html), [exec.library/AllocSignal()](../Includes_and_Autodocs_3._guide/node01E9.html),

