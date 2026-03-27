---
title: 23 / List Functions / Prioritized Insertion
manual: libraries
chapter: libraries
section: 23-list-functions-prioritized-insertion
functions: [Enqueue, Insert, RemHead, RemTail]
libraries: [exec.library]
---

# 23 / List Functions / Prioritized Insertion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The list functions discussed so far do not make use of the priority field
in a [Node](libraries/23-list-structure-node-structure-definition.md). The [Enqueue()](autodocs-2.0/exec-library-enqueue.md) function is equivalent to [Insert()](libraries/23-list-functions-insertion-and-removal.md), except it
inserts nodes into a list sorting them according to their priority.  It
keeps the higher-priority nodes towards the head of the list.  All nodes
passed to this function must have their priority and name assigned prior
to the call. Enqueue([header](libraries/23-exec-lists-and-queues-list-functions.md),mynode) inserts mynode behind the lowest
priority node with a priority greater than or equal to mynode's. For
Enqueue() to work properly, the list must already be sort according to
priority.  Because the highest priority node is at the head of the list,
the [RemHead()](libraries/23-list-functions-special-case-removal.md) function will remove the highest-priority node.  Likewise,
[RemTail()](libraries/23-list-functions-special-case-removal.md) will remove the lowest-priority node.


```c
    FIFO Is Used For The Same Priority.
    -----------------------------------
    If you add a node that has the same priority as another node in the
    queue, [Enqueue()](autodocs-2.0/exec-library-enqueue.md) will use [FIFO](libraries/23-list-functions-special-case-removal.md) ordering.  The new node is inserted
    following the last node of equal priority.
```

---

## See Also

- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
- [Insert — exec.library](../autodocs/exec.library.md#insert)
- [RemHead — exec.library](../autodocs/exec.library.md#remhead)
- [RemTail — exec.library](../autodocs/exec.library.md#remtail)
