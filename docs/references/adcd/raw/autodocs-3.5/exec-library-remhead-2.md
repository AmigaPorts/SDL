# exec.library/RemHead



   NAME
	RemHead -- remove the head node from a list

   SYNOPSIS
	node = RemHead(list)
	D0	       A0

	struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *RemHead(struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *);

   FUNCTION
	Get a pointer to the head node and remove it from the list.
	Assembly programmers may prefer to use the REMHEAD macro from
	"exec/lists.i".

   WARNING
	This function does not arbitrate for access to the list.  The
	calling task must be the owner of the involved list.

   INPUTS
	list - a pointer to the target list header

   RESULT
	node - the node removed or zero when empty list

   SEE ALSO
	[AddHead()](../Includes_and_Autodocs_3._guide/node01D9.html), [AddTail()](../Includes_and_Autodocs_3._guide/node01E1.html), [Enqueue()](../Includes_and_Autodocs_3._guide/node0206.html), [Insert()](../Includes_and_Autodocs_3._guide/node0219.html), [Remove()](../Includes_and_Autodocs_3._guide/node022F.html), [RemTail()](../Includes_and_Autodocs_3._guide/node0233.html)

