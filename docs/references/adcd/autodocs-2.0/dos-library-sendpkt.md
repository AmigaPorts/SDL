---
title: dos.library/SendPkt
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-sendpkt
functions: [AllocDosObject, DoPkt, FreeDosObject, WaitPkt]
libraries: [dos.library]
---

# dos.library/SendPkt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SendPkt -- Sends a packet to a handler (V36)
```
SYNOPSIS

```c
    SendPkt(packet, port, replyport)
             D1     D2      D3

    void SendPkt(struct [DosPacket](autodocs-2.0/includes-dos-dosextens-h.md) *,struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *,struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *)
```
FUNCTION

```c
    Sends a packet to a handler and does not wait.  All fields in the
    packet must be initialized before calling this routine.  The packet
    will be returned to replyport.  If you wish to use this with
    [WaitPkt()](autodocs-2.0/dos-library-waitpkt.md), use the address or your pr_MsgPort for replyport.
```
INPUTS

```c
    packet - packet to send, must be initialized and have a message.
    port   - pr_MsgPort of handler process to send to.
    replyport - [MsgPort](autodocs-2.0/includes-exec-ports-h.md) for the packet to come back to.
```
NOTES

    Callable from a task.
SEE ALSO

```c
    [DoPkt()](autodocs-2.0/dos-library-dopkt.md), [WaitPkt()](autodocs-2.0/dos-library-waitpkt.md), [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md), [FreeDosObject()](autodocs-2.0/dos-library-freedosobject.md), [AbortPkt()](autodocs-2.0/dos-library-abortpkt.md)
```

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [DoPkt — dos.library](../autodocs/dos.library.md#dopkt)
- [FreeDosObject — dos.library](../autodocs/dos.library.md#freedosobject)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)
