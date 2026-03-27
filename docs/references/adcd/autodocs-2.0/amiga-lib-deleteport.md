---
title: amiga.lib/DeletePort
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-deleteport
functions: []
libraries: []
---

# amiga.lib/DeletePort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DeletePort - free a message port created by [CreatePort()](autodocs-2.0/amiga-lib-createport.md)
```
SYNOPSIS

```c
    DeletePort(port)

    VOID DeletePort(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *);
```
FUNCTION

```c
    Frees a message port created by [CreatePort](autodocs-2.0/amiga-lib-createport.md). All messages that
    may have been attached to this port must have already been
    replied before this function is called.
```
INPUTS

    port - message port to delete
SEE ALSO

```c
    [CreatePort()](autodocs-2.0/amiga-lib-createport.md)
```
