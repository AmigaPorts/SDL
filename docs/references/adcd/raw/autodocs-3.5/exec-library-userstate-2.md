# exec.library/UserState



   NAME
	UserState -- return to user state with user stack

   SYNOPSIS
	UserState(sysStack)
		  D0

	void UserState(APTR);

   FUNCTION
	Return to user state with user stack, from supervisor state with
	user stack.  This function is normally used in conjunction with the
	[SuperState](../Includes_and_Autodocs_3._guide/node0241.html) function above.

	This function must not be called from the user state.

   INPUT
	sysStack - supervisor stack pointer

   BUGS
	This function is broken in V33/34 Kickstart.  Fixed in V1.31 setpatch.

   SEE ALSO
	[SuperState()](../Includes_and_Autodocs_3._guide/node0241.html), [Supervisor()](../Includes_and_Autodocs_3._guide/node0242.html)

