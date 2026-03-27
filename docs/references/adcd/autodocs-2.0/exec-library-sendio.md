---
title: exec.library/SendIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-sendio
functions: []
libraries: []
---

# exec.library/SendIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SendIO -- initiate an I/O command
SYNOPSIS

```c
    SendIO(iORequest)
           A1

    void SendIO(struct [IORequest](autodocs-2.0/includes-exec-io-h.md) *);
```
FUNCTION

```c
    This function requests the device driver start processing the given
    I/O request.  The device will return control without waiting for
    the I/O to complete.

    The io_Flags field of the [IORequest](autodocs-2.0/includes-exec-io-h.md) will be set to zero before the
    request is sent.  See [BeginIO()](autodocs-2.0/serial-device-beginio.md) for more details.
```
INPUTS

```c
    iORequest - pointer to an I/O request, or a device specific
                extended [IORequest](autodocs-2.0/includes-exec-io-h.md).
```
SEE ALSO

```c
    [DoIO](autodocs-2.0/exec-library-doio.md), [CheckIO](autodocs-2.0/exec-library-checkio.md), [WaitIO](autodocs-2.0/exec-library-waitio.md), [AbortIO](autodocs-2.0/timer-device-abortio.md)
```
