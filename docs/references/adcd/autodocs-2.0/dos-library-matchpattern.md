---
title: dos.library/MatchPattern
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-matchpattern
functions: [IoErr, MatchFirst, MatchNext, MatchPatternNoCase, ParsePattern]
libraries: [dos.library]
---

# dos.library/MatchPattern

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    MatchPattern --  Checks for a pattern match with a string (V36)
```
SYNOPSIS

```c
    match = MatchPattern(pat, str)
    D0                   D1   D2

    BOOL MatchPattern(STRPTR, STRPTR)
```
FUNCTION

```c
    Checks for a pattern match with a string.  The pattern must be a
    tokenized string output by [ParsePattern()](autodocs-2.0/dos-library-parsepattern.md).  This routine is
    case-sensitive.

    NOTE: this routine is highly recursive.  You must have at least
    1500 free bytes of stack to call this (it will cut off it's
    recursion before going any deeper than that and return failure).
    That's _currently_ enough for about 100 levels deep of #, (, ~, etc.
```
INPUTS

```c
    pat - Special pattern string to match as returned by [ParsePattern()](autodocs-2.0/dos-library-parsepattern.md)
    str - String to match against given pattern
```
RESULT

```c
    match - success or failure of pattern match.  On failure,
            [IoErr()](autodocs-2.0/dos-library-ioerr.md) will return 0 or ERROR_TOO_MANY_LEVELS (starting
            with V37 - before that there was no stack checking).
```
SEE ALSO

```c
    [ParsePattern()](autodocs-2.0/dos-library-parsepattern.md), [MatchPatternNoCase()](autodocs-2.0/dos-library-matchpatternnocase.md), [MatchFirst()](autodocs-2.0/dos-library-matchfirst.md), [MatchNext()](autodocs-2.0/dos-library-matchnext.md)
```

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [MatchFirst — dos.library](../autodocs/dos.library.md#matchfirst)
- [MatchNext — dos.library](../autodocs/dos.library.md#matchnext)
- [MatchPatternNoCase — dos.library](../autodocs/dos.library.md#matchpatternnocase)
- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
