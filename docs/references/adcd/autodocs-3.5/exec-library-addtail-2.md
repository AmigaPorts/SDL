---
title: exec.library/AddTail
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-addtail-2
functions: [AddHead, Enqueue, Insert, RemHead, RemTail, Remove]
libraries: [exec.library]
---

# exec.library/AddTail

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddTail -- append node to tail of a list

   SYNOPSIS
	AddTail(list, node)

                A0    A1
	void AddTail(struct [List](autodocs-3.5/include-exec-lists-h.md) *, struct [Node](autodocs-3.5/include-exec-nodes-h.md) *);

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
	[AddHead()](autodocs-3.5/exec-library-addhead-2.md), [Enqueue()](autodocs-3.5/exec-library-enqueue-2.md), [Insert()](autodocs-3.5/exec-library-insert-2.md), [Remove()](autodocs-3.5/exec-library-remove-2.md), [RemHead()](autodocs-3.5/exec-library-remhead-2.md), [RemTail()](autodocs-3.5/exec-library-remtail-2.md)

---

## See Also

- [AddHead — exec.library](../autodocs/exec.library.md#addhead)
- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
- [Insert — exec.library](../autodocs/exec.library.md#insert)
- [RemHead — exec.library](../autodocs/exec.library.md#remhead)
- [RemTail — exec.library](../autodocs/exec.library.md#remtail)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
