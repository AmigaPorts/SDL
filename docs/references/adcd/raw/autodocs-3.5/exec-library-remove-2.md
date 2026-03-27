# exec.library/Remove



   NAME
	Remove -- remove a node from a list

   SYNOPSIS
	Remove(node)
	       A1

	void Remove(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *);

   FUNCTION
	Unlink a node from whatever list it is in.  Nodes that are not part
	of a list must not be passed to this function!  Assembly programmers
	may prefer to use the REMOVE macro from "exec/lists.i".

   WARNING
	This function does not arbitrate for access to the list.  The
	calling task must be the owner of the involved list.

   INPUTS
	node - the node to remove

   SEE ALSO
	[AddHead()](../Includes_and_Autodocs_3._guide/node01D9.html), [AddTail()](../Includes_and_Autodocs_3._guide/node01E1.html), [Enqueue()](../Includes_and_Autodocs_3._guide/node0206.html), [Insert()](../Includes_and_Autodocs_3._guide/node0219.html), [RemHead()](../Includes_and_Autodocs_3._guide/node022B.html), [RemTail()](../Includes_and_Autodocs_3._guide/node0233.html)

