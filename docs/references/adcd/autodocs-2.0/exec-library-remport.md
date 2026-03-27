---
title: exec.library/RemPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-remport
functions: []
libraries: []
---

# exec.library/RemPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RemPort -- remove a message port from the system
SYNOPSIS

```c
    RemPort(port)
            A1

    void RemPort(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *);
```
FUNCTION

    This function removes a message port structure from the system's
    message port list.  Subsequent attempts to rendezvous by name with
    this port will fail.
INPUTS

    port - pointer to a message port
SEE ALSO

```c
    [AddPort](autodocs-2.0/exec-library-addport.md), [FindPort](autodocs-2.0/exec-library-findport.md)
```
