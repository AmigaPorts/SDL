---
title: asl.library/FreeFileRequest
manual: autodocs-2.0
chapter: autodocs-2.0
section: asl-library-freefilerequest
functions: [AllocFileRequest, FreeAslRequest, FreeFileRequest]
libraries: [asl.library]
---

# asl.library/FreeFileRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeFileRequest -- frees requester allocated by [AllocFileRequest](autodocs-2.0/asl-library-allocfilerequest.md) (V36)
```
SYNOPSIS

```c
    FreeFileRequest( request )
                     A0

    struct [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) *request;
```
FUNCTION

```c
    This function is identical to the [FreeAslRequest()](autodocs-2.0/asl-library-freeaslrequest.md) function, but is
    documented for source code compatability and ease of use.
    Applications may use either [FreeAslRequest()](autodocs-2.0/asl-library-freeaslrequest.md) or FreeFileRequest() to
    free the data structures allocated by [AllocFileRequest()](autodocs-2.0/asl-library-allocfilerequest.md).
```
INPUTS

```c
    request = the return value from [AllocFileRequest()](autodocs-2.0/asl-library-allocfilerequest.md).
```
SEE ALSO

```c
    [FreeAslRequest()](autodocs-2.0/asl-library-freeaslrequest.md)
```

---

## See Also

- [AllocFileRequest — asl.library](../autodocs/asl.library.md#allocfilerequest)
- [FreeAslRequest — asl.library](../autodocs/asl.library.md#freeaslrequest)
- [FreeFileRequest — asl.library](../autodocs/asl.library.md#freefilerequest)
