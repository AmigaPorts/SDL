# dos.library/GetFileSysTask



   NAME
	GetFileSysTask -- Returns the default filesystem for the process (V36)

   SYNOPSIS
	port = GetFileSysTask()
	D0

	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *GetFileSysTask(void)

   FUNCTION
	Returns the default filesystem task's port (pr_FileSystemTask) for the
	current process.

   RESULT
	port - The pr_MsgPort of the filesystem, or NULL.

   SEE ALSO
	[SetFileSysTask()](../Includes_and_Autodocs_3._guide/node01B7.html), [Open()](../Includes_and_Autodocs_3._guide/node0196.html)

