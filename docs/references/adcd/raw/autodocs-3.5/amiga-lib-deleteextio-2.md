# amiga.lib/DeleteExtIO



   NAME
	DeleteExtIO - return memory allocated for extended IO request

   SYNOPSIS
	DeleteExtIO(ioReq);

	VOID DeleteExtIO(struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *);

   FUNCTION
	Frees up an IO request as allocated by [CreateExtIO()](../Includes_and_Autodocs_3._guide/node0029.html).

   INPUTS
	ioReq - the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block to be freed, or NULL.

   SEE ALSO
	[CreateExtIO()](../Includes_and_Autodocs_3._guide/node0029.html)

