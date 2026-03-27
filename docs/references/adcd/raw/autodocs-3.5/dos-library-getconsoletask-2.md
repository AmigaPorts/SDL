# dos.library/GetConsoleTask



   NAME
	GetConsoleTask -- Returns the default console for the process (V36)

   SYNOPSIS
	port = GetConsoleTask()
	D0

	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *GetConsoleTask(void)

   FUNCTION
	Returns the default console task's port (pr_ConsoleTask) for the
	current process.

   RESULT
	port - The pr_MsgPort of the console handler, or NULL.

   SEE ALSO
	[SetConsoleTask()](../Includes_and_Autodocs_3._guide/node01B3.html), [Open()](../Includes_and_Autodocs_3._guide/node0196.html)

