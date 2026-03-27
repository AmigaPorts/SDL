# exec.library/Permit



    NAME
	Permit -- permit task rescheduling.

    SYNOPSIS
	Permit()

	void Permit(void);

    FUNCTION
	Allow other tasks to be scheduled to run by the dispatcher, after a
	matching [Forbid()](../Includes_and_Autodocs_3._guide/node020C.html) has been executed.

    RESULTS
	Other tasks will be rescheduled as they are ready to run. In order
	to restore normal task rescheduling, the programmer must execute
	exactly one call to Permit() for every call to [Forbid()](../Includes_and_Autodocs_3._guide/node020C.html).

    NOTE
	This call is guaranteed to preserve all registers.

    SEE ALSO
	[Forbid()](../Includes_and_Autodocs_3._guide/node020C.html), [Disable()](../Includes_and_Autodocs_3._guide/node0203.html), [Enable()](../Includes_and_Autodocs_3._guide/node0205.html)

