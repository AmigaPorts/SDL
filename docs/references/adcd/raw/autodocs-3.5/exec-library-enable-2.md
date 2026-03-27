# exec.library/Enable



   NAME
	Enable -- permit system interrupts to resume.

   SYNOPSIS
	Enable();

	void Enable(void);

   FUNCTION
	Allow system interrupts to again occur normally, after a matching
	[Disable()](../Includes_and_Autodocs_3._guide/node0203.html) has been executed.

   RESULTS
	[Interrupt](../Includes_and_Autodocs_3._guide/node061D.html#line21) processing is restored to normal operation. The
	programmer must execute exactly one call to Enable() for every call
	to [Disable()](../Includes_and_Autodocs_3._guide/node0203.html).

    NOTE
	This call is guaranteed to preserve all registers.

   SEE ALSO
	[Forbid()](../Includes_and_Autodocs_3._guide/node020C.html), [Permit()](../Includes_and_Autodocs_3._guide/node0224.html), [Disable()](../Includes_and_Autodocs_3._guide/node0203.html)

