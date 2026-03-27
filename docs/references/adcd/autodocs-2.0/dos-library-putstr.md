---
title: dos.library/PutStr
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-putstr
functions: [FPutC, FPuts, FWrite, WriteChars]
libraries: [dos.library]
---

# dos.library/PutStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    PutStr -- Writes a string the the default output (buffered) (V36)
```
SYNOPSIS

```c
    error = PutStr(str)
    D0             D1

    LONG PutStr(STRPTR)
```
FUNCTION

    This routine writes an unformatted string to the default output.  No
    newline is appended to the string and any error is returned.  This
    routine is buffered.
INPUTS

    str   - Null-terminated string to be written to default output
RESULT

    error - 0 for success, -1 for any error.  NOTE: this is opposite
            most Dos function returns!
SEE ALSO

```c
    [FPuts()](autodocs-2.0/dos-library-fputs.md), [FPutC()](autodocs-2.0/dos-library-fputc.md), [FWrite()](autodocs-2.0/dos-library-fwrite.md), [WriteChars()](autodocs-2.0/dos-library-writechars.md)
```

---

## See Also

- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [FPuts — dos.library](../autodocs/dos.library.md#fputs)
- [FWrite — dos.library](../autodocs/dos.library.md#fwrite)
- [WriteChars — dos.library](../autodocs/dos.library.md#writechars)
