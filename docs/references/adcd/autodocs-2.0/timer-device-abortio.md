---
title: timer.device/AbortIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: timer-device-abortio
functions: [AbortIO]
libraries: [timer.device]
---

# timer.device/AbortIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AbortIO -- Remove an existing timer request.
SYNOPSIS

```c
    error = AbortIO( [timerequest](autodocs-2.0/includes-devices-timer-h.md) )
    D0               A1

    LONG AbortIO( struct [timerequest](autodocs-2.0/includes-devices-timer-h.md) * );
```
FUNCTION

    This is an exec.library call.

    This routine removes a timerquest from the timer.  It runs in
    the context of the caller.
INPUTS

```c
    [timerequest](autodocs-2.0/includes-devices-timer-h.md) - the timer request to be aborted
```
RETURNS

    0  if the request was aborted, io_Error will also be set to
        IOERR_ABORTED.
    -1 otherwise
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    exec.library/AbortIO()
```
BUGS

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
