---
title: 23 / List Functions / Special Case Removal
manual: libraries
chapter: libraries
section: 23-list-functions-special-case-removal
functions: [AddHead, AddTail, RemHead, RemTail]
libraries: [exec.library]
---

# 23 / List Functions / Special Case Removal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The two functions [RemHead()](autodocs-2.0/exec-library-remhead.md) and [RemTail()](autodocs-2.0/exec-library-remtail.md) are used in combination with
[AddHead()](libraries/23-list-functions-special-case-insertion.md) and [AddTail()](libraries/23-list-functions-special-case-insertion.md) to create special list ordering.  When you combine
AddTail() and RemHead(), you produce a first-in-first-out (FIFO) list.
When you combine AddHead() and RemHead() a last-in-first-out (LIFO or
stack) list is produced.  RemTail() exists for symmetry. Other
combinations of these functions can also be used productively.

Both [RemHead()](autodocs-2.0/exec-library-remhead.md) and [RemTail()](autodocs-2.0/exec-library-remtail.md) remove a [node](libraries/23-exec-lists-and-queues-list-functions.md) from the list, and return a
pointer to the removed node. If the list is empty, the function return a
NULL result.

---

## See Also

- [AddHead — exec.library](../autodocs/exec.library.md#addhead)
- [AddTail — exec.library](../autodocs/exec.library.md#addtail)
- [RemHead — exec.library](../autodocs/exec.library.md#remhead)
- [RemTail — exec.library](../autodocs/exec.library.md#remtail)
