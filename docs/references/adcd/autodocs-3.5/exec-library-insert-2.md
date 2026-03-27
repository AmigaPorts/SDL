---
title: exec.library/Insert
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-insert-2
functions: [AddHead, AddTail, Enqueue, RemHead, RemTail, Remove]
libraries: [exec.library]
---

# exec.library/Insert

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Insert -- insert a node into a list

   SYNOPSIS
	Insert(list, node, listNode)
	       A0    A1    A2

	void Insert(struct [List](autodocs-3.5/include-exec-lists-h.md) *, struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [Node](autodocs-3.5/include-exec-nodes-h.md) *);

   FUNCTION
	Insert a node into a doubly linked list AFTER a given node
	position.  Insertion at the head of a list is possible by passing a
	zero value for listNode, though the [AddHead](autodocs-3.5/exec-library-addhead-2.md) function is slightly
	faster for that special case.

   WARNING
	This function does not arbitrate for access to the list.  The
	calling task must be the owner of the involved list.

   INPUTS
	list - a pointer to the target list header
	node - the node to insert
	listNode - the node after which to insert

    SEE ALSO
	[AddHead()](autodocs-3.5/exec-library-addhead-2.md), [AddTail()](autodocs-3.5/exec-library-addtail-2.md), [Enqueue()](autodocs-3.5/exec-library-enqueue-2.md), [RemHead()](autodocs-3.5/exec-library-remhead-2.md), [Remove()](autodocs-3.5/exec-library-remove-2.md), [RemTail()](autodocs-3.5/exec-library-remtail-2.md)

---

## See Also

- [AddHead — exec.library](../autodocs/exec.library.md#addhead)
- [AddTail — exec.library](../autodocs/exec.library.md#addtail)
- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
- [RemHead — exec.library](../autodocs/exec.library.md#remhead)
- [RemTail — exec.library](../autodocs/exec.library.md#remtail)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
