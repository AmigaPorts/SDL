# amiga.lib/CreateStdIO



   NAME
	CreateStdIO -- create an [IOStdReq](../Includes_and_Autodocs_3._guide/node0621.html#line26) structure

   SYNOPSIS
	ioReq = CreateStdIO(port);

	struct [IOStdReq](../Includes_and_Autodocs_3._guide/node0621.html#line26) *CreateStdIO(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *)

   FUNCTION
	Allocates memory for and initializes a new [IOStdReq](../Includes_and_Autodocs_3._guide/node0621.html#line26) structure.

   INPUTS
	port - an already initialized message port to be used for this IO
	       request's reply port. If this is NULL this function fails.

   RESULT
	ioReq - a new [IOStdReq](../Includes_and_Autodocs_3._guide/node0621.html#line26) structure, or NULL if there was not enough
		memory

   SEE ALSO
	[DeleteStdIO()](../Includes_and_Autodocs_3._guide/node0036.html), [CreateExtIO()](../Includes_and_Autodocs_3._guide/node0029.html), [exec.library/CreateIORequest()](../Includes_and_Autodocs_3._guide/node01FB.html)

