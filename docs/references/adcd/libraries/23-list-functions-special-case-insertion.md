---
title: 23 / List Functions / Special Case Insertion
manual: libraries
chapter: libraries
section: 23-list-functions-special-case-insertion
functions: [AddHead, AddTail, Insert]
libraries: [exec.library]
---

# 23 / List Functions / Special Case Insertion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Although the [Insert()](libraries/23-list-functions-insertion-and-removal.md) function allows new nodes to be inserted at the head
and the tail of a list, the [AddHead()](autodocs-2.0/exec-library-addhead.md) and [AddTail()](autodocs-2.0/exec-library-addtail.md) functions will do so
with higher efficiency.  Adding to the head or tail of a list is common
practice in first-in-first-out ([FIFO](libraries/23-list-functions-special-case-removal.md)) or last-in-first-out ([LIFO](libraries/23-list-functions-special-case-removal.md) or stack)
operations.  For example, AddHead([header](libraries/23-exec-lists-and-queues-list-functions.md),[node](libraries/23-exec-lists-and-queues-list-functions.md)) would insert the node at
the head of the specified list.

---

## See Also

- [AddHead — exec.library](../autodocs/exec.library.md#addhead)
- [AddTail — exec.library](../autodocs/exec.library.md#addtail)
- [Insert — exec.library](../autodocs/exec.library.md#insert)
