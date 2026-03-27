# dos.library/SetFileSysTask



   NAME
	SetFileSysTask -- Sets the default filesystem for the process (V36)

   SYNOPSIS
	oldport = SetFileSysTask(port)
	D0			  D1

	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *SetFileSysTask(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *)

   FUNCTION
	Sets the default filesystem task's port (pr_FileSystemTask) for the
	current process.

   INPUTS
	port - The pr_MsgPort of the default filesystem for the process

   RESULT
	oldport - The previous FileSysTask value

   SEE ALSO
	[GetFileSysTask()](../Includes_and_Autodocs_3._guide/node0178.html), [Open()](../Includes_and_Autodocs_3._guide/node0196.html)

