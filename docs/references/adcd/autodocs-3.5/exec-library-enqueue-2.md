---
title: exec.library/Enqueue
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-enqueue-2
functions: [AddHead, AddTail, Insert, RemHead, RemTail, Remove]
libraries: [exec.library]
---

# exec.library/Enqueue

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Enqueue -- insert or append node to a system queue

   SYNOPSIS
	Enqueue(list, node)
		A0    A1

	void Enqueue(struct [List](autodocs-3.5/include-exec-lists-h.md) *, struct [Node](autodocs-3.5/include-exec-nodes-h.md) *);

   FUNCTION
	[Insert](autodocs-3.5/exec-library-insert-2.md) or append a node into a system queue.  The insert is
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
	[AddHead()](autodocs-3.5/exec-library-addhead-2.md), [AddTail()](autodocs-3.5/exec-library-addtail-2.md), [Insert()](autodocs-3.5/exec-library-insert-2.md), [Remove()](autodocs-3.5/exec-library-remove-2.md), [RemHead()](autodocs-3.5/exec-library-remhead-2.md), [RemTail()](autodocs-3.5/exec-library-remtail-2.md)

---

## See Also

- [AddHead — exec.library](../autodocs/exec.library.md#addhead)
- [AddTail — exec.library](../autodocs/exec.library.md#addtail)
- [Insert — exec.library](../autodocs/exec.library.md#insert)
- [RemHead — exec.library](../autodocs/exec.library.md#remhead)
- [RemTail — exec.library](../autodocs/exec.library.md#remtail)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
