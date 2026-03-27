# exec.library/AddHead



   NAME
	AddHead -- insert node at the head of a list

   SYNOPSIS
	AddHead(list, node)
		A0    A1

	void AddHead(struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *, struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *)

   FUNCTION
	Add a node to the head of a doubly linked list. Assembly
	programmers may prefer to use the ADDHEAD macro from
	"exec/lists.i".

   WARNING
	This function does not arbitrate for access to the list.  The
	calling task must be the owner of the involved list.

   INPUTS
	list - a pointer to the target list header
	node - the node to insert at head

   SEE ALSO
	[AddTail()](../Includes_and_Autodocs_3._guide/node01E1.html), [Enqueue()](../Includes_and_Autodocs_3._guide/node0206.html), [Insert()](../Includes_and_Autodocs_3._guide/node0219.html), [Remove()](../Includes_and_Autodocs_3._guide/node022F.html), [RemHead()](../Includes_and_Autodocs_3._guide/node022B.html), [RemTail()](../Includes_and_Autodocs_3._guide/node0233.html)

