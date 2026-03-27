---
title: dos.library/MatchEnd
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-matchend
functions: [MatchFirst, MatchNext, ParsePattern]
libraries: [dos.library]
---

# dos.library/MatchEnd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    MatchEnd -- Free storage allocated for [MatchFirst()/MatchNext()](autodocs-2.0/dos-library-matchnext.md) (V36)
```
SYNOPSIS

```c
    MatchEnd(AnchorPath)
                 D1

    VOID MatchEnd(struct [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md) *)
```
FUNCTION

    Return all storage associated with a given search.
INPUTS

```c
    [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md) - Anchor used for [MatchFirst()/MatchNext()](autodocs-2.0/dos-library-matchnext.md)
                 MUST be longword aligned!
```
SEE ALSO

```c
    [MatchFirst()](autodocs-2.0/dos-library-matchfirst.md), [ParsePattern()](autodocs-2.0/dos-library-parsepattern.md), [Examine()](autodocs-2.0/dos-library-examine.md), [CurrentDir()](autodocs-2.0/dos-library-currentdir.md), [Examine()](autodocs-2.0/dos-library-examine.md),
    [MatchNext()](autodocs-2.0/dos-library-matchnext.md), [ExNext()](autodocs-2.0/dos-library-exnext.md), [<dos/dosasl.h>](autodocs-2.0/includes-dos-dosasl-h.md)
```

---

## See Also

- [MatchFirst — dos.library](../autodocs/dos.library.md#matchfirst)
- [MatchNext — dos.library](../autodocs/dos.library.md#matchnext)
- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
