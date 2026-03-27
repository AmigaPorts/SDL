# exec.library/Enqueue



   NAME
	Enqueue -- insert or append node to a system queue

   SYNOPSIS
	Enqueue(list, node)
		A0    A1

	void Enqueue(struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *, struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *);

   FUNCTION
	[Insert](../Includes_and_Autodocs_3._guide/node0219.html) or append a node into a system queue.  The insert is
	performed based on the node priority -- it will keep the list
	properly sorted.  New nodes will be inserted in front of the first
	node with a lower priority.   Hence a FIFO queue for nodes of equal
	priority

   WARNING
	This function does not arbitrate for access to the list.  The
	calling task must be the owner of the involved list.

   INPUTS
	list - a pointer to the system queue header
	node - the node to enqueue.  This must be a full featured node
	       with type, priority and name fields.

   SEE ALSO
	[AddHead()](../Includes_and_Autodocs_3._guide/node01D9.html), [AddTail()](../Includes_and_Autodocs_3._guide/node01E1.html), [Insert()](../Includes_and_Autodocs_3._guide/node0219.html), [Remove()](../Includes_and_Autodocs_3._guide/node022F.html), [RemHead()](../Includes_and_Autodocs_3._guide/node022B.html), [RemTail()](../Includes_and_Autodocs_3._guide/node0233.html)

