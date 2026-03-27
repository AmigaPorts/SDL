---
title: exec.library/AddHead
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-addhead-2
functions: [AddTail, Enqueue, Insert, RemHead, RemTail, Remove]
libraries: [exec.library]
---

# exec.library/AddHead

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddHead -- insert node at the head of a list

   SYNOPSIS
	AddHead(list, node)
		A0    A1

	void AddHead(struct [List](autodocs-3.5/include-exec-lists-h.md) *, struct [Node](autodocs-3.5/include-exec-nodes-h.md) *)

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
	[AddTail()](autodocs-3.5/exec-library-addtail-2.md), [Enqueue()](autodocs-3.5/exec-library-enqueue-2.md), [Insert()](autodocs-3.5/exec-library-insert-2.md), [Remove()](autodocs-3.5/exec-library-remove-2.md), [RemHead()](autodocs-3.5/exec-library-remhead-2.md), [RemTail()](autodocs-3.5/exec-library-remtail-2.md)

---

## See Also

- [AddTail — exec.library](../autodocs/exec.library.md#addtail)
- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
- [Insert — exec.library](../autodocs/exec.library.md#insert)
- [RemHead — exec.library](../autodocs/exec.library.md#remhead)
- [RemTail — exec.library](../autodocs/exec.library.md#remtail)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
