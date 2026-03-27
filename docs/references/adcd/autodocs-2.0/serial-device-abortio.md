---
title: serial.device/AbortIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: serial-device-abortio
functions: [AbortIO, WaitIO]
libraries: [exec.library, timer.device]
---

# serial.device/AbortIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AbortIO(ioRequest) -- abort an I/O request
            A1
```
FUNCTION

```c
    This is an exec.library call.

    This function attempts to aborts a specified read or write request.
    If the request is active, it is stopped immediately. If the request is
    queued, it is painlessly removed.  The request will be returned
    in the same way any completed request it.

    After AbortIO(), you must generally do a [WaitIO()](autodocs-2.0/exec-library-waitio.md).
```
INPUTS

```c
    iORequest  -- pointer to the [IORequest](autodocs-2.0/includes-exec-io-h.md) Block that is to be aborted.
```
RESULTS

```c
    io_Error -- if the Abort succeded, then io_Error will be #IOERR_ABORTED
                (-2) and the request will be flagged as aborted (bit 5 of
                io_Flags is set).  If the Abort failed, then the Error will
                be zero.
```
BUGS

```c
    Previous to version 34, the serial.device would often hang when
    aborting CTS/RTS handshake requests.  This was the cause of the
    incorrect assumption that AbortIO() does not need to be followed
    by a wait for a reply (or a WaitIO()).
```

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
