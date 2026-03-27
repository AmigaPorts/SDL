---
title: exec.library/AddTail
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-addtail
functions: []
libraries: []
---

# exec.library/AddTail

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddTail -- append node to tail of a list
SYNOPSIS

```c
    AddTail(list, node)
            A0    A1

    void AddTail(struct [List](autodocs-2.0/includes-exec-lists-h.md) *, struct [Node](autodocs-2.0/includes-exec-nodes-h.md) *);
```
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

```c
    [AddHead](autodocs-2.0/exec-library-addhead.md), [Enqueue](autodocs-2.0/exec-library-enqueue.md), Insert, Remove, [RemHead](autodocs-2.0/exec-library-remhead.md), [RemTail](autodocs-2.0/exec-library-remtail.md)
```
