---
title: exec.library/RemTail
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-remtail
functions: []
libraries: []
---

# exec.library/RemTail

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RemTail -- remove the tail node from a list
SYNOPSIS

```c
    node = RemTail(list)
    D0             A0

    struct [Node](autodocs-2.0/includes-exec-nodes-h.md) *RemTail(struct [List](autodocs-2.0/includes-exec-lists-h.md) *);
```
FUNCTION

    Remove the last node from a list, and return a pointer to it. If
    the list is empty, return zero. Assembly programmers may prefer to
    use the REMTAIL macro from "exec/lists.i".
WARNING

    This function does not arbitrate for access to the list.  The
    calling task must be the owner of the involved list.
INPUTS

    list - a pointer to the target list header
RESULT

    node - the node removed or zero when empty list
SEE ALSO

```c
    [AddHead](autodocs-2.0/exec-library-addhead.md), [AddTail](autodocs-2.0/exec-library-addtail.md), [Enqueue](autodocs-2.0/exec-library-enqueue.md), Insert, Remove, [RemHead](autodocs-2.0/exec-library-remhead.md), RemTail
```
