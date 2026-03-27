# amiga.lib/DeleteStdIO



   NAME
	DeleteStdIO - return memory allocated for [IOStdReq](../Includes_and_Autodocs_3._guide/node0621.html#line26)

   SYNOPSIS
	DeleteStdIO(ioReq);

	VOID DeleteStdIO(struct [IOStdReq](../Includes_and_Autodocs_3._guide/node0621.html#line26) *);

   FUNCTION
	Frees up an [IOStdReq](../Includes_and_Autodocs_3._guide/node0621.html#line26) as allocated by [CreateStdIO()](../Includes_and_Autodocs_3._guide/node002B.html).

   INPUTS
	ioReq - the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block to be freed, or NULL.

   SEE ALSO
	[CreateStdIO()](../Includes_and_Autodocs_3._guide/node002B.html), [DeleteExtIO()](../Includes_and_Autodocs_3._guide/node0034.html), [exec.library/CreateIORequest()](../Includes_and_Autodocs_3._guide/node01FB.html)

