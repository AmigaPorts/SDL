---
title: exec.library/AbortIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-abortio
functions: [AbortIO, Remove]
libraries: [exec.library, timer.device]
---

# exec.library/AbortIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AbortIO - attempt to abort an in-progress I/O request
SYNOPSIS

```c
    AbortIO(iORequest)
            A1

    VOID AbortIO(struct [IORequest](autodocs-2.0/includes-exec-io-h.md) *);
```
FUNCTION

```c
    Ask a device to abort a previously started [IORequest](autodocs-2.0/includes-exec-io-h.md).  This is done
    by calling the device's ABORTIO vector, with your given [IORequest](autodocs-2.0/includes-exec-io-h.md).


    AbortIO is a command the device that may or may not grant.  If
    successful, the device will stop processing the [IORequest](autodocs-2.0/includes-exec-io-h.md), and
    reply to it earlier than it would otherwise have done.
```
NOTE

```c
    AbortIO() does NOT [Remove()](autodocs-2.0/exec-library-remove.md) the [IORequest](autodocs-2.0/includes-exec-io-h.md) from your ReplyPort, OR
    wait for it to complete.  After an AbortIO() you must wait normally
    for the reply message before actually reusing the request.

    If a request has already completed when AbortIO() is called, no
    action is taken.
```
EXAMPLE

```c
        AbortIO(timer_request);
        WaitIO(timer_request);
        /* [Message](autodocs-2.0/includes-exec-ports-h.md) is free to be reused */
```
INPUTS

```c
    iORequest - pointer to an I/O request block (must have been used
            at least once.  May be active or finished).
```
SEE ALSO

```c
    [WaitIO](autodocs-2.0/exec-library-waitio.md), [DoIO](autodocs-2.0/exec-library-doio.md), [SendIO](autodocs-2.0/exec-library-sendio.md), [CheckIO](autodocs-2.0/exec-library-checkio.md)
```

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
