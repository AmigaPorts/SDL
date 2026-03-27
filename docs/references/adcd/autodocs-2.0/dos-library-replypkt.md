---
title: dos.library/ReplyPkt
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-replypkt
functions: [DoPkt, IoErr, ReplyPkt, SendPkt, WaitPkt]
libraries: [dos.library]
---

# dos.library/ReplyPkt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ReplyPkt -- replies a packet to the person who sent it to you (V36)
```
SYNOPSIS

```c
    ReplyPkt(packet, result1, result2)
               D1      D2       D3

    void ReplyPkt(struct [DosPacket](autodocs-2.0/includes-dos-dosextens-h.md) *, LONG, LONG)
```
FUNCTION

```c
    This returns a packet to the process which sent it to you.  In
    addition, puts your pr_MsgPort address in dp_Port, so using ReplyPkt()
    again will send the message to you.  (This is used in "ping-ponging"
    packets between two processes).  It uses result 1 & 2 to set the
    dp_Res1 and dp_Res2 fields of the packet.
```
INPUTS

    packet  - packet to reply, assumed to set up correctly.
    result1 - first result
    result2 - secondary result
SEE ALSO

```c
    [DoPkt()](autodocs-2.0/dos-library-dopkt.md), [SendPkt()](autodocs-2.0/dos-library-sendpkt.md), [WaitPkt()](autodocs-2.0/dos-library-waitpkt.md), [IoErr()](autodocs-2.0/dos-library-ioerr.md)
```

---

## See Also

- [DoPkt — dos.library](../autodocs/dos.library.md#dopkt)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [ReplyPkt — dos.library](../autodocs/dos.library.md#replypkt)
- [SendPkt — dos.library](../autodocs/dos.library.md#sendpkt)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)
