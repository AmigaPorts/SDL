---
title: dos.library/MatchNext
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-matchnext
functions: [MatchEnd, MatchFirst, MatchNext, ParsePattern]
libraries: [dos.library]
---

# dos.library/MatchNext

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    MatchNext - Finds the next file or directory that matches pattern (V36)
```
SYNOPSIS

```c
    error = MatchNext(AnchorPath)
    D0                    D1

    LONG MatchNext(struct [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md) *)
```
FUNCTION

```c
    Locates the next file or directory that matches a given pattern.
    See [<dos/dosasl.h>](autodocs-2.0/includes-dos-dosasl-h.md) for more information.  Various bits in the flags
    allow the application to control the operation of MatchNext().

    See [MatchFirst()](autodocs-2.0/dos-library-matchfirst.md) for other notes.
```
INPUTS

```c
    [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md) - Place holder for search.  MUST be longword aligned!
```
RESULT

```c
    error - 0 for success or error code.  (Opposite of most Dos calls)
```
BUGS

```c
    See [MatchFirst()](autodocs-2.0/dos-library-matchfirst.md).
```
SEE ALSO

```c
    [MatchFirst()](autodocs-2.0/dos-library-matchfirst.md), [ParsePattern()](autodocs-2.0/dos-library-parsepattern.md), [Examine()](autodocs-2.0/dos-library-examine.md), [CurrentDir()](autodocs-2.0/dos-library-currentdir.md), [Examine()](autodocs-2.0/dos-library-examine.md),
    [MatchEnd()](autodocs-2.0/dos-library-matchend.md), [ExNext()](autodocs-2.0/dos-library-exnext.md), [<dos/dosasl.h>](autodocs-2.0/includes-dos-dosasl-h.md)
```

---

## See Also

- [MatchEnd — dos.library](../autodocs/dos.library.md#matchend)
- [MatchFirst — dos.library](../autodocs/dos.library.md#matchfirst)
- [MatchNext — dos.library](../autodocs/dos.library.md#matchnext)
- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
