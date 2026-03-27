---
title: dos.library/SetMode
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-setmode
functions: [SetMode]
libraries: [dos.library]
---

# dos.library/SetMode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetMode - Set the current behavior of a handler (V36)
```
SYNOPSIS

```c
    success = SetMode(fh, mode)
    D0                D1  D2

    BOOL SetMode(BPTR, LONG)
```
FUNCTION

```c
    SetMode() sends an ACTION_SCREEN_MODE packet to the handler in
    question, normally for changing a CON: handler to raw mode or
    vice-versa.  For CON:, use 1 to go to RAW: mode, 0 for CON: mode.
```
INPUTS

    fh   - filehandle
    mode - The new mode you want
RESULT

    success - Boolean
SEE ALSO

---

## See Also

- [SetMode — dos.library](../autodocs/dos.library.md#setmode)
