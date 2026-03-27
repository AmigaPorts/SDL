---
title: 23 / List Functions / Insertion and Removal
manual: libraries
chapter: libraries
section: 23-list-functions-insertion-and-removal
functions: [Insert, Remove]
libraries: [exec.library]
---

# 23 / List Functions / Insertion and Removal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [Insert()](autodocs-2.0/exec-library-insert.md) function is used for inserting a new node into any position
in a list.  It always inserts the node following a specified node that is
already part of the list.  For example, Insert([header](libraries/23-exec-lists-and-queues-list-functions.md),[node](libraries/23-exec-lists-and-queues-list-functions.md),pred) inserts
the node node after the node pred in the specified list.  If the pred node
points to the list header or is NULL, the new node will be inserted at the
head of the list.  Similarly, if the pred node points to the [lh_Tail](libraries/23-list-structure-list-header-structure-definition.md) of
the list, the new node will be inserted at the tail of the list.  However,
both of these actions can be better accomplished with the functions
mentioned in the "[Special Case Insertion](libraries/23-list-functions-special-case-insertion.md)" section below.

The [Remove()](autodocs-2.0/exec-library-remove.md) function is used to remove a specified node from a list.  For
example, Remove([node](libraries/23-exec-lists-and-queues-list-functions.md)) will remove the specified node from whatever list it
is in.  To be removed, a node must actually be in a list. If you attempt
to remove a node that is not in a list, you will cause serious system
problems.

---

## See Also

- [Insert — exec.library](../autodocs/exec.library.md#insert)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
