---
title: dos.library/GetProgramName
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-getprogramname
functions: [IoErr]
libraries: [dos.library]
---

# dos.library/GetProgramName

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetProgramName -- Returns the current program name (V36)
```
SYNOPSIS

```c
    success = GetProgramName(buf, len)
    D0                       D1   D2

    BOOL GetProgramName(STRPTR, LONG)
```
FUNCTION

```c
    Extracts the program name from the CLI structure and puts it
    into the buffer.  If the buffer is too small, the name is truncated
    present, a null string is returned in the buffer, and failure from
    the call (with [IoErr()](autodocs-2.0/dos-library-ioerr.md) == ERROR_OBJECT_WRONG_TYPE);
```
INPUTS

    buf     - Buffer to hold extracted name
    len     - Number of bytes of space in buffer
RESULT

    success - Success/failure indicator
SEE ALSO

```c
    [SetProgramName()](autodocs-2.0/dos-library-setprogramname.md)
```

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
