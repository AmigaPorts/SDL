---
title: dos.library/WriteChars
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-writechars
functions: [FPutC, FPuts, FWrite, PutStr]
libraries: [dos.library]
---

# dos.library/WriteChars

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    WriteChars -- Writes bytes to the the default output (buffered) (V36)
```
SYNOPSIS

```c
    count = WriteChars(buf, buflen)
    D0                 D1

    LONG WriteChars(STRPTR, LONG)
```
FUNCTION

    This routine writes a number of bytes to the default output.  The
    length is returned.  This routine is buffered.
INPUTS

    buf    - buffer of characters to write
    buflen - number of characters to write
RESULT

```c
    count - Number of bytes written.  -1 (EOF) indicates an error
```
SEE ALSO

```c
    [FPuts()](autodocs-2.0/dos-library-fputs.md), [FPutC()](autodocs-2.0/dos-library-fputc.md), [FWrite()](autodocs-2.0/dos-library-fwrite.md), [PutStr()](autodocs-2.0/dos-library-putstr.md)
```

---

## See Also

- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [FPuts — dos.library](../autodocs/dos.library.md#fputs)
- [FWrite — dos.library](../autodocs/dos.library.md#fwrite)
- [PutStr — dos.library](../autodocs/dos.library.md#putstr)
