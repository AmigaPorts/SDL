---
title: dos.library/ReadItem
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-readitem
functions: [FGetC, FindArg, FreeArgs, Input, ReadArgs, UnGetC]
libraries: [dos.library]
---

# dos.library/ReadItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ReadItem - reads a single argument/name from command line (V36)
```
SYNOPSIS

```c
    value = ReadItem(buffer, maxchars, input)
    D0                D1        D2      D3

    LONG ReadItem(STRPTR, LONG, struct [CSource](autodocs-2.0/includes-dos-rdargs-h.md) *)
```
FUNCTION

```c
    Reads a "word" from either [Input()](autodocs-2.0/dos-library-input.md) (buffered), or via [CSource](autodocs-2.0/includes-dos-rdargs-h.md), if it
    is non-NULL (see [<dos/rdargs.h>](autodocs-2.0/includes-dos-rdargs-h.md) for more information).  Handles
    quoting and some '*' substitutions (*e and *n) inside quotes (only).
    See [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md) for a listing of values returned by ReadItem()
    (ITEM_XXXX).  A "word" is delimited by whitespace, quotes, or an EOF.

    ReadItem always unreads the last thing read (UnGetC(fh,-1)) so the
    caller can find out what the terminator was.
```
INPUTS

```c
    buffer   - buffer to store word in.
    maxchars - size of the buffer
    input    - [CSource](autodocs-2.0/includes-dos-rdargs-h.md) input or NULL (uses FGetC(Input()))
```
RESULT

```c
    value - See [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md) for return values.
```
SEE ALSO

```c
    [ReadArgs()](autodocs-2.0/dos-library-readargs.md), [FindArg()](autodocs-2.0/dos-library-findarg.md), [UnGetC()](autodocs-2.0/dos-library-ungetc.md), [FGetC()](autodocs-2.0/dos-library-fgetc.md), [Input()](autodocs-2.0/dos-library-input.md), [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md),
    [<dos/rdargs.h>](autodocs-2.0/includes-dos-rdargs-h.md), [FreeArgs()](autodocs-2.0/dos-library-freeargs.md)
```

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [FindArg — dos.library](../autodocs/dos.library.md#findarg)
- [FreeArgs — dos.library](../autodocs/dos.library.md#freeargs)
- [Input — dos.library](../autodocs/dos.library.md#input)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
- [UnGetC — dos.library](../autodocs/dos.library.md#ungetc)
