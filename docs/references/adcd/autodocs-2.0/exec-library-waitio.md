---
title: exec.library/WaitIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-waitio
functions: [Remove, Wait, WaitIO]
libraries: [exec.library]
---

# exec.library/WaitIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    WaitIO -- wait for completion of an I/O request
SYNOPSIS

```c
    error = WaitIO(iORequest)
    D0             A1

    BYTE WaitIO(struct [IORequest](autodocs-2.0/includes-exec-io-h.md) *);
```
FUNCTION

```c
    This function waits for the specified I/O request to complete, then
    removes it from the replyport.  If the I/O has already completed,
    this function will return immediately.

    This function should be used with care, as it does not return until
    the I/O request completes; if the I/O never completes, this
    function will never return, and your task will hang.  If this
    situation is a possibility, it is safer to use the [Wait()](autodocs-2.0/exec-library-wait.md) function.
    [Wait()](autodocs-2.0/exec-library-wait.md) will return return when any of a specified set of signal is
    received.  This is how I/O timeouts can be properly handled.
```
WARNING

```c
    If this [IORequest](autodocs-2.0/includes-exec-io-h.md) was "Quick" or otherwise finished BEFORE this
    call, this function drops though immediately, with no call to
    [Wait()](autodocs-2.0/exec-library-wait.md).  A side effect is that the signal bit related the port may
    remain set.  Expect this.

    When removing a known complete [IORequest](autodocs-2.0/includes-exec-io-h.md) from a port, WaitIO() is the
    preferred method.  A simple [Remove()](autodocs-2.0/exec-library-remove.md) would require a Disable/Enable
    pair!
```
INPUTS

    iORequest - pointer to an I/O request block
RESULTS

```c
    error - zero if successful, else an error is returned
            (a sign extended copy of io_Error).
```
SEE ALSO

```c
    [DoIO](autodocs-2.0/exec-library-doio.md), [SendIO](autodocs-2.0/exec-library-sendio.md), [CheckIO](autodocs-2.0/exec-library-checkio.md), [AbortIO](autodocs-2.0/timer-device-abortio.md)
```

---

## See Also

- [Remove — exec.library](../autodocs/exec.library.md#remove)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
