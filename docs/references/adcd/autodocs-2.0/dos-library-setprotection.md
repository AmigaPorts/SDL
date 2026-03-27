---
title: dos.library/SetProtection
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-setprotection
functions: [SetComment, SetProtection]
libraries: [dos.library]
---

# dos.library/SetProtection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetProtection -- Set protection for a file or directory
SYNOPSIS

```c
    success = SetProtection( name, mask )
    D0                       D1    D2:4

    BOOL SetProtection (STRPTR, LONG)
```
FUNCTION

```c
    SetProtection() sets the protection attributes on a file or
    directory. The lower bits of the mask are as follows:

    bit 4: 1 = file has not changed         0 = file has been changed
    bit 3: 1 = reads not allowed,           0 = reads allowed.
    bit 2: 1 = writes not allowed,          0 = writes allowed.
    bit 1: 1 = execution not allowed,       0 = execution allowed.
    bit 0: 1 = deletion not allowed,        0 = deletion allowed.

    Before V36, the ROM filesystem didn't respect the Read and Write
    bits.  In V36 or later and in the FFS, the Read and Write
    bits are respected.

    The archive bit should be cleared by the filesystem whenever the file
    is changed.  Backup utilities will generally set the bit after
    backing up each file.

    The V36 Shell looks at the execute bit, and will refuse to execute
    a file if it is set.

    Other bits will be defined in the [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md) include files.  Rather
    than referring to bits by number you should use the definitions in
    [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md).
```
INPUTS

    name - pointer to a null-terminated string
    mask - the protection mask required
RESULTS

    success - boolean
SEE ALSO

```c
    [SetComment()](autodocs-2.0/dos-library-setcomment.md), [Examine()](autodocs-2.0/dos-library-examine.md), [ExNext()](autodocs-2.0/dos-library-exnext.md), [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md)
```

---

## See Also

- [SetComment — dos.library](../autodocs/dos.library.md#setcomment)
- [SetProtection — dos.library](../autodocs/dos.library.md#setprotection)
