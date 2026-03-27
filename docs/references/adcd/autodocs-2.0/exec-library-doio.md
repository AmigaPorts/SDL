---
title: exec.library/DoIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-doio
functions: [DoIO, OpenDevice]
libraries: [exec.library]
---

# exec.library/DoIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    DoIO -- perform an I/O command and wait for completion
SYNOPSIS

```c
    error = DoIO(iORequest)
    D0           A1

    BYTE DoIO(struct [IORequest](autodocs-2.0/includes-exec-io-h.md) *);
```
FUNCTION

```c
    This function requests a device driver to perform the I/O command
    specified in the I/O request.  This function will always wait until
    the I/O request is fully complete.

    DoIO() handles all the details, including Quick I/O, waiting for
    the request, and removing the reply message, etc..
```
IMPLEMENTATION

```c
    This function first tries to complete the IO via the "Quick I/O"
    mechanism.  The io_Flags field is always set to IOF_QUICK (0x01)
    before the internal device call.

    The LN_TYPE field is used internally to flag completion.  Active
    requests have type NT_MESSAGE.  Requests that have been replied
    have type NT_REPLYMSG.  It is illegal to start IO using a
    still active [IORequest](autodocs-2.0/includes-exec-io-h.md), or a request with type NT_REPLYMSG.
```
INPUTS

```c
    iORequest - pointer to an [IORequest](autodocs-2.0/includes-exec-io-h.md) initialized by [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
```
RESULTS

```c
    error - a sign-extended copy of the io_Error field of the
            [IORequest](autodocs-2.0/includes-exec-io-h.md).  Most device commands require that the error
            return be checked.
```
SEE ALSO

```c
    [SendIO](autodocs-2.0/exec-library-sendio.md), [CheckIO](autodocs-2.0/exec-library-checkio.md), [WaitIO](autodocs-2.0/exec-library-waitio.md), [AbortIO](autodocs-2.0/timer-device-abortio.md), [amiga.lib/BeginIO](autodocs-2.0/serial-device-beginio.md)
```

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
