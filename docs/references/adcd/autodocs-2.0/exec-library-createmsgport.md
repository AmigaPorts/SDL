---
title: exec.library/CreateMsgPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-createmsgport
functions: [AddPort, CreateMsgPort, DeleteMsgPort, RemPort]
libraries: [exec.library]
---

# exec.library/CreateMsgPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CreateMsgPort - Allocate and initialize a new message port  (V36)
```
SYNOPSIS

```c
    CreateMsgPort()

    struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) * CreateMsgPort(void);
```
FUNCTION

```c
    Allocates and initializes a new message port.  The message list
    of the new port will be prepared for use (via NewList).  A signal
    bit will be allocated, and the port will be set to signal your
    task when a message arrives (PA_SIGNAL).

    You *must* use [DeleteMsgPort()](autodocs-2.0/exec-library-deletemsgport.md) to delete ports created with
    CreateMsgPort()!
```
RESULT

```c
    [MsgPort](autodocs-2.0/includes-exec-ports-h.md) - A new [MsgPort](autodocs-2.0/includes-exec-ports-h.md) structure ready for use, or NULL if out of
            memory or signals.  If you wish to add this port to the public
            port list, fill in the ln_Name and ln_Pri fields, then call
            [AddPort()](autodocs-2.0/exec-library-addport.md).  Don't forget RemPort()!
```
SEE ALSO

```c
    [DeleteMsgPort()](autodocs-2.0/exec-library-deletemsgport.md), [exec/AddPort()](autodocs-2.0/exec-library-addport.md), [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md), [amiga.lib/CreatePort()](autodocs-2.0/amiga-lib-createport.md)
```

---

## See Also

- [AddPort — exec.library](../autodocs/exec.library.md#addport)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DeleteMsgPort — exec.library](../autodocs/exec.library.md#deletemsgport)
- [RemPort — exec.library](../autodocs/exec.library.md#remport)
