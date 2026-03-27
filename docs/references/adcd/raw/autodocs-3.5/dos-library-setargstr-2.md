# dos.library/SetArgStr



   NAME
	SetArgStr -- Sets the arguments for the current process (V36)

   SYNOPSIS
	oldptr = SetArgStr(ptr)
	D0		   D1

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) SetArgStr(STRPTR)

   FUNCTION
	Sets the arguments for the current program.  The ptr MUST be reset
	to it's original value before process exit.

   INPUTS
	ptr - pointer to new argument string.

   RESULT
	oldptr - the previous argument string

   SEE ALSO
	[GetArgStr()](../Includes_and_Autodocs_3._guide/node0174.html), [RunCommand()](../Includes_and_Autodocs_3._guide/node01AA.html)

