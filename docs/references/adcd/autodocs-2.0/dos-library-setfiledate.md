---
title: dos.library/SetFileDate
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-setfiledate
functions: [DateStamp]
libraries: [dos.library]
---

# dos.library/SetFileDate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetFileDate -- Sets the modification date for a file or dir (V36)
```
SYNOPSIS

```c
    success = SetFileDate(name, date)
    D0                     D1    D2

    BOOL SetFileDate(STRPTR, struct [DateStamp](autodocs-2.0/includes-dos-dos-h.md) *)
```
FUNCTION

    Sets the file date for a file or directory.  Note that for the Old
    File System and the Fast File System, the date of the root directory
    cannot be set.  Other filesystems may not support setting the date
    for all files/directories.
INPUTS

    name - Name of object
    date - New modification date
RESULT

    success - Success/failure indication
SEE ALSO

```c
    [DateStamp()](autodocs-2.0/dos-library-datestamp.md), [Examine()](autodocs-2.0/dos-library-examine.md), [ExNext()](autodocs-2.0/dos-library-exnext.md), [ExAll()](autodocs-2.0/dos-library-exall.md)
```

---

## See Also

- [DateStamp — dos.library](../autodocs/dos.library.md#datestamp)
