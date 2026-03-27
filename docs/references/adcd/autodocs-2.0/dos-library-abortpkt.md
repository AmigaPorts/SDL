---
title: dos.library/AbortPkt
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-abortpkt
functions: [DoPkt, SendPkt, WaitPkt]
libraries: [dos.library]
---

# dos.library/AbortPkt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AbortPkt -- Aborts an asynchronous packet, if possible. (V36)
```
SYNOPSIS

```c
    AbortPkt(port, pkt)
              D1    D2

    void AbortPkt(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *, struct [DosPacket](autodocs-2.0/includes-dos-dosextens-h.md) *)
```
FUNCTION

```c
    This attempts to abort a packet sent earlier with [SendPkt](autodocs-2.0/dos-library-sendpkt.md) to a
    handler.  There is no guarantee that any given handler will allow
    a packet to be aborted, or if it is aborted whether function
    requested completed first or completely.  After calling AbortPkt(),
    you must wait for the packet to return before reusing it or
    deallocating it.
```
INPUTS

    port - port the packet was sent to
    pkt  - the packet you wish aborted
BUGS

    As of V37, this function does nothing.
SEE ALSO

```c
    [SendPkt()](autodocs-2.0/dos-library-sendpkt.md), [DoPkt()](autodocs-2.0/dos-library-dopkt.md), [WaitPkt()](autodocs-2.0/dos-library-waitpkt.md)
```

---

## See Also

- [DoPkt — dos.library](../autodocs/dos.library.md#dopkt)
- [SendPkt — dos.library](../autodocs/dos.library.md#sendpkt)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)
