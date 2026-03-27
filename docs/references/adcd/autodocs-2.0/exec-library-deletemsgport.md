---
title: exec.library/DeleteMsgPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-deletemsgport
functions: [CreateMsgPort]
libraries: [exec.library]
---

# exec.library/DeleteMsgPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DeleteMsgPort - Free a message port created by [CreateMsgPort](autodocs-2.0/exec-library-createmsgport.md)  (V36)
```
SYNOPSIS

```c
    DeleteMsgPort(msgPort)
                  a0

    void DeleteMsgPort(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *);
```
FUNCTION

```c
    Frees a message port created by [CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md).  All messages that
    may have been attached to this port must have already been
    replied to.
```
INPUTS

    msgPort - A message port.  NULL for no action.
SEE ALSO

```c
    [CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md), [amiga.lib/DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)
```

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
