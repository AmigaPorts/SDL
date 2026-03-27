---
title: asl.library/AllocAslRequest
manual: autodocs-2.0
chapter: autodocs-2.0
section: asl-library-allocaslrequest
functions: [AslRequest, FreeAslRequest]
libraries: [asl.library]
---

# asl.library/AllocAslRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AllocAslRequest -- alloc an ASL requester, with [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) modifiers (V36)
```
SYNOPSIS

```c
    request = AllocAslRequest( type, ptags )
    D0                         D0    A0

    APTR    request;
    ulong   type;
    struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md)       *ptags;
```
FUNCTION

```c
    Allocates an ASL requester data structure of the specified type,
    with optional [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) modifiers.
```
INPUTS

```c
    type = type of requester to create.  Currently defined types
        include ASL_FileRequest and ASL_FontRequest.
    ptags = pointer to a tagitem array, which is defined for each
        specified type.  See "asl.h" and example programs for usage
        of various tag types.  See [AslRequest()](autodocs-2.0/asl-library-aslrequest.md) for specifications
        of currently defined tag values and their effects.

    Note that tag values stay in effect for each use of the
    requester until they are cleared or modified by passing the
    same tag with a new value.

    AllocAslRequestTags( type, tags... ) which accepts your tags
    on the stack, is available in amiga.lib.

    Example Usage: AllocAslRequestTags( ASL_FileRequest,
                                        ASL_Hail, "My Title Bar",
                                        TAG_DONE );
```
RESULT

```c
    Pointer to an initialized requester data structure, or NULL on
    failure.  The data structure returned will match the requested
    type; for type ASL_FileRequest, a struct [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) *; for
    ASL_FontRequest, a struct [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) *.

    The requester returned may then be passed to [AslRequest()](autodocs-2.0/asl-library-aslrequest.md), and
    is freed by calling [FreeAslRequest()](autodocs-2.0/asl-library-freeaslrequest.md).
```
SEE ALSO

```c
    [AslRequest()](autodocs-2.0/asl-library-aslrequest.md), [FreeAslRequest()](autodocs-2.0/asl-library-freeaslrequest.md)
```

---

## See Also

- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
- [FreeAslRequest — asl.library](../autodocs/asl.library.md#freeaslrequest)
