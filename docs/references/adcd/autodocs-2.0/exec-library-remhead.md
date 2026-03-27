---
title: exec.library/RemHead
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-remhead
functions: []
libraries: []
---

# exec.library/RemHead

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RemHead -- remove the head node from a list
SYNOPSIS

```c
    node = RemHead(list)
    D0             A0

    struct [Node](autodocs-2.0/includes-exec-nodes-h.md) *RemHead(struct [List](autodocs-2.0/includes-exec-lists-h.md) *);
```
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

```c
    [AddHead](autodocs-2.0/exec-library-addhead.md), [AddTail](autodocs-2.0/exec-library-addtail.md), [Enqueue](autodocs-2.0/exec-library-enqueue.md), Insert, Remove, [RemTail](autodocs-2.0/exec-library-remtail.md)
```
