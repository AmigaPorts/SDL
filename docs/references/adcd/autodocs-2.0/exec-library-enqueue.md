---
title: exec.library/Enqueue
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-enqueue
functions: []
libraries: []
---

# exec.library/Enqueue

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Enqueue -- insert or append node to a system queue
SYNOPSIS

```c
    Enqueue(list, node)
            A0    A1

    void Enqueue(struct [List](autodocs-2.0/includes-exec-lists-h.md) *, struct [Node](autodocs-2.0/includes-exec-nodes-h.md) *);
```
FUNCTION

    Insert or append a node into a system queue.  The insert is
    performed based on the node priority -- it will keep the list
    properly sorted.  New nodes will be inserted in front of the first
    node with a lower priority.   Hence a FIFO queue for nodes of equal
    priority
WARNING

    This function does not arbitrate for access to the list.  The
    calling task must be the owner of the involved list.
INPUTS

    list - a pointer to the system queue header
    node - the node to enqueue.  This must be a full featured list
           with type, priority and name fields.
SEE ALSO

```c
    [AddHead](autodocs-2.0/exec-library-addhead.md), [AddTail](autodocs-2.0/exec-library-addtail.md), Insert, Remove, [RemHead](autodocs-2.0/exec-library-remhead.md), [RemTail](autodocs-2.0/exec-library-remtail.md)
```
