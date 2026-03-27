---
title: dos.library/NameFromFH
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-namefromfh
functions: [NameFromLock]
libraries: [dos.library]
---

# dos.library/NameFromFH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    NameFromFH -- Get the name of an open filehandle (V36)
```
SYNOPSIS

```c
    success = NameFromFH(fh, buffer, len)
    D0                   D1    D2    D3

    BOOL NameFromFH(BPTR, STRPTR, LONG)
```
FUNCTION

```c
    Returns a fully qualified path for the filehandle.  This routine is
    guaranteed not to write more than len characters into the buffer.  The
    name will be null-terminated.  See [NameFromLock()](autodocs-2.0/dos-library-namefromlock.md) for more information.
```
INPUTS

    fh     - Lock of object to be examined.
    buffer - Buffer to store name.
    len    - Length of buffer.
RESULT

    success - Success/failure indicator.
SEE ALSO

```c
    [NameFromLock()](autodocs-2.0/dos-library-namefromlock.md)
```

---

## See Also

- [NameFromLock — dos.library](../autodocs/dos.library.md#namefromlock)
