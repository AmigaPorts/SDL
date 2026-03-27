# amiga.lib/CreateExtIO



   NAME
	CreateExtIO -- create an [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) structure

   SYNOPSIS
	ioReq = CreateExtIO(port,ioSize);

	struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *CreateExtIO(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *, ULONG);

   FUNCTION
	Allocates memory for and initializes a new IO request block
	of a user-specified number of bytes. The number of bytes
	MUST be the size of a legal [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) (or extended IORequest)
	or very nasty things will happen.

   INPUTS
	port - an already initialized message port to be used for this IO
	       request's reply port. If this is NULL this function fails.
	ioSize - the size of the IO request to be created.

   RESULT
	ioReq - a new IO [Request](../Includes_and_Autodocs_3._guide/node03E5.html) block, or NULL if there was not enough memory

   EXAMPLE
	if (ioReq = CreateExtIO(CreatePort(NULL,0),sizeof(struct IOExtTD)))

   SEE ALSO
	[DeleteExtIO()](../Includes_and_Autodocs_3._guide/node0034.html), [CreatePort()](../Includes_and_Autodocs_3._guide/node002A.html), [exec.library/CreateMsgPort()](../Includes_and_Autodocs_3._guide/node01FC.html)

