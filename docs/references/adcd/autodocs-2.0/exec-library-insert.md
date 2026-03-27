---
title: exec.library/Insert
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-insert
functions: []
libraries: []
---

# exec.library/Insert

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Insert -- insert a node into a list
SYNOPSIS

```c
    Insert(list, node, listNode)
           A0    A1    A2

    void Insert(struct [List](autodocs-2.0/includes-exec-lists-h.md) *, struct [Node](autodocs-2.0/includes-exec-nodes-h.md) *, struct [Node](autodocs-2.0/includes-exec-nodes-h.md) *);
```
FUNCTION

```c
    Insert a node into a doubly linked list AFTER a given node
    position.  Insertion at the head of a list is possible by passing a
    zero value for listNode, though the [AddHead](autodocs-2.0/exec-library-addhead.md) function is slightly
    faster for that special case.
```
WARNING

    This function does not arbitrate for access to the list.  The
    calling task must be the owner of the involved list.
INPUTS

    list - a pointer to the target list header
    node - the node to insert
    listNode - the node after which to insert
SEE ALSO

```c
    [AddHead](autodocs-2.0/exec-library-addhead.md), [AddTail](autodocs-2.0/exec-library-addtail.md), [Enqueue](autodocs-2.0/exec-library-enqueue.md), [RemHead](autodocs-2.0/exec-library-remhead.md), Remove, [RemTail](autodocs-2.0/exec-library-remtail.md)
```
