# dos.library/GetArgStr



   NAME
	GetArgStr -- Returns the arguments for the process (V36)

   SYNOPSIS
	ptr = GetArgStr()
	D0

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) GetArgStr(void)

   FUNCTION
	Returns a pointer to the (null-terminated) arguments for the program
	(process).  This is the same string passed in a0 on startup from CLI.

   RESULT
	ptr - pointer to arguments

   SEE ALSO
	[SetArgStr()](../Includes_and_Autodocs_3._guide/node01B1.html), [RunCommand()](../Includes_and_Autodocs_3._guide/node01AA.html)

