# exec.library/AddTail



   NAME
	AddTail -- append node to tail of a list

   SYNOPSIS
	AddTail(list, node)

                A0    A1
	void AddTail(struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *, struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *);

   FUNCTION
	Add a node to the tail of a doubly linked list.  Assembly
	programmers may prefer to use the ADDTAIL macro from
	"exec/lists.i".

   WARNING
	This function does not arbitrate for access to the list.  The
	calling task must be the owner of the involved list.

   INPUTS
	list - a pointer to the target list header
	node - a pointer to the node to insert at tail of the list

   SEE ALSO
	[AddHead()](../Includes_and_Autodocs_3._guide/node01D9.html), [Enqueue()](../Includes_and_Autodocs_3._guide/node0206.html), [Insert()](../Includes_and_Autodocs_3._guide/node0219.html), [Remove()](../Includes_and_Autodocs_3._guide/node022F.html), [RemHead()](../Includes_and_Autodocs_3._guide/node022B.html), [RemTail()](../Includes_and_Autodocs_3._guide/node0233.html)

