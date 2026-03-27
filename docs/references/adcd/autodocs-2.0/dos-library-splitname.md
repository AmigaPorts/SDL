---
title: dos.library/SplitName
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-splitname
functions: [AddPart, FilePart, PathPart]
libraries: [dos.library]
---

# dos.library/SplitName

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SplitName -- splits out a component of a pathname into a buffer (V36)
```
SYNOPSIS

```c
    newpos = SplitName(name, separator, buf, oldpos, size)
    D0                  D1      D2      D3     D4     D5

    WORD SplitName(STRPTR, UBYTE, STRPTR, WORD, LONG)
```
FUNCTION

```c
    This routine splits out the next piece of a name from a given file
    name.  Each piece is copied into the buffer, truncating at size-1
    characters.  The new position is then returned so that it may be
    passed in to the next call to splitname.  If the separator is not
    found within 'size' characters, then size-1 characters plus a null will
    be put into the buffer, and the position of the next separator will
    be returned.

    If a a separator cannot be found, -1 is returned (but the characters
    from the old position to the end of the string are copied into the
    buffer, up to a maximum of size-1 characters).  Both strings are
    null-terminated.

    This function is mainly intended to support handlers.
```
INPUTS

```c
    name      - Filename being parsed.
    separator - Separator charactor to split by.
    buf       - Buffer to hold separated name.
    oldpos    - Current position in the file.
    size      - Size of buf in bytes (including null termination);
```
RESULT

    newpos    - New position for next call to splitname.  -1 for last one.
SEE ALSO

```c
    [FilePart()](autodocs-2.0/dos-library-filepart.md), [PathPart()](autodocs-2.0/dos-library-pathpart.md), [AddPart()](autodocs-2.0/dos-library-addpart.md)
```

---

## See Also

- [AddPart — dos.library](../autodocs/dos.library.md#addpart)
- [FilePart — dos.library](../autodocs/dos.library.md#filepart)
- [PathPart — dos.library](../autodocs/dos.library.md#pathpart)
