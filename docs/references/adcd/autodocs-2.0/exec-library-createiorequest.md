---
title: exec.library/CreateIORequest
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-createiorequest
functions: [CreateIORequest, CreateMsgPort]
libraries: [exec.library]
---

# exec.library/CreateIORequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CreateIORequest() -- create an [IORequest](autodocs-2.0/includes-exec-io-h.md) structure  (V36)
```
SYNOPSIS

```c
    ioReq = CreateIORequest( ioReplyPort, size );
                             A0           D0

    struct [IORequest](autodocs-2.0/includes-exec-io-h.md) *CreateIORequest(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *, ULONG);
```
FUNCTION

    Allocates memory for and initializes a new IO request block
    of a user-specified number of bytes.  The number of bytes
    must be at least as large as a "struct Message".
INPUTS

```c
    ioReplyPort - Pointer to a port for replies (an initialized message
            port, as created by [CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md) ).  If NULL, this
            function fails.
    size - the size of the IO request to be created.
```
RESULT

```c
    ioReq - A pointer to the new [IORequest](autodocs-2.0/includes-exec-io-h.md) block, or NULL.
```
SEE ALSO

```c
    [DeleteIORequest](autodocs-2.0/exec-library-deleteiorequest.md), [CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md), [amiga.lib/CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)
```

---

## See Also

- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
