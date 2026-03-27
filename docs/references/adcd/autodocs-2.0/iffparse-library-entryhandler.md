---
title: iffparse.library/EntryHandler
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-entryhandler
functions: [ExitHandler, ParseIFF, StopChunk, StoreItemInContext, StoreLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/EntryHandler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    EntryHandler -- Add an entry handler to the [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) context.
```
SYNOPSIS

```c
    error = EntryHandler (iff, type, id, position, hook, object)
     d0                   a0    d0   d1    d2       a1     a2

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    LONG             type, id, position;
    struct [Hook](autodocs-2.0/includes-utility-hooks-h.md)     *hook;
    APTR             object;
```
FUNCTION

```c
    Installs an entry handler vector for a specific type of chunk into
    the context for the given [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.  Type and id are the
    longword identifiers for the chunk to handle.  The hook is a client-
    supplied standard 2.0 [Hook](autodocs-2.0/includes-utility-hooks-h.md) structure, properly initialized.  Position
    tells where to put the handler in the context.  The handler will be
    called whenever the parser enters a chunk of the given type, so the
    IFF stream will be positioned to read the first data byte in the
    chunk.  The handler will execute in the same context as whoever
    called [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md).  The handler will be called (through the hook)
    with the following arguments:

            A0:     the [Hook](autodocs-2.0/includes-utility-hooks-h.md) pointer you passed.
            A2:     the 'object' pointer you passed.
            A1:     pointer to a LONG containing the value
                    IFFCMD_ENTRY.

    The error code your call-back routine returns will affect the parser
    in three different ways:

    Return value            Result
    ------------            ------
    0:                      Normal success;  [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md) will continue
                            through the file.
    IFF_RETURN2CLIENT:      [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md) will stop and return the value 0.
                            (StopChunk() is internally implemented using
                            this return value.)
    Any other value:        [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md) will stop and return the value
                            you supplied.  This is how errors should be
                            returned.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    type    - type code for chunk to handle (ex. "ILBM").
    id      - ID code for chunk to handle (ex. "CMAP").
    position- Local context item position.  One of the IFFSLI_#? codes.
    hook    - pointer to [Hook](autodocs-2.0/includes-utility-hooks-h.md) structure.
    object  - a client-defined pointer which is passed in A2 during call-
              back.
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

    Returning the values IFFERR_EOF or IFFERR_EOC from the call-back
    routine *may* confuse the parser.

    There is no way to explicitly remove a handler once installed.
    However, by installing a do-nothing handler using IFFSLI_TOP,
    previous handlers will be overridden until the context expires.
SEE ALSO

```c
    [ExitHandler()](autodocs-2.0/iffparse-library-exithandler.md), [StoreLocalItem()](autodocs-2.0/iffparse-library-storelocalitem.md), [StoreItemInContext()](autodocs-2.0/iffparse-library-storeitemincontext.md),
    [utility/hooks.h](autodocs-2.0/includes-utility-hooks-h.md)
```

---

## See Also

- [ExitHandler — iffparse.library](../autodocs/iffparse.library.md#exithandler)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)
- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)
- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)
