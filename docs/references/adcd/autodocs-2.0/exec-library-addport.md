---
title: exec.library/AddPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-addport
functions: [AddPort, FindPort]
libraries: [exec.library]
---

# exec.library/AddPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddPort -- add a public message port to the system
SYNOPSIS

```c
    AddPort(port)
            A1

    void AddPort(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *);
```
FUNCTION

```c
    This function attaches a message port structure to the system's
    public message port list, where it can be found by the [FindPort()](autodocs-2.0/exec-library-findport.md)
    function.  The name and priority fields of the port structure must
    be initialized prior to calling this function.  If the user does
    not require the priority field, it should be initialized to zero.

    Only ports that will be searched for with [FindPort()](autodocs-2.0/exec-library-findport.md) need to
    be added to the system list.  In addition, adding ports is often
    useful during debugging.  If the port will be searched for,
    the priority field should be at least 1 (to avoid the large number
    of inactive ports at priority zero).  If the port will be searched
    for often, set the proritiry in the 50-100 range (so it will be
    before other less used ports).

    Once a port has been added to the naming list, you must be careful
    to remove the port from the list (via RemPort) before deallocating
    its memory.
```
NOTE

```c
    A point of confusion is that clearing a [MsgPort](autodocs-2.0/includes-exec-ports-h.md) structure to all
    zeros is not enough to prepare it for use.  As mentioned in the
    Exec chapter of the ROM Kernel Manual, the [List](autodocs-2.0/includes-exec-lists-h.md) for the [MsgPort](autodocs-2.0/includes-exec-ports-h.md)
    must be initialized.  This is automatically handled by AddPort(),
    and [amiga.lib/CreatePort](autodocs-2.0/amiga-lib-createport.md).  This initialization can be done manually
    with [amiga.lib/NewList](autodocs-2.0/amiga-lib-newlist.md) or the assembly NEWLIST macro.

    Do not AddPort an active port.
```
INPUTS

    port - pointer to a message port
SEE ALSO

```c
    [RemPort](autodocs-2.0/exec-library-remport.md), [FindPort](autodocs-2.0/exec-library-findport.md), [amiga.lib/CreatePort](autodocs-2.0/amiga-lib-createport.md), [amiga.lib/NewList](autodocs-2.0/amiga-lib-newlist.md)
```

---

## See Also

- [AddPort — exec.library](../autodocs/exec.library.md#addport)
- [FindPort — exec.library](../autodocs/exec.library.md#findport)
