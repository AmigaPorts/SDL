---
title: dos.library/SetProgramDir
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-setprogramdir
functions: [GetProgramDir, Open]
libraries: [dos.library]
---

# dos.library/SetProgramDir

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetProgramDir -- Sets the directory returned by [GetProgramDir](autodocs-2.0/dos-library-getprogramdir.md) (V36)
```
SYNOPSIS

```c
    oldlock = SetProgramDir(lock)
    D0                       D1

    BPTR SetProgramDir(BPTR)
```
FUNCTION

```c
    Sets a shared lock on the directory the program was loaded from.
    This can be used for a program to find data files, etc, that are
    stored with the program, or to find the program file itself.  NULL
    is a valid input.  This can be accessed via [GetProgramDir()](autodocs-2.0/dos-library-getprogramdir.md) or
    by using paths relative to PROGDIR:.
```
INPUTS

    lock - A lock on the directory the current program was loaded from
RESULT

    oldlock - The previous ProgramDir.
SEE ALSO

```c
    [GetProgramDir()](autodocs-2.0/dos-library-getprogramdir.md), [Open()](autodocs-2.0/dos-library-open.md)
```

---

## See Also

- [GetProgramDir — dos.library](../autodocs/dos.library.md#getprogramdir)
- [Open — dos.library](../autodocs/dos.library.md#open)
