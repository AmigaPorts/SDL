---
title: dos.library/ParsePatternNoCase
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-parsepatternnocase
functions: [IoErr, MatchFirst, MatchNext, MatchPatternNoCase, ParsePattern]
libraries: [dos.library]
---

# dos.library/ParsePatternNoCase

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ParsePatternNoCase -- Create a tokenized string for
                                            [MatchPatternNoCase()](autodocs-2.0/dos-library-matchpatternnocase.md) (V37)
```
SYNOPSIS

```c
    IsWild = ParsePatternNoCase(Source, Dest, DestLength)
    d0                            D1     D2      D3

    LONG ParsePatternNoCase(STRPTR, STRPTR, LONG)
```
FUNCTION

```c
    Tokenizes a pattern, for use by [MatchPatternNoCase()](autodocs-2.0/dos-library-matchpatternnocase.md).  Also indicates
    if there are any wildcards in the pattern (i.e. whether it might match
    more than one item).  Note that Dest must be at least 2 times as
    large as Source plus 2 bytes.

    For a description of the wildcards, see [ParsePattern()](autodocs-2.0/dos-library-parsepattern.md).
```
INPUTS
    source     - unparsed wildcard string to search for.
   dest       - output string, gets tokenized version of input.

```c
    DestLength - length available in destination (should be at least as
                 twice as large as source + 2 bytes).
```
RESULT

    IsWild - 1 means there were wildcards in the pattern,
             0 means there were no wildcards in the pattern,
            -1 means there was a buffer overflow or other error
BUGS

```c
    Should set [IoErr()](autodocs-2.0/dos-library-ioerr.md) to something useful (not currently set) on an
    error.
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
