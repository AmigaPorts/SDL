---
title: amiga.lib/NewList
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-newlist
functions: []
libraries: []
---

# amiga.lib/NewList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    NewList -- prepare a list structure for use
SYNOPSIS

```c
    NewList(list)

    VOID NewList(struct [List](autodocs-2.0/includes-exec-lists-h.md) *);
    VOID NewList(struct [MinList](autodocs-2.0/includes-exec-lists-h.md) *);
```
FUNCTION

```c
    Perform the magic needed to prepare a [List](autodocs-2.0/includes-exec-lists-h.md) header structure for
    use; the list will be empty and ready to use.  (If the list is the
    full featured type, you may need to initialize lh_Type afterwards)

    Assembly programmers may want to use the NEWLIST macro instead.
```
INPUTS

```c
    list - pointer to a [List](autodocs-2.0/includes-exec-lists-h.md) or [MinList](autodocs-2.0/includes-exec-lists-h.md).
```
SEE ALSO

```c
    [<exec/lists.h>](autodocs-2.0/includes-exec-lists-h.md)
```
