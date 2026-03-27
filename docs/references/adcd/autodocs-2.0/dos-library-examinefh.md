---
title: dos.library/ExamineFH
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-examinefh
functions: [AllocDosObject, Open]
libraries: [dos.library]
---

# dos.library/ExamineFH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ExamineFH -- Gets information on an open file (V36)
```
SYNOPSIS

```c
    success = ExamineFH(fh, fib)
    D0                  D1  D2

    BOOL ExamineFH(BPTR, struct [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) *)
```
FUNCTION

```c
    Examines a filehandle and returns information about the file in the
    [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md).  There are no guarantees as to whether the fib_Size
    field will reflect any changes made to the file size it was opened,
    though filesystems should attempt to provide up-to-date information
    for it.
```
INPUTS

```c
    fh  - Filehandle you wish to examine
    fib - [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md), must be longword aligned.
```
RESULT

    success - Success/failure indication
SEE ALSO

```c
    [Examine()](autodocs-2.0/dos-library-examine.md), [ExNext()](autodocs-2.0/dos-library-exnext.md), [ExAll()](autodocs-2.0/dos-library-exall.md), [Open()](autodocs-2.0/dos-library-open.md), [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md)
```

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [Open — dos.library](../autodocs/dos.library.md#open)
