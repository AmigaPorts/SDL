# dos.library/ExAllEnd



   NAME
	ExAllEnd -- Stop an [ExAll()](../Includes_and_Autodocs_3._guide/node015A.html) (V39)

   SYNOPSIS
	ExAllEnd(lock, buffer, size, type, control)
	          D1     D2     D3    D4     D5

	ExAllEnd(BPTR,[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57),[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),struct [ExAllControl](../Includes_and_Autodocs_3._guide/node0608.html#line69) *)

   FUNCTION
	Stops an [ExAll()](../Includes_and_Autodocs_3._guide/node015A.html) on a directory before it hits NO_MORE_ENTRIES.
	The full set of arguments that had been passed to [ExAll()](../Includes_and_Autodocs_3._guide/node015A.html) must be
	passed to ExAllEnd(), so it can handle filesystems that can't abort
	an [ExAll()](../Includes_and_Autodocs_3._guide/node015A.html) directly.

   INPUTS
	lock    - [Lock](../Includes_and_Autodocs_3._guide/node0186.html) on directory to be examined.
	buffer  - Buffer for data returned (MUST be at least word-aligned,
		  preferably long-word aligned).
	size    - Size in bytes of 'buffer'.
	type    - Type of data to be returned.
	control - Control data structure (see notes above).  MUST have been
		  allocated by AllocDosObject!

   SEE ALSO
	[ExAll()](../Includes_and_Autodocs_3._guide/node015A.html), [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html)

