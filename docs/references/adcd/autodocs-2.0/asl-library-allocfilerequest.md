---
title: asl.library/AllocFileRequest
manual: autodocs-2.0
chapter: autodocs-2.0
section: asl-library-allocfilerequest
functions: [AllocAslRequest, AllocFileRequest, AslRequest, FreeAslRequest, RequestFile]
libraries: [asl.library]
---

# asl.library/AllocFileRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AllocFileRequest -- allocates a [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) structure (V36)
```
SYNOPSIS

```c
    request = AllocFileRequest()
    D0

    struct [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) *request;
```
FUNCTION

```c
    Creates and initializes the data structure required to pass to the
    [RequestFile()](autodocs-2.0/asl-library-requestfile.md) function.
```
INPUTS

```c
    None.  If you wish to get other than default values, you can use
    [AllocAslRequest()](autodocs-2.0/asl-library-allocaslrequest.md) to set up a file request with tag items.
```
RESULT

```c
    Pointer to a struct [FileRequester](autodocs-2.0/includes-libraries-asl-h.md), which is to be passed to the
    [RequestFile()](autodocs-2.0/asl-library-requestfile.md) function.

    The returned [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) pointer has public fields which are
    readable by the application as defined in aslbase.h.
```
CAUTION

```c
    The application MUST use either the AllocFileRequest(), or
    [AllocAslRequest()](autodocs-2.0/asl-library-allocaslrequest.md), function to allocate the structure to be passed to
    the FileRequest() or [AslRequest()](autodocs-2.0/asl-library-aslrequest.md) functions; it is not possible to
    create a struct FileRequest except through the library calls.

    Also, any modifications MUST be done through [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) values, rather
    than directly modifying, unless explicitly documented otherwise.
```
SEE ALSO

```c
    [RequestFile()](autodocs-2.0/asl-library-requestfile.md), [FreeAslRequest()](autodocs-2.0/asl-library-freeaslrequest.md), [AslRequest()](autodocs-2.0/asl-library-aslrequest.md)
```

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [AllocFileRequest — asl.library](../autodocs/asl.library.md#allocfilerequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
- [FreeAslRequest — asl.library](../autodocs/asl.library.md#freeaslrequest)
- [RequestFile — asl.library](../autodocs/asl.library.md#requestfile)
