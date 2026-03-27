---
title: dos.library/SetComment
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-setcomment
functions: [SetComment, SetProtection]
libraries: [dos.library]
---

# dos.library/SetComment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetComment -- Change a files' comment string
SYNOPSIS

```c
    success = SetComment( name, comment )
    D0                    D1    D2

    BOOL SetComment(STRPTR, STRPTR)
```
FUNCTION

```c
    SetComment() sets a comment on a file or directory. The comment is
    a pointer to a null-terminated string of up to 80 characters in the
    current ROM filesystem (and RAM:).  Note that not all filesystems
    will support comments (for example, NFS usually will not), or the
    size of comment supported may vary.
```
INPUTS

    name    - pointer to a null-terminated string
    comment - pointer to a null-terminated string
RESULTS

    success - boolean
SEE ALSO

```c
    [Examine()](autodocs-2.0/dos-library-examine.md), [ExNext()](autodocs-2.0/dos-library-exnext.md), [SetProtection()](autodocs-2.0/dos-library-setprotection.md)
```

---

## See Also

- [SetComment — dos.library](../autodocs/dos.library.md#setcomment)
- [SetProtection — dos.library](../autodocs/dos.library.md#setprotection)
