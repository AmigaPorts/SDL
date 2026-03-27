---
title: dos.library/DoPkt
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-dopkt
functions: [AllocDosObject, CreateNewProc, DoPkt, FreeDosObject, GetMsg, IoErr, PutMsg, SendPkt, WaitPkt, WaitPort]
libraries: [dos.library, exec.library]
---

# dos.library/DoPkt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DoPkt -- Send a dos packet and wait for reply (V36)
```
SYNOPSIS

```c
    result1 = DoPkt(port,action,arg1,arg2,arg3,arg4,arg5)
    D0               D1    D2    D3   D4   D5   D6   D7

    LONG DoPkt(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *,LONG,LONG,LONG,LONG,LONG,LONG)
```
FUNCTION

```c
    Sends a packet to a handler and waits for it to return.  Any secondary
    return will be available in D1 AND from [IoErr()](autodocs-2.0/dos-library-ioerr.md).  DoPkt() will work
    even if the caller is an exec task and not a process; however it will
    be slower, and may fail for some additional reasons, such as being
    unable to allocate a signal.  DoPkt() uses your pr_MsgPort for the
    reply, and will call pr_PktWait.  (See BUGS regarding tasks, though).

    Only allows 5 arguments to be specified.  For more arguments (packets
    support a maximum of 7) create a packet and use [SendPkt()/WaitPkt()](autodocs-2.0/dos-library-waitpkt.md).
```
INPUTS

    port    - pr_MsgPort of the handler process to send to.
    action  - the action requested of the filesystem/handler
    arg1, arg2, arg3, arg4,arg5 - arguments, depend on the action, may not
               be required.
RESULT

```c
    result1 - the value returned in dp_Res1, or FALSE if there was some
              problem in sending the packet or recieving it.
    result2 - Available from [IoErr()](autodocs-2.0/dos-library-ioerr.md) AND in register D1.
```
BUGS

```c
    Using DoPkt() from tasks doesn't work in V36. Use [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md),
    [PutMsg()](autodocs-2.0/exec-library-putmsg.md), and [WaitPort()/GetMsg()](autodocs-2.0/exec-library-getmsg.md) for a workaround, or you can call
    [CreateNewProc()](autodocs-2.0/dos-library-createnewproc.md) to start a process to do Dos I/O for you.  In V37,
    DoPkt() will allocate, use, and free the [MsgPort](autodocs-2.0/includes-exec-ports-h.md) required.
```
NOTES

```c
    Callable from a task (under V37 and above).
```
SEE ALSO

```c
    [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md), [FreeDosObject()](autodocs-2.0/dos-library-freedosobject.md), [SendPkt()](autodocs-2.0/dos-library-sendpkt.md), [WaitPkt()](autodocs-2.0/dos-library-waitpkt.md),
    [CreateNewProc()](autodocs-2.0/dos-library-createnewproc.md), [AbortPkt()](autodocs-2.0/dos-library-abortpkt.md)
```

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
- [DoPkt — dos.library](../autodocs/dos.library.md#dopkt)
- [FreeDosObject — dos.library](../autodocs/dos.library.md#freedosobject)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PutMsg — exec.library](../autodocs/exec.library.md#putmsg)
- [SendPkt — dos.library](../autodocs/dos.library.md#sendpkt)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
