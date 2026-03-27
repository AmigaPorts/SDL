---
title: exec.library/DeleteIORequest
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-deleteiorequest
functions: [CreateIORequest, DeleteIORequest]
libraries: [exec.library]
---

# exec.library/DeleteIORequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DeleteIORequest() - Free a request made by [CreateIORequest()](autodocs-2.0/exec-library-createiorequest.md)  (V36)
```
SYNOPSIS

```c
    DeleteIORequest( ioReq );
                     a0

    void DeleteIORequest(struct [IORequest](autodocs-2.0/includes-exec-io-h.md) *);
```
FUNCTION

```c
    Frees up an IO request as allocated by [CreateIORequest()](autodocs-2.0/exec-library-createiorequest.md).
```
INPUTS

```c
    ioReq - A pointer to the [IORequest](autodocs-2.0/includes-exec-io-h.md) block to be freed, or NULL.
            This function uses the mn_Length field to determine how
            much memory to free.
```
SEE ALSO

```c
    [CreateIORequest()](autodocs-2.0/exec-library-createiorequest.md), [amiga.lib/DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)
```

---

## See Also

- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
- [DeleteIORequest — exec.library](../autodocs/exec.library.md#deleteiorequest)
