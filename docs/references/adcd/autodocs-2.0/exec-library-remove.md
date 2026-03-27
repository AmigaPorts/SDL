---
title: exec.library/Remove
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-remove
functions: []
libraries: []
---

# exec.library/Remove

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Remove -- remove a node from a list
SYNOPSIS

```c
    Remove(node)
           A1

    void Remove(struct [Node](autodocs-2.0/includes-exec-nodes-h.md) *);
```
FUNCTION

    Unlink a node from whatever list it is in.  Nodes that are not part
    of a list must not be passed to this funcion!  Assembly programmers
    may prefer to use the REMOVE macro from "exec/lists.i".
WARNING

    This function does not arbitrate for access to the list.  The
    calling task must be the owner of the involved list.
INPUTS

    node - the node to remove
SEE ALSO

```c
    [AddHead](autodocs-2.0/exec-library-addhead.md), [AddTail](autodocs-2.0/exec-library-addtail.md), [Enqueue](autodocs-2.0/exec-library-enqueue.md), Insert, [RemHead](autodocs-2.0/exec-library-remhead.md), [RemTail](autodocs-2.0/exec-library-remtail.md)
```
