# amiga.lib/NewList



   NAME
	NewList -- prepare a list structure for use

   SYNOPSIS
	NewList(list)

	VOID NewList(struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *);
	VOID NewList(struct [MinList](../Includes_and_Autodocs_3._guide/node0628.html#line30) *);

   FUNCTION
	Perform the magic needed to prepare a [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) header structure for
	use; the list will be empty and ready to use.  (If the list is the
	full featured type, you may need to initialize lh_Type afterwards)

	Assembly programmers may want to use the NEWLIST macro instead.

   INPUTS
	list - pointer to a [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) or [MinList](../Includes_and_Autodocs_3._guide/node0628.html#line30).

   SEE ALSO
	[<exec/lists.h>](../Includes_and_Autodocs_3._guide/node0628.html)

