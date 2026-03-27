---
title: exec.library/AddHead
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-addhead
functions: []
libraries: []
---

# exec.library/AddHead

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddHead -- insert node at the head of a list
SYNOPSIS

```c
    AddHead(list, node)
            A0    A1

    void AddHead(struct [List](autodocs-2.0/includes-exec-lists-h.md) *, struct [Node](autodocs-2.0/includes-exec-nodes-h.md) *)
```
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

```c
    [AddTail](autodocs-2.0/exec-library-addtail.md), [Enqueue](autodocs-2.0/exec-library-enqueue.md), Insert, Remove, [RemHead](autodocs-2.0/exec-library-remhead.md), [RemTail](autodocs-2.0/exec-library-remtail.md)
```
