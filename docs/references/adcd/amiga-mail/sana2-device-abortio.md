---
title: sana2.device/AbortIO
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-abortio
functions: [AbortIO, WaitIO]
libraries: [exec.library, timer.device]
---

# sana2.device/AbortIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AbortIO -- Remove an existing device request.
SYNOPSIS

```c
    error = AbortIO(Sana2Req)
    D0              A1

    LONG AbortIO(struct IOSana2Req *);
```
FUNCTION

```c
    This is an exec.library call.

    This function aborts an ioRequest. If the request is active, it may or
    may not be aborted. If the request is queued it is removed. The
    request will be returned in the same way as if it had normally
    completed.  You must WaitIO() after AbortIO() for the request to
    return.
```
INPUTS

    Sana2Req        - Sana2Req to be aborted.
RESULTS

    error           - Zero if the request was aborted, non-zero otherwise.
                      io_Error in Sana2Req will be set to IOERR_ABORTED
                      if it was aborted.
NOTES

SEE ALSO

```c
    exec.library/AbortIO(), exec.library/WaitIO()
```
BUGS

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
