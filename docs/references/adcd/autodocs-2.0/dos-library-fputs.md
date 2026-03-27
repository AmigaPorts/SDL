---
title: dos.library/FPuts
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-fputs
functions: [FGets, FPutC, FWrite, PutStr]
libraries: [dos.library]
---

# dos.library/FPuts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FPuts -- Writes a string the the specified output (buffered) (V36)
```
SYNOPSIS

```c
    error = FPuts(fh, str)
    D0            D1  D2

    LONG FPuts(BPTR, STRPTR)
```
FUNCTION

    This routine writes an unformatted string to the filehandle.  No
    newline is appended to the string and the length actually written is
    returned.  This routine is buffered.
INPUTS

    fh    - filehandle to use for buffered I/O
    str   - Null-terminated string to be written to default output
RESULT

    error - 0 normally, otherwise -1.  Note that this is opposite of
            most other Dos functions, which return success.
SEE ALSO

```c
    [FGets()](autodocs-2.0/dos-library-fgets.md), [FPutC()](autodocs-2.0/dos-library-fputc.md), [FWrite()](autodocs-2.0/dos-library-fwrite.md), [PutStr()](autodocs-2.0/dos-library-putstr.md)
```

---

## See Also

- [FGets — dos.library](../autodocs/dos.library.md#fgets)
- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [FWrite — dos.library](../autodocs/dos.library.md#fwrite)
- [PutStr — dos.library](../autodocs/dos.library.md#putstr)
