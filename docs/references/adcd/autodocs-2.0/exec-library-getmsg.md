---
title: exec.library/GetMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-getmsg
functions: [GetMsg, ReplyMsg, Wait, WaitPort]
libraries: [exec.library]
---

# exec.library/GetMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GetMsg -- get next message from a message port
SYNOPSIS

```c
    message = GetMsg(port)
    D0               A0

    struct [Message](autodocs-2.0/includes-exec-ports-h.md) *GetMsg(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *);
```
FUNCTION

```c
    This function receives a message from a given message port. It
    provides a fast, non-copying message receiving mechanism. The
    received message is removed from the message port.

    This function will not wait.  If a message is not present this
    function will return zero.  If a program must wait for a message,
    it can [Wait()](autodocs-2.0/exec-library-wait.md) on the signal specified for the port or use the
    [WaitPort()](autodocs-2.0/exec-library-waitport.md) function.  There can only be one task waiting for any
    given port.

    Getting a message does not imply to the sender that the message is
    free to be reused by the sender.  When the receiver is finished
    with the message, it may [ReplyMsg()](autodocs-2.0/exec-library-replymsg.md) it back to the sender.


    Getting a signal does NOT always imply a message is ready.  More
    than one message may arrive per signal, and signals may show up
    without messages.  Typically you must loop to GetMsg() until it
    returns zero, then [Wait()](autodocs-2.0/exec-library-wait.md) or [WaitPort()](autodocs-2.0/exec-library-waitport.md).
```
INPUT

    port - a pointer to the receiver message port
RESULT

    message - a pointer to the first message available.  If
              there are no messages, return zero.
              Callers must be prepared for zero at any time.
SEE ALSO

```c
    [PutMsg](autodocs-2.0/exec-library-putmsg.md), [ReplyMsg](autodocs-2.0/exec-library-replymsg.md), [WaitPort](autodocs-2.0/exec-library-waitport.md), Wait, [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md)
```

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
