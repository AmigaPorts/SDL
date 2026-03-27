---
title: dos.library/GetPrompt
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-getprompt
functions: [IoErr]
libraries: [dos.library]
---

# dos.library/GetPrompt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetPrompt -- Returns the prompt for the current process (V36)
```
SYNOPSIS

```c
    success = GetPrompt(buf, len)
    D0                  D1   D2

    BOOL GetPrompt(STRPTR, LONG)
```
FUNCTION

```c
    Extracts the prompt string from the CLI structure and puts it
    into the buffer.  If the buffer is too small, the string is truncated
    appropriately and a failure code returned.  If no CLI structure is
    present, a null string is returned in the buffer, and failure from
    the call (with [IoErr()](autodocs-2.0/dos-library-ioerr.md) == ERROR_OBJECT_WRONG_TYPE);
```
INPUTS

    buf     - Buffer to hold extracted prompt
    len     - Number of bytes of space in buffer
RESULT

    success - Success/failure indicator
SEE ALSO

```c
    [SetPrompt()](autodocs-2.0/dos-library-setprompt.md)
```

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
