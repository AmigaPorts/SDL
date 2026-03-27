---
title: exec.library/Remove
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-remove-2
functions: [AddHead, AddTail, Enqueue, Insert, RemHead, RemTail]
libraries: [exec.library]
---

# exec.library/Remove

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Remove -- remove a node from a list

   SYNOPSIS
	Remove(node)
	       A1

	void Remove(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *);

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
	[AddHead()](autodocs-3.5/exec-library-addhead-2.md), [AddTail()](autodocs-3.5/exec-library-addtail-2.md), [Enqueue()](autodocs-3.5/exec-library-enqueue-2.md), [Insert()](autodocs-3.5/exec-library-insert-2.md), [RemHead()](autodocs-3.5/exec-library-remhead-2.md), [RemTail()](autodocs-3.5/exec-library-remtail-2.md)

---

## See Also

- [AddHead — exec.library](../autodocs/exec.library.md#addhead)
- [AddTail — exec.library](../autodocs/exec.library.md#addtail)
- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
- [Insert — exec.library](../autodocs/exec.library.md#insert)
- [RemHead — exec.library](../autodocs/exec.library.md#remhead)
- [RemTail — exec.library](../autodocs/exec.library.md#remtail)
