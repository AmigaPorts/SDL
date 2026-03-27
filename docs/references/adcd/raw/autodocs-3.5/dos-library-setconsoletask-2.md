# dos.library/SetConsoleTask



   NAME
	SetConsoleTask -- Sets the default console for the process (V36)

   SYNOPSIS
	oldport = SetConsoleTask(port)
	D0			  D1

	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *SetConsoleTask(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *)

   FUNCTION
	Sets the default console task's port (pr_ConsoleTask) for the
	current process.

   INPUTS
	port - The pr_MsgPort of the default console handler for the process

   RESULT
	oldport - The previous ConsoleTask value.

   SEE ALSO
	[GetConsoleTask()](../Includes_and_Autodocs_3._guide/node0175.html), [Open()](../Includes_and_Autodocs_3._guide/node0196.html)

