---
title: exec.library/RemHead
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-remhead-2
functions: [AddHead, AddTail, Enqueue, Insert, RemTail, Remove]
libraries: [exec.library]
---

# exec.library/RemHead

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemHead -- remove the head node from a list

   SYNOPSIS
	node = RemHead(list)
	D0	       A0

	struct [Node](autodocs-3.5/include-exec-nodes-h.md) *RemHead(struct [List](autodocs-3.5/include-exec-lists-h.md) *);

   FUNCTION
	Get a pointer to the head node and remove it from the list.
	Assembly programmers may prefer to use the REMHEAD macro from
	"exec/lists.i".

   WARNING
	This function does not arbitrate for access to the list.  The
	calling task must be the owner of the involved list.

   INPUTS
	list - a pointer to the target list header

   RESULT
	node - the node removed or zero when empty list

   SEE ALSO
	[AddHead()](autodocs-3.5/exec-library-addhead-2.md), [AddTail()](autodocs-3.5/exec-library-addtail-2.md), [Enqueue()](autodocs-3.5/exec-library-enqueue-2.md), [Insert()](autodocs-3.5/exec-library-insert-2.md), [Remove()](autodocs-3.5/exec-library-remove-2.md), [RemTail()](autodocs-3.5/exec-library-remtail-2.md)

---

## See Also

- [AddHead — exec.library](../autodocs/exec.library.md#addhead)
- [AddTail — exec.library](../autodocs/exec.library.md#addtail)
- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
- [Insert — exec.library](../autodocs/exec.library.md#insert)
- [RemTail — exec.library](../autodocs/exec.library.md#remtail)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
