# exec.library/Insert



   NAME
	Insert -- insert a node into a list

   SYNOPSIS
	Insert(list, node, listNode)
	       A0    A1    A2

	void Insert(struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *, struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *);

   FUNCTION
	Insert a node into a doubly linked list AFTER a given node
	position.  Insertion at the head of a list is possible by passing a
	zero value for listNode, though the [AddHead](../Includes_and_Autodocs_3._guide/node01D9.html) function is slightly
	faster for that special case.

   WARNING
	This function does not arbitrate for access to the list.  The
	calling task must be the owner of the involved list.

   INPUTS
	list - a pointer to the target list header
	node - the node to insert
	listNode - the node after which to insert

    SEE ALSO
	[AddHead()](../Includes_and_Autodocs_3._guide/node01D9.html), [AddTail()](../Includes_and_Autodocs_3._guide/node01E1.html), [Enqueue()](../Includes_and_Autodocs_3._guide/node0206.html), [RemHead()](../Includes_and_Autodocs_3._guide/node022B.html), [Remove()](../Includes_and_Autodocs_3._guide/node022F.html), [RemTail()](../Includes_and_Autodocs_3._guide/node0233.html)

