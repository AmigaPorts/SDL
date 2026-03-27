---
title: dos.library/SetArgStr
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-setargstr
functions: [GetArgStr, RunCommand]
libraries: [dos.library]
---

# dos.library/SetArgStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetArgStr -- Sets the arguments for the current process (V36)
```
SYNOPSIS

```c
    oldptr = SetArgStr(ptr)
    D0                 D1

    STRPTR SetArgStr(STRPTR)
```
FUNCTION

    Sets the arguments for the current program.  The ptr MUST be reset
    to it's original value before process exit.
INPUTS

    ptr - pointer to new argument string.
RESULT

    oldptr - the previous argument string
SEE ALSO

```c
    [GetArgStr()](autodocs-2.0/dos-library-getargstr.md), [RunCommand()](autodocs-2.0/dos-library-runcommand.md)
```

---

## See Also

- [GetArgStr — dos.library](../autodocs/dos.library.md#getargstr)
- [RunCommand — dos.library](../autodocs/dos.library.md#runcommand)
