---
title: amiga.lib/CreateExtIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-createextio
functions: [CreateMsgPort]
libraries: [exec.library]
---

# amiga.lib/CreateExtIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CreateExtIO -- create an [IORequest](autodocs-2.0/includes-exec-io-h.md) structure
```
SYNOPSIS

```c
    ioReq = CreateExtIO(port,ioSize);

    struct [IORequest](autodocs-2.0/includes-exec-io-h.md) *CreateExtIO(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *, ULONG);
```
FUNCTION

```c
    Allocates memory for and initializes a new IO request block
    of a user-specified number of bytes. The number of bytes
    MUST be the size of a legal [IORequest](autodocs-2.0/includes-exec-io-h.md) (or extended IORequest)
    or very nasty things will happen.
```
INPUTS

    port - an already initialized message port to be used for this IO
           request's reply port. If this is NULL this function fails.
    ioSize - the size of the IO request to be created.
RESULT

    ioReq - a new IO Request block, or NULL if there was not enough memory
EXAMPLE

```c
    if (ioReq = CreateExtIO(CreatePort(NULL,0),sizeof(struct IOExtTD)))
```
SEE ALSO

```c
    [DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md), [CreatePort()](autodocs-2.0/amiga-lib-createport.md), [exec.library/CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md)
```

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
