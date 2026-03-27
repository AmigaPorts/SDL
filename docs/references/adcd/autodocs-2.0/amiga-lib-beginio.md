---
title: amiga.lib/BeginIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-beginio
functions: [DoIO, SendIO, WaitIO]
libraries: [exec.library]
---

# amiga.lib/BeginIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    BeginIO -- initiate asynchronous device I/O
SYNOPSIS

```c
    BeginIO(ioReq)

    VOID BeginIO(struct [IORequest](autodocs-2.0/includes-exec-io-h.md) *);
```
FUNCTION

```c
    This function takes an [IORequest](autodocs-2.0/includes-exec-io-h.md), and passes it directly to the
    "BeginIO" vector of the proper device.  This is equivalent to
    [SendIO()](autodocs-2.0/exec-library-sendio.md), except that io_Flags is not cleared. A good understanding
    of Exec device I/O is required to properly use this function.

    This function does not wait for the I/O to complete.
```
INPUTS

```c
    ioReq - an initialized and opened [IORequest](autodocs-2.0/includes-exec-io-h.md) structure with the
            io_Flags field set to a reasonable value (set to 0 if you do
            not require io_Flags).
```
SEE ALSO

```c
    [exec.library/DoIO()](autodocs-2.0/exec-library-doio.md), [exec.library/SendIO()](autodocs-2.0/exec-library-sendio.md), [exec.library/WaitIO()](autodocs-2.0/exec-library-waitio.md)
```

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
