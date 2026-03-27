---
title: asl.library/FreeAslRequest
manual: autodocs-2.0
chapter: autodocs-2.0
section: asl-library-freeaslrequest
functions: [AllocAslRequest, AllocFileRequest, AslRequest, FreeAslRequest]
libraries: [asl.library]
---

# asl.library/FreeAslRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeAslRequest - frees requester obtained from [AllocAslRequest](autodocs-2.0/asl-library-allocaslrequest.md) (V36)
```
SYNOPSIS

```c
    FreeAslRequest( request )
                    A0

    APTR request;
```
FUNCTION

```c
    FreeAslRequest() is used to free the structure returned by
    [AllocAslRequest()](autodocs-2.0/asl-library-allocaslrequest.md) or [AllocFileRequest()](autodocs-2.0/asl-library-allocfilerequest.md), in order to free
    all resources associated with that requester after the
    application has completed all use of the data structures.
```
INPUTS

```c
    request - value returned from [AllocAslRequest()](autodocs-2.0/asl-library-allocaslrequest.md) or
                    [AllocFileRequest()](autodocs-2.0/asl-library-allocfilerequest.md).
```
RESULT

    None.  All resources associated with the request will be
    freed.
SEE ALSO

```c
    [AllocAslRequest()](autodocs-2.0/asl-library-allocaslrequest.md), [AslRequest()](autodocs-2.0/asl-library-aslrequest.md), [AllocFileRequest()](autodocs-2.0/asl-library-allocfilerequest.md)
```

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [AllocFileRequest — asl.library](../autodocs/asl.library.md#allocfilerequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
- [FreeAslRequest — asl.library](../autodocs/asl.library.md#freeaslrequest)
