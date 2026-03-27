# exec.library/DeleteIORequest



   NAME
	DeleteIORequest() - Free a request made by [CreateIORequest()](../Includes_and_Autodocs_3._guide/node01FB.html)  (V36)

   SYNOPSIS
	DeleteIORequest( ioReq );
	                 a0

	void DeleteIORequest(struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *);

   FUNCTION
	Frees up an IO request as allocated by [CreateIORequest()](../Includes_and_Autodocs_3._guide/node01FB.html).

   INPUTS
	ioReq - A pointer to the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block to be freed, or NULL.
		This function uses the mn_Length field to determine how
		much memory to free.

   SEE ALSO
	[CreateIORequest()](../Includes_and_Autodocs_3._guide/node01FB.html), [amiga.lib/DeleteExtIO()](../Includes_and_Autodocs_3._guide/node0034.html)

