---
title: exec.library/WaitPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-waitport
functions: [GetMsg, Wait]
libraries: [exec.library]
---

# exec.library/WaitPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    WaitPort -- wait for a given port to be non-empty
SYNOPSIS

```c
    message = WaitPort(port)
    D0                 A0

    struct [Message](autodocs-2.0/includes-exec-ports-h.md) *WaitPort(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *);
```
FUNCTION

```c
    This function waits for the given port to become non-empty.  If
    necessary, the [Wait()](autodocs-2.0/exec-library-wait.md) function will be called to wait for the port
    signal.  If a message is already present at the port, this function
    will return immediately.  The return value is always a pointer to
    the first message queued (but it is not removed from the queue).
```
CAUTION

```c
    More than one message may be at the port when this returns.  It is
    proper to call the [GetMsg()](autodocs-2.0/exec-library-getmsg.md) function in a loop until all messages
    have been handled, then wait for more to arrive.

    To wait for more than one port, combine the signal bits from each
    port into one call to the [Wait()](autodocs-2.0/exec-library-wait.md) function, then use a [GetMsg()](autodocs-2.0/exec-library-getmsg.md) loop
    to collect any and all messages.  It is possible to get a signal
    for a port WITHOUT a message showing up.  Plan for this.
```
INPUT

    port - a pointer to the message port
RETURN

    message - a pointer to the first available message
SEE ALSO

```c
    [GetMsg](autodocs-2.0/exec-library-getmsg.md)
```

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
