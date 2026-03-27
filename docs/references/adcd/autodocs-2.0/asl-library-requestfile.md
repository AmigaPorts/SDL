---
title: asl.library/RequestFile
manual: autodocs-2.0
chapter: autodocs-2.0
section: asl-library-requestfile
functions: [AllocFileRequest, AslRequest, FreeFileRequest, RequestFile]
libraries: [asl.library]
---

# asl.library/RequestFile

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RequestFile -- request user to select file(s) (V36)
```
SYNOPSIS

```c
    BOOL result = RequestFile( request )
    D0                         A0

    BOOL    result;
    struct [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) *request;
```
FUNCTION

```c
    RequestFile() displays a file requester and waits for the user to
    select filenames or cancel the request.  This function is identical
    to the [AslRequest()](autodocs-2.0/asl-library-aslrequest.md) function, except that there is no TagList to
    modify the settings for the requester.  See [AslRequest()](autodocs-2.0/asl-library-aslrequest.md) for details.
```
INPUT

```c
    request = struct [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) * returned by [AllocFileRequest()](autodocs-2.0/asl-library-allocfilerequest.md).
```
RESULT

```c
    result - See [AslRequest()](autodocs-2.0/asl-library-aslrequest.md) result.  NULL indicates cancelled.
```
SEE ALSO

```c
    [AllocFileRequest()](autodocs-2.0/asl-library-allocfilerequest.md), [FreeFileRequest()](autodocs-2.0/asl-library-freefilerequest.md), [AslRequest()](autodocs-2.0/asl-library-aslrequest.md)
```

---

## See Also

- [AllocFileRequest — asl.library](../autodocs/asl.library.md#allocfilerequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
- [FreeFileRequest — asl.library](../autodocs/asl.library.md#freefilerequest)
- [RequestFile — asl.library](../autodocs/asl.library.md#requestfile)
