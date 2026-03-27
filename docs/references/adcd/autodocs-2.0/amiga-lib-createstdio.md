---
title: amiga.lib/CreateStdIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-createstdio
functions: [CreateIORequest]
libraries: [exec.library]
---

# amiga.lib/CreateStdIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CreateStdIO -- create an [IOStdReq](autodocs-2.0/includes-exec-io-h.md) structure
```
SYNOPSIS

```c
    ioReq = CreateStdIO(port);

    struct [IOStdReq](autodocs-2.0/includes-exec-io-h.md) *CreateStdIO(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *)
```
FUNCTION

```c
    Allocates memory for and initializes a new [IOStdReq](autodocs-2.0/includes-exec-io-h.md) structure.
```
INPUTS

    port - an already initialized message port to be used for this IO
           request's reply port. If this is NULL this function fails.
RESULT

```c
    ioReq - a new [IOStdReq](autodocs-2.0/includes-exec-io-h.md) structure, or NULL if there was not enough
            memory
```
SEE ALSO

```c
    [DeleteStdIO()](autodocs-2.0/amiga-lib-deletestdio.md), [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md), [exec.library/CreateIORequest()](autodocs-2.0/exec-library-createiorequest.md)
```

---

## See Also

- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
