---
title: dos.library/RunCommand
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-runcommand
functions: [CreateNewProc, GetArgStr, ReadArgs, RunCommand, SystemTagList]
libraries: [dos.library]
---

# dos.library/RunCommand

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RunCommand -- Runs a program using the current process (V36)
```
SYNOPSIS

```c
    rc = RunCommand(seglist, stacksize, argptr, argsize)
    D0                D1         D2       D3      D4

    LONG RunCommand(BPTR, ULONG, STRPTR, ULONG)
```
FUNCTION

```c
    Runs a command on your process/cli.  Seglist may be any language,
    including BCPL programs.  Stacksize is in bytes.  argptr is a null-
    terminated string, argsize is its length.  Returns the returncode the
    program exited with in d0. Returns -1 if the stack couldn't be
    allocated.

    NOTE: the argument string MUST be terminated with a newline to work
    properly with [ReadArgs()](autodocs-2.0/dos-library-readargs.md) and other argument parsers.

    RunCommand also takes care of setting up the current input filehandle
    in such a way that [ReadArgs()](autodocs-2.0/dos-library-readargs.md) can be used in the program, and restores
    the state of the buffering before returning.  It also sets the value
    returned by [GetArgStr()](autodocs-2.0/dos-library-getargstr.md), and restores it before returning.  NOTE:
    the setting of the argument string in the filehandle was added in V37.

    It's usually appropriate to set the command name (via
    [SetProgramName()](autodocs-2.0/dos-library-setprogramname.md)) before calling RunCommand().  RunCommand() sets
    the value returned by [GetArgStr()](autodocs-2.0/dos-library-getargstr.md) while the command is running.
```
INPUTS

    seglist   - Seglist of command to run.
    stacksize - Number of bytes to allocate for stack space
    argptr    - Pointer to argument command string.
    argsize   - Number of bytes in argument command.
RESULT

    rc        - Return code from executed command. -1 indicates failure
SEE ALSO

```c
    [CreateNewProc()](autodocs-2.0/dos-library-createnewproc.md), [SystemTagList()](autodocs-2.0/dos-library-systemtaglist.md), [Execute()](autodocs-2.0/dos-library-execute.md), [GetArgStr()](autodocs-2.0/dos-library-getargstr.md),
    [SetProgramName()](autodocs-2.0/dos-library-setprogramname.md), [ReadArgs()](autodocs-2.0/dos-library-readargs.md)
```

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
- [GetArgStr — dos.library](../autodocs/dos.library.md#getargstr)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
- [RunCommand — dos.library](../autodocs/dos.library.md#runcommand)
- [SystemTagList — dos.library](../autodocs/dos.library.md#systemtaglist)
