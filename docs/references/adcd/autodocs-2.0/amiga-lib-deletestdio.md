---
title: amiga.lib/DeleteStdIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-deletestdio
functions: [CreateIORequest]
libraries: [exec.library]
---

# amiga.lib/DeleteStdIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DeleteStdIO - return memory allocated for [IOStdReq](autodocs-2.0/includes-exec-io-h.md)
```
SYNOPSIS

```c
    DeleteStdIO(ioReq);

    VOID DeleteStdIO(struct [IOStdReq](autodocs-2.0/includes-exec-io-h.md) *);
```
FUNCTION

```c
    Frees up an [IOStdReq](autodocs-2.0/includes-exec-io-h.md) as allocated by [CreateStdIO()](autodocs-2.0/amiga-lib-createstdio.md).
```
INPUTS

```c
    ioReq - the [IORequest](autodocs-2.0/includes-exec-io-h.md) block to be freed, or NULL.
```
SEE ALSO

```c
    [CreateStdIO()](autodocs-2.0/amiga-lib-createstdio.md), [DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md), [exec.library/CreateIORequest()](autodocs-2.0/exec-library-createiorequest.md)
```

---

## See Also

- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
