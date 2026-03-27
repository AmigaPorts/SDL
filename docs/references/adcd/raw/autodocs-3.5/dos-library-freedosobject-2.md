# dos.library/FreeDosObject



   NAME
	FreeDosObject -- Frees an object allocated by [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html) (V36)

   SYNOPSIS
	FreeDosObject(type, ptr)
		       D1   D2

	void FreeDosObject(ULONG, void *)

   FUNCTION
	Frees an object allocated by [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html).  Do NOT call for
	objects allocated in any other way.

   INPUTS
	type - type passed to [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html)
	ptr  - ptr returned by [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html)

   BUGS
	Before V39, DOS_CLI objects will only have the struct
	[CommandLineInterface](../Includes_and_Autodocs_3._guide/node05D9.html#line313) freed, not the strings it points to.  This
	is fixed in V39 dos.  Before V39, you can workaround this bug by
	using [FreeVec()](../Includes_and_Autodocs_3._guide/node0212.html) on cli_SetName, cli_CommandFile, cli_CommandName,
	and cli_Prompt, and then setting them all to NULL.  In V39 or
	above, do NOT use the workaround.

   SEE ALSO
	[AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html), [FreeVec()](../Includes_and_Autodocs_3._guide/node0212.html), [<dos/dos.h>](../Includes_and_Autodocs_3._guide/node05F8.html)

