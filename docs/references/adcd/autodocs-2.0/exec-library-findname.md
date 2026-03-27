---
title: exec.library/FindName
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-findname
functions: []
libraries: []
---

# exec.library/FindName

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FindName -- find a system list node with a given name
SYNOPSIS

```c
    node = FindName(start, name)
    D0,Z            A0     A1

    struct [Node](autodocs-2.0/includes-exec-nodes-h.md) *FindName(struct [List](autodocs-2.0/includes-exec-lists-h.md) *, STRPTR);
```
FUNCTION

    Traverse a system list until a node with the given name is found.
    To find multiple occurrences of a string, this function may be
    called with a node starting point.

    No arbitration is done for access to the list!  If multiple tasks
    access the same list, an arbitration mechanism such as
    SignalSemaphores must be used.
INPUTS

```c
    start - a list header or a list node to start the search
            (if node, this one is skipped)
    name - a pointer to a name string terminated with NULL
```
RESULTS

    node - a pointer to the node with the same name else
        zero to indicate that the string was not found.
