---
title: dos.library/GetArgStr
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-getargstr
functions: [GetArgStr, RunCommand, SetArgStr]
libraries: [dos.library]
---

# dos.library/GetArgStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetArgStr -- Returns the arguments for the process (V36)
```
SYNOPSIS

```c
    ptr = GetArgStr()
    D0

    STRPTR GetArgStr(void)
```
FUNCTION

```c
    Returns a pointer to the (null-terminated) arguments for the program
    (process).  This is the same string passed in a0 on startup from CLI.
```
RESULT

    ptr - pointer to arguments
SEE ALSO

```c
    [SetArgStr()](autodocs-2.0/dos-library-setargstr.md), [RunCommand()](autodocs-2.0/dos-library-runcommand.md)
```

---

## See Also

- [GetArgStr — dos.library](../autodocs/dos.library.md#getargstr)
- [RunCommand — dos.library](../autodocs/dos.library.md#runcommand)
- [SetArgStr — dos.library](../autodocs/dos.library.md#setargstr)
