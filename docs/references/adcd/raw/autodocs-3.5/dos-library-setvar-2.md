# dos.library/SetVar



   NAME
	SetVar -- Sets a local or environment variable (V36)

   SYNOPSIS
	success = SetVar( name, buffer, size, flags )
	D0	           D1     D2     D3    D4

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SetVar(STRPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), ULONG )

   FUNCTION
	Sets a local or environment variable.  It is advised to only use
	ASCII strings inside variables, but not required.

   INPUTS
	name   - pointer to an variable name.  Note variable names follow
		 filesystem syntax and semantics.
	buffer - a user allocated area which contains a string that is the
		 value to be associated with this variable.
	size   - length of the buffer region in bytes.  -1 means buffer
		 contains a null-terminated string.
	flags  - combination of type of var to set (low 8 bits), and
		 flags to control the behavior of this routine.  Currently
		 defined flags include:

		GVF_LOCAL_ONLY - set a local (to your process) variable.
		GVF_GLOBAL_ONLY - set a global environment variable.

		The default is to set a local environment variable.

   RESULT
	success - If non-zero, the variable was sucessfully set, FALSE
	 	  indicates failure.

   BUGS
	LV_VAR is the only type that can be global

   SEE ALSO
	[GetVar()](../Includes_and_Autodocs_3._guide/node017C.html), [DeleteVar()](../Includes_and_Autodocs_3._guide/node0153.html), [FindVar()](../Includes_and_Autodocs_3._guide/node0169.html), [<dos/var.h>](../Includes_and_Autodocs_3._guide/node0629.html)

