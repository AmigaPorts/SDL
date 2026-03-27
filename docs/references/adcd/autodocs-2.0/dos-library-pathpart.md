---
title: dos.library/PathPart
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-pathpart
functions: [AddPart, FilePart]
libraries: [dos.library]
---

# dos.library/PathPart

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    PathPart -- Returns a pointer to the end of the next-to-last (V36)
                component of a path.
```
SYNOPSIS

```c
    fileptr = PathPart( path )
    D0                   D1

    STRPTR PathPart( STRPTR )
```
FUNCTION

```c
    This function returns a pointer to the character after the next-to-last
    component of a path specification, which will normally be the directory
    name.  If there is only one component, it returns a pointer to the
    beginning of the string.  The only real difference between this and
    [FilePart()](autodocs-2.0/dos-library-filepart.md) is the handling of '/'.
```
INPUTS

    path - pointer to an path string.  May be relative to the current
           directory or the current disk.
RESULT

    fileptr - pointer to the end of the next-to-last component of the path.
EXAMPLE

```c
    PathPart("xxx:yyy/zzz/qqq") would return a pointer to the last '/'.
    PathPart("xxx:yyy") would return a pointer to the first 'y').
```
SEE ALSO

```c
    [FilePart()](autodocs-2.0/dos-library-filepart.md), [AddPart()](autodocs-2.0/dos-library-addpart.md)
```

---

## See Also

- [AddPart — dos.library](../autodocs/dos.library.md#addpart)
- [FilePart — dos.library](../autodocs/dos.library.md#filepart)
