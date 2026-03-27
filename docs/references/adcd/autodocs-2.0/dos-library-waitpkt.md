---
title: dos.library/WaitPkt
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-waitpkt
functions: [DoPkt, GetMsg, SendPkt, WaitPkt]
libraries: [dos.library, exec.library]
---

# dos.library/WaitPkt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    WaitPkt -- Waits for a packet to arrive at your pr_MsgPort (V36)
```
SYNOPSIS

```c
    packet = WaitPkt()
    D0

    struct [DosPacket](autodocs-2.0/includes-dos-dosextens-h.md) *WaitPkt(void);
```
FUNCTION

```c
    Waits for a packet to arrive at your pr_MsgPort.  If anyone has
    installed a packet wait function in pr_PktWait, it will be called.
    The message will be automatically GetMsg()ed so that it is no longer
    on the port.  It assumes the message is a dos packet.  It is NOT
    guaranteed to clear the signal for the port.
```
RESULT

```c
    packet - the packet that arrived at the port (from ln_Name of message).
```
SEE ALSO

```c
    [SendPkt()](autodocs-2.0/dos-library-sendpkt.md), [DoPkt()](autodocs-2.0/dos-library-dopkt.md), [AbortPkt()](autodocs-2.0/dos-library-abortpkt.md)
```

---

## See Also

- [DoPkt — dos.library](../autodocs/dos.library.md#dopkt)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [SendPkt — dos.library](../autodocs/dos.library.md#sendpkt)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)
