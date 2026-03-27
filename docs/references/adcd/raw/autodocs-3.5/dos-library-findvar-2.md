# dos.library/FindVar



   NAME
	FindVar -- Finds a local variable (V36)

   SYNOPSIS
	var = FindVar( name, type )
	D0		D1    D2

	struct [LocalVar](../Includes_and_Autodocs_3._guide/node0629.html#line24) * FindVar(STRPTR, ULONG )

   FUNCTION
	Finds a local variable structure.

   INPUTS
	name - pointer to an variable name.  Note variable names follow
	       filesystem syntax and semantics.

	type - type of variable to be found (see [<dos/var.h>](../Includes_and_Autodocs_3._guide/node0629.html))

   RESULT

	var  - pointer to a [LocalVar](../Includes_and_Autodocs_3._guide/node0629.html#line24) structure or NULL

   SEE ALSO
	[GetVar()](../Includes_and_Autodocs_3._guide/node017C.html), [SetVar()](../Includes_and_Autodocs_3._guide/node01BF.html), [DeleteVar()](../Includes_and_Autodocs_3._guide/node0153.html), [<dos/var.h>](../Includes_and_Autodocs_3._guide/node0629.html)

