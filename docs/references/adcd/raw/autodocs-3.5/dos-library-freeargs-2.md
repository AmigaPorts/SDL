# dos.library/FreeArgs



   NAME
	FreeArgs - Free allocated memory after [ReadArgs()](../Includes_and_Autodocs_3._guide/node01A1.html) (V36)

   SYNOPSIS
	FreeArgs(rdargs)
	           D1

	void FreeArgs(struct [RDArgs](../Includes_and_Autodocs_3._guide/node05F5.html#line94) *)

   FUNCTION
	Frees memory allocated to return arguments in from [ReadArgs()](../Includes_and_Autodocs_3._guide/node01A1.html).  If
	[ReadArgs](../Includes_and_Autodocs_3._guide/node01A1.html) allocated the [RDArgs](../Includes_and_Autodocs_3._guide/node05F5.html#line94) structure it will be freed.  If NULL
	is passed in this function does nothing.

   INPUTS
	rdargs - structure returned from [ReadArgs()](../Includes_and_Autodocs_3._guide/node01A1.html) or NULL.

   SEE ALSO
	[ReadArgs()](../Includes_and_Autodocs_3._guide/node01A1.html), [ReadItem()](../Includes_and_Autodocs_3._guide/node01A2.html), [FindArg()](../Includes_and_Autodocs_3._guide/node0165.html)

