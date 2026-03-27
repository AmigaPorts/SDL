---
title: dos.library/FilePart
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-filepart
functions: [AddPart, PathPart]
libraries: [dos.library]
---

# dos.library/FilePart

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FilePart -- Returns the last component of a path (V36)
```
SYNOPSIS

```c
    fileptr = FilePart( path )
    D0                   D1

    STRPTR FilePart( STRPTR )
```
FUNCTION

    This function returns a pointer to the last component of a string path
    specification, which will normally be the file name.  If there is only
    one component, it returns a pointer to the beginning of the string.
INPUTS

    path - pointer to an path string.  May be relative to the current
           directory or the current disk.
RESULT

    fileptr - pointer to the last component of the path.
EXAMPLE

```c
    FilePart("xxx:yyy/zzz/qqq") would return a pointer to the first 'q'.
    FilePart("xxx:yyy") would return a pointer to the first 'y').
```
SEE ALSO

```c
    [PathPart()](autodocs-2.0/dos-library-pathpart.md), [AddPart()](autodocs-2.0/dos-library-addpart.md)
```

---

## See Also

- [AddPart — dos.library](../autodocs/dos.library.md#addpart)
- [PathPart — dos.library](../autodocs/dos.library.md#pathpart)
