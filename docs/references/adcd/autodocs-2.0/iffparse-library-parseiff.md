---
title: iffparse.library/ParseIFF
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-parseiff
functions: [EntryHandler, ExitHandler, ParseIFF, PopChunk, PushChunk, StopChunk, StopOnExit]
libraries: [iffparse.library]
---

# iffparse.library/ParseIFF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ParseIFF -- Parse an IFF file from an [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct stream.
```
SYNOPSIS

```c
    error = ParseIFF (iff, control)
     d0               a0     d0

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    LONG             control;
```
FUNCTION

```c
    This is the biggie.

    Traverses a file opened for read by pushing chunks onto the context
    stack and popping them off directed by the generic syntax of IFF
    files.  As it pushes each new chunk, it searches the context stack
    for handlers to apply to chunks of that type.  If it finds an entry
    handler it will invoke it just after entering the chunk.  If it finds
    an exit handler it will invoke it just before leaving the chunk.
    Standard handlers include entry handlers for pre-declared
    property chunks and collection chunks and entry and exit handlers for
    for stop chunks - that is, chunks which will cause the ParseIFF()
    function to return control to the client.  Client programs can also
    provide their own custom handlers.

    The control flag can have three values:

    IFFPARSE_SCAN:
            In this normal mode, ParseIFF() will only return control to
            the caller when either:
                    1) an error is encountered,
                    2) a stop chunk is encountered, or a user handler
                       returns the special IFF_RETURN2CLIENT code, or
                    3) the end of the logical file is reached, in which
                       case IFFERR_EOF is returned.

            ParseIFF() will continue pushing and popping chunks until one
            of these conditions occurs.  If ParseIFF() is called again
            after returning, it will continue to parse the file where it
            left off.

    IFFPARSE_STEP and _RAWSTEP:
            In these two modes, ParseIFF() will return control to the
            caller after every step in the parse, specifically, after
            each push of a context node and just before each pop.  If
            returning just before a pop, ParseIFF() will return
            IFFERR_EOC, which is not an error, per se, but is just an
            indication that the most recent context is ending.  In STEP
            mode, ParseIFF() will invoke the handlers for chunks, if
            any, before returning.  In RAWSTEP mode, ParseIFF() will not
            invoke any handlers and will return right away.  In both
            cases the function can be called multiple times to step
            through the parsing of the IFF file.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    control - control code (IFFPARSE_SCAN, _STEP or _RAWSTEP).
```
RESULT

    error   - 0 or IFFERR_#? value or return value from user handler.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PushChunk()](autodocs-2.0/iffparse-library-pushchunk.md), [PopChunk()](autodocs-2.0/iffparse-library-popchunk.md), [EntryHandler()](autodocs-2.0/iffparse-library-entryhandler.md), [ExitHandler()](autodocs-2.0/iffparse-library-exithandler.md),
    PropChunk[s](), CollectionChunk[s](), [StopChunk()](autodocs-2.0/iffparse-library-stopchunk.md), [StopOnExit()](autodocs-2.0/iffparse-library-stoponexit.md)
```

---

## See Also

- [EntryHandler — iffparse.library](../autodocs/iffparse.library.md#entryhandler)
- [ExitHandler — iffparse.library](../autodocs/iffparse.library.md#exithandler)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)
- [StopOnExit — iffparse.library](../autodocs/iffparse.library.md#stoponexit)
