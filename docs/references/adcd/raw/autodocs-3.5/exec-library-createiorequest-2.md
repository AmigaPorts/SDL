# exec.library/CreateIORequest



   NAME
	CreateIORequest() -- create an [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) structure  (V36)

   SYNOPSIS
	ioReq = CreateIORequest( ioReplyPort, size );
	 D0                       A0           D0

	struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *CreateIORequest(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *, ULONG);

   FUNCTION
	Allocates memory for and initializes a new IO request block
	of a user-specified number of bytes.  The number of bytes
	must be at least as large as a "struct Message".

   INPUTS
	ioReplyPort - Pointer to a port for replies (an initialized message
		port, as created by [CreateMsgPort()](../Includes_and_Autodocs_3._guide/node01FC.html) ).  If NULL, this
		function fails.
	size - the size of the IO request to be created.

   RESULT
	ioReq - A pointer to the new [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block, or NULL.

   SEE ALSO
	[DeleteIORequest()](../Includes_and_Autodocs_3._guide/node0200.html), [CreateMsgPort()](../Includes_and_Autodocs_3._guide/node01FC.html), [amiga.lib/CreateExtIO()](../Includes_and_Autodocs_3._guide/node0029.html)

