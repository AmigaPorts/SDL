# exec.library/RemTail



   NAME
	RemTail -- remove the tail node from a list

   SYNOPSIS
	node = RemTail(list)
	D0	       A0

	struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *RemTail(struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *);

   FUNCTION
	[Remove](../Includes_and_Autodocs_3._guide/node022F.html) the last node from a list, and return a pointer to it. If
	the list is empty, return zero. Assembly programmers may prefer to
	use the REMTAIL macro from "exec/lists.i".

   WARNING
	This function does not arbitrate for access to the list.  The
	calling task must be the owner of the involved list.

   INPUTS
	list - a pointer to the target list header

   RESULT
	node - the node removed or zero when empty list

   SEE ALSO
	[AddHead()](../Includes_and_Autodocs_3._guide/node01D9.html), [AddTail()](../Includes_and_Autodocs_3._guide/node01E1.html), [Enqueue()](../Includes_and_Autodocs_3._guide/node0206.html), [Insert()](../Includes_and_Autodocs_3._guide/node0219.html), [Remove()](../Includes_and_Autodocs_3._guide/node022F.html), [RemHead()](../Includes_and_Autodocs_3._guide/node022B.html)

