---
title: exec.library/CheckIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-checkio
functions: [CheckIO, Disable, Remove, WaitIO]
libraries: [exec.library]
---

# exec.library/CheckIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CheckIO -- get the status of an [IORequest](autodocs-2.0/includes-exec-io-h.md)
```
SYNOPSIS

```c
    result = CheckIO(iORequest)
    D0               A1

    BOOL CheckIO(struct [IORequest](autodocs-2.0/includes-exec-io-h.md) *);
```
FUNCTION

```c
    This function determines the current state of an I/O request and
    returns FALSE if the I/O has not yet completed.  This function
    effectively hides the internals of the I/O completion mechanism.

    CheckIO() will NOT remove the returned [IORequest](autodocs-2.0/includes-exec-io-h.md) from the reply port.
    This is best performed with [WaitIO()](autodocs-2.0/exec-library-waitio.md). If the request has already
    completed, [WaitIO()](autodocs-2.0/exec-library-waitio.md) will return quickly. Use of the [Remove()](autodocs-2.0/exec-library-remove.md)
    function is dangerous, since other tasks may still be adding things
    to your message port; a [Disable()](autodocs-2.0/exec-library-disable.md) would be required.

    This function should NOT be used to busy loop (looping until IO is
    complete).  [WaitIO()](autodocs-2.0/exec-library-waitio.md) is provided for that purpose.
```
INPUTS

    iORequest - pointer to an I/O request block
RESULTS

```c
    result - NULL if I/O is still in progress.  Otherwise
             D0 points to the [IORequest](autodocs-2.0/includes-exec-io-h.md) block.
```
NOTE

```c
    CheckIO can hang if called on an [IORequest](autodocs-2.0/includes-exec-io-h.md) that has never been used.
    This occurs if LN_TYPE of the [IORequest](autodocs-2.0/includes-exec-io-h.md) is set to "NT_MESSAGE".
    Instead simply set LN_TYPE to 0.
```
SEE ALSO

```c
    [DoIO](autodocs-2.0/exec-library-doio.md), [SendIO](autodocs-2.0/exec-library-sendio.md), [WaitIO](autodocs-2.0/exec-library-waitio.md), [AbortIO](autodocs-2.0/timer-device-abortio.md)
```

---

## See Also

- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
